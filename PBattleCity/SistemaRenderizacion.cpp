#include "SistemaRenderizacion.h"
#include <iostream>
#include <cstdio>
using namespace std;

SistemaRenderizacion::SistemaRenderizacion()
{
	handdleConsola = 0;
	
	for (int f = 0; f < filasPantalla; f++) {
		for (int c = 0; c < columnasPantalla; c++) {
			bufferFondoPantalla[f][c].simbolo = 0;
			bufferFondoPantalla[f][c].colorSimbolo = ColorConsola_Gris;
			bufferFondoPantalla[f][c].colorFondo = ColorConsola_Negro;
			
			bufferPantalla[f][c] = bufferFondoPantalla[f][c];
		}
	}
		
}

void SistemaRenderizacion::inicializar()
{
	handdleConsola = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO informacionCursor;
	informacionCursor.bVisible = 0;
	informacionCursor.dwSize = 1;
	SetConsoleCursorInfo(handdleConsola, &informacionCursor);
}

void SistemaRenderizacion::limpiar()
{
	for (int f = 0; f < filasPantalla; f++) {
		for (int c = 0; c < columnasPantalla; c++) {
			bufferFondoPantalla[f][c].simbolo = 0;
			bufferFondoPantalla[f][c].colorSimbolo = ColorConsola_Gris;
			bufferFondoPantalla[f][c].colorFondo = ColorConsola_Negro;
		}
	}
}

void SistemaRenderizacion::dibujarCaracter(int _fila, int _columna, char _simbolo, ColorConsola _colorSimbolo, ColorConsola _colorFondo)
{
	if (_fila < 0 || _columna < 0 || _fila >= filasPantalla || _columna >= columnasPantalla)
		return;

	bufferFondoPantalla[_fila][_columna].simbolo = _simbolo;
	bufferFondoPantalla[_fila][_columna].colorSimbolo = _colorSimbolo;
	bufferFondoPantalla[_fila][_columna].colorFondo = _colorFondo;
}

//void SistemaRenderizacion::dibujarTexto(int _fila, int _columna, const string _texto, ColorConsola _colorSimbolo, ColorConsola _colorFondo)
//{
//	int columnaActual = _columna;
//	for (int i = 0; i < _texto.length(); i++) {
//		dibujarCaracter(_fila, columnaActual, _texto[i], _colorSimbolo, _colorFondo);
//		columnaActual++;
//	}
//}

void SistemaRenderizacion::dibujarTexto(int _fila, int _columna, const char* _texto, ColorConsola _colorSimbolo, ColorConsola _colorFondo)
{
	int columna = _columna;
	char simbolo = *_texto;

	while (simbolo != 0)
	{
		dibujarCaracter(_fila, columna, simbolo, _colorSimbolo, _colorFondo);

		_texto++;
		columna++;
		simbolo = *_texto;
	}
}


void SistemaRenderizacion::ejecutar()
{
	bool bufferPantallaModificado = false;


	for (int f = 0; f < filasPantalla; f++) {
		for (int c = 0; c < columnasPantalla; c++) {
			if ((bufferFondoPantalla[f][c].simbolo != bufferPantalla[f][c].simbolo)
				|| (bufferFondoPantalla[f][c].colorSimbolo != bufferPantalla[f][c].colorSimbolo)
				|| (bufferFondoPantalla[f][c].colorFondo != bufferPantalla[f][c].colorFondo)) {
				//Copiar del bufferFondoPantalla a bufferPantalla, para recupera lo modificado en pantalla
				bufferPantalla[f][c] = bufferFondoPantalla[f][c];

				//Dibujar simbolo en la posicion f, c
				setCursorConsola(f, c);
				setColorConsola(bufferPantalla[f][c].colorSimbolo, bufferPantalla[f][c].colorFondo);
				//cout << bufferPantalla[f][c] << endl;
				printf("%c", bufferPantalla[f][c].simbolo);

				bufferPantallaModificado = true;
			}
		}
	}
}

void SistemaRenderizacion::setCursorConsola(int _fila, int _columna) {
	COORD CoordenadasCursor;
	CoordenadasCursor.X = _columna;
	CoordenadasCursor.Y = _fila;
	SetConsoleCursorPosition(handdleConsola, CoordenadasCursor);
}

void SistemaRenderizacion::setColorConsola(ColorConsola _colorSimbolo, ColorConsola _colorFondo)
{
	/*int colorConsola;
	colorConsola = _colorFondo * 16 + _colorSimbolo;*/

	unsigned char colorConsola = _colorSimbolo | (_colorFondo << 4);
	
	SetConsoleTextAttribute(handdleConsola, colorConsola);
}

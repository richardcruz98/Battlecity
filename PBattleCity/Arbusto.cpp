#include "Arbusto.h"

Arbusto::Arbusto()
{
	tipoActor = TipoActor_Arbusto;

	setImagenArbusto(arbustoImagen, arbustoColorColorSimbolo, arbustoColorFondo);
}

void Arbusto::setImagenArbusto(unsigned char _simbolo, ColorConsola _colorImagen, ColorConsola _colorFondo) {
	imagenArbusto.simbolo = _simbolo;
	imagenArbusto.colorSimbolo = _colorImagen;
	imagenArbusto.colorFondo = _colorFondo;
}
void Arbusto::renderizar(SistemaRenderizacion* _sistemaRenderizacion) {
	int fila = int(y);
	int columna = int(x);

	_sistemaRenderizacion->dibujarCaracter(fila, columna, imagenArbusto.simbolo, imagenArbusto.colorSimbolo, imagenArbusto.colorFondo);
}
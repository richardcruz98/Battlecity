#include "Pared.h"

Pared::Pared()
{
	tipoActor = TipoActor_Pared;

	setImagenPared(ladrilloParedImagen, ladrilloParedColorSimbolo, ladrilloParedColorFondo);
}

void Pared::setImagenPared(unsigned char _simbolo, ColorConsola _colorImagen, ColorConsola _colorFondo) {
	imagenPared.simbolo = _simbolo;
	imagenPared.colorSimbolo = _colorImagen;
	imagenPared.colorFondo = _colorFondo;
}

void Pared::renderizar(SistemaRenderizacion* _sistemaRenderizacion) {
	int fila = int(y);
	int columna = int(x);

	_sistemaRenderizacion->dibujarCaracter(fila, columna, imagenPared.simbolo, imagenPared.colorSimbolo, imagenPared.colorFondo);
}

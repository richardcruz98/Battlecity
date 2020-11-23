#include "Tanque.h"

Tanque::Tanque()
{
	tipoActor = TipoActor_Tanque;
	ancho = tamanoTanque;
	alto = tamanoTanque;
	velocidad = 0;
	fuegoTiempoEnfriamiento = 0.0;

	setColor(ColorConsola_GrisOscuro, ColorConsola_Gris);
}

void Tanque::actualizar(float _dt)
{
	Actor::actualizar(_dt);

	if (fuegoTiempoEnfriamiento > 0)
		fuegoTiempoEnfriamiento -= _dt;
}

void Tanque::renderizar(SistemaRenderizacion* _sistemaRenderizacion)
{
	Actor::renderizar(_sistemaRenderizacion);

	int fila = int(y);
	int columna = int(x);

	for (int f = 0; f < tamanoTanque; f++) {
		for (int c = 0; c < tamanoTanque; c++){
			DatosSimboloConsola sd = imagenTanque[direccion][f][c];
			_sistemaRenderizacion->dibujarCaracter(fila + f, columna + c, sd.simbolo, sd.colorSimbolo, sd.colorFondo);
		}
	}
}

void Tanque::setColor(ColorConsola _colorTanque1, ColorConsola _colorTanque2)
{
	for (int d = Direccion_Izquierda; d < Direccion_MAX; d++)
		for (int f = 0; f < tamanoTanque; f++)
			for (int c = 0; c < tamanoTanque; c++)
			{
				// Simbolo
				imagenTanque[d][f][c].simbolo = imagenTanqueNivel[d][f][c].simbolo;

				// Color simbolo
				switch (imagenTanqueNivel[d][f][c].colorSimbolo)
				{
				case ColorTanque_0:
					imagenTanque[d][f][c].colorSimbolo = ColorConsola_Negro;
					break;

				case ColorTanque_1:
					imagenTanque[d][f][c].colorSimbolo = _colorTanque1;
					break;

				case ColorTanque_2:
					imagenTanque[d][f][c].colorSimbolo = _colorTanque2;
					break;
				}

				// Color fondo
				switch (imagenTanqueNivel[d][f][c].colorFondo)
				{
				case ColorTanque_0:
					imagenTanque[d][f][c].colorFondo = ColorConsola_Negro;
					break;

				case ColorTanque_1:
					imagenTanque[d][f][c].colorFondo = _colorTanque1;
					break;

				case ColorTanque_2:
					imagenTanque[d][f][c].colorFondo = _colorTanque2;
					break;
				}
			}
}

void Tanque::mover(Direccion _direccion)
{
	setDireccion(_direccion);

	setXVelocidad(0);
	setYVelocidad(0);

	switch (direccion)
	{
	case Direccion_Izquierda: setXVelocidad(-velocidad); break;
	case Direccion_Derecha: setXVelocidad(velocidad); break;
	case Direccion_Arriba: setYVelocidad(-velocidad); break;
	case Direccion_Abajo: setYVelocidad(velocidad); break;
	}
}

void Tanque::disparar()
{
	if (fuegoTiempoEnfriamiento > 0)
		return;

	fuegoTiempoEnfriamiento = fuegoTiempoEnfriamientoTanque;

	float x = 0.0;
	float y = 0.0;
	float xVelocidad = 0.0;
	float yVelocidad = 0.0;

	calcularPosicionCeldaFrontal(&x, &y);

	switch (direccion)
	{
	case Direccion_Izquierda: xVelocidad = -velocidadBala; break;
	case Direccion_Derecha: xVelocidad = velocidadBala; break;
	case Direccion_Arriba: yVelocidad = -velocidadBala; break;
	case Direccion_Abajo: yVelocidad = velocidadBala; break;
	}

	/*Bullet* bullet = (Bullet*)m_game->createObject(GameObjectType_Bullet, x, y);
	if (bullet)
	{
		bullet->setOwnerType(m_type);
		bullet->setXSpeed(xSpeed);
		bullet->setYSpeed(ySpeed);
	}*/
}

void Tanque::calcularPosicionCeldaFrontal(float* _x, float* _y)
{
	switch (direccion)
	{
	case Direccion_Izquierda:
		(*_x) = int(getX()) - 0.01;
		(*_y) = int(getY()) + (getAlto() / 2.0);

		break;
	case Direccion_Derecha:
		(*_x) = int(getX()) + getAncho() + 0.01;
		(*_y) = int(getY()) + (getAlto() / 2.0);
		break;
	case Direccion_Arriba:
		(*_y) = int(getY()) - 0.01;
		(*_x) = int(getX()) + (getAncho() / 2.0);
		break;
	case Direccion_Abajo:
		(*_y) = int(getY()) + getAlto() + 0.01;
		(*_x) = int(getX()) + (getAncho() / 2.0);
		break;
	}
}

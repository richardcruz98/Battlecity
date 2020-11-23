#include "GameManager.h"
#include "TanqueJugador.h"
#include <cstdlib>
#include <cstdio>
#include <cmath>

#include "Pared.h"
#include "Arbusto.h"

void GameManager::renderizar()
{
	// Frame inicial
	sistemaRenderizacion.limpiar();

	//Dibujar todos los actores del juego
	int contadorActores = 0;
	for (int i = 0; i < numeroMaximoActores; i++) {
		if (actores[i] != 0)
		{
			actores[i]->renderizar(&sistemaRenderizacion);
			contadorActores++;
		}
	}

	//Dibuja actores contados
	char buffer[64];
	sprintf_s(buffer, "Objectos: %d", contadorActores);
	sistemaRenderizacion.dibujarTexto(0, 0, buffer, ColorConsola_Gris, ColorConsola_Negro);

	//Dibujar Interface de Usuario
	for (int f = 0; f < filasPantalla; f++) {
		for (int c = columnasNivel; c < columnasPantalla; c++)
			sistemaRenderizacion.dibujarCaracter(f, c, ' ', ColorConsola_GrisOscuro, ColorConsola_GrisOscuro);
	}

	//Dibujar los demas elementos del juego

	sistemaRenderizacion.dibujarTexto(2, 71, "Base", ColorConsola_Blanco, ColorConsola_GrisOscuro);
	if (base)
	{
		int sc = 71;
		int sf = 3;
		int c = 0;
		int f = 0;
		int h = base->getEnergia();
		while (h > 0)
		{
			sistemaRenderizacion.dibujarCaracter(sf + f, sc + c, 3, ColorConsola_Rojo, ColorConsola_RojoOscuro);
			--h;
			++c;
			if (c > 7)
			{
				++f;
				c = 0;
			}
		}
	}

	sistemaRenderizacion.dibujarTexto(5, 71, "Jugador 1", ColorConsola_Blanco, ColorConsola_GrisOscuro);
	if (jugador1)
	{
		int sc = 71;
		int sf = 6;
		int c = 0;
		int f = 0;
		int h = jugador1->getEnergia();
		while (h > 0)
		{
			sistemaRenderizacion.dibujarCaracter(sf + f, sc + c, 3, ColorConsola_Amarillo, ColorConsola_Cafe);
			--h;
			++c;
			if (c > 7)
			{
				++f;
				c = 0;
			}
		}
	}

	sistemaRenderizacion.dibujarTexto(9, 71, "Jugador 2 2", ColorConsola_Blanco, ColorConsola_GrisOscuro);
	if (jugador2)
	{
		int sc = 71;
		int sf = 10;
		int c = 0;
		int f = 0;
		int h = jugador2->getEnergia();
		while (h > 0)
		{
			sistemaRenderizacion.dibujarCaracter(sf + f, sc + c, 3, ColorConsola_Verde, ColorConsola_VerdeOscuro);
			--h;
			++c;
			if (c > 7)
			{
				++f;
				c = 0;
			}
		}
	}

	sistemaRenderizacion.dibujarTexto(13, 71, "Enemigos", ColorConsola_Blanco, ColorConsola_GrisOscuro);
	int sc = 71;
	int sf = 14;
	int c = 0;
	int f = 0;
	int h = enemigosPorNivel - contadorEnemigosMuertos;
	while (h > 0)
	{
		sistemaRenderizacion.dibujarCaracter(sf + f, sc + c, 127, ColorConsola_Celeste, ColorConsola_CelesteOscuro);
		--h;
		++c;
		if (c > 7)
		{
			++f;
			c = 0;
		}
	}


	// Finalizar frame

	sistemaRenderizacion.ejecutar();
}

void GameManager::actualizar(float _dt)
{
	for (int i = 0; i < numeroMaximoActores; i++) {
		if (actores[i] != 0) {
			actores[i]->actualizar(_dt);

			if (actores[i]->getEnergia() <= 0 && actores[i]->getDestruirDespuesMuerte())
				destruirActor(actores[i]);
		}
	}

	// Base destruida
	if (base && base->getEnergia() <= 0)
		inicializar();

	// Jugador1 destruido
	if (jugador1 && jugador1->getEnergia() <= 0)
	{
		destruirActor(jugador1);
		jugador1 = NULL;
	}

	// Jugador2 destruido
	if (jugador2 && jugador2->getEnergia() <= 0)
	{
		destruirActor(jugador2);
		jugador2 = NULL;
	}

	// Todos los enemigos destruidos
	if (contadorEnemigosMuertos == enemigosPorNivel)
		inicializar();
}

GameManager::GameManager()
{
	juegoActivo = true;
	relojUltimoFrame = 0;

	for (int i = 0; i < numeroMaximoActores; i++) {
		actores[i] = 0;
	}

	base = 0;
	jugador1 = 0;
	jugador2 = 0;

	contadorEnemigosMuertos = 0;
}

void GameManager::configurarSistema()
{
	srand(time(0));
	sistemaRenderizacion.inicializar();
}

void GameManager::inicializar()
{
	abandonarJuego();
	contadorEnemigosMuertos = 0;

	for (int f = 0; f < filasNivel; f++) {
		for (int c = 0; c < columnasNivel; c++) {
			unsigned char celdaSimbolo = datosNivel0[f][c];
			switch (celdaSimbolo)
			{
			case celdaSimbolo_LadrilloPared:
			{
				//Aqui se crea un actor ladrillo pared.
				Pared* pared = (Pared*)crearActor(TipoActor_Pared, c, f);
				break;
			}
			case celdaSimbolo_MetalPared:
			{
				Pared* pared = (Pared*)crearActor(TipoActor_Pared, c, f);
				pared->setImagenPared(metalParedImagen, metalParedColorSimbolo, metalParedColorFondo);
				pared->setInvulnerable(true);
				break;
				//Aqui se crea un actor bloque metal pared.
			}
			case celdaSimbolo_Arbusto:
			{
				Arbusto* arbusto = (Arbusto*)crearActor(TipoActor_Arbusto, c, f);
				arbusto->setFisico(false);
				break;
				//Aqui se crea un actor Arbusto.
			}
			case celdaSimbolo_Base:
			{
				//Aqui se crea un actor base.
				break;
			}
			case celdaSimbolo_Jugador1:
			{
				//Aqui se crea un actor jugador 1.
				TanqueJugador* jugador1 = (TanqueJugador*)crearActor(TipoActor_TanqueJugador, c + 0.5, f + 0.5);
				jugador1->setColor(ColorConsola_Cafe, ColorConsola_Amarillo);
				jugador1->setTeclas(VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN, VK_SPACE);
				this->jugador1 = jugador1;
				break;
			}
			case celdaSimbolo_Jugador2:
			{
				//Aqui se crea un actor jugador 2.
				break;
			}
			case celdaSimbolo_GeneradorEnemigo:
			{
				//Aqui se crea un actor generador de enemigos.
				break;
			}
			}
		}
	}
}
bool GameManager::bucle()
{
	//Calculo del tiempo delta
	clock_t relojAhora = clock();
	clock_t deltaReloj = relojAhora - relojUltimoFrame;
	float deltaTiempo = float(deltaReloj) / CLOCKS_PER_SEC;
	relojUltimoFrame = relojAhora;

	renderizar();
	actualizar(deltaTiempo);
	return juegoActivo;
}

void GameManager::abandonarJuego()
{
	for(int i = 0; i < numeroMaximoActores; i++){
		if (actores[i] != 0) {
			delete actores[i];
			actores[i] = 0;
		}
	}
}

Actor* GameManager::crearActor(TipoActor _tipoActor, float _x, float _y)
{
	// Encuentra puntero libre y crea objeto
	for (int i = 0; i <  numeroMaximoActores; i++)
	{
		if (actores[i] == 0)
		{
			Actor* actor = 0;

			switch (_tipoActor)
			{
			case TipoActor_Pared:				actor = new Pared();			break;
			case TipoActor_Arbusto:				actor = new Arbusto();			break;
			//case TipoActor_Base:				actor = new Base();				break;
			//case TipoActor_Bala:				actor = new Bala();				break;
			case TipoActor_TanqueJugador:		actor = new TanqueJugador();	break;
			//case TipoActor_TanqueEnemigo:		actor = new TanqueEnemigo();	break;
			//case TipoActor_GeneradorEnemigo:	actor = new GeneradorEnemigo();	break;
			}

			if (actor == 0)
				return 0;

			actor->setGameManager(this);

			if (moverActorA(actor, _x, _y) == false)
			{
				delete actor;
				return 0;
				//return nullptr;
			}

			actores[i] = actor;

			return actor;
		}
	}

	return 0;
	//return nullptr;
}

void GameManager::destruirActor(Actor* _actor)
{
	for (int i = 0; i < numeroMaximoActores; i++)
	{
		if (actores[i] == _actor)
		{
			delete actores[i];
			actores[i] = 0;

			return;
		}
	}
}

Actor* GameManager::detectarColisiones(float _x, float _y, float _ancho, float _alto, Actor* _actorExcluido)
{
	int f00 = int(_y);
	int c00 = int(_x);
	int f01 = f00 + _alto - 1;
	int c01 = c00 + _ancho - 1;

	for (int i = 0; i < numeroMaximoActores; i++)
		if (actores[i] != 0 && actores[i]->getFisico() && actores[i] != _actorExcluido)
		{
			int f10 = int(actores[i]->getY());
			int c10 = int(actores[i]->getX());
			int f11 = f10 + actores[i]->getAlto() - 1;
			int c11 = c10 + actores[i]->getAncho() - 1;

			if (f00 <= f11 && f01 >= f10 && c00 <= c11 && c01 >= c10)
				return actores[i];
		}

	return nullptr;
}

bool GameManager::moverActorA(Actor* actor, float _x, float _y)
{
	int f0 = int(_y);
	int c0 = int(_x);
	int f1 = f0 + actor->getAlto() - 1;
	int c1 = c0 + actor->getAncho() - 1;

	if (f0 < 0 || c0 < 0 || f1 >= filasNivel || c1 >= columnasNivel)
		return false;


	bool puedeMoverACelda = false;

	Actor* otroActor = detectarColisiones(_x, _y, actor->getAncho(), actor->getAlto(), actor);

	if (otroActor)
		actor->intersectar(otroActor);
	else
		puedeMoverACelda = true;


	if (puedeMoverACelda)
	{
		actor->setX(_x);
		actor->setY(_y);
	}

	return puedeMoverACelda;
}

int GameManager::getConteoActores(TipoActor _tipoActor)
{
	return 0;
}

int GameManager::incrementarContadorEnemigosMuertos()
{
	return 0;
}


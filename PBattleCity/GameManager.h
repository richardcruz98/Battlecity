#pragma once
#include <ctime>

#include "Actor.h"
#include "TipoActor.h"
#include "SistemaRenderizacion.h"
#include "Nivel.h"

const int numeroMaximoActores = 1024;

class Actor;

class GameManager
{
private:
	bool juegoActivo;
	clock_t relojUltimoFrame;
	SistemaRenderizacion sistemaRenderizacion;

	Actor* actores[numeroMaximoActores];

	Actor* base;
	Actor* jugador1;
	Actor* jugador2;

	int contadorEnemigosMuertos;

	void renderizar();
	void actualizar(float _dt);

public:
	GameManager();

	void configurarSistema();
	void inicializar();
	bool bucle();
	void abandonarJuego();

	Actor* crearActor(TipoActor _tipoActor, float _x, float _y);
	void destruirActor(Actor* _actor);
	Actor* detectarColisiones(float _x, float _y, float _ancho, float _alto, Actor* _actorExcluido);
	bool moverActorA(Actor* _actor, float _x, float _y);
	int getConteoActores(TipoActor _tipoActor);
	int getConteoEnemigosMuertos() { return contadorEnemigosMuertos; }
	int incrementarContadorEnemigosMuertos();
};


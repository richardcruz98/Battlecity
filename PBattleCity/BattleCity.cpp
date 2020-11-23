#include <iostream>
#include "GameManager.h"
#include "SistemaRenderizacion.h"

//#include "Tanque.h"
//#include "Bala.h"
//#include "./Escenario/MuroLadrillo.h"
//#include "./Escenario/MuroMetal.h"
//#include <conio.h>
//#include <stdio.h>
//#include <time.h>
//#include "Municion.h"

using namespace std;

int main()
{
	GameManager gameManager;

	gameManager.configurarSistema();
	gameManager.inicializar();

	while (gameManager.bucle());
	gameManager.abandonarJuego();

	cin.get();
	return 0;
}
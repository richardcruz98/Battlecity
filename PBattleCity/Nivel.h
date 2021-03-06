#pragma once

#include "SistemaRenderizacion.h"
#include "Direccion.h"

// Datos del nivel 
const int filasNivel = filasPantalla;
const int columnasNivel = 70;

const unsigned char	celdaSimbolo_Jugador1 = '1';
const unsigned char	celdaSimbolo_Jugador2 = '2';
const unsigned char	celdaSimbolo_Tanque = 'T';
const unsigned char	celdaSimbolo_LadrilloPared = '#';
const unsigned char	celdaSimbolo_MetalPared = '@';
const unsigned char celdaSimbolo_Arbusto = '&';
const unsigned char	celdaSimbolo_Base = 'B';
const unsigned char	celdaSimbolo_GeneradorEnemigo = 'S';

const unsigned char datosNivel0[filasNivel][columnasNivel + 1] =
{
	"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
	"@S                                @@                              S  @",
	"@                                 @@                                 @",
	"@                                 @@                                 @",
	"@   ##   ##   @@@###### S   @@@        @@@ S   ######@@@   ##   ##   @",
	"@   #######   @@@######     @@@        @@@     ######@@@   #######   @",
	"@   #######&&&&&&&&&&&&&&&&&@@@        @@@&&&&&&&&&&&&&&&&&#######   @",
	"@   ##   ##&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&##   ##   @",
	"@          &&&&&&&&&&&&&&&&&      @@      &&&&&&&&&&&&&&&&&          @",
	"@                @@@              @@              @@@                @",
	"@                @@@              @@              @@@                @",
	"@@@   @@@#####   ############            ############   #####@@@   @@@",
	"@@@   @@@#####   ######@@######        ######@@######   #####@@@   @@@",
	"@@@   @@@#####   ######@@@#####        #####@@@######   #####@@@   @@@",
	"@                   ###@@@@@###@@    @@###@@@@@###                   @",
	"@                     #########@@@@@@@@#########                     @",
	"@                           ##############                           @",
	"@   ##   ##                    ########                    ##   ##   @",
	"@   #######                                                #######   @",
	"@   #######   @@@######                        ######@@@   #######   @",
	"@   ##   ##   @@@######                        ######@@@   ##   ##   @",
	"@                        2   ############ 1                          @",
	"@                            ##B       ##                            @",
	"@                            ##        ##                            @",
	"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
};

const unsigned char	ladrilloParedImagen = 177;
const ColorConsola ladrilloParedColorSimbolo = ColorConsola_Cafe;
const ColorConsola ladrilloParedColorFondo = ColorConsola_Rojo;

const unsigned char	metalParedImagen = 254;
const ColorConsola metalParedColorSimbolo = ColorConsola_Gris;
const ColorConsola metalParedColorFondo = ColorConsola_GrisOscuro;

const unsigned char	arbustoImagen = 176;
const ColorConsola arbustoColorColorSimbolo = ColorConsola_Verde;
const ColorConsola arbustoColorFondo = ColorConsola_VerdeOscuro;


// Tanques
const float fuegoTiempoEnfriamientoTanque = 0.5;
const int tamanoTanque = 3;

enum ColorTanque
{
	ColorTanque_0,
	ColorTanque_1,
	ColorTanque_2
};

struct CeldaImagenTanque
{
	unsigned char simbolo;
	ColorTanque colorSimbolo;
	ColorTanque colorFondo;
};

const CeldaImagenTanque imagenTanqueNivel[Direccion_MAX][tamanoTanque][tamanoTanque] =
{
	// Izquierda
	{
		{ {220, ColorTanque_1, ColorTanque_0}, {220, ColorTanque_1, ColorTanque_0}, {220, ColorTanque_1, ColorTanque_0} },
		{ {196, ColorTanque_2, ColorTanque_0}, {  4, ColorTanque_2, ColorTanque_1}, {221, ColorTanque_1, ColorTanque_0} },
		{ {223, ColorTanque_1, ColorTanque_0}, {223, ColorTanque_1, ColorTanque_0}, {223, ColorTanque_1, ColorTanque_0} }
	},
	// Arriba
	{
		{ {220, ColorTanque_1, ColorTanque_0}, {179, ColorTanque_2, ColorTanque_0}, {220, ColorTanque_1, ColorTanque_0} },
		{ {219, ColorTanque_1, ColorTanque_1}, {  4, ColorTanque_2, ColorTanque_1}, {219, ColorTanque_1, ColorTanque_1} },
		{ {223, ColorTanque_1, ColorTanque_0}, {  0, ColorTanque_0, ColorTanque_0}, {223, ColorTanque_1, ColorTanque_0} }
	},
	// Derecha
	{
		{ {220, ColorTanque_1, ColorTanque_0}, {220, ColorTanque_1, ColorTanque_0}, {220, ColorTanque_1, ColorTanque_0} },
		{ {222, ColorTanque_1, ColorTanque_0}, {  4, ColorTanque_2, ColorTanque_1}, {196, ColorTanque_2, ColorTanque_0} },
		{ {223, ColorTanque_1, ColorTanque_0}, {223, ColorTanque_1, ColorTanque_0}, {223, ColorTanque_1, ColorTanque_0} }
	},
	// Abajo
	{
		{ {220, ColorTanque_1, ColorTanque_0}, {  0, ColorTanque_0, ColorTanque_0}, {220, ColorTanque_1, ColorTanque_0} },
		{ {219, ColorTanque_1, ColorTanque_1}, {  4, ColorTanque_2, ColorTanque_1}, {219, ColorTanque_1, ColorTanque_1} },
		{ {223, ColorTanque_1, ColorTanque_0}, {179, ColorTanque_2, ColorTanque_0}, {223, ColorTanque_1, ColorTanque_0} }
	}
};


/////////////////////////////////////
// Datos jugador
const int energiaJugador = 16;
const int velocidadJugador = 10;


/////////////////////////////////////
// Datos enemigos
const int enemigosPorNivel = 24;
const int enemigosPorNivelEnUnMomento = 6;
const int energiaEnemigo = 5;
const int velocidadEnemigo = 5;
const float generadorEnemigosTiempoGeneracion = 10.0;
const float tiempoAnalisisIAEnemiga = 0.5;


/////////////////////////////////////
// Datos base
const int columnasBase = 8;
const int filasBase = 2;
const int energiaBase = 3;

const ColorConsola bc0 = ColorConsola_Negro;
const ColorConsola bc1 = ColorConsola_Gris;
const ColorConsola bc2 = ColorConsola_Rojo;
const ColorConsola bc3 = ColorConsola_RojoOscuro;

const DatosSimboloConsola imagenBaseNormal[filasBase][columnasBase] =
{
	{ { 17, bc2, bc0}, {221, bc1, bc0}, {254, bc0, bc3}, {254, bc0, bc3}, {254, bc0, bc3}, {254, bc0, bc3}, {222, bc1, bc0}, { 16, bc2, bc0} },
	{ {  0, bc0, bc0}, {221, bc1, bc0}, {254, bc0, bc3}, {176, bc0, bc1}, {176, bc0, bc1}, {254, bc0, bc3}, {222, bc1, bc0}, {  0, bc0, bc0} }
};

const DatosSimboloConsola imagenBaseDanada[filasBase][columnasBase] =
{
	{ {  0, bc0, bc0}, {  0, bc0, bc0}, {254, bc0, bc3}, {254, bc0, bc3}, {  0, bc0, bc0}, {254, bc0, bc3}, {222, bc1, bc0}, { 16, bc2, bc0} },
	{ {  0, bc0, bc0}, {221, bc1, bc0}, {254, bc0, bc3}, {176, bc1, bc0}, {176, bc1, bc0}, {254, bc0, bc3}, {222, bc1, bc0}, {  0, bc0, bc0} }
};

const DatosSimboloConsola imagenBaseDestruida[filasBase][columnasBase] =
{
	{ {  0, bc0, bc0}, {  0, bc0, bc0}, {  0, bc0, bc0}, {254, bc0, bc3}, {'_', bc3, bc0}, {254, bc0, bc3}, {  0, bc0, bc0}, {  0, bc0, bc0} },
	{ {  0, bc0, bc0}, {  0, bc0, bc0}, {254, bc0, bc3}, {  0, bc0, bc0}, {'/', bc1, bc0}, {254, bc0, bc3}, {222, bc1, bc0}, {  0, bc0, bc0} }
};


/////////////////////////////////////
// Datos bala
const float velocidadBala = 30.0;
const char imagenBala = '*';



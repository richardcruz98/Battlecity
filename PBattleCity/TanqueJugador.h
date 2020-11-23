#pragma once
#include "Tanque.h"
class TanqueJugador :
    public Tanque
{
public:
    TanqueJugador();
    void actualizar(float _dt);
    void setTeclas(int _teclaIzquierda, int _teclaDerecha, int _teclaArriba, int _teclaAbajo, int _teclaDisparo);
protected:
    int teclaIzquierda;
    int teclaDerecha;
    int teclaArriba;
    int teclaAbajo;
    int teclaDisparo;
};


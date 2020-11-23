#pragma once
#include "Actor.h"
class Arbusto :
    public Actor
{
private:
    DatosSimboloConsola imagenArbusto;
public:
    Arbusto();
    virtual void renderizar(SistemaRenderizacion* _sistemaRenderizacion);
    void setImagenArbusto(unsigned char _simbolo, ColorConsola _colorImagen, ColorConsola _colorFondo);
};


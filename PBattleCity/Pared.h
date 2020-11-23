#pragma once
#include "Actor.h"
class Pared :
    public Actor
{
private:
    DatosSimboloConsola imagenPared;
public:
    Pared();
    virtual void renderizar(SistemaRenderizacion* _sistemaRenderizacion);
    void setImagenPared(unsigned char _simbolo, ColorConsola _colorImagen, ColorConsola _colorFondo);
};


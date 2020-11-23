#pragma once
#include "Actor.h"

enum Direccion;

enum EstadoMunicion{
    Inactivo,
    Activado,
    EnCurso,
    Impactado
};

class Municion :
    public Actor
{
protected:
    Direccion direccion;
    EstadoMunicion estado;
    string avatarExplosion;
    int alcance;
public:
    //Municion(int _x, int _y, string _avatar, int _ancho, int _alto, int _dx, int _dy, int _velocidad, Direccion _direccion, EstadoMunicion _estado, string _avatarExplosion, int _alcance) :Actor(_x, _y, _avatar, _ancho, _alto, _dx, _dy, _velocidad), direccion(_direccion), estado(_estado), avatarExplosion(_avatarExplosion), alcance(_alcance) {};
    Municion();
    Direccion getDireccion() { return direccion; }
    EstadoMunicion getEstado() { return estado; }
    string getAvatarExplosion() { return avatarExplosion; }

    void setDireccion(Direccion _direccion) { direccion = _direccion; }
    void setEstado(EstadoMunicion _estado) { estado = _estado; }
    void setAvatarExplosion(string _avatarExplosion) { avatarExplosion = _avatarExplosion; }

    virtual void Mostrar() = 0;
    virtual void Mover() = 0;
    virtual void Impactar() = 0;
    virtual void CambiarDireccion() = 0;
};


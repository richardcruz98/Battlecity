#pragma once
#include <string>
using namespace std;


class MuroLadrillo
{
private:
	int x;
	int y;
	int ancho;
	int alto;
	string avatar;
public:
	void setX(int _x) { x = _x; }
	void setY(int _y) { y = _y; }
	void setAncho(int _ancho) { ancho = _ancho; }
	void setAlto(int _alto) { alto = _alto; }
	string getAvatar() { return avatar; }
	void setAvatar(string _avatar) { avatar = _avatar; }
	void Mostrar();
};


#include "Bala.h"

//void Bala::Mostrar()
//{
//	gotoxy(getX(), getY());
//	cout << getAvatar() << endl;
//}
//
//void Bala::Mover()
//{
//	if (recorrido < alcance && estado == EstadoMunicion::EnCurso){
//		gotoxy(getX(), getY());
//		cout << " " << endl;
//		setX(getX() + getDx());
//		setY(getY() + getDy());
//		Mostrar();
//		recorrido++;
//	}
//	else {
//		//Impactar();
//		estado = EstadoMunicion::Impactado;
//	}
//}
//
//void Bala::Impactar()
//{
//	gotoxy(getX(), getY());
//	cout << getAvatarExplosion() << endl;
//}
//
//void Bala::Disparar()
//{
//	recorrido = 0;
//	estado = EstadoMunicion::EnCurso;
//}
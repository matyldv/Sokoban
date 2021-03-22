#include "stdafx.h"
#include "Pole.h"
#include <SFML/Graphics.hpp>


Pole::Pole()
{
	isMoving = false;
	isEmpty = true;
	id = 0;
	plik = "img/pole.png";
}


Pole::~Pole()
{
}

void Pole::rysuj(RenderWindow& window, int pozX, int pozY) 
{
	t.loadFromFile(plik);
	Sprite shape(t);
	t.setSmooth(true);
	shape.setPosition(pozX, pozY);
	window.draw(shape);
}

bool Pole::getIsEmpty()
{
	return isEmpty;
}

bool Pole::getIsMoving()
{
	return isMoving;
}

bool Pole::getCel()
{
	return cel;
}
int Pole::getPozX()
{
	return pozX;
}
int Pole::getPozY()
{
	return pozY;
}

int Pole::getId()
{
	return id;
}


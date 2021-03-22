#include "stdafx.h"
#include "Sciana.h"


Sciana::Sciana()
{
	isMoving = false;
	id = 1;
	isEmpty = false;
	plik = "img/wall.png";
}


Sciana::~Sciana()
{
}

int Sciana::getId()
{
	return 1;
}
#include "stdafx.h"
#include "Cel.h"


Cel::Cel()
{
	isMoving = false;
	isEmpty = true;
	cel = true;
	id = 3;
	plik = "img/cel.png";
}


Cel::~Cel()
{
}

int Cel::getId()
{
	return 3;
}
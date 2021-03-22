#include "stdafx.h"
#include "Box.h"


Box::Box()
{
	isMoving = true;
	isEmpty = false;
	id = 2;
	plik = "img/box.png";
}

int Box::getId()
{
	return 2;
}

Box::~Box()
{
}

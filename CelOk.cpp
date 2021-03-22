#include "stdafx.h"
#include "CelOk.h"


CelOk::CelOk()
{
	isMoving = true;
	isEmpty = false;
	cel = true;
	id = 4;
	plik = "img/celok.png";
}

int CelOk::getId()
{
	return 4;
}


CelOk::~CelOk()
{
}

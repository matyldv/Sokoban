#include "stdafx.h"
#include "Gracz.h"
#include "CelOk.h"
#include "Pole.h"
#include "Box.h"
#include "Cel.h"
#include <iostream>

using namespace std;

Gracz::Gracz()
{
	isMoving = true;
	isEmpty = false;
	id = 8;
	plik = "img/player.png";
}

int Gracz::getId()
{
	return 8;
}

void Gracz::setPosition(int x, int y)
{
	pozX = x;
	pozY = y;
}


void Gracz::move(vector<vector<Pole*> > &mapa, Gracz &gracz, int &ruchy, int &cele)
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Left))
	{
		//sciana
		if ((mapa[pozY][pozX - 1]->getIsEmpty() == false) && (mapa[pozY][pozX - 1]->getIsMoving() == false)) return;
		//sciana
		if ((mapa[pozY][pozX - 1]->getIsEmpty() == false) && (mapa[pozY][pozX - 2]->getIsEmpty() == false)) return;
		//puste pole
		if (mapa[pozY][pozX - 1]->getIsEmpty() == true)
		{
			gracz.setPosition(gracz.pozX - 1, gracz.pozY);
			ruchy++;
			//cout << "Ruchy: " << ruchy << " Cele: " << cele << endl;
			return;
		}

		//skrzynka przesuwana z celu na cel
		if ((mapa[pozY][pozX - 1]->getIsMoving() == true) && (mapa[pozY][pozX - 2]->getIsEmpty() == true) && (mapa[pozY][pozX - 1]->getCel() == true) && (mapa[pozY][pozX - 2]->getCel() == true))
		{
			swap(mapa[pozY][pozX - 2], mapa[pozY][pozX - 1]);
			gracz.setPosition(gracz.pozX - 1, gracz.pozY);

			ruchy++;
			//cout << "Ruchy: " << ruchy << " Cele: " << cele << endl;
			return;
		}

		//skrzynka przesuwana z celu
		if ((mapa[pozY][pozX - 1]->getIsMoving() == true) && (mapa[pozY][pozX - 2]->getIsEmpty() == true) && (mapa[pozY][pozX - 1]->getCel() == true))
		{
			mapa[pozY][pozX - 1] = new Cel;
			mapa[pozY][pozX - 2] = new Box;
			gracz.setPosition(gracz.pozX - 1, gracz.pozY);

			ruchy++;
			cele++;
			//cout << "Ruchy: " << ruchy << " Cele: " << cele << endl;
			return;
		}


		//skrzynka mozliwa do przesuniecia na cel
		if ((mapa[pozY][pozX - 1]->getIsMoving() == true) && (mapa[pozY][pozX - 2]->getCel() == true))
		{

			mapa[pozY][pozX - 2] = new CelOk;
			mapa[pozY][pozX - 1] = new Pole;
			gracz.setPosition(gracz.pozX - 1, gracz.pozY);

			ruchy++;
			cele--;
			//cout << "Ruchy: " << ruchy << " Cele: " << cele << endl;
			return;
		}

		//skrzynka mozliwa do przesuniecia
		if ((mapa[pozY][pozX - 1]->getIsMoving() == true) && (mapa[pozY][pozX - 2]->getIsEmpty() == true))
		{
			swap(mapa[pozY][pozX - 1], mapa[pozY][pozX - 2]);
			gracz.setPosition(gracz.pozX - 1, gracz.pozY);

			ruchy++;
			//cout << "Ruchy: " << ruchy << " Cele: " << cele << endl;
			return;
		}

	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Right))
	{
		//sciana
		if ((mapa[pozY][pozX + 1]->getIsEmpty() == false) && (mapa[pozY][pozX + 1]->getIsMoving() == false)) return;

		if ((mapa[pozY][pozX + 1]->getIsEmpty() == false) && (mapa[pozY][pozX + 2]->getIsEmpty() == false)) return;
		//puste pole
		if (mapa[pozY][pozX + 1]->getIsEmpty() == true)
		{
			gracz.setPosition(gracz.pozX + 1, gracz.pozY);

			ruchy++;
			//cout << "Ruchy: " << ruchy << " Cele: " << cele << endl;
			return;
		}

		//skrzynka przesuwana z celu na cel
		if ((mapa[pozY][pozX + 1]->getIsMoving() == true) && (mapa[pozY][pozX + 2]->getIsEmpty() == true) && (mapa[pozY][pozX + 1]->getCel() == true) && (mapa[pozY][pozX + 2]->getCel() == true))
		{
			swap(mapa[pozY][pozX + 2], mapa[pozY][pozX + 1]);
			gracz.setPosition(gracz.pozX + 1, gracz.pozY);

			ruchy++;
			//cout << "Ruchy: " << ruchy << " Cele: " << cele << endl;
			return;
		}

		//skrzynka przesuwana z celu
		if ((mapa[pozY][pozX + 1]->getIsMoving() == true) && (mapa[pozY][pozX + 2]->getIsEmpty() == true) && (mapa[pozY][pozX + 1]->getCel() == true))
		{
			mapa[pozY][pozX + 1] = new Cel;
			mapa[pozY][pozX + 2] = new Box;
			gracz.setPosition(gracz.pozX + 1, gracz.pozY);

			ruchy++;
			cele++;
			//cout << "Ruchy: " << ruchy << " Cele: " << cele << endl;
			return;
		}
		//skrzynka mozliwa do przesuniecia na cel
		if ((mapa[pozY][pozX + 1]->getIsMoving() == true) && (mapa[pozY][pozX + 2]->getCel() == true))
		{

			mapa[pozY][pozX + 2] = new CelOk;
			mapa[pozY][pozX + 1] = new Pole;
			gracz.setPosition(gracz.pozX + 1, gracz.pozY);

			ruchy++;
			cele--;
			//cout << "Ruchy: " << ruchy << " Cele: " << cele << endl;
			return;
		}

		//skrzynka mozliwa do przesuniecia
		if ((mapa[pozY][pozX + 1]->getIsMoving() == true) && (mapa[pozY][pozX + 2]->getIsEmpty() == true))
		{
			swap(mapa[pozY][pozX + 1], mapa[pozY][pozX + 2]);
			gracz.setPosition(gracz.pozX + 1, gracz.pozY);

			ruchy++;
			//cout << "Ruchy: " << ruchy << " Cele: " << cele << endl;
			return;
		}

	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Up))
	{
		//sciana
		if ((mapa[pozY - 1][pozX]->getIsEmpty() == false) && (mapa[pozY - 1][pozX]->getIsMoving() == false)) return;
		if ((mapa[pozY - 1][pozX]->getIsEmpty() == false) && (mapa[pozY - 2][pozX]->getIsEmpty() == false)) return;
		//puste pole
		if (mapa[pozY - 1][pozX]->getIsEmpty() == true)
		{
			gracz.setPosition(gracz.pozX, gracz.pozY - 1);
			ruchy++;
			//cout << "Ruchy: " << ruchy << " Cele: " << cele << endl;
			return;
		}

		//skrzynka przesuwana z celu na cel
		if ((mapa[pozY - 1][pozX]->getIsMoving() == true) && (mapa[pozY - 2][pozX]->getIsEmpty() == true) && (mapa[pozY - 1][pozX]->getCel() == true) && (mapa[pozY - 2][pozX]->getCel() == true))
		{
			swap(mapa[pozY - 2][pozX], mapa[pozY - 1][pozX]);
			gracz.setPosition(gracz.pozX, gracz.pozY - 1);

			ruchy++;
			//cout << "Ruchy: " << ruchy << " Cele: " << cele << endl;
			return;
		}

		//skrzynka przesuwana z celu
		if ((mapa[pozY - 1][pozX]->getIsMoving() == true) && (mapa[pozY - 2][pozX]->getIsEmpty() == true) && (mapa[pozY - 1][pozX]->getCel() == true))
		{
			mapa[pozY - 1][pozX] = new Cel;
			mapa[pozY - 2][pozX] = new Box;
			gracz.setPosition(gracz.pozX, gracz.pozY - 1);

			ruchy++;
			cele++;
			//cout << "Ruchy: " << ruchy << " Cele: " << cele << endl;
			return;
		}


		//skrzynka mozliwa do przesuniecia na cel
		if ((mapa[pozY - 1][pozX]->getIsMoving() == true) && (mapa[pozY - 2][pozX]->getCel() == true))
		{

			mapa[pozY - 2][pozX] = new CelOk;
			mapa[pozY - 1][pozX] = new Pole;
			gracz.setPosition(gracz.pozX, gracz.pozY - 1);

			ruchy++;
			cele--;
			//cout << "Ruchy: " << ruchy << " Cele: " << cele << endl;
			return;
		}

		//skrzynka mozliwa do przesuniecia
		if ((mapa[pozY - 1][pozX]->getIsMoving() == true) && (mapa[pozY - 2][pozX]->getIsEmpty() == true))
		{
			swap(mapa[pozY - 1][pozX], mapa[pozY - 2][pozX]);
			gracz.setPosition(gracz.pozX, gracz.pozY - 1);

			ruchy++;
			//cout << "Ruchy: " << ruchy << " Cele: " << cele << endl;
			return;
		}

	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Down))
	{
		//sciana
		if ((mapa[pozY + 1][pozX]->getIsEmpty() == false) && (mapa[pozY + 1][pozX]->getIsMoving() == false)) return;
		if ((mapa[pozY + 1][pozX]->getIsEmpty() == false) && (mapa[pozY + 2][pozX]->getIsEmpty() == false)) return;

		//puste pole
		if (mapa[pozY + 1][pozX]->getIsEmpty() == true)
		{
			gracz.setPosition(gracz.pozX, gracz.pozY + 1);
			ruchy++;
			//cout << "Ruchy: " << ruchy << " Cele: " << cele << endl;
			return;
		}

		//skrzynka przesuwana z celu na cel
		if ((mapa[pozY + 1][pozX]->getIsMoving() == true) && (mapa[pozY + 2][pozX]->getIsEmpty() == true) && (mapa[pozY + 1][pozX]->getCel() == true) && (mapa[pozY + 2][pozX]->getCel() == true))
		{
			swap(mapa[pozY + 2][pozX], mapa[pozY + 1][pozX]);
			gracz.setPosition(gracz.pozX, gracz.pozY + 1);

			ruchy++;
			//cout << "Ruchy: " << ruchy << " Cele: " << cele << endl;
			return;
		}

		//skrzynka przesuwana z celu
		if ((mapa[pozY + 1][pozX]->getIsMoving() == true) && (mapa[pozY + 2][pozX]->getIsEmpty() == true) && (mapa[pozY + 1][pozX]->getCel() == true))
		{
			mapa[pozY + 1][pozX] = new Cel;
			mapa[pozY + 2][pozX] = new Box;
			gracz.setPosition(gracz.pozX, gracz.pozY + 1);

			ruchy++;
			cele++;
			//cout << "Ruchy: " << ruchy << " Cele: " << cele << endl;
			return;
		}


		//skrzynka mozliwa do przesuniecia na cel
		if ((mapa[pozY + 1][pozX]->getIsMoving() == true) && (mapa[pozY + 2][pozX]->getCel() == true))
		{

			mapa[pozY + 2][pozX] = new CelOk;
			mapa[pozY + 1][pozX] = new Pole;
			gracz.setPosition(gracz.pozX, gracz.pozY + 1);

			ruchy++;
			cele--;
			//cout << "Ruchy: " << ruchy << " Cele: " << cele << endl;
			return;
		}

		//skrzynka mozliwa do przesuniecia
		if ((mapa[pozY + 1][pozX]->getIsMoving() == true) && (mapa[pozY + 2][pozX]->getIsEmpty() == true))
		{
			swap(mapa[pozY + 1][pozX], mapa[pozY + 2][pozX]);
			gracz.setPosition(gracz.pozX, gracz.pozY + 1);

			ruchy++;
			//cout << "Ruchy: " << ruchy << " Cele: " << cele << endl;
			return;
		}

	}


}
Gracz::~Gracz()
{
}

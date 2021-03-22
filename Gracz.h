#pragma once
#include "Pole.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;


class Gracz: public Pole
{
public:
	///
	/// \brief Metoda zwracajaca atrybut id
	int getId();
	///
	/// \brief Konstruktor obiektu Gracz
	Gracz();
	///
	/// \brief Destruktor obiektu, nie jest uzywany, ale zostal stworzony dla ewentualnych zmian w kodzie
	~Gracz();
	///
	/// \brief Funkcja odpowiedzialna za poruszanie graczem
	void move(vector<vector<Pole*> > &mapa, Gracz &gracz, int &ruchy, int &cele);
	///
	/// \brief Funkcja pozwalajaca ustawic pozycje gracza
	void setPosition(int x, int y);
};


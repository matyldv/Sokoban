#pragma once

#include "Pole.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Sciana : public Pole
{
public:
	///
	/// \brief Metoda zwracajaca atrybut id
	int getId();
	///
	/// \brief Konstruktor obiektu Sciana
	Sciana();
	///
	/// \brief Destruktor obiektu, nie jest uzywany, ale zostal stworzony dla ewentualnych zmian w kodzie
	~Sciana();
};


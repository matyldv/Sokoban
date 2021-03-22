#pragma once
#include "Pole.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Box : public Pole
{
public:
	int getId();

	///
	/// \brief Konstruktor obiektu Box
	Box();
	///
	/// \brief Destruktor obiektu, nie jest uzywany, ale zostal stworzony dla ewentualnych zmian w kodzie
	~Box();
};


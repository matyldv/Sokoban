#pragma once
#include "Pole.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class CelOk : public Pole
{
public:
	///
	/// \brief Metoda zwracajaca atrybut id
	int getId();
	///
	/// \brief Konstruktor obiektu CelOk
	CelOk();
	///
	/// \brief Destruktor obiektu, nie jest uzywany, ale zostal stworzony dla ewentualnych zmian w kodzie
	~CelOk();
};


#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
class Pole
{

protected:
	///
	/// Textura potrzebna do tworzenia grafiki
	Texture t;
	///
	/// \brief Atrybut okreslajacy, czy obiekt moze zostac przesuniety.
	bool isMoving;
	///
	/// \brief Atrybut okreslajacy, czy obiekt jest pusty, czyli czy mozna na niego stanac lub cos przesunac.
	bool isEmpty;
	///
 	/// \brief Atrybut okreslajacy, czy obiekt jest celem, na ktorym maja stac skrzynki.
	bool cel=false;
	///
	/// \brief Atrybut okreslajacy pozycje X obiektu.
	int pozX;
	///
	/// \brief Atrybut okreslajacy pozycje Y obiektu.
	int pozY;
	///
	/// \brief Atrybut okreslajacy nazwe pliku z obrazkiem.
	string plik;
	///
	/// \brief Id okresla rodzaj obiektu, atrybut potrzebny do zapisu do pliku.
	int id;

public:
	///
	/// \brief Metoda do rysowania obiektow
	void rysuj(RenderWindow& window, int pozX, int pozY);
	///
	/// \brief Metoda zwracajaca atrybut isMoving
	bool getIsMoving();
	///
	/// \brief Metoda zwracajaca atrybut isEmpty
	bool getIsEmpty();
	///
	/// \brief Metoda zwracajaca atrybut cel
	bool getCel();
	///
	/// \brief Metoda zwracajaca atrybut pozX
	int getPozX();
	///
	/// \brief Metoda zwracajaca atrybut pozY
	int getPozY();
	///
	/// \brief Metoda wirtualna zwracajaca atrybut id
	int virtual getId();
	///
	/// \brief Konstruktor obiektu Pole
	Pole();
	///
	/// \brief Destruktor obiektu, nie jest uzywany, ale zostal stworzony dla ewentualnych zmian w kodzie
	~Pole();
};


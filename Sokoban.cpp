// sokoban.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Box.h"
#include "Cel.h"
#include "CelOk.h"
#include "Gracz.h"
#include "Pole.h"
#include "Sciana.h"
#include <vector>
#include <fstream>
#include <sstream>  

using namespace sf;
using namespace std;

void start(vector<vector<Pole*> > &mapa, int** board, int wierszy, int kolumn, int &cele, Gracz &gracz)
{
	cele = 0;
	for (int i = 0; i < wierszy; i++)
		for (int j = 0; j < kolumn; j++)
		{
			switch (board[i][j])
			{
			case 0:
				mapa[i][j] = new Pole;
				break;

			case 1:
				mapa[i][j] = new Sciana;
				break;

			case 2:
				mapa[i][j] = new Box;
				break;

			case 3:
				mapa[i][j] = new Cel;
				cele++;
				break;

			case 4:
				mapa[i][j] = new CelOk;
				break;

			case 8:
				mapa[i][j] = new Pole;
				
				gracz.setPosition(j, i);
				break;
			}
		}
}




int main()
{
	
		RenderWindow window(VideoMode(1000, 640), "Sokoban"); //x1000
		window.setFramerateLimit(60);
		window.clear(Color::Black);
		Event event;
		Text napis;
		Font font;
		font.loadFromFile("arial.ttf");
		napis.setFont(font);

		napis.setFillColor(Color::White);

		napis.setCharacterSize(32);
		napis.setString("Wybierz pozion:\n1 - poziom 1\n2 - poziom 2\n3 - wczytaj");
		napis.setPosition(250, 250);

		window.draw(napis);

		window.display();
		string poziom = "level";

		while (true)
		{
			window.pollEvent(event);
			if (event.type == Event::Closed)
				window.close();
			if (Keyboard::isKeyPressed(Keyboard::Key::Num1)) poziom += "1";
			else if (Keyboard::isKeyPressed(Keyboard::Key::Num2)) poziom += "2";
			else if (Keyboard::isKeyPressed(Keyboard::Key::Num3)) poziom += "3";

			if (poziom != "level") break;
		}
	
	int ruchy, cele;
	fstream plik;
	int wierszy, kolumn;
	try 
	{
		plik.open(poziom+".txt", ios::in);
		if (plik.fail())
		{
			throw exception();
		}
	}

	catch(...)
	{
		cout << "Blad odczytu danych z pliku!" << endl;
		window.close();
		system("pause");
		return 0;
	}
	
	plik >> wierszy >> kolumn;
	int** board = new int*[wierszy];
	for (int i = 0; i < wierszy; i++)
		board[i] = new int[kolumn];

	for (int i = 0; i < wierszy; i++)
		for (int j = 0; j < kolumn; j++)
		{
			plik >> board[i][j];
		}

	if(!plik.eof()) plik >> ruchy;
	else ruchy = 0;
	int ruchy_start = ruchy;
	
	plik.close();
	vector<vector<Pole*> > mapa(wierszy, vector<Pole*>(kolumn));

	
	Gracz gracz;
	start(mapa, board, wierszy, kolumn, cele, gracz);
	

	Text tekst;
	tekst.setFont(font);

	tekst.setFillColor(Color::White);

	tekst.setCharacterSize(32);
	tekst.setString("Sokoban");
	tekst.setPosition(640 + 180 - (tekst.getLocalBounds().width) / 2, 25);

	Text tekst1 =  tekst;
	Text reset = tekst;
	Text save = tekst;
	
	tekst1.setPosition(700, 100);
	reset.setPosition(700, 550);
	reset.setString("R - reset");
	save.setPosition(700, 500);
	save.setString("S - zapis");

//	Event event;
	int x = 0;
	int y = 0;

	while (window.isOpen())
	{

		window.clear(Color::Black);
		window.pollEvent(event);

		window.draw(tekst);


		if (event.type == Event::Closed)
			window.close();
		if (Keyboard::isKeyPressed(Keyboard::Key::R))
		{
			ruchy = ruchy_start;
			start(mapa, board, wierszy, kolumn, cele, gracz);
			continue;
		}

		if (Keyboard::isKeyPressed(Keyboard::Key::S))
		{
			fstream zapis;
			zapis.open("level3.txt", ios::out);
			zapis << wierszy << " " << kolumn << endl;
			
			

			for (int i = 0; i < wierszy; i++)
			{
				for (int j = 0; j < kolumn; j++)
				{
					if(j == gracz.getPozX() && i == gracz.getPozY())
						zapis << gracz.getId() << " ";
					else
						zapis << mapa[i][j]->getId() << " ";


				}
				zapis << endl;
			}
			
			zapis << ruchy;



		}

		if (cele>0)
		{
			gracz.move(mapa, gracz, ruchy, cele);
			while (Keyboard::isKeyPressed(Keyboard::Key::Left) || Keyboard::isKeyPressed(Keyboard::Key::Right) || Keyboard::isKeyPressed(Keyboard::Key::Up) || Keyboard::isKeyPressed(Keyboard::Key::Down)) {}
			for (int i = 0; i<wierszy; i++)
				for (int j = 0; j < kolumn; j++)
				{
					mapa[i][j]->rysuj(window, j * 64, i * 64);

				}

			gracz.rysuj(window, gracz.getPozX() * 64, gracz.getPozY() * 64);

			

			ostringstream ss;
			ss << "Ruchy: " << ruchy << endl << "Skrzynie : " << cele;
			tekst1.setString(ss.str());
			window.draw(tekst1);
			window.draw(reset);
			window.draw(save);

			window.display();
		}
	}
	return 0;
}

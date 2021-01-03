#include "stdafx.h"
#include <iostream>
#include <SFML\Graphics.hpp>
//#include "menu.h"
#include "Header.h"
using namespace std;
using namespace sf;

Header::Header(float width, float height)
{
	if (!font.loadFromFile("arial.ttf")) // load text
	{
		cout << " Cannot load font \n";
	}
	else

	text[0].setFont(font);
	text[0].setString("Play");
	text[0].setPosition(Vector2f(width / 2.2, height / 4 * 1));
	text[0].setFillColor(Color::Green);
	text[0].setCharacterSize(40);


	text[1].setFont(font);
	text[1].setFillColor(Color::Red);
	text[1].setString("Options");
	text[1].setPosition(Vector2f(width / 2.3, height / 4 * 2));
	text[1].setCharacterSize(40);

	text[2].setFont(font);
	text[2].setPosition(Vector2f(width / 2.2, height / 4 * 3));
	text[2].setFillColor(Color::Cyan);
	text[2].setString("Quit");
	text[2].setCharacterSize(40);
}

void Header::drawmenu(RenderWindow &window)
{
	for (int i = 0; i < MAX; i++)
	{
		window.draw(text[i]); //Draw the text from first to last index

	}
	
}
void Header::moveup()
{
	if (selected -1> 0)
		text[selected].setFillColor(Color::Red);
	selected--;
	text[selected].setFillColor(Color::Red);
	
}
void Header::movedown()
{
	if (selected + 1 <  3)
		text[selected].setFillColor(Color::White);
	selected++;
	text[selected].setFillColor(Color::Red);


}




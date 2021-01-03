#include "stdafx.h"
#include "menu.h"
#include "SFML\Graphics.hpp"
#include <iostream>
using namespace std;
using namespace sf;


int main()
{

	RenderWindow window(VideoMode(800, 800), "Maze Game");

	menu Menu(window.getSize().x, window.getSize().y);

	Texture image;
	Sprite imagee;
	image.loadFromFile("wallpaper.jpg");
	imagee.setTexture(image);

	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == event.Closed)
				window.close();




		}



		window.clear();
		window.draw(imagee);
		Menu.draw(window);
		window.display();

	}

}


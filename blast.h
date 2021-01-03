#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>

using namespace sf;
using namespace std;


class blast
{
public:
	blast();

	Sprite blastsprite;
	Texture blasttexture;

	void draw(RenderWindow &window);
	RectangleShape rectangle;
	void update();
	int direction;

};


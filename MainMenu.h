#pragma once
#include "SFML\Graphics.hpp"
using namespace sf;

class MainMenu
{
public:
	MainMenu();
	bool removescreen = true;
	Sprite menusprite;
	Texture menutexture;
	void update();
	void draw(RenderWindow& window);

};


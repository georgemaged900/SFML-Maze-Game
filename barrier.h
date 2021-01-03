#pragma once
#include "SFML\Graphics.hpp"
using namespace sf;

class barrier
{
public:
	barrier();
	RectangleShape rect;
	Sprite wallsprite;
		Texture walltexture;

		Sprite wallspritearray[20][20];
		Texture walltexturearray[20][20];
};


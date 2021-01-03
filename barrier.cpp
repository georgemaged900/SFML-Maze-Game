#include "stdafx.h"
#include "barrier.h"


barrier::barrier()
{

	rect.setFillColor(Color::Black);
	rect.setPosition(10, 10);
	rect.setSize(Vector2f(30,30));

	walltexture.loadFromFile("newwall.png");
	wallsprite.setTexture(walltexture);
	//wallsprite.setPosition(40, 40);


	
}




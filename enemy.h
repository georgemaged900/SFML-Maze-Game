#include "stdafx.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>


using namespace sf;
using namespace std;



class enemy
{

private:

	Texture enemytexture;
	int counterwalking = 0;
	int enemymovementspeed = 0;
	int movementlength = 50;
	int movementspeed = 1;


public:
	enemy();
	void updatemovement();
	void drawenemy(RenderWindow& window);
	void enemymovement();
	int counter = 0;
	Sprite enemysprite;
	int direction = 0;
	bool canmoveup = true;
	bool canmovedown = true;
	bool canmoveleft = true;
	bool canmoveright = true;
	bool dead = true;


	
};
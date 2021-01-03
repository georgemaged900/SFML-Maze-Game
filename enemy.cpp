#include "stdafx.h"
#include <SFML\Graphics.hpp>
#include "enemy.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace sf;
using namespace std;

#define width 800
#define height 738



enemy::enemy()
{
	enemysprite.setPosition(400, 400);
	enemymovementspeed = 0.5;

	

	enemytexture.loadFromFile("black.png");
	enemysprite.setTexture(enemytexture);
	enemysprite.setTextureRect(IntRect(0, 0, 50, 56));

	
}

void enemy::drawenemy(RenderWindow& window)
{
	
	window.draw(enemysprite);
}


void enemy::updatemovement()
{
	srand(time(NULL));
	direction = rand() % 4;


	if (direction == 1) // Up
	{
		if (canmoveup == true)
		{

			enemysprite.move(0, -movementspeed);
			enemysprite.setTextureRect(IntRect(1, 0, 50, 56));
			direction = 1;
			canmoveup = true;
			canmovedown = true;
			canmoveleft = true;
			canmoveright = true;
		}
		
	}
	else
		if (direction == 2) // Down
		{
			if (canmovedown == true)
			{

				enemysprite.move(0, movementspeed);
				enemysprite.setTextureRect(IntRect(2*50, 0, 50, 56));
				direction = 2;
				canmoveup = true;
				canmovedown = true;
				canmoveleft = true;
				canmoveright = true;
			}

		}
		else
			if (direction == 3) // Left
			{
				if (canmoveleft == true)
				{
     
					enemysprite.move(-movementspeed, 0);
					enemysprite.setTextureRect(IntRect(0, 1*50, 50, 75));
					canmoveup = true;
					canmovedown = true;
					canmoveleft = true;
					canmoveright = true;

				}
			}
			else
				if (direction == 4) //Right
				{
					if (canmoveright == true)
					{
						enemysprite.move(movementspeed, 0);
						enemysprite.setTextureRect(IntRect(1*50, 2*56, 50, 56));
						canmoveup = true;
						canmovedown = true;
						canmoveleft = true;
						canmoveright = true;
					}
				}
				else
				{
					//no movement
				}
	
	counterwalking++; // for animation 
	counter++; // for movement duration of enemy

	
	if (counter > 400)
	{
		direction = rand() % 5;
		counter = 0;
	}
}
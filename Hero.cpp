//TEST player
#include "stdafx.h"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "Hero.h"
#include "menu.h"
#include "blast.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using namespace sf;


Hero::Hero() 
{

	movementspeed = 0;
	
}
void Hero::initalize(RenderWindow &window , string pic)
{
	

	herosprite.setTextureRect(IntRect(0, 0, 32, 32));
	herotexture.loadFromFile(pic);
	herosprite.setTexture(herotexture);
	//herosprite.setPosition(window.getSize().x / 2, window.getSize().y / 2);
	herosprite.setPosition(60, 60);
	window.setFramerateLimit(100);
	
}
void Hero::draw(RenderWindow &window)
{
	
	window.draw(herosprite);

}
Hero::Hero(float &movementspeed1)
{

	movementspeed = movementspeed1;
	
}

void Hero::set_hero(float &movementspeed1) // setter
{
	movementspeed1 = movementspeed = 1;

}
void Hero::updatemovement() // update player movement
{
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		
		if (canomveup == true)
		{


			herosprite.move(0, -movementspeed);
			herosprite.setTextureRect(IntRect(c * 32, 32 * 3, 32, 32));
			
			direction = 1;

			canmovedown = true;
			canmoveleft = true;
			canomveup = true;
			canmoveright = true;
		}
		
	}
	else
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			if (canmovedown == true)
			{


				herosprite.move(0, movementspeed);
				herosprite.setTextureRect(IntRect(c * 32, 0, 32, 32));
				
			      direction = 2;

				canmovedown = true;
				canmoveleft = true;
				canomveup = true;
				canmoveright = true;
			}
		}
		else
		
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				
				if (canmoveleft == true)
				{


					herosprite.move(-movementspeed, 0);
					herosprite.setTextureRect(IntRect(c * 32, 32 * 1, 32, 32));
					
					direction = 3;

					canmovedown = true;
					canmoveleft = true;
					canomveup = true;
					canmoveright = true;
				}
			}
			else

			if (Keyboard::isKeyPressed(Keyboard::Right))
				{
					
					if (canmoveright == true)
					{

						herosprite.move(movementspeed, 0);
						herosprite.setTextureRect(IntRect(c * 32, 32 * 2, 32, 32));
						direction = 4;

						canmovedown = true;
						canmoveleft = true;
						canomveup = true;
						canmoveright = true;
					}

				}
	c++;  // increment counter for anaimation times the texture rect 

	if (c >= 3) // adjusting the animation speed 
		c = 0; 
}






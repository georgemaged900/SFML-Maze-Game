#include "stdafx.h"
#include <SFML\Graphics.hpp>
#include "menu.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace sf;
using namespace std;



class Hero
{
private:
	
	int c = 0; // initialize speed for animation to 0 at first 
	Texture herotexture;
		
public:
	Hero(); // Default Constructor 
	float  movementspeed = 1; // speed of hero
	bool move = true;
	void initalize(RenderWindow &window , string pic); // pic will contain the name of the hero picture
	Hero(float&);
	void set_hero(float&); // setter for the hero speed
  void updatemovement();
  void draw(RenderWindow &window); // Draw hero
  void music(); 
	bool gamerunning = true;
	bool gamebuttons = true;
    Sprite herosprite;
	int blast_direction;

	bool canomveup = true;
	bool canmovedown = true;
	bool canmoveleft = true;
	bool canmoveright = true;
	int direction;

	

	

};





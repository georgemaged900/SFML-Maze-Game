#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
using namespace sf;

class pickup
{
public:
	pickup();
   Sprite pickupsprite;
	Texture pickuptexture;
	void coin_sound();
	

	void update();
	void pickupresult(RenderWindow&);

  private:

	SoundBuffer buffer;
	Sound sound;
	
};


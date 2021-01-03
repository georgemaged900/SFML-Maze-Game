#include "stdafx.h"
#include "pickup.h"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include <vector>
using namespace sf;

pickup::pickup()
{
	
	pickupsprite.setPosition(0, 0);
	pickupsprite.setColor(Color::Yellow);
	pickupsprite.setTextureRect(IntRect(7, 5, 18, 25));
	
	
	
}
void pickup::coin_sound()
{
	buffer.loadFromFile("coinsound.ogg");
	sound.setBuffer(buffer);
	sound.play();
	
	
}
void pickup::update()
{
	pickupsprite.setPosition(10, 10);
}


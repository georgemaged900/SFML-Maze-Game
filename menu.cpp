#include "stdafx.h"
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML/Audio.hpp>
#include "menu.h"
using namespace std;
using namespace sf;


menu::menu()
{

	 backgroundtex.loadFromFile("menu.png");     // background pic of the main menu
	 backgroundsprite.setTexture(backgroundtex);
   	 backgroundsprite.setPosition(0,0);

    playtexture.loadFromFile("playy.png");
	playsprite.setTexture(playtexture);


	  exittexture.loadFromFile("newexit.png");
	  exitsprite.setTexture(exittexture);
	   exitsprite.setPosition(310, 350);

	 optiontexture.loadFromFile("options.png");
	 optionsprite.setTexture(optiontexture);
	 


	 settingstexture.loadFromFile("menu.png");
	 settingssprite.setTexture(settingstexture);
	 settingssprite.setPosition(0, 0);

	 Soundofftexture.loadFromFile("soundoff.png");
	 Soundoffsprite.setTexture(Soundofftexture);
	 
	 Soundontexture.loadFromFile("soundon.png");
	 Soundonsprite.setTexture(Soundontexture);
	 
	 Backtexture.loadFromFile("Back.png");
	 Backsprite.setTexture(Backtexture);


}
void menu::drawmenu(RenderWindow &window )
{
	
	       
	playsprite .setPosition (window.getSize().x / 2.2 , window.getSize().y /4 *1);
	optionsprite.setPosition(window.getSize().x / 2.3, window.getSize().y / 4 * 2);
	exitsprite.setPosition(window.getSize().x / 2.2, window.getSize().y / 4 * 3);
	 
	Soundoffsprite.setPosition(Vector2f(280 , 290));
	Soundonsprite.setPosition(Vector2f(280, 370));

	Backsprite.setPosition(0, 0);

}

void menu::runmenu(RenderWindow &window)
{


	if (menuplay == true) // check if main menu is running and true
	{
		window.draw(backgroundsprite);
		window.draw(playsprite);
		window.draw(optionsprite);
		window.draw(exitsprite);
	}	
	
}
void menu::playmusic()
{

	music.openFromFile("music.ogg");
	music.play();

	music.setLoop(true); // to loop and keep playing after it finishes
	
}

void menu::soundoff() // Music is off
{
	music.pause();
}
void menu::soundon() // Music is on
{
	music.play();
}
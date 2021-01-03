#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"

using namespace sf;

 
class menu
{

private:

	Music music;
	

public:
	menu();
	
	
	Sprite backgroundsprite;
	Texture backgroundtex;

	Sprite playsprite;
	Texture playtexture;

	Sprite optionsprite;
	Texture optiontexture;

	Sprite exitsprite;
	Texture exittexture;

	Sprite Soundonsprite;
	Texture Soundontexture;

	Sprite Soundoffsprite;
	Texture Soundofftexture;

	Sprite settingssprite;
	Texture settingstexture;

	Sprite Backsprite;
	Texture Backtexture;

	bool active = true;
	
	bool back = true;
	bool playbutton = true; 
	bool optionbutton = true;
	bool exitbutton = true;
	bool menuplay = true;
	bool optionbackground = true;

	
	void runmenu(RenderWindow &window);
	
	void soundon();
	void soundoff();

	void drawmenu(RenderWindow &window);

	void playmusic();

};


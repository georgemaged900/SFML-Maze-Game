#include "stdafx.h"
#include "MainMenu.h"


MainMenu::MainMenu()
{
	menutexture.loadFromFile("maze.png");
	menusprite.setTexture(menutexture);
	

}
void MainMenu::update()
{

}
void MainMenu::draw(RenderWindow &window)
{
	window.draw(menusprite);
}

#include "stdafx.h"
#include "Hero.h"
#include "enemy.h"
#include "menu.h"
#include "pickup.h"
#include "blast.h"
#include "barrier.h"
#include "SFML\Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
using namespace std;
using namespace sf;




int main()
{
	
	
	RenderWindow window(VideoMode(800, 800), "Maze Game");
	
	
	Sprite coinlogosprite;
	Texture coinlogotexture;

	if (!coinlogotexture.loadFromFile("coin logo text.png"));
	{

		cout << " Cannot load coin logo pic \n";
	}

	coinlogosprite.setTexture(coinlogotexture);
	coinlogosprite.setPosition(120,740);
    

	RectangleShape win;    // winning spot 
	win.setPosition(700, 60);
	win.setSize(Vector2f(30, 30));
	Sprite mountiansprite;
	Texture mountaintexture;

	//Background inside game 
	mountaintexture.loadFromFile("ground.jpg");
	mountiansprite.setTexture(mountaintexture);
	


//	bool gamerunning = true;

	//timer
	Clock clock;
	int countdown = 30; // countdown for the level to be 30 seconds
	int timer;

	int p = 0;
	int wallcounter = 0;
	Text Hptext;
	Font Hpfont;
	Hptext.setFont(Hpfont);
    
	int counter = 0; // for pickups 
	pickup Pickup;
	Hero hero;
  
	Texture image;
	Sprite imagee;
	int coinscounter = 0; // for coins 
	Font fontpickup;
	Text textpickup;
	float ms; // speed of hero
	int HPcounter = 100;

	
	barrier wall;
	menu Menu;
//	Menu.music(); // call function music from class Menu

	int cc = 0;
	
hero.initalize(window, "hero.png");

	//image.loadFromFile("Forest_moving.gif");
//	imagee.setTexture(image);

	//Load Menu background
	Sprite backgroundsprite;
	Texture backgroundtexture;


	//Load pickup coin sprite  
	Pickup.pickuptexture.loadFromFile("coin.jpg");
	Pickup.pickupsprite.setTexture(Pickup.pickuptexture);
	


	// lOAD FONT 
	if (!fontpickup.loadFromFile("arial.ttf"))
	{
		cout << "cannot load text \n";

	}

	//Set font in tex for the coin word and counter
	textpickup.setFont(fontpickup);
	textpickup.setFillColor(Color::White);
	textpickup.setOutlineThickness(6);
	textpickup.setPosition(Vector2f(180, 740));



	if (!Hpfont.loadFromFile("arial.ttf"))
	{
		cout << " cannot load text \n";

	}
	//Vector of type pickup class holds pickup array
	vector <pickup>pickupcontainer;

	enemy Enemy;
	blast projectiles;

	vector<blast>::const_iterator iter11;
	vector<blast>projectilearray;

	

	vector <enemy> enemycontainer;
	vector <enemy>::const_iterator iter;
	enemycontainer.push_back(Enemy);
	enemycontainer.push_back(Enemy);
	Enemy.enemysprite.setPosition(500, 500);
	enemycontainer.push_back(Enemy);

	vector <barrier>wallcontainer;
	
	wallcounter = 0;

	while (wallcounter <= 20)
	{

		wallcontainer.push_back(wall);
		wall.wallsprite.setPosition(35 * wallcounter , 0); // Horizantal wall //k

		wallcontainer.push_back(wall);
		wall.wallsprite.setPosition(wallcounter * 40, 690);
        wallcounter++;

		wallcontainer.push_back(wall);
    	wall.wallsprite.setPosition(265 , 500); // k.. bottom 2 bricks , left side 

		wallcontainer.push_back(wall);  // with one above it 
		wall.wallsprite.setPosition(215, 500);

		wallcontainer.push_back(wall);  // with one above it 
		wall.wallsprite.setPosition(215, 445 ); // k

		

		
	}
	
	wallcounter = 0;
	
	while (wallcounter <= 30) //Vertical wall   up to down
	{
		wallcontainer.push_back(wall);
		wall.wallsprite.setPosition(0, wallcounter * 21);//k

		wallcontainer.push_back(wall);
		wall.wallsprite.setPosition(740,wallcounter * 21);//k
		
		
		  wallcounter++;

			
		}

	wallcounter = 0;
	while (wallcounter <= 10)
	{
	
		wallcontainer.push_back(wall);   // one alone on right ..k
		wall.wallsprite.setPosition(500, 100 * 4);

		wallcontainer.push_back(wall);   // one alone on right ..k
		wall.wallsprite.setPosition(553, 100 * 4);

		wallcontainer.push_back(wall);   // one alone on right ..k
		wall.wallsprite.setPosition(553,87 * 4);


		wallcontainer.push_back(wall); // leftt up alone k
		wall.wallsprite.setPosition(51, 200);

		wallcontainer.push_back(wall); // leftt up alone k
		wall.wallsprite.setPosition(105, 200);


		wallcontainer.push_back(wall);
		wall.wallsprite.setPosition(300, wallcounter * 20);

		wallcontainer.push_back(wall);
		wall.wallsprite.setPosition(50,150);

		wallcontainer.push_back(wall);
		wall.wallsprite.setPosition(500, 22*wallcounter);

		
		wallcounter++;
	}
	
	while (wallcounter <= 3)
	{
		wallcontainer.push_back(wall);
		wall.wallsprite.setPosition(600,wallcounter*8);
	}
	
	//Push back to add pickups  in the vector 
	int cg = 0;
	
   Pickup.pickupsprite.setPosition(160, 150);
	pickupcontainer.push_back(Pickup);
	Pickup.pickupsprite.setPosition(700, 500);
	Pickup.pickupsprite.setPosition(650, 450);
	pickupcontainer.push_back(Pickup);
	Pickup.pickupsprite.setPosition(500, 500);
	pickupcontainer.push_back(Pickup);
	Pickup.pickupsprite.setPosition(300, 300);
	pickupcontainer.push_back(Pickup);
	Pickup.pickupsprite.setPosition(200, 200);
	pickupcontainer.push_back(Pickup);
	Pickup.pickupsprite.setPosition(600, 100);
	pickupcontainer.push_back(Pickup);


    Hptext.setFillColor(Color::Red);
	Hptext.setOutlineThickness(7);
	Hptext.setPosition(Vector2f(0,740));
	

   Menu.playmusic(); // Play music for the game 
   
   
	while (window.isOpen()) //GAME LOOP
	{
		
	  Event event;
		
		while (window.pollEvent(event)) //Event Loop
		{
			
			if (event.type == event.Closed || Keyboard::isKeyPressed(Keyboard::Escape))
			   window.close(); // close window
			   window.clear();

				
			 if (Mouse::isButtonPressed(Mouse::Left)) 
			{
				if (Menu.playsprite.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) // click play
				{
					Menu.playbutton = true; // click play button to begin the game and draw everything 
					Menu.menuplay = false; // draw menu
					Menu.optionbackground = false;
					Menu.optionbutton = false;
				
				}

                if (Menu.exitsprite.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
				{

				 window.close();
				 //gamerunning = false;
				}

				if (Menu.optionsprite.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
				{
					Menu.optionbutton = true;
					Menu.optionbackground = true;
					Menu.playbutton = false;
					Menu.menuplay = false;
				//	gamerunning = false;
				    	
				}
			
				if (Menu.optionbackground == true)
				{
					Menu.playbutton = false;
					Menu.menuplay = false;
					//gamerunning = false;
				}

				if (Menu.Soundoffsprite.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
				{

					Menu.soundoff();
					
				}
				if (Menu.Soundonsprite.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
				{
					Menu.soundon();  
					
				}

				if (Menu.Backsprite.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
				{
					Menu.back = true;
					
                }


		}	// braces of if condition of the mouse 
		}//Braces of event loop
		
         window.clear();

        if (Menu.optionbackground == true) // option background is opened after clicking on its button
		{
			
		   window.draw(Menu.settingssprite);
		   window.draw(Menu.Soundoffsprite);
           window.draw(Menu.Soundonsprite);
		   window.draw(Menu.Backsprite);
      }

      if (Menu.playbutton == true)

		 {

			 window.draw(mountiansprite);  


             //Pickups
			 for (unsigned int i = 0; i < pickupcontainer.size(); i++) // loop from 0 to size of the pickupcontainer
			 {
				 window.draw(pickupcontainer[i].pickupsprite); // draw vector pickups on screen
			 }
			 Hptext.setString("HP :" + to_string(HPcounter));
			 textpickup.setString(" "+ to_string(coinscounter)); //output coins text and its counter
			 

			 counter = 0;


			 for (int i = 0; i < pickupcontainer.size(); i++)  // loop to check for player collision  
			 {
				 if (hero.herosprite.getGlobalBounds().intersects(pickupcontainer[counter].pickupsprite.getGlobalBounds()))
				 {

					 pickupcontainer.erase(pickupcontainer.begin() + i); // erase from begin plus index i each time incremented in loop
					 coinscounter++; // increment coins counter when colliding 
					 Pickup.coin_sound(); // play coin sound 
				 }
				 counter++; // increment in vector to move through it 
			 }

			 
			 //HP 

			 cg = 0;
			 if (hero.herosprite.getGlobalBounds().intersects(Enemy.enemysprite.getGlobalBounds()))
			 {
				 HPcounter--;
				 
				 
				 if (HPcounter == 0) // when player loses
				 {
					 cout << " you lost \n";
					 //  window.close();
				 }
}
			  //Fire projectiles after pressing space button

				 if (Keyboard::isKeyPressed(Keyboard::Space))
				 {

					 projectiles.rectangle.setPosition(hero.herosprite.getPosition().x, hero.herosprite.getPosition().y);
					 projectiles.direction = hero.direction;
					 projectilearray.push_back(projectiles);
				 }

				 //Draw Projectiles


				 for (int i = 0; i < projectilearray.size(); i++)
				 {
					 projectilearray[i].update();
					 window.draw(projectilearray[i].rectangle);

				 }

			   //Draw Wall

				 for (int i = 0; i < wallcontainer.size(); i++)
				 {
					window.draw(wallcontainer[i].wallsprite);
				 }

				 //Wall Collision
			 
				 for (int i = 0; i < wallcontainer.size(); i++)
				 {
					 if (hero.herosprite.getGlobalBounds().intersects(wallcontainer[i].wallsprite.getGlobalBounds()))// collision
					 {
						 if (hero.direction == 1) // Up
						 {
							 hero.canomveup = false; // cannot move up when colliding with wall
							 hero.herosprite.move(0, 1);
						 }

						 else if (hero.direction == 2) // Down
						 {

							 hero.canmovedown = false; // cannot move down when colliding with wall
							 hero.herosprite.move(0, -1);
						 }

						 else if (hero.direction == 3) // Left 
						 {

							 hero.canmoveleft = false;  // cannot move left when colliding with wall
							 hero.herosprite.move(1, 0);
						 }


						 else	if (hero.direction == 4) // Right
						 {
							 hero.canmoveright = false; // cannot move right when colliding with wall
							 hero.herosprite.move(-1, 0);
						 }
						 else
						 {
							 // No Movement
						 }

					 }

					 // Enemy collides with wall
					 for (int j = 0; j < enemycontainer.size(); j++)
					 {

                      if (enemycontainer[j].enemysprite.getGlobalBounds().intersects(wallcontainer[i].wallsprite.getGlobalBounds()))
						 {
							 if (enemycontainer[j].direction == 1)
							 {
								 enemycontainer[j].canmoveup = false;
								 enemycontainer[j].enemysprite.move(0, 1);
							 }
							 if (enemycontainer[j].direction == 2)
							 {
								 enemycontainer[j].canmovedown = false;
								 enemycontainer[j].enemysprite.move(0, -1);
							 }
							 if (enemycontainer[j].direction == 3)
							 {
								 enemycontainer[j].canmoveleft = false;
								 enemycontainer[j].enemysprite.move(1, 0);
							 }
							 if (enemycontainer[j].direction == 4)
							 {
								 enemycontainer[j].canmoveright = false;
								 enemycontainer[j].enemysprite.move(-1, 0);

							 }
							 else
							 {
								 //No movement
							 }
						 }
					 }
				 }

				 for (int i = 0; i < enemycontainer.size(); i++)
				 {
					 window.draw(enemycontainer[i].enemysprite);
					 enemycontainer[i].updatemovement();

				 }

			 //To win

			 if (hero.herosprite.getGlobalBounds().intersects(win.getGlobalBounds()))
			 {
				 cout << " You win \n";
			 }

			// Draw everything

		     Enemy.drawenemy(window);
             window.draw(textpickup);
			 hero.draw(window);
			 hero.set_hero(ms);
			 hero.updatemovement();
			 Enemy.updatemovement();
			 Menu.runmenu(window);
			 Menu.drawmenu(window);
			 window.draw(Hptext);
			 projectiles.update();
     	     window.draw(win);
			 window.draw(coinlogosprite);
			  
		 
}
  window.display(); // display everything on the screen
			
    }
}

	

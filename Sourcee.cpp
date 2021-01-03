
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace std;
#include <iostream>

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"

#include "random.h"
#include "player.h"
#include "entity.h"
#include "projectile.h"
#include "enemy.h"
#include "textDisplay.h"
#include "pickup.h"

int main(int, char const**)
{
	// Variables
	sf::Clock clock;
	sf::Clock clock2;
	sf::Clock clock3;
	float playerMovementSpeed = 2;
	int counterWalking = 0;
	int counter = 0;
	int counter2 = 0;
	int counter3 = 0;

	// Create the main window
	sf::RenderWindow window(sf::VideoMode(1000, 800), "I want to learn SFML! W00tsaurs");
	window.setFramerateLimit(60);

	// Set the Icon
	sf::Image icon;
	if (!icon.loadFromFile(resourcePath() + "icon.png")) {
		return EXIT_FAILURE;
	}
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	// Load a sprite to display
	sf::Texture textureLion;
	if (!textureLion.loadFromFile(resourcePath() + "lion.jpg")) {
		return EXIT_FAILURE;
	}
	sf::Sprite spriteLion(textureLion);
	spriteLion.setPosition(500, 500);

	sf::Texture textureEnemy;
	if (!textureEnemy.loadFromFile(resourcePath() + "enemySpriteSheet.png")) {
		return EXIT_FAILURE;
	}

	sf::Texture textureCoin;
	if (!textureCoin.loadFromFile(resourcePath() + "coin.gif")) {
		return EXIT_FAILURE;
	}

	sf::Texture textureFireBall;
	if (!textureFireBall.loadFromFile(resourcePath() + "fireball.png")) {
		return EXIT_FAILURE;
	}

	// Load a sprite to display
	sf::Texture texturePlayer;
	if (!texturePlayer.loadFromFile(resourcePath() + "spriteWalk.png")) {
		return EXIT_FAILURE;
	}
	sf::Sprite spritePlayer(texturePlayer);
	spritePlayer.setPosition(window.getSize().x / 2, window.getSize().y / 2);
	spritePlayer.setTextureRect(sf::IntRect(0, 0, 32, 32));

	// Create a graphical text to display
	sf::Font font;
	if (!font.loadFromFile(resourcePath() + "pixel.ttf")) {
		return EXIT_FAILURE;
	}
	sf::Text text("Gil: ", font, 25);
	text.setColor(sf::Color::Yellow);
	text.setPosition(0, 0);

	// Load a music to play
	sf::Music music;
	if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
		return EXIT_FAILURE;
	}

	// Play the music
	//music.play();

	// Class Object
	class player Player1;
	Player1.sprite.setTexture(texturePlayer);


	// Projectile Vector Array
	vector<projectile>::const_iterator iter;
	vector<projectile> projectileArray;

	// Projectile Object
	class projectile projectile1;
	projectile1.sprite.setTexture(textureFireBall);


	// Enemy Vector Array
	vector<enemy>::const_iterator iter4;
	vector<enemy> enemyArray;

	// Enemy Object
	class enemy enemy1;
	enemy1.sprite.setTexture(textureEnemy);
	//enemy1.sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

	enemy1.rect.setPosition(600, 200);
	enemyArray.push_back(enemy1);

	// Text Vector Array
	vector<textDisplay>::const_iterator iter8;
	vector<textDisplay> textDisplayArray;

	// Text Display Object
	class textDisplay textDisplay1;
	textDisplay1.text.setFont(font);





	// Pickup Vector Array
	vector<pickup>::const_iterator iter11;
	vector<pickup> pickupArray;

	// Coin Object
	class pickup pickup1;
	pickup1.sprite.setTexture(textureCoin);
	pickup1.rect.setPosition(500, 500);
	pickup1.rect.setSize(sf::Vector2f(32, 32));
	pickupArray.push_back(pickup1);

	pickup1.rect.setPosition(700, 500);
	pickupArray.push_back(pickup1);


	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			// Escape pressed: exit
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				window.close();
			}
		}

		// Clear screen
		window.clear();

		// Clock
		sf::Time elapsed1 = clock.getElapsedTime();
		sf::Time elapsed2 = clock2.getElapsedTime();
		sf::Time elapsed3 = clock3.getElapsedTime();




		// Player collides with Pickup Item
		counter = 0;
		for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
		{
			if (Player1.rect.getGlobalBounds().intersects(pickupArray[counter].rect.getGlobalBounds()))
			{
				if (pickupArray[counter].isCoin == true)
				{
					Player1.gil += pickupArray[counter].coinValue;
				}

				pickupArray[counter].destroy = true;
			}

			counter++;
		}





		if (elapsed2.asSeconds() >= 0.5)
		{
			clock2.restart();

			// Enemy Collides with Player (Player takes damage)
			counter = 0;
			for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
			{
				if (Player1.rect.getGlobalBounds().intersects(enemyArray[counter].rect.getGlobalBounds()))
				{
					// Text Display
					textDisplay1.text.setString(to_string(enemyArray[counter].attackDamage));
					textDisplay1.text.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x / 2, Player1.rect.getPosition().y - Player1.rect.getSize().y / 2);
					textDisplayArray.push_back(textDisplay1);

					Player1.hp -= enemyArray[counter].attackDamage;
				}

				counter++;
			}
		}

		cout << Player1.hp << endl;



		// Projectile Collides with Enemy
		counter = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
		{
			counter2 = 0;
			for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
			{
				if (projectileArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()))
				{
					projectileArray[counter].destroy = true;

					// Text Display
					textDisplay1.text.setString(to_string(projectileArray[counter].attackDamage));
					textDisplay1.text.setPosition(enemyArray[counter2].rect.getPosition().x + enemyArray[counter2].rect.getSize().x / 2, enemyArray[counter2].rect.getPosition().y - enemyArray[counter2].rect.getSize().y / 2);
					textDisplayArray.push_back(textDisplay1);

					enemyArray[counter2].hp -= projectileArray[counter].attackDamage;
					if (enemyArray[counter2].hp <= 0)
					{
						enemyArray[counter2].alive = false;
					}
				}

				counter2++;
			}

			counter++;
		}

		// Delete Dead Enemy
		counter = 0;
		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
		{
			if (enemyArray[counter].alive == false)
			{
				cout << "Enemy has been obliterated! lawlz" << endl;

				// Drop Coin
				if (generateRandom(4) == 1)
				{
					pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
					pickupArray.push_back(pickup1);
				}

				enemyArray.erase(iter4);
				break;
			}

			counter++;
		}

		// Delete Projectile
		counter = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
		{
			if (projectileArray[counter].destroy == true)
			{
				projectileArray.erase(iter);
				break;
			}

			counter++;
		}

		// Delete Text Display
		counter = 0;
		for (iter8 = textDisplayArray.begin(); iter8 != textDisplayArray.end(); iter8++)
		{
			if (textDisplayArray[counter].destroy == true)
			{
				textDisplayArray.erase(iter8);
				break;
			}

			counter++;
		}

		// Delete Pickup Items
		counter = 0;
		for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
		{
			if (pickupArray[counter].destroy == true)
			{
				pickupArray.erase(iter11);
				break;
			}

			counter++;
		}







		// Spawn Enemies (Y-Key)
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
		{
			enemy1.rect.setPosition(generateRandom(window.getSize().x), generateRandom(window.getSize().y));
			enemyArray.push_back(enemy1);
		}

		// Fires Missle (Space bar)
		if (elapsed1.asSeconds() >= 0.1)
		{
			clock.restart();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x / 2 - projectile1.rect.getSize().x / 2, Player1.rect.getPosition().y + Player1.rect.getSize().y / 2 - projectile1.rect.getSize().y / 2);
				projectile1.direction = Player1.direction;
				projectileArray.push_back(projectile1);
			}
		}

		// Draw Pickup Items
		counter = 0;
		for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
		{
			pickupArray[counter].update();
			window.draw(pickupArray[counter].rect);
			window.draw(pickupArray[counter].sprite);

			counter++;
		}

		// Draw Projectiles
		counter = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
		{
			projectileArray[counter].update(); // Update Projectile
											   //window.draw(projectileArray[counter].rect);
			window.draw(projectileArray[counter].sprite);

			counter++;
		}

		// Draw Enemies
		counter = 0;
		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
		{
			enemyArray[counter].update();
			enemyArray[counter].updateMovement();
			//window.draw(enemyArray[counter].rect);
			window.draw(enemyArray[counter].sprite);

			counter++;
		}

		// Update Player
		Player1.update();
		Player1.updateMovement();

		// Draw Player
		window.draw(Player1.sprite);
		//window.draw(Player1.rect);

		// Draw Text
		counter = 0;
		for (iter8 = textDisplayArray.begin(); iter8 != textDisplayArray.end(); iter8++)
		{
			textDisplayArray[counter].update();
			window.draw(textDisplayArray[counter].text);

			counter++;
		}

		// Gil
		text.setString("Gil : " + to_string(Player1.gil));
		window.draw(text);

		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
}

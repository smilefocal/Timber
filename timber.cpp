//#include "stdafx.h"
#include "SFML/Graphics.hpp"

using namespace sf;

int main() 
{
	VideoMode vm(1920, 1080);

	//create and open a window
	RenderWindow window(vm, "Timber!!!", Style::Fullscreen);

	//A texture to hold graphic on the GPU
	Texture textureBackground;
	//load graphic into the texture
	textureBackground.loadFromFile("graphics/background.png");

	//create a sprite
	Sprite spriteBackground;

	//Attach texture to sprite
	spriteBackground.setTexture(textureBackground);
	//set spritebacground to cover screen
	spriteBackground.setPosition(0, 0);

	//make a tree sprite
	Texture textureTree;
	textureTree.loadFromFile("graphics/tree.png");
	Sprite spriteTree;
	spriteTree.setTexture(textureTree);
	spriteTree.setPosition(810, 0);

	//prepare the bee
	Texture textureBee;
	textureBee.loadFromFile("graphics/bee.png");
	Sprite spriteBee;
	spriteBee.setTexture(textureBee);
	spriteBee.setPosition(0, 800);
	//is the bee currently moving?
	bool beeActive = false;
	//How fast can the bee fly?
	float beeSpeed = 0.0f;

	//make 3 clouds from 1 texture
	Texture textureCloud;
	//load 1 new texture
	textureCloud.loadFromFile("Graphics/cloud.png");
	//3 new sprites with same texture
	Sprite spriteCloud1;
	Sprite spriteCloud2;
	Sprite spriteCloud3;

	spriteCloud1.setTexture(textureCloud);
	spriteCloud2.setTexture(textureCloud);
	spriteCloud3.setTexture(textureCloud);

	//position the clouds off screen
	spriteCloud1.setPosition(0, 0);
	spriteCloud2.setPosition(0, 250);
	spriteCloud3.setPosition(0, 500);

	//Are the clouds currently on screen
	bool cloud1Active = false;
	bool cloud2Active = false;
	bool cloud3Active = false;
	//how fast is each cloud
	float cloud1Speed = 0.0f;
	float cloud2Speed = 0.0f;
	float cloud3Speed = 0.0f;

	//variables to control time itself
	Clock clock;

	//track whether game is paused
	bool paused = true;

	while (window.isOpen())
	{
		//Input from player

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		//start the game
		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			paused = false;
		}
		/*
		UPDATE THE SCENE
		*/
		if (!paused)
		{
		//measure time
		Time dt = clock.restart();

		//Setup the bee
		if (!beeActive)
		{
			//how fast is the bee
			srand((int)time(0) * 10);
			beeSpeed = (rand() % 200) + 200;
			//how high is the bee
			srand((int)time(0) * 10);
			float height = (rand() % 500) + 500;
			spriteBee.setPosition(2000, height);
			beeActive = true;
		}
		else
			//move the bee
		{
			spriteBee.setPosition(
				spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()), spriteBee.getPosition().y);
			//has the bee reached the right hand edge of the screen?
			if (spriteBee.getPosition().x < -100)
			{
				//set it up ready to be a whole new cloud next frame
				beeActive = false;
			}
		}
		//Manage the clouds
		//Cloud1
		if (!cloud1Active)
		{
			//how fast is the cloud
			srand((int)time(0) * 10);
			cloud1Speed = (rand() % 200);

			//how high is the cloud
			srand((int)time(0) * 10);
			float height = (rand() % 150);
			spriteCloud1.setPosition(-200, height);
			cloud1Active = true;
		}
		else
		{
			spriteCloud1.setPosition(
				spriteCloud1.getPosition().x +
				(cloud1Speed * dt.asSeconds()),
				spriteCloud1.getPosition().y
			);

			//has the cloud reached the right hand edge of the screen
			if (spriteCloud1.getPosition().x > 1920)
			{
				//set it up ready to be a whole new cloud next frame
				cloud1Active = false;
			}
		}

		//Cloud 2
		if (!cloud2Active)
		{
			//how fast is the cloud
			srand((int)time(0) * 20);
			cloud2Speed = (rand() % 200);

			//how high is the cloud
			srand((int)time(0) * 20);
			float height = (rand() % 150);
			spriteCloud2.setPosition(-200, height);
			cloud2Active = true;
		}
		else
		{
			spriteCloud2.setPosition(
				spriteCloud2.getPosition().x +
				(cloud2Speed * dt.asSeconds()),
				spriteCloud2.getPosition().y
			);

			//has the cloud reached the right hand edge of the screen
			if (spriteCloud2.getPosition().x > 1920)
			{
				//set it up ready to be a whole new cloud next frame
				cloud2Active = false;
			}
		}

		//Cloud 3
		if (!cloud1Active)
		{
			//how fast is the cloud
			srand((int)time(0) * 30);
			cloud3Speed = (rand() % 200);

			//how high is the cloud
			srand((int)time(0) * 30);
			float height = (rand() % 150);
			spriteCloud3.setPosition(-200, height);
			cloud3Active = true;
		}
		else
		{
			spriteCloud3.setPosition(
				spriteCloud3.getPosition().x +
				(cloud3Speed * dt.asSeconds()),
				spriteCloud3.getPosition().y
			);

			//has the cloud reached the right hand edge of the screen
			if (spriteCloud3.getPosition().x > 1920)
			{
				//set it up ready to be a whole new cloud next frame
				cloud3Active = false;
			}
		}

		}//endif

		/*
		DRAW THE SCENE
		*/
		window.clear();

		//draw game scene
		window.draw(spriteBackground);

		//draw the clouds
		window.draw(spriteCloud1);
		window.draw(spriteCloud2);
		window.draw(spriteCloud3);

		//draw the tree
		window.draw(spriteTree);

		//draw the insect
		window.draw(spriteBee);

		//show everythin we just drew
		window.display();
	}
	return 0;
}

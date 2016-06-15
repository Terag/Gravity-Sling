#include "interface.h"
#include <string>
#include <iostream>

MyInterface::MyInterface() :
	level(NULL), window(sf::VideoMode(1024,768),"GravitySling", sf::Style::Titlebar), nextLevel(false)
{
}

MyInterface::~MyInterface()
{
}


void MyInterface::update()
{
	if (level != NULL) {
		level->update(window);
	}
	for (auto &sprite : sprites)
	{
		//std::cout << "for";
		window.draw(sprite);
	}
}

void MyInterface::display()
{
	window.display();
}

void MyInterface::initTextures()
{
	textures.clear();

	sf::Texture base;
	loadTexture("base", base);

	assert(level != NULL);
	if (level->getNbBlackHoles() >= 1)
	{

		sf::Texture b1, b1X;
		loadTexture("b1" + level->getFormatBlackHole(0), b1);
		loadTexture("b1X", b1X);

		if (level->getNbBlackHoles() >= 2)
		{

			sf::Texture b2, b2X;
			loadTexture("b2" + level->getFormatBlackHole(1), b2);
			loadTexture("b2X", b2X);

			if (level->getNbBlackHoles() >= 3)
			{
				sf::Texture b3, b3X;
				loadTexture("b3" + level->getFormatBlackHole(2), b3);
				loadTexture("b3X", b3X);

			}
		}
	}

	sf::Texture nextLevelX, go, stop, options;
	loadTexture("nextLevelX", nextLevelX);
	loadTexture("go", go);
	loadTexture("stop", stop);
	loadTexture("options", options);
}

void MyInterface::init()
{
	sprites.clear();

	sf::Sprite sBase, sGo;
	loadSprite("base", sBase);
	loadSprite("go", sGo);

	if (level->getNbBlackHoles() >= 1)
	{

		sf::Sprite sB1;
		loadSprite("b1" + level->getFormatBlackHole(0),sB1);

		if (level->getNbBlackHoles() >= 2)
		{
			sf::Sprite sB2;
			loadSprite("b2" + level->getFormatBlackHole(1) , sB2);
			
			if (level->getNbBlackHoles() >= 3)
			{

				sf::Sprite sB3;
				loadSprite("b3" + level->getFormatBlackHole(2), sB3);

			}
		}
	}

	sf::Sprite sNextLevelX;
	loadSprite("nextLevelX", sNextLevelX);
}

void MyInterface::unlockNextLevel()
{
	if (level->getState() == WINNING && !level->levelIsFinish())
	{
		sprites.pop_back();
	}

}

void MyInterface::setLevel(Level * lvl)
{
	level = lvl;
	nextLevel = false;
}

void MyInterface::setBlackHole(int i, sf::Event event)
{


	if (event.type == sf::Event::MouseButtonPressed)
	{
		sf::Vector2i position = sf::Mouse::getPosition(window);

		if (655 > position.y && position.x < 805)
		{
			level->moveHoleTo(position.x, position.y, i-1);
		}
		if (675 < position.y && position.y < 755)
		{
			if (i == 1 && 35 < position.x && position.x < 180)
			{
				level->disableHole(i-1);
			}

			if (i == 2 && 205 < position.x && position.x < 345)
			{
				level->disableHole(i-1);
			}

			if (i == 3 && 370 < position.x && position.x < 700)
			{
				level->disableHole(i-1);
			}
		}
	}
}


void MyInterface::loadTexture(std::string textureName, sf::Texture texture)
{
	if (!texture.loadFromFile("./textures/" + textureName + ".png"))
	{
		std::cout << textureName + "loading error";
	}
	textures.insert(std::pair<std::string, sf::Texture>(textureName, texture));
}

void MyInterface::loadSprite(std::string textureName, sf::Sprite sprite)
{
	sprite.setTexture(textures[textureName]);
	sprites.push_back(sprite);
}

sf::Event MyInterface::drawUntilNextClick(std::string textureName, sf::Sprite sprite)
{
	sprite.setTexture(textures[textureName]);
	window.draw(sprite);
	window.display();
	sf::Event event;
	int v = 1;
	while (v)
	{
		while (window.pollEvent(event))
		{

			if (event.type==sf::Event::MouseButtonPressed){
				v = 0;
				return event;
			}
		}
	}
}

void MyInterface::chechIfRun()
{
	if (level->getState() == STOP) {
		sprites[1].setTexture(textures["go"]);
	}
}



bool MyInterface::isOpen()
{
	return window.isOpen();
}

void MyInterface::treatEvents() {
		
	sf::Event event;
	while (window.pollEvent(event))
	{

		if (level == NULL) {
			break;
		}

		if (event.type == sf::Event::Closed) {
			window.close();
		}

		if (event.type == sf::Event::KeyPressed  && level->getState() == STOP)
		{

			if (event.key.code == sf::Keyboard::F1)
			{

				sf::Sprite sB1X;
				setBlackHole(1, drawUntilNextClick("b1X", sB1X));
				
			}

			if ((event.key.code == sf::Keyboard::F2) && (level->getNbBlackHoles()>1))
			{
				sf::Sprite sB2X;
				setBlackHole(2, drawUntilNextClick("b2X", sB2X));
			}

			if ((event.key.code == sf::Keyboard::F3) && level->getNbBlackHoles() == 3)
			{
				sf::Sprite sB3X;
				setBlackHole(3, drawUntilNextClick("b3X", sB3X));
			}


		}
		if (event.type == sf::Event::MouseButtonPressed)
		{

			sf::Vector2i position = sf::Mouse::getPosition(window);
			//menu de droite
			if (835<position.x && position.x<995)
			{
				if (35<position.y && position.y<145)// STOP/GO
				{
					switch (level->getState()) {
					case STOP :
						sprites[1].setTexture(textures["stop"]);
						level->setState(RUN);
						break;
					case RUN :
						sprites[1].setTexture(textures["go"]);
						level->setState(STOPPING);
						break;
					default :
						break;
					}
				}

				if (180<position.y && position.y<265)
				{
					level->setState(RESET);
				}

				if (290<position.y && position.y<370)
				{
					if (level->levelIsFinish())
					{
						nextLevel = true;
					}
				}

				if (400 < position.y && position.y < 480)
				{
					sf::Sprite sOptions;
					drawUntilNextClick("options", sOptions);
				}

				if (505<position.y && position.y<590) //Quit
				{
					window.close();
				}
			}
		}

	}
}

bool MyInterface::isNextLevel()
{
	return nextLevel;
}

void MyInterface::calculate()
{
	unlockNextLevel();
	if (level->getState() == STOP) {
		sprites[1].setTexture(textures["go"]);
	}
	if (level != NULL) {
		level->calculate();
	}
}

void MyInterface::clear()
{
	window.clear();
}

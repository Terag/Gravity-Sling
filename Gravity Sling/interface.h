#pragma once
#include "level.h"
#include <vector>
#include <map>
#include <SFML/Window.hpp>
#include <assert.h>

class MyInterface {
public:
	friend class GameLoop;

	MyInterface();
	~MyInterface();

	void init();
	void initTextures();
	void unlockNextLevel();
	void setLevel(Level *lvl);
	void setBlackHole(int i, sf::Event event);
	void loadTexture(std::string textureName, sf::Texture texture);
	void loadSprite(std::string textureName, sf::Sprite sprite);
	sf::Event drawUntilNextClick(std::string textureName, sf::Sprite sprite);
	void chechIfRun();


protected:
	bool isOpen();
	void setFrameRate(int rate) { window.setFramerateLimit(60); }
	void treatEvents();
	bool isNextLevel();
	void calculate();
	void clear();
	void update();
	void display();

private:
	Level *level;
	bool nextLevel;
	std::map<std::string, sf::Texture> textures;
	std::vector<sf::Sprite> sprites;
	sf::RenderWindow window;

};
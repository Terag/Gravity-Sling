#include "gameLoop.h"

GameLoop::GameLoop()
{
}

GameLoop::~GameLoop()
{
}

void GameLoop::loop()
{
	myInterface.initTextures();
	myInterface.init();
	myInterface.setFrameRate(60);
	
	while (myInterface.isOpen())
	{

		myInterface.treatEvents();
		if (myInterface.isNextLevel()) {
			currentLevel++;
			if (currentLevel < levels.size()) {
				myInterface.setLevel(&(levels[currentLevel]));
				myInterface.initTextures();
				myInterface.init();
			}
		}
		myInterface.calculate();
		myInterface.clear();
		myInterface.update();
		myInterface.display();
	}
}

void GameLoop::initGame()
{
	if (levels.size() > 0) {
		myInterface.setLevel(&(levels[0]));
	}
	currentLevel = 0;
}

void GameLoop::pushLevel(Level & level)
{
	levels.push_back(level);
}

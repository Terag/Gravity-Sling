#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "interface.h"

class GameLoop
{
public:

	GameLoop();
	~GameLoop();

	void loop();
	void initGame();
	void pushLevel(Level &level);

	std::vector<Level> levels;

private:
	MyInterface myInterface;
	int currentLevel;
};

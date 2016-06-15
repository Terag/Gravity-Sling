#pragma once
#include <vector>
#include <iostream>
#include <memory>

#include <string>
#include "obstacle.h"
#include "blackHole.h"
#include "ship.h"

//états de la machine
typedef enum {
	RUN,
	STOP,
	RESET,
	STOPPING,
	WINNING
} LevelState;

class Level
{
public:
	//structure des méthodes à mettre dans le tableau
	//typedef void (Level::*StateMachineFunction)(void);
	
	Level();
	Level(Ship &spaceShip, Obstacle &station, std::string name, std::string spriteName);
	~Level();

	//fonctions de la machine
	void update(sf::RenderWindow &app);
	void calculate();
	void run();
	void stop();
	void reset();
	void stopping();
	void winning();

	void moveHoleTo(float X, float Y, int holeNumber);
	void disableHole(int holeNumber);
	void gravityEffect();
	static bool isCollide(SpaceEntity &entity1, SpaceEntity &entity2);
	void addObstacle(Obstacle &obstacle);
	void addHole(BlackHole& blackHole);
	std::string getFormatBlackHole(int blackHoleNb);

	//getters
	LevelState getState() const { return state; }
	std::string getName() const { return levelName; }
	int getNbBlackHoles() const { return blackHoles.size(); }
	bool levelIsFinish() const { return win; }
	float getSizeBlackHole(int blackHoleNb) const { return blackHoles[blackHoleNb].getRadius(); }

	//setters
	void setState(LevelState newState) { state = newState; }

private:
	
	std::vector<Obstacle> obstacles;
	std::vector<BlackHole> blackHoles;
	Ship ship;
	Obstacle spaceStation;
	LevelState state;
	std::string levelName;
	sf::Texture backGround;
	sf::RectangleShape screen;
	bool win;

	//tableau de fonctions
	//std::vector<StateMachineFunction*> transitions;
};


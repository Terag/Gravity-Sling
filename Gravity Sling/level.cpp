#include "level.h"
#include <iostream>
#include <math.h>

Level::Level()
{
}

Level::Level(Ship &spaceShip, Obstacle &station, std::string name, std::string spriteName) :
	levelName(name), state(STOP), ship(spaceShip), spaceStation(station), 
	screen(sf::RectangleShape(sf::Vector2f(800,800)))
{
	backGround.loadFromFile(spriteName);
	screen.setTexture(&backGround);
								/* State	 /  function */
	//transitions.push_back(	/* RUN		*/	&this->run		);
	//transitions.push_back(	/* STOP		*/	&this->stop		);
	//transitions.push_back(	/* RESET    */	&this->reset	);
	//transitions.push_back(	/* STOPPING */	&this->stopping	);
	//transitions.push_back(	/* WIN		*/	&this->winning	);*/
}

void Level::update(sf::RenderWindow &app)
{
	app.draw(screen);

	for (auto &hole : blackHoles) {
		hole.update(app);
	}

	for (auto &obstacle : obstacles) {
		obstacle.update(app);
	}

	ship.update(app);
	spaceStation.update(app);
}

void Level::calculate()
{
	//moveHoleTo(450, 300, 1);
	switch (state) {
	case RUN:
		run();
		break;
	case STOP:
		stop();
		break;
	case RESET:
		reset();
		break;
	case STOPPING:
		stopping();
		break;
	case WINNING:
		winning();
		break;
	}
}

void Level::run()
{
	gravityEffect();
	ship.move();
	for (auto &obstacle : obstacles) {
		if (isCollide(ship, obstacle)) {
			state = STOPPING;
		}
	}
	for (auto &hole : blackHoles) {
		if (isCollide(ship, hole) && hole.isEnable()) {
			state = STOPPING;
		}
	}
	if (isCollide(ship, spaceStation)) {
		state = WINNING;
	}
}

void Level::stop()
{
	ship.reset();
}

void Level::reset()
{
	for (auto &obstacle : obstacles) {
		obstacle.reset();
	}

	for (auto &hole : blackHoles) {
		hole.reset();
	}

	ship.reset();
	spaceStation.reset();
	state = STOP;
}

void Level::stopping()
{
	ship.reset();
	state = STOP;
}

void Level::winning()
{
	ship.reset();
	win = true;
	state = STOP;
}

void Level::moveHoleTo(float X, float Y, int holeNumber)
{
	if (state == STOP) {
		if (-1 < holeNumber && holeNumber < blackHoles.size()) {
			blackHoles[holeNumber].moveTo(X, Y);
		}
	}
}

void Level::disableHole(int holeNumber)
{
	if (state == STOP) {
		if (-1 < holeNumber && holeNumber < blackHoles.size()) {
			blackHoles[holeNumber].reset();
		}
	}
}

void Level::gravityEffect()
{
	float Ax = 0;
	float Ay = 0;
	float d = 0;
	for (auto &hole : blackHoles) {
		if (hole.isEnable()) {
			d = sqrt(pow(ship.getX() - hole.getX(), 2) + pow(ship.getX() - hole.getY(), 2));
			Ax += -(hole.getMass()*(ship.getX() - hole.getX())) / pow(d, 3);
			Ay += -(hole.getMass()*(ship.getY() - hole.getY())) / pow(d, 3);
		}
	}
	ship.setSpeedX(ship.getSpeedX() + Ax);
	ship.setSpeedY(ship.getSpeedY() + Ay);
}

bool Level::isCollide(SpaceEntity & entity1, SpaceEntity & entity2)
{
	float dCarre = pow(entity1.getX() - entity2.getX(), 2) + pow(entity1.getY() - entity2.getY(), 2);
	float rCarre = pow(entity1.getRadiusCollide() + entity2.getRadiusCollide(), 2);
	if (dCarre < rCarre) {
		return true;
	} else {
		return false;
	}
}

void Level::addObstacle(Obstacle &obstacle)
{
	obstacles.push_back(obstacle);
}

void Level::addHole(BlackHole &blackHole)
{
	if (blackHoles.size() < 3) {
		blackHoles.push_back(blackHole);
	}
}

std::string Level::getFormatBlackHole(int blackHoleNb)
{
	if (-1 < blackHoleNb && blackHoleNb < blackHoles.size()) {
		float size = blackHoles[blackHoleNb].getRadius();
		if (size <= 50) {
			return std::string("1");
		}
		else
		if (size <= 100) {
			return std::string("2");
		}
		else {
			return std::string("3");
		}
	}
}

Level::~Level()
{
}


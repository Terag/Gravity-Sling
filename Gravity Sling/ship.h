#pragma once
#include "spaceEntity.h"
#include <iostream>

class Ship :
	public SpaceEntity
{
public:
	Ship();
	Ship(float X, float Y, float R, float speedX, float speedY, float radiusCollOverRadius, std::string spriteName);
	~Ship();

	void update(sf::RenderWindow &app);
	void reset();
	void move();

	//getters
	float getSpeedX() const { return speedX; }
	float getSpeedY() const { return speedY; }

	//setters
	void setSpeedX(float sX) { speedX = sX; }
	void setSpeedY(float sY) { speedY = sY; }

private:
	float initX;
	float initY;
	float initSpeedX;
	float initSpeedY;
	float speedX;
	float speedY;
	float angle;
	sf::CircleShape circle;

	void setAngleWithSpeed();
};


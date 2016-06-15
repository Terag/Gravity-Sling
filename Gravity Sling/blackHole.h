#pragma once

#include "spaceEntity.h"

class BlackHole :
	public SpaceEntity
{
public:
	BlackHole();
	BlackHole(float X, float Y, float R, float M, float radiusCollOverRadius, std::string spriteName);
	~BlackHole();

	void update(sf::RenderWindow &app);
	void reset();
	void moveTo(float X, float Y);

	//getters
	bool isEnable() const { return utility; }
	float getMass() const { return mass; }

private:
	float mass;
	bool utility;
	sf::CircleShape circle;
};


#pragma once

#include <SFML/Graphics.hpp>
#include "spaceEntity.h"

class Obstacle :
	public SpaceEntity
{
public:
	Obstacle();
	Obstacle(float X, float Y, float R, float radiusCollOverRadius, std::string spriteName);
	~Obstacle();

	void update(sf::RenderWindow &app);
	void reset();

private:
	sf::CircleShape circle;

};


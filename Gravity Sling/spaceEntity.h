#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


class SpaceEntity
{
public:
	SpaceEntity();
	SpaceEntity(float X, float Y, float R, float radiusCollOverRadius, std::string spriteName);
	~SpaceEntity();

	virtual void update(sf::RenderWindow &app) = 0;
	virtual void reset() = 0;
	float getRadius() const { return radius; }
	float getRadiusCollide() const { return radiusCollide; }
	float getX() const { return posX; }
	float getY() const { return posY; }

protected:
	float posX;
	float posY;
	float radius;
	float radiusCollide;
	sf::Image imageSprite;
	sf::Texture sprite;
};


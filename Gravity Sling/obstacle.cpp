#include "obstacle.h"


Obstacle::Obstacle()
{
}

Obstacle::Obstacle(float X, float Y, float R, float radiusCollOverRadius, std::string spriteName) :
	SpaceEntity(X, Y, R, radiusCollOverRadius, spriteName), circle(sf::CircleShape(R))
{
	circle.setTexture(&sprite);
}

void Obstacle::update(sf::RenderWindow &app)
{
	circle.setPosition(posX - radius, posY - radius);
	app.draw(circle);
	/*
	sf::CircleShape cercle(radiusCollide);
	cercle.setPosition(posX - radiusCollide, posY - radiusCollide);
	app.draw(cercle);
	sf::RectangleShape rectangle(sf::Vector2f(radiusCollide, radiusCollide));
	rectangle.setFillColor(sf::Color(150, 0, 0));
	rectangle.setPosition(posX, posY);
	app.draw(rectangle);*/
}

void Obstacle::reset()
{
	//nothing to do
}

Obstacle::~Obstacle()
{

}
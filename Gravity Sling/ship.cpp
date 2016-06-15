#include "ship.h"
#include <cmath>

const float Pi = 3.141592654f;

float DegToRad(float x)
{
	return x / 180 * Pi;
}

float RadToDeg(float x)
{
	return x / Pi * 180;
}

Ship::Ship()
{
}

Ship::Ship(float X, float Y, float R, float speedX, float speedY, float radiusCollOverRadius, std::string spriteName) :
	SpaceEntity(X,Y, R, radiusCollOverRadius, spriteName), circle(sf::CircleShape(R)),
	initX(X), initY(Y), initSpeedX(speedX), initSpeedY(speedY), speedX(speedX), speedY(speedY)
{
	circle.setOrigin(radius, radius);
	circle.setTexture(&sprite);
	circle.setPosition(posX - R, posY - R);
	setAngleWithSpeed();
	if (!speedX && !speedY) {
		angle = 0;
	}
}


Ship::~Ship()
{
}

void Ship::update(sf::RenderWindow & app)
{
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

void Ship::reset()
{
	posX = initX;
	posY = initY;
	speedX = initSpeedX;
	speedY = initSpeedY;
	setAngleWithSpeed();
	circle.setPosition(posX, posY);
	circle.setRotation(angle);
}

void Ship::move()
{
	posX += speedX;
	posY += speedY;
	setAngleWithSpeed();
	circle.setPosition(posX, posY);
	circle.setRotation(angle);
}

void Ship::setAngleWithSpeed()
{
	if (speedX > 0) {
		angle = RadToDeg(atan(speedY / speedX)) + 90;
	} else
	if (speedX < 0) {
		angle = RadToDeg(atan(speedY / speedX)) + 270;
	} else
	if (speedX == 0 && speedY != 0) {
		angle = 90 * (speedY / abs(speedY)) + 90;
	}
}

#include "blackHole.h"



BlackHole::BlackHole()
{
}

BlackHole::BlackHole(float X, float Y, float R, float M, float radiusCollOverRadius,std::string spriteName):
	SpaceEntity(X, Y, R, radiusCollOverRadius, spriteName), circle(sf::CircleShape(R)), mass(M), utility(false)
{
	circle.setTexture(&sprite);
}


BlackHole::~BlackHole()
{
}

void BlackHole::update(sf::RenderWindow & app)
{
	if (utility) {
		circle.setPosition(posX - radius, posY - radius);
		app.draw(circle);
		
	}
	/*
	sf::CircleShape cercle(radiusCollide);
	cercle.setPosition(posX - radiusCollide, posY - radiusCollide);
	app.draw(cercle);
	sf::RectangleShape rectangle(sf::Vector2f(radiusCollide, radiusCollide));
	rectangle.setFillColor(sf::Color(150, 0, 0));
	rectangle.setPosition(posX, posY);
	app.draw(rectangle);*/
}

void BlackHole::reset()
{
	utility = false;
}

void BlackHole::moveTo(float X, float Y)
{
	posX = X;
	posY = Y;
	utility = true;
}
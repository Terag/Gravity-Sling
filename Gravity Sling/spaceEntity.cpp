#include "spaceEntity.h"
#include <iostream>

SpaceEntity::SpaceEntity()
{
}

SpaceEntity::SpaceEntity(float X, float Y, float R, float radiusCollOverRadius, std::string spriteName) :
	posX(X), posY(Y), radius(R), radiusCollide(R*radiusCollOverRadius)
{
	imageSprite.loadFromFile(spriteName);
	if (!sprite.loadFromImage(imageSprite)) {
		std::cout << spriteName << " n'a pas été chargé correctement\n";
	}
}


SpaceEntity::~SpaceEntity()
{
}

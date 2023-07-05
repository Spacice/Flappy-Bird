#pragma once
#include "mySprite.h"
#include "boxCollider.h"

class wall
{
	boxCollider collider;
	mySprite up;
	mySprite down;
public:
	wall();
	wall(sf::String F);
	void init(sf::String F, unsigned short spanWidth);
	void setPosition(float x, float y);
	const boxCollider* const getCollider() { return &collider; }
	void draw(sf::RenderWindow *const window);
	void drawCollider(sf::RenderWindow* const window) { collider.draw(window); }
};


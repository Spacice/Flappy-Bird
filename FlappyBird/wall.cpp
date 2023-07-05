#include "wall.h"
#include <iostream>

wall::wall()
{
}

wall::wall(sf::String F)
{
	collider.setSize(sf::Vector2f(64, 192));

	sf::Image im;
	im.loadFromFile(F);
	im.createMaskFromColor(sf::Color(255, 255, 255));

	up.init(&im);
	up.setOrigin(up.getSize().x / 2.f, (float)(up.getSize().y - 1));

	im.flipVertically();
	down.init(&im);
	down.setOrigin(down.getSize().x / 2.f, 0);

	up.setPosition(500, 360 - collider.getSize().y / 2.f);
	collider.setPosition(500, 360);
	down.setPosition(500, 360 + collider.getSize().y / 2.f);
}

void wall::init(sf::String F, unsigned short spanWidth)
{
	collider.setSize(sf::Vector2f(64, spanWidth));

	sf::Image im;
	im.loadFromFile(F);
	im.createMaskFromColor(sf::Color(255, 255, 255));

	up.init(&im);
	up.setOrigin(up.getSize().x / 2.f, (float)(up.getSize().y - 1));

	im.flipVertically();
	down.init(&im);
	down.setOrigin(down.getSize().x / 2.f, 0);

	up.setPosition(500, 360 - collider.getSize().y / 2.f);
	collider.setPosition(500, 360);
	down.setPosition(500, 360 + collider.getSize().y / 2.f);
}

void wall::setPosition(float x, float y)
{
	up.setPosition(x, y - collider.getSize().y / 2.f);
	collider.setPosition(x, y);
	down.setPosition(x, y + collider.getSize().y / 2.f);
}

void wall::draw(sf::RenderWindow* const window)
{
	up.draw(window);
	down.draw(window);
}

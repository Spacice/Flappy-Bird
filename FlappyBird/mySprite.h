#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class mySprite
{
protected:
	sf::Texture tex;
	sf::Sprite spr;
public:
	mySprite();
	mySprite(sf::String F, bool isStartFromCenter, sf::Color mask);

	void init(sf::String F);
	void init(sf::Image *const I);

	void setOrigin(float x, float y)						{ spr.setOrigin(x, y); }

	void setPosition(sf::Vector2f newPosition)				{ spr.setPosition(newPosition); }
	void setPosition(float x, float y)						{ spr.setPosition(x, y); }

	sf::Vector2f getPosition()								{ return spr.getPosition(); }
	sf::Vector2u getSize()									{ return tex.getSize(); }

	void setRotation(float angle)							{ spr.setRotation(angle); }

	void draw(sf::RenderWindow* const window)				{ window->draw(spr); }
};


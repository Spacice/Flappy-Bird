#pragma once
#include <SFML/Graphics.hpp>

class boxCollider
{
	sf::RectangleShape box;
public:
	boxCollider();
	boxCollider(float x, float y, float width, float height);

	void setPosition(float x, float y)									{ box.setPosition(x, y); }
	void setPosition(sf::Vector2f newPosition)							{ box.setPosition(newPosition); }
	void setSize(float width, float height);
	void setSize(sf::Vector2f newSize);

	sf::Vector2f getPosition()											{ return box.getPosition(); }
	sf::Vector2f getSize()												{ return box.getSize(); }

	void draw(sf::RenderWindow* const window)							{ window->draw(box); }

	static bool checkBirdCollision(const boxCollider *const bird, const boxCollider *const tubeHole);
};


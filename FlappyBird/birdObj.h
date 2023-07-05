#pragma once
#include "mySprite.h"
#include "boxCollider.h"

class birdObj : public mySprite
{
private:
	float m_fallAcceleration;
	float m_verticalSpeed;

	float m_distance;
	float m_flySpeed;

	sf::Vector2f startScreenPosition;

	boxCollider collider;
public:
	birdObj();
	birdObj(sf::String F, sf::Color mask, float fallAcceleration);
	void init(sf::String F, sf::Color mask, float fallAcceleration);
	void update(float elepGameTime);
	void force(float value)												{ m_verticalSpeed += value; }
	void reset();

	const boxCollider* const getCollider()								{ return &collider; }

	void setFallSpeed(float value)										{ m_verticalSpeed = value; }
	void setFlySpeed(float value)										{ m_flySpeed = value; }
	
	//unsigned short getFlySpeed();
	float getDistance()													{ return m_distance; }
};


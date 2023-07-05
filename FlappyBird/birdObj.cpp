#include "birdObj.h"

birdObj::birdObj()
	: mySprite()
{
	m_fallAcceleration = 0.f;
	m_verticalSpeed = 0.f;
	m_distance = 0.f;
	m_flySpeed = 0.f;
	collider.setSize(sf::Vector2f(tex.getSize()));
	startScreenPosition = sf::Vector2f(0.f, 0.f);
}

birdObj::birdObj(sf::String F, sf::Color mask, float fallAcceleration)
	: mySprite(F, true, mask)
{
	m_distance = 0.f;
	m_flySpeed = 0.f;
	m_verticalSpeed = 0.f;
	m_fallAcceleration = fallAcceleration;
	collider.setSize(sf::Vector2f(tex.getSize()));
	startScreenPosition = sf::Vector2f(0.f, 0.f);
}

void birdObj::init(sf::String F, sf::Color mask, float fallAcceleration)
{
	sf::Image im;
	im.loadFromFile(F);
	im.createMaskFromColor(mask);
	tex.loadFromImage(im);
	spr.setTexture(tex);
	spr.setOrigin(spr.getTextureRect().width / 2.f, spr.getTextureRect().height / 2.f);
	m_fallAcceleration = fallAcceleration;
	collider.setSize(sf::Vector2f(tex.getSize()));
}

void birdObj::update(float elepGameTime)
{
	if (spr.getPosition().y > 719) {
		spr.setPosition(spr.getPosition().x, 720);
		m_verticalSpeed = 0.f;
	}
	else {
		m_verticalSpeed += m_fallAcceleration * elepGameTime;
		spr.move(0, m_verticalSpeed * elepGameTime);
		if (spr.getPosition().y < 0) {
			spr.setPosition(spr.getPosition().x, 0);
			m_verticalSpeed = 0.f;
		}
	}
	m_distance += m_flySpeed * elepGameTime;
	collider.setPosition(spr.getPosition());
}

void birdObj::reset()
{
	m_distance = 0.f;
	spr.setPosition(250, 100);//Hardcode
}

/*unsigned short birdObj::getFlySpeed()
{
	return m_flySpeed;
}*/


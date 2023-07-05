#include "boxCollider.h"

boxCollider::boxCollider()
{
	box.setPosition(0.f, 0.f);
	box.setSize(sf::Vector2f(0.f, 0.f));
	box.setFillColor(sf::Color(255, 255, 255, 255));
	box.setOrigin(box.getSize().x / 2.f, box.getSize().y / 2.f);
}

boxCollider::boxCollider(float x, float y, float width, float height)
	: boxCollider()
{
	box.setPosition(x, y);
	box.setSize(sf::Vector2f(width, height));
}

void boxCollider::setSize(float width, float height)
{
	box.setSize(sf::Vector2f(width, height));
	box.setOrigin(box.getSize().x / 2.f, box.getSize().y / 2.f);
}

void boxCollider::setSize(sf::Vector2f newSize)
{
	box.setSize(newSize);
	box.setOrigin(box.getSize().x / 2.f, box.getSize().y / 2.f);
}

bool boxCollider::checkBirdCollision(const boxCollider* const bird, const boxCollider* const tubeHole)
{
	if(bird != nullptr && tubeHole != nullptr)
		if (abs(bird->box.getPosition().x - tubeHole->box.getPosition().x) < (bird->box.getSize().x + tubeHole->box.getSize().x) / 2.f) {
		if (abs(bird->box.getPosition().y - tubeHole->box.getPosition().y) > abs(tubeHole->box.getSize().y - bird->box.getSize().y) / 2.f)
				return true;
		}
	return false;
}

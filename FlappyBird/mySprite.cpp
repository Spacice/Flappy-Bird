#include "mySprite.h"

mySprite::mySprite()
{
	/*sf::Image im;
	im.create(64, 64, Color(255, 255, 255));
	tex.loadFromImage(im);
	spr.setTexture(tex);*/
}

mySprite::mySprite(sf::String F, bool isStartFromCenter, sf::Color mask)
{
	sf::Image im;
	im.loadFromFile(F);
	im.createMaskFromColor(mask);
	tex.loadFromImage(im);
	spr.setTexture(tex);
	if (isStartFromCenter) spr.setOrigin(spr.getTextureRect().width / 2.f, spr.getTextureRect().height / 2.f);
}

void mySprite::init(sf::String F)
{
	sf::Image im;
	im.loadFromFile(F);
	im.createMaskFromColor(sf::Color(255, 255, 255));
	tex.loadFromImage(im);
	spr.setTexture(tex);
}

void mySprite::init(sf::Image* const I)
{
	tex.loadFromImage(*I);
	spr.setTextureRect(IntRect(Vector2i(0, 0), sf::Vector2i(tex.getSize())));
	spr.setTexture(tex);
}

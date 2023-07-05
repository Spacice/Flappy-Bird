#pragma once
#include <SFML/Graphics.hpp>
#include "mySprite.h"

#define NUM0_PATH "res/num0.png"
#define NUM1_PATH "res/num1.png"
#define NUM2_PATH "res/num2.png"
#define NUM3_PATH "res/num3.png"
#define NUM4_PATH "res/num4.png"
#define NUM5_PATH "res/num5.png"
#define NUM6_PATH "res/num6.png"
#define NUM7_PATH "res/num7.png"
#define NUM8_PATH "res/num8.png"
#define NUM9_PATH "res/num9.png"

class scoreboard
{
	const int DIGIT_WIDTH = 20;
	const int DIGIT_INTERVAL = 4;
	sf::Vector2f screenPosition;
	mySprite numSprs[10];

	unsigned int tens(const unsigned int zeros);
public:
	scoreboard();

	void setScreenPosition(sf::Vector2f position);
	sf::Vector2f getScreenPosition();

	void draw(sf::RenderWindow* const window, unsigned int value);
};


#include "scoreboard.h"

unsigned int scoreboard::tens(const unsigned int zeros)
{
	unsigned int result = 1;
	for (int i = 0; i < zeros; i++)
		result *= 10;
	return result;
}

scoreboard::scoreboard()
{
	screenPosition = sf::Vector2f(640, 100);
	numSprs[0].init(NUM0_PATH);
	numSprs[1].init(NUM1_PATH);
	numSprs[2].init(NUM2_PATH);
	numSprs[3].init(NUM3_PATH);
	numSprs[4].init(NUM4_PATH);
	numSprs[5].init(NUM5_PATH);
	numSprs[6].init(NUM6_PATH);
	numSprs[7].init(NUM7_PATH);
	numSprs[8].init(NUM8_PATH);
	numSprs[9].init(NUM9_PATH);
}

void scoreboard::setScreenPosition(sf::Vector2f position)
{
	this->screenPosition = position;
}

sf::Vector2f scoreboard::getScreenPosition()
{
	return this->screenPosition;
}

void scoreboard::draw(sf::RenderWindow* const window, unsigned int value)
{
	unsigned short digitCount = 1;
	while (value / tens(digitCount) != 0)
		digitCount++;

	float center = digitCount * (DIGIT_WIDTH / 2 + DIGIT_INTERVAL) / 2 - DIGIT_INTERVAL;

	while (digitCount) {
		unsigned short num = int(value / tens(digitCount - 1)) % 10;
		numSprs[num].setPosition(screenPosition - sf::Vector2f((digitCount - 1) * (DIGIT_WIDTH + DIGIT_INTERVAL) - center, 0.f));
		numSprs[num].draw(window);
		digitCount--;
	}
}

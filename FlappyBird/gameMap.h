#pragma once
#include "wall.h"
#include <vector>

#define TUBE_PATH "res/tube.png"

class gameMap
{
	std::vector<short> heightList;
	wall tube;

	float distanceOfBird;

	int differenceHeight;//Разница высот пролёта
	unsigned short spanWidth;//Ширина дырки
	unsigned short wallInterval;//Растояние между парами труб
	unsigned short firstTubeDistance;//Расстояние начала карты труб от начала координат
	unsigned short startLevelPosition;//Нулевой уровень, относительно которого распологаются трубы по высоте

	//Hardcode :)
	const int birdWidth = 32;
	const int tubeWidth = 32;
public:
	gameMap();
	gameMap(unsigned int size);
	void init(unsigned int size, int differenceHeight, unsigned short spanWidth, unsigned short wallInterval, unsigned short firstTubeDistance);
	void generate(unsigned int size);
	void setBirdDistance(float value)									{ distanceOfBird = value; }
	const void* const getCollider(sf::RenderWindow* const window);
	void draw(sf::RenderWindow *const window);

	const unsigned short getWallInterval() { return wallInterval; }
	const unsigned short getFirstTubeDistance() { return firstTubeDistance; }

	~gameMap()															{ heightList.clear(); }
};


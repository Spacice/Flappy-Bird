#include "gameMap.h"
//#include <iostream>

gameMap::gameMap()
{
	distanceOfBird = 0;

	differenceHeight = 100;
	spanWidth = 192;
	wallInterval = 200;
	firstTubeDistance = 500;
	startLevelPosition = 360;

	srand((unsigned)time(0));
	tube.init(TUBE_PATH, spanWidth);
}

gameMap::gameMap(unsigned int size)
	:gameMap()
{
	heightList.reserve(size);
	for (unsigned int i = 0; i < size; i++) {
		heightList.push_back((short)((rand() % differenceHeight) - differenceHeight / 2));
	}
}

void gameMap::init(unsigned int size, int differenceHeight, unsigned short spanWidth, unsigned short wallInterval, unsigned short firstTubeDistance)
{
	this->generate(size);
	this->differenceHeight = differenceHeight;
	this->spanWidth = spanWidth;
	this->wallInterval = wallInterval;
	this->firstTubeDistance = firstTubeDistance;
	tube.init(TUBE_PATH, spanWidth);
}

void gameMap::generate(unsigned int size)
{
	heightList.clear();
	heightList.reserve(size);
	for (unsigned int i = 0; i < size; i++) {
		heightList.push_back((short)((rand() % differenceHeight) - differenceHeight / 2));
	}
}

const void* const gameMap::getCollider(sf::RenderWindow* const window)
{
	//TODO переделать
	int index = (((int)distanceOfBird - (firstTubeDistance - 250) + wallInterval - birdWidth - tubeWidth) / wallInterval);
	//std::cout << index << std::endl;
	if (index >= 0 && index < (int)heightList.size()) {
		tube.setPosition(firstTubeDistance - distanceOfBird + index * wallInterval, (float)(heightList[index] + startLevelPosition));
		//tube.drawCollider(window);
		return tube.getCollider();
	}
	return nullptr;
}

//const sf::RectangleShape* const gameMap::getNearbybBoxCollider()
//{
//	int index = (distanceOfBird - firstTubeDistance + tube.getBoxCollider()->getSize().x / 2.f + 32 + wallInterval) / wallInterval;
//	if (index < heightList.size() && index >= 0) {
//		tube.setPosition(firstTubeDistance - distanceOfBird + index * wallInterval, heightList[index] + startLevelPosition);
//		return tube.getBoxCollider();
//	}
//	return nullptr;
//}

void gameMap::draw(sf::RenderWindow* const window)
{
	for (int i = 0; i < (int)heightList.size(); i++) {
		if (firstTubeDistance - distanceOfBird + i * wallInterval + 32 > 0 && firstTubeDistance - distanceOfBird + i * wallInterval - 32 < 1280) {
			tube.setPosition(firstTubeDistance - distanceOfBird + i * wallInterval, (float)(heightList[i] + startLevelPosition));
			tube.draw(window);
		}
	}
}

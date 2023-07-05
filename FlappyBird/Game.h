#pragma once
#include "gameMap.h"
#include "birdObj.h"
#include "scoreboard.h"

#define BIRD_PATH "res/bird.png"

class Game
{
	unsigned short state;//0 - starting, 1 - playing, 2 - game over
	sf::Vector2f spawnBirdPoint;//Позиция птицы на экране
	gameMap tubeMap;
	birdObj bird;
	scoreboard sb;
	int score;
public:
	enum gameStates {
		STARTING,
		PLAYING,
		GAMEOVER
	};
	Game();

	void startGame();
	unsigned short getGameState()								{ return state; }
	void jump();
	sf::Vector2f getBirdPosition()								{ return bird.getPosition() + sf::Vector2f(bird.getDistance(), 0) - sf::Vector2f(spawnBirdPoint.x, 0); }
	sf::Vector2f getBirdScreenPosition()						{ return bird.getPosition(); }

	void update(float elepTime, sf::RenderWindow* const window);
	void draw(sf::RenderWindow *const window);
};


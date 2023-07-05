#include "Game.h"
#include "boxCollider.h"
#include <iostream>
//#include <algorithm>

Game::Game()
{
	bird.init(BIRD_PATH, Color(255, 255, 255), 0.002f);
	bird.setPosition(250, 100);
	bird.setFlySpeed(0.15f);

	tubeMap.generate(1000);
	state = STARTING;
	std::cout << "Done" << std::endl;
}

void Game::startGame()
{
	if (state == GAMEOVER) {
		state = STARTING;
		std::cout << "Get ready" << std::endl;
	}
}

void Game::jump()
{
	if(state == PLAYING)
		bird.setFallSpeed(-0.5);
	else if (state == STARTING) {
		state = PLAYING;
		bird.setFallSpeed(-0.5);
		std::cout << "Go!" << std::endl;
	}
}

void Game::update(float elepTime, sf::RenderWindow* const window)
{
	switch (state)
	{
	case STARTING:
		bird.reset();
		tubeMap.setBirdDistance(0.f);
		break;
	case PLAYING:
		bird.update(elepTime);
		tubeMap.setBirdDistance(bird.getDistance());
		//tubeMap.getCollider(window);
		if (boxCollider::checkBirdCollision(bird.getCollider(), (boxCollider*)tubeMap.getCollider(window))) {
			state = GAMEOVER;
			std::cout << "You dead :(" << std::endl;
		}
		score = std::max((bird.getDistance() - 64 - 64) / tubeMap.getWallInterval(), 0.f);
		break;
	case GAMEOVER:
		bird.update(elepTime);
		break;
	default:
		break;
	}
}

void Game::draw(sf::RenderWindow* const window)
{
	tubeMap.draw(window);
	bird.draw(window);
	sb.draw(window, score);
}

#include <SFML/Graphics.hpp>
#include "Game.h"

#include <iostream>

using namespace sf;

int main() {
	std::cout << "Loading...";
	RenderWindow window(VideoMode(1280, 720), "Flappy Bird");
	window.setVerticalSyncEnabled(true);
	Game thisGame;
	thisGame.startGame();

	Clock gclk;
	bool pressed = false;

	while (window.isOpen())
	{
		float gameTime = gclk.getElapsedTime().asMicroseconds() / 1000.f;
		gclk.restart();
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed)
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
					thisGame.startGame();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (!pressed) {
				thisGame.jump();
				pressed = true;
			}
		}
		else pressed = false;

		//std::cout << thisGame.getBirdPosition().x << std::endl;

		window.clear(Color(255, 255, 255));
		thisGame.update(gameTime, &window);
		thisGame.draw(&window);
		window.display();
	}
	return 0;
}
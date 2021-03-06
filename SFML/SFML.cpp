#include "stdafx.h"
#include <omp.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "define.h"
#include "particle.h"
#include "cloud.h"

using namespace sf;

int main() {
	RenderWindow win(VideoMode(W_WIDTH, W_HEIGHT), "Particles", STYLE);
	win.setVerticalSyncEnabled(true);

	Clock clock;
	clock.restart();

	Cloud cloud;

	float dt = 0.0f;

	while (win.isOpen()) {
		Event event;
		while (win.pollEvent(event)) {
			if (event.type == Event::Closed)
				win.close();
			if (event.type == Event::KeyPressed) {
				switch (event.key.code) {
				case Keyboard::Escape:
					win.close();
					break;
				}
			}
		}

		dt = clock.getElapsedTime().asSeconds();
		std::cout << round(1 / dt) << "FPS" << std::endl;
		clock.restart();

		win.clear();
		cloud.main(win, Mouse::isButtonPressed(Mouse::Left), Mouse::getPosition(win), dt);
		win.display();
	}
}


#include "../ctr/healthController.h"
#include <iostream>

healthController::healthController() {

}

void healthController::setHealthFont() {
	if (!healthFontFamily.loadFromFile("./res/fonts/INVADERS.TTF")) {
		healthFontFamily.loadFromFile("./res/arial.ttf");
		std::cout << "[SpaceInvadersConsole->Error] 'INVADERS.TTF' font file not found in /res/fonts/ - switching to default font." << std::endl;
	}
}

void healthController::dispHealthText() {
	healthDispText.setFont(healthFontFamily);
	healthDispText.setFillColor(sf::Color::Red);
	healthDispText.setPosition(sf::Vector2f(0.0f, 680.0f));
	healthDispText.setCharacterSize(35);
}

void healthController::tickUpdateHealth(int &health) {
	if (health == 3)
	{
		healthDispText.setString("|||");
	}
	else if (health == 2) {
		healthDispText.setString("||");
	}
	else if (health == 1) {
		healthDispText.setString("|");
	}
	else if (health == 0) {
		healthDispText.setString("");
	}
}

healthController::~healthController() {

}
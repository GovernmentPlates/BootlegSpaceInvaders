#include "../ctr/environmentController.h"

void environmentController::setBackgroundImage() {
	if (!bgImageTexture.loadFromFile("./res/bgspaceinvaders.png")) {
		bgImageTexture.loadFromFile("./res/bgerror.png");
		bgImageSprite.setTexture(bgImageTexture);
	}
	else {
		bgImageSprite.setTexture(bgImageTexture);
	}

	bgImageSprite.setScale(0.7, 0.7);
}

void environmentController::genWindow(sf::RenderWindow &siWindow) { 
	siWindow.setFramerateLimit(60);
	siWindow.setPosition(sf::Vector2i(100, 100));
	siWindow.setMouseCursorVisible(false);
}
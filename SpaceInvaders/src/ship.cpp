#include "../inc/laser.h"
#include "../inc/ship.h"

sf::Texture shipTexture;

Ship::Ship() {

}

void Ship::genShip(sf::Sprite &shipSprite) {
	if (!shipTexture.loadFromFile("./res/ship.png")) {
		shipTexture.loadFromFile("./res/error.png");
	}
	else {
		shipSprite.setScale(sf::Vector2f(0.2f, 0.2f));
	}

	shipSprite.setPosition(sf::Vector2f(1280/2,650));
	shipSprite.setOrigin(shipTexture.getSize().x / 2.0f, shipTexture.getSize().y / 2.0f);
	shipSprite.setTexture(shipTexture);
}

bool Ship::checkDeathCondition() {
	if (shipDrawn) {
		if (shipDrawn && shipHealth == 0) {
			return true;
		}
		else {
			return false;
		}
	}
}

Ship::~Ship() {

}
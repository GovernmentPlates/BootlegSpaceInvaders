#include "../ctr/collisionController.h"
#include "../ctr/environmentController.h"
#include <iostream>

void collisionController::collisionShipScreenBounds(sf::Sprite &entity) {
	if (entity.getPosition().x >= 1280) {
		entity.move(-20.f, 0.f);
	}
	else if (entity.getPosition().x <= 50) {
		entity.move(20.f, 0.f);
	}
}

void collisionController::collisionLaserShield(sf::Sprite &laserSprite, sf::Sprite &shieldSprite, bool &laserDrawnOnScreen, bool &shieldDrawn, Shield &shield, Laser &laser) {
	if (laserSprite.getGlobalBounds().intersects(shieldSprite.getGlobalBounds())) {
		laserSprite.setPosition(sf::Vector2f(-200.f, 0.f));
		shield.shieldDamageLvl++;
		shield.updateShieldState(shieldSprite, shield.shieldDamageLvl);
		laserDrawnOnScreen = false;
	}

	if (shield.shieldDamageLvl == 3) {
		shield.shieldDrawn = false;
		shieldSprite.setPosition(sf::Vector2f(-50.f, 0.f));
		shield.shieldDamageLvl == 0;
	}
}

void collisionController::collisionInvaderLaserShip(sf::Sprite &laserInvaderSprite, sf::Sprite &shipSprite, bool &invaderDrawn, bool &shipDrawn, Ship &ship) {
	if (laserInvaderSprite.getGlobalBounds().intersects(shipSprite.getGlobalBounds())) {
		shipDrawn, invaderDrawn = false;
		laserInvaderSprite.setPosition(sf::Vector2f(-100.0f, 0.f));
		shipDrawn = true, ship.shipHealth--;
		shipSprite.setPosition(sf::Vector2f(1280 / 2, 650));
	}
}

void collisionController::collisionLaserInvader(sf::Sprite &laserSprite, sf::Sprite &invaderSprite, bool &laserDrawnOnScreen, bool &invaderDrawn, scoreController &scoreController) {
	if (laserSprite.getGlobalBounds().intersects(invaderSprite.getGlobalBounds())) {
		laserDrawnOnScreen, invaderDrawn = false;
		laserSprite.setPosition(sf::Vector2f(0.f, 0.f));
		invaderSprite.setPosition(sf::Vector2f(-500.f, 0.f));
		scoreController.sessionScore++;
	}
}
#pragma once
#ifndef COLLISIONCONTROLLER_H 
#define COLLISIONCONTROLLER_H
#include "SFML/Graphics.hpp"
#include "../inc/ship.h"
#include "../inc/laser.h"
#include "../inc/shield.h"
#include "../ctr/scoreController.h"

class collisionController {
public:
	void collisionShipScreenBounds(sf::Sprite &entity);

	void collisionLaserInvader(sf::Sprite &laserSprite, sf::Sprite &invaderSprite, bool &laserDrawnOnScreen, bool &invaderDrawn, scoreController &scoreController);

	void collisionLaserShield(sf::Sprite &laserSprite, sf::Sprite &shieldSprite, bool &laserDrawnOnScreen, bool &shieldDrawn, Shield &shield, Laser &laser);

	void collisionInvaderLaserShip(sf::Sprite &laserInvaderSprite, sf::Sprite &shipSprite, bool &invaderDrawn, bool &shipDrawn, Ship &ship);

};

#endif
#pragma once
#ifndef LASER_H
#define LASER_H
#include "SFML/Graphics.hpp"
#include "../inc/ship.h"

class Laser {
public:
	Laser();
	~Laser();
	void genLaser(sf::Sprite &laserShipSprite);
	void genInvaderLaser(sf::Sprite &laserInvaderSprite);
	void fireLaser(sf::Sprite &entity, sf::Sprite &laserSprite, bool &laserDrawnOnScreen);

	bool laserDrawnOnScreen = false;
	bool invaderLaserDrawn = false;
};
#endif
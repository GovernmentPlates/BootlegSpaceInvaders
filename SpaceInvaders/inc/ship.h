#pragma once
#ifndef SHIP_H
#define SHIP_H
#include "SFML/Graphics.hpp"

class Ship {
public:
	Ship();
	~Ship();
	void genShip(sf::Sprite &shipSprite);
	bool checkDeathCondition();

	bool shipDrawn = true;
	int shipHealth = 3;
};

#endif
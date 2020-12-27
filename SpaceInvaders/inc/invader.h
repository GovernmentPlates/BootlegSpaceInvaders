#pragma once
#ifndef INVADER_H
#define INVADER_H

#include "SFML/Graphics.hpp"
#include "../inc/ship.h"

class Invader {
public:
	Invader();
	~Invader();
	void genInvaderRow1(sf::Sprite &invaderSprite, int invX, int invY);
	void genInvaderRow2(sf::Sprite &invaderSprite, int invX, int invY);
	void genInvaderRow3(sf::Sprite &invaderSprite, int invX, int invY);
	void onMoveInvader(sf::Sprite &invaderSprite);
	void moveInvaderDown(sf::Sprite &invaderSprite);
	bool invaderDrawn = true;
	bool stateInvaderMoveDownScreen = false;
	void checkFallPos(Ship &ship);
	int posInvaderMoved = 0;
	int descendDown = 0;
	int timesDescended = 0;

};

#endif
#include "../inc/invader.h"
#include <iostream>

Invader::Invader() {

}

sf::Texture invaderCrab;

void Invader::genInvaderRow1(sf::Sprite &invaderSprite, int invX, int invY) {
	if (!invaderCrab.loadFromFile("./res/invaderCrab.png")) {
		invaderCrab.loadFromFile("./res/error.png");
	}
	else {
		invaderSprite.setTexture(invaderCrab);
		invaderSprite.setScale(sf::Vector2f(0.2f, 0.2f));
	}

	invaderSprite.setOrigin(650.0f / 2, 650.0f / 2);
	invaderSprite.setPosition(invX, invY);
}

sf::Texture invaderSquid;

void Invader::genInvaderRow2(sf::Sprite &invaderSprite, int invX, int invY) {
	if (!invaderSquid.loadFromFile("./res/invaderSquid.png")) {
		invaderSquid.loadFromFile("./res/error.png");
	}
	else {
		invaderSprite.setTexture(invaderSquid);
		invaderSprite.setScale(sf::Vector2f(0.2f, 0.2f));
	}

	invaderSprite.setOrigin(650.0f / 2, 650.0f / 2);
	invaderSprite.setPosition(invX, invY);
}

sf::Texture invaderOctopus;

void Invader::genInvaderRow3(sf::Sprite &invaderSprite, int invX, int invY) {
	if (!invaderOctopus.loadFromFile("./res/invaderOctopus.png")) {
		invaderOctopus.loadFromFile("./res/error.png");
	}
	else {
		invaderSprite.setTexture(invaderOctopus);
		invaderSprite.setScale(sf::Vector2f(0.2f, 0.2f));
	}

	invaderSprite.setOrigin(650.0f / 2, 650.0f / 2);
	invaderSprite.setPosition(invX, invY);
}


void Invader::onMoveInvader(sf::Sprite &invaderSprite) {
	if (posInvaderMoved == 32) {
		stateInvaderMoveDownScreen = true;
	}
	else if (posInvaderMoved == -6) {
		stateInvaderMoveDownScreen = false;
	}


	if (stateInvaderMoveDownScreen) {
		invaderSprite.move(-20.f, 0.f);
		posInvaderMoved--, descendDown++;
	} 
	else if (!stateInvaderMoveDownScreen) {
		invaderSprite.move(20.f, 0.f);
		posInvaderMoved++, descendDown++;
	}
}


void Invader::checkFallPos(Ship &ship) {
	if (timesDescended ==  5) {
		ship.shipHealth = 0;
	}
}


void Invader::moveInvaderDown(sf::Sprite &invaderSprite) {
	if (descendDown == 12) {
		invaderSprite.move(0.f, 35.f);
		timesDescended++, descendDown = 0;
	}
}

Invader::~Invader() {

}
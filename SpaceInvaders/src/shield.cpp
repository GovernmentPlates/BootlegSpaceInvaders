#include "../ctr/environmentController.h"
#include "../inc/shield.h"
#include <iostream>

sf::Texture shieldTexture;
sf::Texture shieldDamageState1;
sf::Texture shieldDamageState2;


Shield::Shield() {

}

void Shield::genShield(sf::Sprite &shieldSprite, int shdPosX) {
	if (!shieldTexture.loadFromFile("./res/shield.png")) {
		shieldTexture.loadFromFile("./res/error.png");
	}
	else {
		shieldTexture.setRepeated(true);
	}

	shieldSprite.setPosition(sf::Vector2f(shdPosX, 500.f));
	shieldSprite.setTextureRect(sf::IntRect(0, 0, 200, 20));
	shieldSprite.setOrigin(200.0f / 2, 20.0f / 2);
	shieldSprite.setTexture(shieldTexture);
}

void Shield::updateShieldState(sf::Sprite &shieldSprite, int shieldDamageLvl) {
	if (shieldDamageLvl == 1) {
		shieldDamageState1.loadFromFile("./res/shielddamageState1.png");
		shieldSprite.setTexture(shieldDamageState1);
	}

	if (shieldDamageLvl == 2) {
		shieldDamageState2.loadFromFile("./res/shielddamageState2.png");
		shieldSprite.setTexture(shieldDamageState2);
	}
}

Shield::~Shield() {

}
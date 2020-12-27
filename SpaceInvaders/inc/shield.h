#pragma once
#ifndef SHIELD_H
#define SHIELD_H
#include "SFML/Graphics.hpp"

class Shield {
public:
	Shield();
	~Shield();
	void genShield(sf::Sprite &shieldSprite, int shdPosX);
	void updateShieldState(sf::Sprite &shieldSprite, int shieldDamageLvl);
	bool shieldDrawn = true;
	int shieldDamageLvl = 0;
};

#endif

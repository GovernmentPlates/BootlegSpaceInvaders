#pragma once
#ifndef HEALTHCONTROLLER_H
#define HEALTHCONTROLLER_H
#include "SFML/Graphics.hpp"

class healthController {
public:
	healthController();
	~healthController();
	sf::Font healthFontFamily;
	void setHealthFont();

	sf::Text healthDispText;

	void tickUpdateHealth(int &health);
	void dispHealthText();
};

#endif
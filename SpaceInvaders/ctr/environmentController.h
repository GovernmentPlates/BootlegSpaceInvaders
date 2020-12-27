#pragma once
#ifndef ENVIRONMENTCONTROLLER_H
#define ENVIRONMENTCONTROLLER_H
#include "SFML/Graphics.hpp"
#include <iostream>

class environmentController {
public:
	void genWindow(sf::RenderWindow &siWindow);
	void setBackgroundImage();
	sf::Texture bgImageTexture;
	sf::Sprite bgImageSprite;
};

#endif
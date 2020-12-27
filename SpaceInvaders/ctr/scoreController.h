#pragma once
#ifndef SCORECONTROLLER_H
#define SCORECONTROLLER_H
#include "SFML/Graphics.hpp"

class scoreController {
public:
	scoreController();
	~scoreController();
	int sessionScore = 0;

	sf::Font scoreFontFamily;
	void setScoreFont();

	sf::Text scoreDispText, healthDispText, winDispText, loseDispText;
	void dispScoreText();
	void tickUpdateScore();
	void dispWinText();
	void dispLoseText();
	void dispGameResult();
};

#endif
#include "../ctr/scoreController.h"
#include <iostream>

scoreController::scoreController() {

}

void scoreController::setScoreFont() {
	if (!scoreFontFamily.loadFromFile("./res/fonts/ARCADE_I.TTF")) {
		scoreFontFamily.loadFromFile("./res/arial.ttf");
		std::cout << "[SpaceInvaders] 'ARCADE_I.ttf' font file not found in /res/fonts/ - switching to default font...\n" << std::endl;
	}
}

void scoreController::dispScoreText() {
	scoreDispText.setFont(scoreFontFamily);
	scoreDispText.setPosition(sf::Vector2f(0.0f, 0.0f));
	scoreDispText.setCharacterSize(40);
}

void scoreController::tickUpdateScore() {
	std::string sScore = std::to_string(sessionScore);
	scoreDispText.setString("Score: " + sScore);
}

void scoreController::dispWinText() {
	winDispText.setFont(scoreFontFamily);
	winDispText.setPosition(sf::Vector2f(640 / 2, 360 / 2));
	winDispText.setFillColor(sf::Color::White);
	winDispText.setCharacterSize(30);
}

void scoreController::dispLoseText() {
	loseDispText.setFont(scoreFontFamily);
	loseDispText.setPosition(sf::Vector2f(640 / 2, 640 / 2));
	loseDispText.setFillColor(sf::Color::Magenta);
	loseDispText.setCharacterSize(30);
}

void scoreController::dispGameResult() {
	std::string sScore = std::to_string(sessionScore);
	winDispText.setString("You've won! Session Score: " + sScore + "\n     Thanks for playing.");
	loseDispText.setString("\n\n\nYou've lost - the Invaders won.\n     Session Score: " + sScore + "\n     Thanks for playing.");
}

scoreController::~scoreController() {

}
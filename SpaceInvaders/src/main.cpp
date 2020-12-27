#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "../ctr/environmentController.h"
#include "../ctr/collisionController.h"
#include "../ctr/healthController.h"
#include "../inc/ship.h"
#include "../inc/laser.h"
#include "../inc/shield.h"
#include "../inc/invader.h"
#include <iostream>
#include <time.h>
#include <random>

const float laserShootSpeed = -10;

int main() {
	environmentController environmentController;
	sf::RenderWindow siWindow(sf::VideoMode(1280, 720), "Bootleg Space Invaders", sf::Style::Titlebar | sf::Style::Close);
	environmentController.setBackgroundImage();

	collisionController collisionController;

	Ship Ship;
	sf::Sprite shipSprite;
	Ship.genShip(shipSprite);

	scoreController scoreController;
	scoreController.setScoreFont();
	scoreController.dispScoreText();
	scoreController.dispGameResult();
	scoreController.dispWinText();
	scoreController.dispLoseText();

	healthController healthController;
	healthController.setHealthFont();
	healthController.dispHealthText();

	Laser Laser, laserInvader;
	sf::Sprite laserSprite, laserInvaderSprite;
	Laser.genLaser(laserSprite);
	Laser.genInvaderLaser(laserInvaderSprite);

	Invader invader1;
	Invader invader2;
	Invader invader3;
	Invader invader4;
	Invader invader5;
	Invader invader6;
	Invader invader7;
	Invader invader8;
	Invader invader9;
	Invader invader10;
	Invader invader11;
	Invader invader12;
	Invader invader13;
	Invader invader14;
	Invader invader15;

	sf::Sprite invaderSprite;
	sf::Sprite invaderSprite2;
	sf::Sprite invaderSprite3;
	sf::Sprite invaderSprite4;
	sf::Sprite invaderSprite5;
	sf::Sprite invaderSprite6;
	sf::Sprite invaderSprite7;
	sf::Sprite invaderSprite8;
	sf::Sprite invaderSprite9;
	sf::Sprite invaderSprite10;
	sf::Sprite invaderSprite11;
	sf::Sprite invaderSprite12;
	sf::Sprite invaderSprite13;
	sf::Sprite invaderSprite14;
	sf::Sprite invaderSprite15;

	invader1.genInvaderRow1(invaderSprite, 200, 200);
	invader2.genInvaderRow1(invaderSprite2, 300, 200);
	invader3.genInvaderRow1(invaderSprite3, 400, 200);
	invader4.genInvaderRow1(invaderSprite4, 500, 200);
	invader5.genInvaderRow1(invaderSprite5, 600, 200);

	invader6.genInvaderRow2(invaderSprite6, 200, 275);
	invader7.genInvaderRow2(invaderSprite7, 300, 275);
	invader8.genInvaderRow2(invaderSprite8, 400, 275);
	invader9.genInvaderRow2(invaderSprite9, 500, 275);
	invader10.genInvaderRow2(invaderSprite10, 600, 275);

	invader11.genInvaderRow3(invaderSprite11, 200, 350);
	invader12.genInvaderRow3(invaderSprite12, 300, 350);
	invader13.genInvaderRow3(invaderSprite13, 400, 350);
	invader14.genInvaderRow3(invaderSprite14, 500, 350);
	invader15.genInvaderRow3(invaderSprite15, 600, 350);

	Shield Shield1;
	Shield Shield2;
	Shield Shield3;

	sf::Sprite shieldSprite;
	sf::Sprite shieldSprite2;
	sf::Sprite shieldSprite3;

	Shield1.genShield(shieldSprite, 200);
	Shield2.genShield(shieldSprite2, 1280 / 2);
	Shield3.genShield(shieldSprite3, 1280 - 200);

	environmentController.genWindow(siWindow);

	sf::SoundBuffer shipBuffer;
	sf::Sound fireSFX;
	fireSFX.setBuffer(shipBuffer);
	fireSFX.setVolume(100);

	if (!shipBuffer.loadFromFile("./res/sfx/fire.ogg")) {
		std::cout << "[SpaceInvaders] Could not load /res/sfx/fire.ogg\n";
	}

	sf::Clock timer;



	while (siWindow.isOpen())
	{
	
		sf::Event onEvent;
		while (siWindow.pollEvent(onEvent)) {

			if (onEvent.type == sf::Event::Closed) {
				siWindow.close();
			}

			if (!(scoreController.sessionScore == 4 && Ship.shipHealth == 0)) {

				if (onEvent.type == sf::Event::KeyPressed) {
					
					if (onEvent.key.code == sf::Keyboard::Left) {
						shipSprite.move(-20.f, 0.f);
					}

					if (onEvent.key.code == sf::Keyboard::Right) {
						shipSprite.move(20.f, 0.f);
					}

					if (onEvent.key.code == sf::Keyboard::Space) {
						fireSFX.play();
						Laser.fireLaser(shipSprite, laserSprite, Laser.laserDrawnOnScreen);
					}


				}
			}

		}

		siWindow.draw(environmentController.bgImageSprite);
		Ship.checkDeathCondition();

		if (Ship.checkDeathCondition()) {
			Ship.shipDrawn = false;
			healthController.tickUpdateHealth(Ship.shipHealth);
		}
		else if (!(Ship.checkDeathCondition())) {
			Ship.shipDrawn = true;
			healthController.tickUpdateHealth(Ship.shipHealth);
		}

		scoreController.tickUpdateScore();
		healthController.tickUpdateHealth(Ship.shipHealth);
		scoreController.dispGameResult();

		siWindow.draw(scoreController.scoreDispText);
		siWindow.draw(healthController.healthDispText);

		invader1.checkFallPos(Ship);
		invader2.checkFallPos(Ship);
		invader3.checkFallPos(Ship);
		invader4.checkFallPos(Ship);
		invader5.checkFallPos(Ship);
		invader6.checkFallPos(Ship);
		invader7.checkFallPos(Ship);
		invader8.checkFallPos(Ship);
		invader9.checkFallPos(Ship);
		invader10.checkFallPos(Ship);
		invader11.checkFallPos(Ship);
		invader12.checkFallPos(Ship);
		invader13.checkFallPos(Ship);
		invader14.checkFallPos(Ship);
		invader15.checkFallPos(Ship);

		if (scoreController.sessionScore == 15) {
			siWindow.draw(scoreController.winDispText);
		}
		else if (Ship.shipHealth == 0) {
			siWindow.draw(scoreController.loseDispText);
			invader1.invaderDrawn = false, invader2.invaderDrawn = false, invader3.invaderDrawn = false, invader4.invaderDrawn = false, invader5.invaderDrawn = false, invader6.invaderDrawn = false, invader7.invaderDrawn = false, invader8.invaderDrawn = false, invader9.invaderDrawn = false, invader10.invaderDrawn = false, invader11.invaderDrawn = false, invader12.invaderDrawn = false, invader13.invaderDrawn = false, invader14.invaderDrawn = false, invader15.invaderDrawn = false;
		}

		if (Ship.shipDrawn) {
			siWindow.draw(shipSprite);
			collisionController.collisionShipScreenBounds(shipSprite);
		}

		if (invader1.invaderDrawn) {
			siWindow.draw(invaderSprite);
		}

		if (invader2.invaderDrawn) {
			siWindow.draw(invaderSprite2);
		}

		if (invader3.invaderDrawn) {
			siWindow.draw(invaderSprite3);
		}

		if (invader4.invaderDrawn) {
			siWindow.draw(invaderSprite4);
		}

		if (invader5.invaderDrawn) {
			siWindow.draw(invaderSprite5);
		}

		if (invader6.invaderDrawn) {
			siWindow.draw(invaderSprite6);
		}

		if (invader7.invaderDrawn) {
			siWindow.draw(invaderSprite7);
		}

		if (invader8.invaderDrawn) {
			siWindow.draw(invaderSprite8);
		}

		if (invader9.invaderDrawn) {
			siWindow.draw(invaderSprite9);
		}

		if (invader10.invaderDrawn) {
			siWindow.draw(invaderSprite10);
		}

		if (invader11.invaderDrawn) {
			siWindow.draw(invaderSprite11);
		}

		if (invader12.invaderDrawn) {
			siWindow.draw(invaderSprite12);
		}

		if (invader13.invaderDrawn) {
			siWindow.draw(invaderSprite13);
		}

		if (invader14.invaderDrawn) {
			siWindow.draw(invaderSprite14);
		}

		if (invader15.invaderDrawn) {
			siWindow.draw(invaderSprite15);
		}

		if (Shield1.shieldDrawn) {
			siWindow.draw(shieldSprite);
		}

		if (Shield2.shieldDrawn) {
			siWindow.draw(shieldSprite2);
		}

		if (Shield3.shieldDrawn) {
			siWindow.draw(shieldSprite3);
		}

		if (Laser.laserDrawnOnScreen) {
			siWindow.draw(laserSprite);
			laserSprite.move(0.f, laserShootSpeed);
		}

		if (Laser.invaderLaserDrawn) {
			siWindow.draw(laserInvaderSprite);
			laserInvaderSprite.move(0.f, -laserShootSpeed);
		}

	
		collisionController.collisionLaserInvader(laserSprite, invaderSprite, Laser.laserDrawnOnScreen, invader1.invaderDrawn, scoreController);
		collisionController.collisionLaserInvader(laserSprite, invaderSprite2, Laser.laserDrawnOnScreen, invader2.invaderDrawn, scoreController);
		collisionController.collisionLaserInvader(laserSprite, invaderSprite3, Laser.laserDrawnOnScreen, invader3.invaderDrawn, scoreController);
		collisionController.collisionLaserInvader(laserSprite, invaderSprite4, Laser.laserDrawnOnScreen, invader4.invaderDrawn, scoreController);
		collisionController.collisionLaserInvader(laserSprite, invaderSprite5, Laser.laserDrawnOnScreen, invader5.invaderDrawn, scoreController);
		collisionController.collisionLaserInvader(laserSprite, invaderSprite6, Laser.laserDrawnOnScreen, invader6.invaderDrawn, scoreController);
		collisionController.collisionLaserInvader(laserSprite, invaderSprite7, Laser.laserDrawnOnScreen, invader7.invaderDrawn, scoreController);
		collisionController.collisionLaserInvader(laserSprite, invaderSprite8, Laser.laserDrawnOnScreen, invader8.invaderDrawn, scoreController);
		collisionController.collisionLaserInvader(laserSprite, invaderSprite9, Laser.laserDrawnOnScreen, invader9.invaderDrawn, scoreController);
		collisionController.collisionLaserInvader(laserSprite, invaderSprite10, Laser.laserDrawnOnScreen, invader10.invaderDrawn, scoreController);
		collisionController.collisionLaserInvader(laserSprite, invaderSprite11, Laser.laserDrawnOnScreen, invader11.invaderDrawn, scoreController);
		collisionController.collisionLaserInvader(laserSprite, invaderSprite12, Laser.laserDrawnOnScreen, invader12.invaderDrawn, scoreController);
		collisionController.collisionLaserInvader(laserSprite, invaderSprite13, Laser.laserDrawnOnScreen, invader13.invaderDrawn, scoreController);
		collisionController.collisionLaserInvader(laserSprite, invaderSprite14, Laser.laserDrawnOnScreen, invader14.invaderDrawn, scoreController);
		collisionController.collisionLaserInvader(laserSprite, invaderSprite15, Laser.laserDrawnOnScreen, invader15.invaderDrawn, scoreController);


	
		collisionController.collisionLaserShield(laserSprite, shieldSprite, Laser.laserDrawnOnScreen, Shield1.shieldDrawn, Shield1, Laser);
		collisionController.collisionLaserShield(laserSprite, shieldSprite2, Laser.laserDrawnOnScreen, Shield2.shieldDrawn, Shield2, Laser);
		collisionController.collisionLaserShield(laserSprite, shieldSprite3, Laser.laserDrawnOnScreen, Shield3.shieldDrawn, Shield3, Laser);

	
		collisionController.collisionLaserShield(laserInvaderSprite, shieldSprite, Laser.invaderLaserDrawn, Shield1.shieldDrawn, Shield1, laserInvader);
		collisionController.collisionLaserShield(laserInvaderSprite, shieldSprite2, Laser.invaderLaserDrawn, Shield2.shieldDrawn, Shield2, laserInvader);
		collisionController.collisionLaserShield(laserInvaderSprite, shieldSprite3, Laser.invaderLaserDrawn, Shield3.shieldDrawn, Shield3, laserInvader);

	
		collisionController.collisionInvaderLaserShip(laserInvaderSprite, shipSprite, Laser.invaderLaserDrawn, Ship.shipDrawn, Ship);

		siWindow.display();

		sf::Time elapsedTime = timer.getElapsedTime();

		if (elapsedTime.asSeconds() > 1.0f) {

		
			std::random_device rd;
			std::uniform_int_distribution<long> genSeed;

			srand(genSeed(rd));

			int invaderShootChance1 = rand() % 7 + 2;
			int invaderShootChance2 = rand() % 5 + 0;
			int invaderShootChance3 = rand() % 4 + 0;
			int invaderShootChance4 = rand() % 10 + 1;
			int invaderShootChance5 = rand() % 3 + 9;
			int invaderShootChance6 = rand() % 5 + 8;
			int invaderShootChance7 = rand() % 3 + 1;
			int invaderShootChance8 = rand() % 4 + 2;
			int invaderShootChance9 = rand() % 3 + 6;
			int invaderShootChance10 = rand() % 7 + 11;


			if (invader1.invaderDrawn) {
				invader1.onMoveInvader(invaderSprite);
				invader1.moveInvaderDown(invaderSprite);
				if (invaderShootChance1 == invaderShootChance2) {
					Laser.fireLaser(invaderSprite, laserInvaderSprite, Laser.invaderLaserDrawn);
				}
			}

			if (invader2.invaderDrawn) {
				invader2.onMoveInvader(invaderSprite2);
				invader2.moveInvaderDown(invaderSprite2);
				if (invaderShootChance3 == invaderShootChance4) {
					Laser.fireLaser(invaderSprite2, laserInvaderSprite, Laser.invaderLaserDrawn);
				}
			}

			if (invader3.invaderDrawn) {
				invader3.onMoveInvader(invaderSprite3);
				invader3.moveInvaderDown(invaderSprite3);
				if (invaderShootChance5 == invaderShootChance6) {
					Laser.fireLaser(invaderSprite3, laserInvaderSprite, Laser.invaderLaserDrawn);
				}
			}

			if (invader4.invaderDrawn) {
				invader4.onMoveInvader(invaderSprite4);
				invader4.moveInvaderDown(invaderSprite4);
				if (invaderShootChance7 == invaderShootChance8) {
					Laser.fireLaser(invaderSprite4, laserInvaderSprite, Laser.invaderLaserDrawn);
				}
			}

			if (invader5.invaderDrawn) {
				invader5.onMoveInvader(invaderSprite5);
				invader5.moveInvaderDown(invaderSprite5);
				if (invaderShootChance9 == invaderShootChance10) {
					Laser.fireLaser(invaderSprite5, laserInvaderSprite, Laser.invaderLaserDrawn);
				}
			}

			if (invader6.invaderDrawn) {
				invader6.onMoveInvader(invaderSprite6);
				invader6.moveInvaderDown(invaderSprite6);
				if (invaderShootChance2 == invaderShootChance4) {
					Laser.fireLaser(invaderSprite6, laserInvaderSprite, Laser.invaderLaserDrawn);
				}
			}

			if (invader7.invaderDrawn) {
				invader7.onMoveInvader(invaderSprite7);
				invader7.moveInvaderDown(invaderSprite7);
				if (invaderShootChance5 == invaderShootChance9) {
					Laser.fireLaser(invaderSprite7, laserInvaderSprite, Laser.invaderLaserDrawn);
				}
			}

			if (invader8.invaderDrawn) {
				invader8.onMoveInvader(invaderSprite8);
				invader8.moveInvaderDown(invaderSprite8);
				if (invaderShootChance4 == invaderShootChance7) {
					Laser.fireLaser(invaderSprite8, laserInvaderSprite, Laser.invaderLaserDrawn);
				}
			}

			if (invader9.invaderDrawn) {
				invader9.onMoveInvader(invaderSprite9);
				invader9.moveInvaderDown(invaderSprite9);
				if (invaderShootChance2 == invaderShootChance6) {
					Laser.fireLaser(invaderSprite9, laserInvaderSprite, Laser.invaderLaserDrawn);
				}
			}

			if (invader10.invaderDrawn) {
				invader10.onMoveInvader(invaderSprite10);
				invader10.moveInvaderDown(invaderSprite10);
				if (invaderShootChance3 == invaderShootChance5) {
					Laser.fireLaser(invaderSprite10, laserInvaderSprite, Laser.invaderLaserDrawn);
				}
			}

			if (invader11.invaderDrawn) {
				invader11.onMoveInvader(invaderSprite11);
				invader11.moveInvaderDown(invaderSprite11);
				if (invaderShootChance4 == invaderShootChance7) {
					Laser.fireLaser(invaderSprite11, laserInvaderSprite, Laser.invaderLaserDrawn);
				}
			}

			if (invader12.invaderDrawn) {
				invader12.onMoveInvader(invaderSprite12);
				invader12.moveInvaderDown(invaderSprite12);
				if (invaderShootChance3 == invaderShootChance9) {
					Laser.fireLaser(invaderSprite12, laserInvaderSprite, Laser.invaderLaserDrawn);
				}
			}

			if (invader13.invaderDrawn) {
				invader13.onMoveInvader(invaderSprite13);
				invader13.moveInvaderDown(invaderSprite13);
				if (invaderShootChance1 == invaderShootChance8) {
					Laser.fireLaser(invaderSprite13, laserInvaderSprite, Laser.invaderLaserDrawn);
				}
			}

			if (invader14.invaderDrawn) {
				invader14.onMoveInvader(invaderSprite14);
				invader14.moveInvaderDown(invaderSprite14);
				if (invaderShootChance2 == invaderShootChance9) {
					Laser.fireLaser(invaderSprite14, laserInvaderSprite, Laser.invaderLaserDrawn);
				}
			}

			if (invader15.invaderDrawn) {
				invader15.onMoveInvader(invaderSprite15);
				invader15.moveInvaderDown(invaderSprite15);
				if (invaderShootChance1 == invaderShootChance7) {
					Laser.fireLaser(invaderSprite15, laserInvaderSprite, Laser.invaderLaserDrawn);
				}
			}

			timer.restart();
		}

	}

}
#include "../inc/laser.h" 
#include "../inc/invader.h" 

sf::Texture laserTexture; 

Laser::Laser() {

}


void Laser::genLaser(sf::Sprite &laserShipSprite) {
	if (!laserTexture.loadFromFile("./res/laser.png")) {
		laserTexture.loadFromFile("./res/error.png");
	}
	else {
		laserShipSprite.setScale(0.1f, 0.1f);
		laserShipSprite.setTexture(laserTexture);
	}
	laserShipSprite.setOrigin(laserTexture.getSize().x / 2.0f, laserTexture.getSize().y / 2.0f);
}

sf::Texture laserInvaderTexture; 


void Laser::genInvaderLaser(sf::Sprite &laserInvaderSprite) {
	if (!laserInvaderTexture.loadFromFile("./res/laserInvader.png")) {
		laserInvaderTexture.loadFromFile("./res/error.png");
	}
	else {
		laserInvaderSprite.setScale(0.1f, 0.1f);
		laserInvaderSprite.setTexture(laserInvaderTexture);
	}
	laserInvaderSprite.setOrigin(laserInvaderTexture.getSize().x / 2.0f, laserInvaderTexture.getSize().y / 2.0f);
}


void Laser::fireLaser(sf::Sprite &entity, sf::Sprite &laserSprite, bool &laserDrawnOnScreen) {
	laserSprite.setPosition(entity.getPosition());
	laserDrawnOnScreen = true;
}

Laser::~Laser() {

}
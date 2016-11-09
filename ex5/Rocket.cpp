#include "Rocket.h"

Rocket::Rocket() {

}

Rocket::Rocket(IrrlichtDevice* device, IVideoDriver* driver) {
	this->device = device;
	this->driver = driver;
}

Rocket::Rocket(const Rocket& orig) {

}

Rocket::~Rocket() {
	this->device = NULL;
	this->driver = NULL;
	this->rocketTexture = NULL;
}

void Rocket::create() {
	this->rocketTexture = this->driver->getTexture(this->rocketTextureLocation);
}

void Rocket::draw() {
	this->driver->draw2DImage(this->rocketTexture, this->rocketPosition, this->rocketDimensions, 0, SColor(255, 255, 255, 255), true);
}

void Rocket::animate(u32 currentTime) {
	if (currentTime - this->lastAnimationFrame >= (1000 / 60)) {
		this->currentColumnFrame++;
		this->lastAnimationFrame = currentTime;

	}
	if (this->currentColumnFrame >= 10) {
		this->currentColumnFrame = 0;
		this->currentRowFrame++;
	}
	if (this->currentRowFrame >= 6) {
		this->currentRowFrame = 0;
	}
}

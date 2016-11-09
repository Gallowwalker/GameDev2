#include "Sun.h"

Sun::Sun() {

}

Sun::Sun(IrrlichtDevice *device, IVideoDriver* driver) {
	this->device = device;
	this->driver = driver;
}

Sun::Sun(const Sun& orig) {

}

Sun::~Sun() {
	this->device = NULL;
	this->driver = NULL;
	this->sunTexture = NULL;
}

void Sun::create() {
	this->sunTexture = this->driver->getTexture(this->sunTextureLocation);
}

void Sun::draw() {
	this->driver->draw2DImage(this->sunTexture, this->sunPosition, this->sunDimentions, 0, SColor(255, 255, 255, 255), true);
}

void Sun::animate(u32 currentTime) {
	if (currentTime - this->lastAnimationFrame >= (1000 / 5)) {
		this->sunFrame++;
		this->lastAnimationFrame = currentTime;
	}
	if (this->sunFrame >= 5) {
		this->sunFrame = 0;
	}
}
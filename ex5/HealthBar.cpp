#include "HealthBar.h"

#include <irrlicht.h>
#include "driverChoice.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

HealthBar::HealthBar() {

}

HealthBar::HealthBar(IrrlichtDevice *device, IVideoDriver* driver) {
	this->device = device;
	this->driver = driver;
}

HealthBar::HealthBar(const HealthBar& orig) {

}

HealthBar::~HealthBar() {
	this->device = NULL;
	this->driver = NULL;
	this->healthBarTexture = NULL;
	this->healthTexture = NULL;
}

void HealthBar::create() {
	this->healthBarTexture = this->driver->getTexture(this->healthBarTextureLocation);
	this->healthTexture = this->driver->getTexture(this->healthTextureLocation);
}

void HealthBar::draw() {
	this->driver->draw2DImage(this->healthBarTexture, this->healthBarPosition, this->healthBarDimentions, 0, SColor(255, 255, 255, 255), true);
	this->driver->draw2DImage(this->healthTexture, this->healthPosition, this->healthDimensions, 0, SColor(255, 255, 255, 255), true);
}

//void HealthBar::destroy() {
//	delete this;
//}

void HealthBar::setHealthAmount(int healthAmount) {
	this->healthAmount = healthAmount;
}

int HealthBar::getHealthAmount() const {
	return this->healthAmount;
}

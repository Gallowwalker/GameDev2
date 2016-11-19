#ifndef ROCKET_H
#define ROCKET_H

#include "GameObject.h"

#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace video;

class Rocket : public GameObject {
public:
    Rocket();
	Rocket(IrrlichtDevice* device, IVideoDriver* driver, u32 lastAnimationFrame);
    Rocket(const Rocket& orig);
    virtual ~Rocket();

	void draw() override;
	void animate(u32 currentTime) override;

private:
	int currentRowFrame = 0;
	int currentColumnFrame = 0;
	u32 lastAnimationFrame = 0;

	IrrlichtDevice* device = NULL;
	IVideoDriver* driver = NULL;
	ITexture* rocketTexture = NULL;

	stringw rocketTextureLocation = "./media/rocket_spritesheet.png";

	rect<s32> rocketDimensions = rect<s32>((this->currentColumnFrame * 55), (this->currentRowFrame * 83), ((this->currentColumnFrame + 1) * 55), ((this->currentRowFrame + 1) * 83));

	position2d<s32> rocketPosition = position2d<s32>(225, 140);

};

#endif /* ROCKET_H */


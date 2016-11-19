#ifndef SUN_H
#define SUN_H

#include "GameObject.h"

#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace video;

class Sun : public GameObject {
public:
	Sun();
	Sun(IrrlichtDevice *device, IVideoDriver* driver, u32 lastAnimationFrame);
	Sun(const Sun& orig);
	virtual ~Sun();

	void draw() override;
	void animate(u32 currentTime) override;

private:
	int sunFrame = 0;
	u32 lastAnimationFrame = 0;
	//u32 currentTime = this->device->getTimer()->getTime();

	IrrlichtDevice *device = NULL;
	IVideoDriver* driver = NULL;
	ITexture* sunTexture = NULL;

	stringw sunTextureLocation = "./media/sun_spritesheet.png";

	rect<s32> sunDimentions = rect<s32>((this->sunFrame * 200), 0, ((this->sunFrame + 1) * 200), 200);

	position2d<s32> sunPosition = position2d<s32>(300, 200);
};

#endif /* ROCKET_H */
#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include "HUD.h"

#include <irrlicht.h>
#include "driverChoice.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class HealthBar : public HUD {
public:
	HealthBar();
	HealthBar(IrrlichtDevice *device, IVideoDriver* driver);
	HealthBar(const HealthBar& orig);
	virtual ~HealthBar();

	void create() override;
	void draw() override;
	/*void destroy() override;*/

	void setHealthAmount(int healthAmount);
	int getHealthAmount() const;

private:
	int healthAmount = 0;

	IrrlichtDevice *device = NULL;
	IVideoDriver* driver = NULL;
	ITexture* healthBarTexture = NULL;
	ITexture* healthTexture = NULL;

	stringw healthBarTextureLocation = "./media/healthbar.png";
	stringw healthTextureLocation = "./media/health.png";
	
	rect<s32> healthBarDimentions = rect<s32>(0, 0, 221, 43);
	rect<s32> healthDimensions = rect<s32>(healthAmount, 0, 193, 14);

	position2d<s32> healthBarPosition = position2d<s32>(10, 10);
	position2d<s32> healthPosition = position2d<s32>(23, 24);
};

#endif /* HEALTHBAR_H */


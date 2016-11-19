#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include "HUD.h"

#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace video;

class HealthBar : public HUD {
public:
	HealthBar();
	HealthBar(IrrlichtDevice *device, IVideoDriver* driver);
	HealthBar(const HealthBar& orig);
	virtual ~HealthBar();

	void draw() override;
	/*void destroy() override;*/

	void setHealthAmount(int healthAmount);
	int getHealthAmount() const;

private:
	/*int minimalHealthAmount = 0;
	int maximalHealthAmount = 193;*/
	int healthAmount = 193; //0 - min | 193 - max

	IrrlichtDevice *device = NULL;
	IVideoDriver* driver = NULL;
	ITexture* healthBarTexture = NULL;
	ITexture* healthTexture = NULL;

	stringw healthBarTextureLocation = "./media/healthbar.png";
	stringw healthTextureLocation = "./media/health.png";
	
	rect<s32> healthBarDimentions = rect<s32>(0, 0, 221, 43);
	rect<s32> healthDimensions = rect<s32>(0, 0, this->healthAmount, 14); //(this->healthAmount - this->minimalHealthAmount) / (this->maximalHealthAmount - this->minimalHealthAmount)

	position2d<s32> healthBarPosition = position2d<s32>(10, 10);
	position2d<s32> healthPosition = position2d<s32>(23, 24);
};

#endif /* HEALTHBAR_H */


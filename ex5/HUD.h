#ifndef HUD_H
#define HUD_H

#include <irrlicht.h>
#include "driverChoice.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class HUD {
public:
	HUD();
	HUD(const HUD& orig);
	virtual ~HUD();

	virtual void create() = 0;
	virtual void draw() = 0;
	/*virtual void destroy() = 0;*/

private:

};

#endif /* HUD_H */


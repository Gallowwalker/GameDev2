#ifndef HUD_H
#define HUD_H

#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace video;

class HUD {
public:
	HUD();
	HUD(const HUD& orig);
	virtual ~HUD();

	virtual void draw() = 0;
	/*virtual void destroy() = 0;*/

private:

};

#endif /* HUD_H */


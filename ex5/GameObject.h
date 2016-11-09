#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <irrlicht.h>
#include "driverChoice.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class GameObject {
public:
    GameObject();
    GameObject(const GameObject& orig);
    virtual ~GameObject();
    
	virtual void create() = 0;
    virtual void draw() = 0;
    virtual void animate(u32 time) = 0;
    
private:

};

#endif /* GAMEOBJECT_H */


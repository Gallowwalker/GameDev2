#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace video;

class GameObject {
public:
    GameObject();
    GameObject(const GameObject& orig);
    virtual ~GameObject();
    
    virtual void draw() = 0;
	virtual void animate(u32 time) = 0;
    
private:

};

#endif /* GAMEOBJECT_H */


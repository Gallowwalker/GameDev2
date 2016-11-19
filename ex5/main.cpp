#include <irrlicht.h>
#include "HealthBar.h"
#include "Rocket.h"
#include "Sun.h"

using namespace irr;
using namespace core;
using namespace video;
using namespace gui;
using namespace io;
using namespace scene;

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

int main()
{
	
	IrrlichtDevice *device = createDevice(video::EDT_DIRECT3D9, core::dimension2d<u32>(1680, 950));

	if (device == 0) {
		return 1; // could not create selected driver.
	}

	/*if (!device) //alternative
	{
		return 1;
	}*/

	device->setWindowCaption(L"Irrlicht Engine - 2D Graphics Demo");

	IVideoDriver* driver = device->getVideoDriver();

	
	ITexture* backgroundTexture = driver->getTexture("./media/Backgrounds/awesome_space_galaxy_wallpaper_hd_8.jpg");
	ITexture* rocketTexture = driver->getTexture("./media/rocket_spritesheet.png");
	ITexture* sunTexture = driver->getTexture("./media/sun_spritesheet.png");

	// driver->makeColorKeyTexture(images, core::position2d<s32>(0,0));

	IGUIFont* font = device->getGUIEnvironment()->getBuiltInFont();
	IGUIFont* font2 = device->getGUIEnvironment()->getFont("./media/fonthaettenschweiler.bmp");

	rect<s32> background = rect<s32>(0, 0, 1680, 950);

	/*
	Prepare a nicely filtering 2d render mode for special cases.
	*/
	driver->getMaterial2D().TextureLayer[0].BilinearFilter=true;
	driver->getMaterial2D().AntiAliasing=video::EAAM_FULL_BASIC;


	HUD* healthBar = new HealthBar(device, driver);

	//healthBar->setHealthAmount(0);

	


	u32 lastAnimationFrame = device->getTimer()->getTime();

	GameObject* rocket = new Rocket(device, driver, lastAnimationFrame);
	GameObject* sun = new Sun(device, driver, lastAnimationFrame);



	s32 lastFPS = -1;

	u32 currentTime = 0;
	u32 lastTime = 0;   //alt+ up and down
	//u32 deltaTime = 0;

	u32 lastSunFrame = device->getTimer()->getTime();
	u32 sunFrame = 0;
	int currentColumnFrame = 0;
	int currentRowFrame = 0;
	

	while(device->run() && driver)
	{
		if (device->isWindowActive())
		{

			
			currentTime = device->getTimer()->getTime();
			////deltaTime = currentTime - lastTime;

			sun->animate(currentTime);
			rocket->animate(currentTime);


			/*if (currentTime - lastSunFrame >= (1000 / 5))
			{
				sunFrame++;
				lastSunFrame = currentTime;
			}
			if (sunFrame >= 5)
			{
				sunFrame = 0;
			}


			if (currentTime - lastAnimationFrame >= (1000 / 60)) {
				currentColumnFrame++;
				lastAnimationFrame = currentTime;

			}
			if (currentColumnFrame >= 10) {
				currentColumnFrame = 0;
				currentRowFrame++;
			}
			if (currentRowFrame >= 6) {
				currentRowFrame = 0;
			}*/

			

			driver->beginScene(true, true, SColor(255,255,255,255));

			driver->draw2DImage(backgroundTexture, position2d<s32>(0, 0), background, 0, SColor(255, 255, 255, 255), true);

			//(time / 1000 % 2) ? hud->setHealth(0) : hud->setHealth(150);
			

			//driver->draw2DImage(rocketTexture, position2d<s32>(225, 140), rect<s32>((currentColumnFrame * 55), (currentRowFrame * 83), ((currentColumnFrame + 1) * 55), ((currentRowFrame + 1) * 83)), 0, SColor(255, 255, 255, 255), true);
				

			// rocket and sun class      abstract game object    functions for draw and animation
																			
			/*driver->draw2DImage(sun, position2d<s32>(300, 200), sunAnim, 0, SColor(255, 255, 255, 255), true);*/

		

			//driver->draw2DImage(sunTexture, position2d<s32>(300, 200), rect<s32>(sunFrame * 200, 0, (sunFrame + 1) * 200, 200), 0, SColor(255, 255, 255, 255), true);

			
			healthBar->draw();
			rocket->draw();

			sun->draw();

			//// draw some text
			//if (font)
			//	font->draw(L"This demo shows that Irrlicht is also capable of drawing 2D graphics.",
			//		core::rect<s32>(130,10,300,50),
			//		video::SColor(255,255,255,255));

			//// draw some other text
			//if (font2)
			//	font2->draw(L"Also mixing with 3d graphics is possible.",
			//		core::rect<s32>(130,20,300,60),
			//		video::SColor(255,255,255,255));

			/*

			

			/*
			Finally draw a half-transparent rect under the mouse cursor.
			*/
			
			/*core::position2d<s32> m = device->getCursorControl()->getPosition();

			driver->draw2DRectangle(video::SColor(100,255,255,255),
				core::rect<s32>(m.X-20, m.Y-20, m.X+20, m.Y+20));*/

			

			driver->endScene();


			lastTime = currentTime;
			s32 fps = driver->getFPS();

			if (lastFPS != fps)
			{
				stringw stringFPS = L"FPS: ";
				stringFPS += fps;
				device->setWindowCaption(stringFPS.c_str());
				lastFPS = fps;
			}




		}
	}

	//healthBar->destroy();
	delete healthBar;
	delete sun;
	delete rocket;

	device->drop();

	return 0;
}

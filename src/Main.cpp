// windows
#include <Windows.h>


// std
import std;

// custom modules
import WindowClass;
import LogTags;
import RendererSetup;
import fpsTimer;
import Renderer;
import dataStructures;

// declare functions
inline void tagSetup(cslTag::Tags& logger);

// main

int main()
{
	//! Settings
	constexpr unsigned int screenWidth = 640;
	constexpr unsigned int screenHeight = 480;
	constexpr unsigned int framerate = 28;

	// creating log tags
	cslTag::Tags logger = {};

	tagSetup(logger);

	//! Creating Window

	logger.tag("WINDOW");
	std::cout << "Creating Window\n";

	// create Window obj
	cWND::Window* pWindow = new cWND::Window(screenWidth,screenHeight);

	// creating renderer obj
	RNDR::Renderer renderer(pWindow);

	// creating renderer handle
	RNDR::RenderingHandle rHandle(screenWidth, screenHeight);

	// creating FPS Timer to controll Framerate
	fps::FPStimer fpsTimer(framerate);

	// Main rendering function
	{
		fps::Timer timer; // timing
		logger.tag("RENDERER");
		std::cout << "Rendering process started!\n";

		//! Main Renderfunction
		// get bitArray (array with RGB value of all pixels)
		COLORREF* bitArray = renderer.getBitArray();

		//! ---

		dta::Vector2D point1(50, 50);
		dta::Vector2D point2(200, 50);

		rHandle.drawLine(point1, point2, bitArray);
		//! ---
		// render bitarray
		renderer.renderBitArray();

		timer.stopTimer();

		logger.tag("RENDERER");
		std::cout << "Render finished in " << timer.getTime() << "s\n";
	}

	//! window update loop
	
	logger.tag("PROGRAM");
	std::cout << "Close rendering window to terminate program!\n";

	bool running = true;
	while (running)
	{
		if (fpsTimer.getUpdate())
		{
			if (!pWindow->ProcessMessages())
			{
				logger.tag("WINDOW");
				std::cout << "Closing Window \n";
				running = false;
				break;
			}
		}
	}

	delete pWindow;

	logger.tag("WINDOW");
	std::cout << "Window obj deleted!\n";

	logger.tag("PROGRAM");
	std::cout << "Clean up finished!\n";
	std::cout << "Press any key to terminate Program!" << std::endl; // endl to clear
	
	std::cin.get(); // wait for input (any key)

	return 0;
}

// functions
inline void tagSetup(cslTag::Tags& logger)
{
	logger.createNewTag(cslTag::RED, "ERROR");
	logger.createNewTag(cslTag::LIGHT_YELLOW, "WARNING");
	logger.createNewTag(cslTag::LIGHT_BLUE, "WINDOW");
	logger.createNewTag(cslTag::LIGHT_GREEN, "RENDERER");
	logger.createNewTag(cslTag::LIGHT_MAGENTA, "PROGRAM");
}
// windows
#include <Windows.h>

// std
import std;

// custom modules
import WindowClass;
import LogTags;
import RendererSetup;
import fpsTimer;

// functions
inline void tagSetup(cslTag::Tags& logger)
{
	logger.createNewTag(cslTag::RED, "ERROR");
	logger.createNewTag(cslTag::LIGHT_YELLOW, "WARNING");
	logger.createNewTag(cslTag::LIGHT_BLUE, "WINDOW");
	logger.createNewTag(cslTag::LIGHT_GREEN, "RENDERER");
	logger.createNewTag(cslTag::LIGHT_MAGENTA, "PROGRAM");
}

// main

int main()
{
	// creating log tags
	cslTag::Tags logger = {};

	tagSetup(logger);

	//! Creating Window

	logger.tag("WINDOW");
	std::cout << "Creating Window\n";

	// create Window obj
	cWND::Window* pWindow = new cWND::Window();

	// creating renderer obj
	RNDR::Renderer renderer(pWindow);

	// creating FPS Timer to controll Framerate
	constexpr unsigned int framerate = 28;
	fps::FPStimer fpsTimer(28);

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
			}

			//! Main Loop
			// get bitArray (array with RGB value of all pixels)
			COLORREF* bitArray = renderer.getBitArray();

			// Todo Render Loop in other decentral file?
			RenderLoop();
			
			// render bit array
			renderer.renderBitArray();
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
// windows
#include <Windows.h>

// std
import std;

// custom modules
import WindowClass;

// main

int main()
{
	//! Creating Window

	std::cout << "[WND] Creating Window\n";

	cWND::Window* pWindow = new cWND::Window();

	bool running = true;
	while (running)
	{
		if (!pWindow->ProcessMessages())
		{
			std::cout << "[WND] Closing Window \n";
			running = false;
		}

		//! Main Loop
		
		//! Writing Pixels

		// window width and height
		unsigned int wndWidth = pWindow->width;
		unsigned int wndHeight = pWindow->height;

		// get window context
		HDC hdc = GetDC(pWindow->m_hWnd);

		COLORREF* arr = static_cast<COLORREF*>(calloc(wndWidth * wndHeight, sizeof(COLORREF)));

		// modify/fill array here

		// creating temp bitmap
		HBITMAP map = CreateBitmap(wndWidth, wndHeight, 1, 8 * 4, static_cast<void*>(arr)); // width, height, Color Planes?, size of memory for one pixel, pointer to array

		// temp HDC to copy picture
		HDC src = CreateCompatibleDC(hdc); // hdc - Device Context for window

		// insert picture into the temp HDC
		SelectObject(src, map);

		// copy picture from temp HDC to window
		BitBlt(hdc, 0, 0, wndWidth, wndHeight, src, 0, 0, SRCCOPY); // Destination, x and, y - upper-let corner of place of where to copy, width of the region,
		// height, source, x and, y of upper-left corner of part of the source, 

		Sleep(1); // Todo Add framerate

		// clearing memory
		DeleteDC(src);
		DeleteObject(map);
		DeleteDC(src);
	}

	delete pWindow;


	return 0;
}
// windows
#include <Windows.h>

// std
import std;

// custom modules


// main

int main()
{
	//! Creating Window
	



	//! Writing Pixels

	// get window context
	HDC hdc = GetDC(NULL);

	COLORREF* arr = static_cast<COLORREF*>(calloc(512 * 512, sizeof(COLORREF)));

	// modify/fill array here

	// creating temp bitmap
	HBITMAP map = CreateBitmap(512, 512, 1, 8 * 4, static_cast<void*>(arr)); // width, height, Color Planes?, size of memory for one pixel, pointer to array

	// temp HDC to copy picture
	HDC src = CreateCompatibleDC(hdc); // hdc - Device Context for window

	// insert picture into the temp HDC
	SelectObject(src, map);

	// copy picture from temp HDC to window
	BitBlt(hdc, 10, 10, 512, 512, src, 0, 0, SRCCOPY); // Destination, x and, y - upper-let corner of place of where to copy, width of the region,
	// height, source, x and, y of upper-left corner of part of the source, 

	std::cin.get();

	// clearing memory
	DeleteDC(src);
	DeleteObject(map);
	DeleteDC(src);

	return 0;
}
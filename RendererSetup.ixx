export module RendererSetup;

// imports
import std;
import WindowClass;
import <Windows.h>;


namespace RNDR
{
	export class Renderer
	{
	private:
		// private member variables
		unsigned int m_screenWidth{ 0 };
		unsigned int m_screenHeight{ 0 };
		HDC m_hdc = nullptr;
		COLORREF* m_bitArray = nullptr;
	public:
		// public variables
	public:
		// public functions
		Renderer(cWND::Window* window)
			: m_screenWidth(window->width), m_screenHeight(window->height)
		{
			m_hdc = GetDC(window->m_hWnd);
			m_bitArray = static_cast<COLORREF*>(calloc(m_screenWidth * m_screenHeight, sizeof(COLORREF)));
		}

		~Renderer() {}

		COLORREF* getBitArray()
		{
			return m_bitArray;
		}

		void renderBitArray()
		{
			// creating temp bitmap
			HBITMAP map = CreateBitmap(m_screenWidth, m_screenHeight, 1, 8 * 4, static_cast<void*>(m_bitArray)); // width, height, Color Planes?, size of memory for one pixel, pointer to array

			// temp HDC to copy picture
			HDC src = CreateCompatibleDC(m_hdc); // hdc - Device Context for window 

			// insert picture into the temp HDC
			SelectObject(src, map);

			// copy picture from temp HDC to window
			BitBlt(m_hdc, 0, 0, m_screenWidth, m_screenHeight, src, 0, 0, SRCCOPY); // Destination, x and, y - upper-let corner of place of where to copy, width of the region,
			// height, source, x and, y of upper-left corner of part of the source

			DeleteDC(src);
			DeleteObject(map);
		}

		inline COLORREF correctedRGB(unsigned int valueR, unsigned int valueG, unsigned int valueB)
		{
			return RGB(valueB, valueG, valueR); // RGB -> BGR (win32 RGB function takes BGR as input)
		}

	};
}
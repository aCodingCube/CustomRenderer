export module Renderer;

#include <Windows.h>

namespace RNDR
{
	export inline unsigned int hash2Dto1D(unsigned int x, unsigned int y, unsigned int xSize)
	{
		unsigned int xBuf = x;
		unsigned int yBuf = y * xSize;
		
		return xBuf + yBuf;
	}

	export inline COLORREF cRGB(unsigned int valueR, unsigned int valueG, unsigned int valueB)
	{
		return RGB(valueB, valueG, valueR); // RGB -> BGR (win32 RGB function takes BGR as input)
	}
}
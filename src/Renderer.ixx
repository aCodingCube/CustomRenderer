export module Renderer;

import vectorPoints;
import std;

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

	export void drawLine(pts::Vector2D point1, pts::Vector2D point2, COLORREF* bitArray)
	{
		pts::Vector2D line = {};
		line.x = point2.x - point1.x;
		line.y = point2.y - point1.y;

		float m = line.y / line.x;

		if (m >= 0)
		{
			for (int i = point1.x; i <= point2.x; i++)
			{
				float y_float = m * i;
				int y_int = std::round(y_float);
				bitArray[RNDR::hash2Dto1D(i, y_int, 640)] = RNDR::cRGB(255, 255, 255);
			}
		}
		// TODO Fix the handling of m < 0
		else if (m < 0)
		{
			for (int i = point1.x; i <= point2.x; i--)
			{
				float y_float = m * i; // m * ( i - ScreenWidth)
				int y_int = std::round(y_float);
				bitArray[RNDR::hash2Dto1D(i, y_int, 640)] = RNDR::cRGB(255, 255, 255);
			}
		}
	}
}
export module Renderer;

import dataStructures;
import std;

#include <Windows.h>

namespace RNDR
{
	// version with vector2D as an input
	export inline unsigned int hash2Dto1D(dta::Vector2D vector, unsigned int screenWidth, unsigned int screenHeight)
	{
		unsigned int xBuf = vector.x;
		unsigned int yBuf = (screenHeight - 1) - vector.y;
		yBuf *= screenWidth;
		return xBuf + yBuf;
	}

	// version with tow seperate numbers as input
	export inline unsigned int hash2Dto1D(unsigned int x, unsigned int y, unsigned int screenWidth, unsigned int screenHeight)
	{
		unsigned int xBuf = x;
		unsigned int yBuf = (screenHeight - 1) - y;
		yBuf *= screenWidth;
		return xBuf + yBuf;
	}

	export inline COLORREF cRGB(unsigned int valueR, unsigned int valueG, unsigned int valueB)
	{
		return RGB(valueB, valueG, valueR); // RGB -> BGR (win32 RGB function takes BGR as input)
	}

	export class RenderingHandle
	{
	private:
		unsigned int m_screenWidth{ 0 };
		unsigned int m_screenHeight{ 0 };
	public:

		RenderingHandle(unsigned int screenWidth, unsigned int screenHeight)
		:m_screenWidth(screenWidth),m_screenHeight(screenHeight) {}

		~RenderingHandle() {}

		// public functions
		void drawLine(dta::Vector2D point1, dta::Vector2D point2, COLORREF* bitArray)
		{
			dta::Vector2D m_point1(point1.x, point1.y);
			dta::Vector2D m_point2(point2.x, point2.y);

			if (point1.x > point2.x)
			{
				m_point1.x = point2.x;
				m_point1.y = point2.y;
				m_point2.x = point1.x;
				m_point2.y = point1.y;
			}

			dta::Vector2D line = {};
			line.x = m_point2.x - m_point1.x;
			line.y = m_point2.y - m_point1.y;

			float m = line.y / line.x;

			if (m > 0)
			{
				for (int x = m_point1.x; x <= m_point2.x; x++)
				{
					float y_float = m * x;

					int y_int = std::round(y_float);

					bitArray[RNDR::hash2Dto1D(x, y_int, m_screenWidth, m_screenHeight)] = RNDR::cRGB(255, 255, 255);
				}
			}

			else if (m < 0)
			{
				for (int x = m_point2.x; x <= m_point1.x; x++)
				{

					float y_float = m * x + (m_point1.y + m_point2.y);

					int y_int = std::round(y_float);

					bitArray[RNDR::hash2Dto1D(x, y_int, m_screenWidth, m_screenHeight)] = RNDR::cRGB(255, 255, 255);
				}
			}

			else if (m == 0)
			{
				for (int x = m_point1.x; x <= m_point2.x; x++)
				{
					bitArray[RNDR::hash2Dto1D(x, point1.y, m_screenWidth, m_screenHeight)] = RNDR::cRGB(255, 255, 255);
				}
			}
		}
	};
}
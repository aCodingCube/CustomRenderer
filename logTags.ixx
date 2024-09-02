export module LogTags;

// includes
#include <Windows.h>

// modules
import std;

namespace cslTag
{
	export enum Color
	{
		BLACK = 30, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, LIGHT_GRAY,
		DARK_GRAY = 90, LIGHT_RED, LIGHT_GREEN, LIGHT_YELLOW, LIGHT_BLUE, LIGHT_MAGENTA, LIGHT_CYAN, WHITE
	};

	export static class Tags
	{
	private:
		// private member variables
		std::map<std::string, unsigned int> m_tagColorMap = {};
		const unsigned int STANDART_COLOR = 37;
	public:

		void createNewTag(Color color, std::string tagName)
		{
			m_tagColorMap[tagName] = color;
		}

		void tag(std::string tagName)
		{	
			try
			{
				// colored tag
				std::cout << "\033[" << m_tagColorMap.at(tagName) << "m";
				std::cout << "[" << tagName << "] ";
				std::cout << "\033[" << STANDART_COLOR << "m";
			}
			catch (const std::exception& e)
			{
				std::cout << "\033[31m";
				std::cout << "[ERROR] ";
				std::cout << "\033[" << STANDART_COLOR << "m";
				std::cout << "LogTags: " << e.what() << "\n";
			}
		}
	};
}
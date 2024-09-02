export module fpsTimer;

import std;

namespace fps
{
	export class FPStimer
	{
	private:
		// private member variables

		std::chrono::time_point<std::chrono::steady_clock> m_timePoint1 = {}, m_timePoint2 = {};
		std::chrono::duration<float> m_duration{ 0 };

		const float m_timeSpan{ 0 };

		unsigned int m_currentFPS{ 0 };
	public:
		// public methods
		FPStimer(const unsigned int maxFPS)
			: m_timeSpan(1.0f / static_cast<float>(maxFPS))
		{
			m_timePoint1 = std::chrono::high_resolution_clock::now();
		}

		~FPStimer()
		{
			
		}

		bool getUpdate()
		{
			m_timePoint2 = std::chrono::high_resolution_clock::now();
			m_duration = m_timePoint2 - m_timePoint1;
			if (m_duration.count() >= m_timeSpan)
			{
				m_timePoint1 = std::chrono::high_resolution_clock::now();
				return true;
			}
			return false;
		}

		unsigned int getFramerate()
		{
			m_currentFPS = std::round(1.0f / m_duration.count());
			return m_currentFPS;
		}
	};
}
export module vectorPoints;

namespace pts
{
	export class Vector2D
	{
	public:
		int x{ 0 };
		int y{ 0 };

		Vector2D() {}

		Vector2D(int inputX, int inputY)
			:x(inputX), y(inputY) {}
	};
}
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

	export class Vector3D
	{
	public:
		int x{ 0 };
		int y{ 0 };
		int z{ 0 };

		Vector3D() {}

		Vector3D(int inputX,int inputY, int inputZ)
			:x(inputX),y(inputY),z(inputZ) {}
	};
}
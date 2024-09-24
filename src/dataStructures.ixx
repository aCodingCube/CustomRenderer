export module dataStructures;

// imports
import std;

namespace dta
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

	export class Vertex
	{
	private:
		// private variables

	public:
		// public variables
		float m_facing{ 0 };
		std::array<int, 3> m_vertices = {};
	public:
		// public functions

		// constructor
		template<size_t Tsize>
		Vertex(int vertices[Tsize])
		{

		}

		~Vertex() {}
	};
}
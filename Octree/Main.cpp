#include "Octree.h"

int main()
{

	TOctree Toctree;
	Toctree.Init(100, 100, 100);
	float fsec = 0.0f;
	while (fsec < 30)
	{
		Toctree.Frame(10.0f / 1000.0f);
		fsec += 10.0f / 1000.0f;
	}
	g_NewNodecount--;
	
	std::cout << "Hello World!!";

	return 0;

}
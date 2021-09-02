#include <iostream>



int main()
{
	int IArr[5][5] = { 0 };
	int IX = 0, IY = 0;
	int ISize = 5;

	IX = ISize / 2;
	
	for (int i = 1; i < (ISize * ISize) + 1; i++)
	{
		if (IY < 0 && IX == ISize)
		{
			IY += 2;
			IX--;
		}
		else if (IY < 0)
		{
			IY = ISize-1;
		}
		else if (IX == ISize)
		{
			IX = 0;
		}
		if (IArr[IY][IX] != 0)
		{
			IY += 2;
			IX--;
		}
		IArr[IY][IX] = i;
		IY--;
		IX++;
	}

	for (int i = 0; i < ISize; i++)
	{
		for (int j = 0; j < ISize; j++)
		{
			std::cout << IArr[i][j] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}
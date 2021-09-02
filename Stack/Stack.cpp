// Stack.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#define Max_Size 3

int IArr[Max_Size];
int ITop;
int IValue;
int IChoise;
bool Exit;


bool Is_Full();
bool Is_Empty();
void Top();
void Push();
void Pop();
void Create();

int main()
{
	Create();

	while (!Exit)
	{
		std::cout << "1.Push 2. Pop 3. Top 4. Exit : " << "\n";
		std::cin >> IChoise;
		switch (IChoise)
		{
			case 1:
			{
				Push();
			} break;
			case 2: {
				Pop();
			}break;
			case 3: {
				Top();
			}break;
			default: 
			{
				Exit = true;
			}break;
		}
	}
	
}
void Create()
{
	memset(IArr, 0, sizeof(int) * Max_Size);
	ITop = 0;
	Exit = false;
}
void Push()
{
	if (!Is_Full())
	{
		std::cin >> IValue;
		IArr[ITop] = IValue;
		ITop++;
		system("cls");
	}
	
}
void Pop()
{
	system("cls");
	if (!Is_Empty())
	{
		ITop--;
		std::cout << IArr[ITop] << "  Out!\n";
		IArr[ITop] = -1;

	}
}
void Top()
{
	system("cls");
	std::cout << IArr[ITop-1] << " ";
	std::cout << "\n";

}
bool Is_Full()
{
	if (ITop == Max_Size)
	{
		std::cout << "Full!\n";
		return true;
	}
	else return false;
}
bool Is_Empty()
{
	if (ITop == 0) 
	{
		system("cls");
		std::cout << "Empty!\n";
		return true;
	}
	else return false;
}




// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

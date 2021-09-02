// Queue.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#define Max_Size 4

int IArr[Max_Size];
int IFront;
int IBack;
int IValue;
int ISelect;
bool BStart;

void Enqueue();
void Dequeue();
void Create();
void Printqueue();

int main()
{
    Create();
    while (BStart)
    {
        std::cout << "1. Push 2. Pop 3. Print 4. Exit  \n";
        std::cin >> ISelect;

        switch (ISelect)
        {
              case 1: 
              {
                  Enqueue();
              }break;
              case 2:
              {
                  Dequeue();
              } break;
              case 3:
              {
                  Printqueue();
              }break;
               default:
              {
                   BStart = false;
              }
                 break;
        }

    }


}

void Enqueue()
{
    if (IBack == IFront)
    {
        system("cls");
        std::cout << "Full! \n";
    }
    else
    {
        std::cin >> IValue;
        IArr[IBack] = IValue;
        IBack = (IBack + 1) % Max_Size;
        system("cls");
    }
    
}
void Dequeue()
{
    if ((IFront+1) == IBack)
    {
        system("cls");
        std::cout << "Empty! \n";
    }
    else 
    {
        IFront = (IFront + 1) % Max_Size;
        IArr[IFront] = -1;
        system("cls");
    }
   
}
void Create()
{
    memset(IArr, 0, sizeof(int) * Max_Size);
    IFront = 0;
    IBack = 1;
    IValue = 0;
    ISelect = 0;
    BStart = true;
}
void Printqueue()
{
    system("cls");
    for (int i = 0; i < Max_Size; i++)
    {
        if (IArr[i] == 0 || IArr[i] == -1)
        {
            std::cout << "  ";
        }
        else
        {
              std::cout << IArr[i] << " ";
        }
    }
    std::cout << "\n";
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

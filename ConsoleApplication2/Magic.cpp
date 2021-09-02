// ConsoleApplication2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
void InitData();
void print();
void Logic(int x, int y);


int arr[20][20];
int Number = 0;
int x = 0, y = 0;


int main()
{
    while (1)
    {
        InitData();

        std::cout << "1~19까지의 홀수중 하나를 고르시오 ";
        std::cin >> Number;
        if (Number == -1) return -1;

        Logic(x, y);

        print();

    }
}
void InitData()
{
    for (int i = 0; i < Number; i++)
    {
        for (int j = 0; j < Number; j++)
        {
            arr[i][j] = 0;
        }
    }
    x = 0, y = 0;
}

void print()
{
    for (int i = 0; i < Number; i++)
    {
        for (int j = 0; j < Number; j++)
        {
            std::cout << "  " << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void Logic(int x, int y)
{
    x = Number / 2;

    for (int i = 0; i < (Number * Number); i++)
    {
        if (y < 0 && x == Number)
        {
            y += 2;
            x--;
        }
        else if (y < 0)
        {
            y = Number - 1;
        }
        else if (x == Number)
        {
            x = 0;
        }

        if (arr[y][x] != 0)
        {
            y += 2;
            x--;
        }


        arr[y][x] = i + 1;
        x++;
        y--;
    }
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

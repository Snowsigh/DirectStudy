#include <iostream>
#define Max_Info 5
#define Max_Word 10

class Info
{
public:
	char CName[Max_Word];
	char CAdd[Max_Word];
	int IAge;
	Info();
private:

};
Info::Info()
{
	memset(CName, 0, sizeof(char) * Max_Word);
	memset(CAdd, 0, sizeof(char) * Max_Word);
	IAge = 0;

}

class Logic : public Info
{
public:
	Info Stack[Max_Info];
	int ITop;
	int ISelect;
	bool BStart;

	void Create();
	void Push();
	void Pop();
	void Print();

private:

};






int main()
{
	Logic logic;
	logic.Create();
	int ISelect = logic.ISelect;
	bool BStart = logic.BStart;


	while (BStart)
	{
		std::cout << "1. 정보기입 2. 정보삭제 3. 정보확인 4. 나가기 :  ";
		std::cin >> ISelect; 
		std::cout << "\n";
		switch (ISelect)
		{
			case 1: 
			{
				logic.Push();
			}break;
			case 2:
			{
				logic.Pop();
			}break;
			case 3:
			{
				logic.Print();
			}break;
		default:
			BStart = false;
			break;
		}
	}
	return 0;
}
void Logic::Create()
{
	ITop = 0;
	ISelect = 0;
	BStart = true;
}

void Logic::Push()
{
	if (ITop == Max_Info)
	{
		std::cout << "정보칸이 다찼습니다\n";
	}
	else
	{
		Info temp;
		std::cout << "\n이름을 입력해주세요 : \n";
		std::cin >> temp.CName;
		std::cout << "\n주소를 간략히 입력해주세요 : \n";
		std::cin >> temp.CAdd;
		std::cout << "\n나이를 입력하여주세요 : \n";
		std::cin >> temp.IAge;
		system("cls");
		Stack[ITop] = temp;
		ITop++;
	}
}
void Logic::Pop()
{
	if (ITop == 0)
	{
		std::cout << "더이상 삭제할 정보가 없습니다\n";
	}
	else
	{
		std::cout << "삭제되는 정보는 " << Stack[ITop - 1].CName << " "
			<< Stack[ITop - 1].CAdd << " " << Stack[ITop - 1].IAge << " 입니다\n";
		ITop--;
	}
}

void Logic::Print()
{
	for (int i = 0; i < ITop; i++)
	{
		std::cout << "현재 인물 정보 " << Stack[i].CName << " "
			<< Stack[i].CAdd << " " << Stack[i].IAge << " 입니다\n";
	}
	std::cout << "*************************\n이상입니다\n";
}
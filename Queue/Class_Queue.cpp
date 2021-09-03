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
	int IBack;
	int IFront;
	int ISelect;
	bool BStart;

	void Create();
	void Push();
	void Pop();
	void Print();
	bool IsFull();
	bool IsEmpty();
	
	bool IsNull(Info temp);

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
		std::cout << "1. �������� 2. �������� 3. ����Ȯ�� 4. ������ :  ";
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
	IBack = 1;
	IFront = 0;
	ISelect = 0;
	BStart = true;
}

void Logic::Push()
{
	if (IsFull())
	{
		std::cout << "����ĭ�� ��á���ϴ�\n";
	}
	else
	{
		Info temp;
		std::cout << "\n�̸��� �Է����ּ��� : \n";
		std::cin >> temp.CName;
		std::cout << "\n�ּҸ� ������ �Է����ּ��� : \n";
		std::cin >> temp.CAdd;
		std::cout << "\n���̸� �Է��Ͽ��ּ��� : \n";
		std::cin >> temp.IAge;
		system("cls");
		Stack[IBack] = temp;
		IBack = (IBack + 1) % Max_Info;
	}
}
void Logic::Pop()
{
	if (IsEmpty())
	{
		std::cout << "���̻� ������ ������ �����ϴ�\n";
	}
	else
	{
		Info temp;
		IFront = (IFront + 1) % Max_Info;
		std::cout << "�����Ǵ� ������ " << Stack[IFront].CName << " "
			<< Stack[IFront].CAdd << " " << Stack[IFront].IAge << " �Դϴ�\n";
		Stack[IFront] = temp;
	}
}

void Logic::Print()
{
	for (int i = 0; i < Max_Info; i++)
	{
		if (Logic::IsNull(Stack[i]))
		{
			std::cout << "********����********\n";
		}
		std::cout << "���� �ι� ���� " << Stack[i].CName << " "
			<< Stack[i].CAdd << " " << Stack[i].IAge << " �Դϴ�\n";
	}
	std::cout << "*************************\n�̻��Դϴ�\n";
}

bool Logic::IsNull(Info temp)
{
	Info info;
	if (info.CName == temp.CName)
	{
		return true;
	}
	else return false;

}
bool Logic::IsFull()
{
	return IFront == IBack;
	
}
bool Logic::IsEmpty()
{
	if ((IFront + 1) % Max_Info == IBack) return true;
	else return false;
}
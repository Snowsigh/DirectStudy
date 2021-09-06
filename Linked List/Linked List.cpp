#include <iostream>

class Node
{
public:
	int iValue;
	Node* nNext;

};

class LinkedList
{
public:
	Node* n_Head;
	int Hum;
	int Select = 3;


	void Add(Node* Data);
	void Del(Node* Data);
	void ShowData();
	void CreateNode();
	void SelectNode();
	LinkedList();
	~LinkedList();


private:

};

LinkedList::LinkedList()
{
	n_Head = new Node;
	n_Head->iValue = NULL;
	n_Head->nNext = n_Head;

}

LinkedList::~LinkedList()
{
	
}
void LinkedList::Add(Node* Data)
{
	Node* Temp = n_Head->nNext;
	n_Head->nNext = Data;
	Data->nNext = Temp;
}
void LinkedList::Del(Node* Data)
{
	Node* Temp = Data->nNext;
	Data->nNext = Data->nNext->nNext;
	delete Temp;
}
void LinkedList::ShowData()
{

		for (Node* pNode = n_Head->nNext; pNode != n_Head; pNode = pNode->nNext)
		{
			std::cout << pNode->iValue << "\n";

		}
	
}
void LinkedList::CreateNode()
{
	std::cout << "인원을 적어주세요 :  ";
	std::cin >> Hum;
	std::cout << "몇번째 숫자를 적어주세요 : ";
	std::cin >> Select;
	for (int i = 0; i < Hum; i++)
	{
		Node* A = new Node;
		A->iValue = i+1;
		Add(A);
	}
	std::cout << "\n";
}
void LinkedList::SelectNode()
{
	int i = 0;
	bool LastNode = true;
	while (LastNode)
	{
		for (Node* pNode = n_Head; pNode->nNext != n_Head;)
		{
			if (pNode == pNode->nNext->nNext)
			{
				LastNode = false;
				std::cout << "\n" << pNode->nNext->iValue << " 이 살아남았습니다\n";
				break;
			}
			else
			{

				if (i == Select - 1)
				{
					std::cout << Select << " 번째였던" << pNode->nNext->iValue << " 이 걸렸습니다\n\n";
					Del(pNode);
					i = 0;
					if (pNode != pNode->nNext->nNext)
					{
						std::cout << pNode->nNext->iValue << " 부터 시작합니다.  " ;
					}
					std::cout << "남은 인원은 이상입니다\n" << "====================================\n";
					ShowData();
					std::cout  << "====================================\n";
				}
				else
				{
					pNode = pNode->nNext;
					i++;
				}
			}
		}
		

	}
	
}



int main()
{
	LinkedList t;
	t.CreateNode();
	t.SelectNode();

	



	return 0;

}



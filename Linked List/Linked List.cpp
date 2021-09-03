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
	for (Node* pNode = n_Head; pNode->nNext != n_Head;)
	{

			if (i == Select - 1)
			{
				std::cout << Select << " 번째였던" << pNode->nNext->iValue << " 이 걸렸습니다\n";
				Del(pNode);
				i = 0;

			}
			else
			{
				pNode = pNode->nNext;
				i++;
			}
	
		
		
		ShowData();
	}
}



int main()
{
	LinkedList t;
	t.CreateNode();
	t.SelectNode();

	t.ShowData();

	



	return 0;

}



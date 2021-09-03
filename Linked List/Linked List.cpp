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

	void Add(Node* Data);
	void Del(Node* Data);
	void ShowData();
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
	int i = 0;

		for (Node* pNode = n_Head->nNext; pNode != pNode->nNext; pNode = pNode->nNext)
		{
			std::cout << pNode->iValue << "\n";
			if (i > 3) break;
			i++;
		}
	
}

int main()
{
	Node* A;
	LinkedList t;
	for (int i = 0; i < 5; i++)
	{
		A = new Node;
		A->iValue = i;
		t.Add(A);

	}
	t.ShowData();
	
	t.Del(A);
	t.ShowData();




	return 0;

}



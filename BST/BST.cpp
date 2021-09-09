#include <iostream>

class Node
{
public:
	Node* p_Left;
	Node* p_Right;
	int Value;
	Node();
	~Node();

};
Node::Node() : p_Left(nullptr), p_Right(nullptr), Value(NULL) {};
Node::~Node() {};


class BinarySearchTree
{
public:
	Node* p_Root;

	void AddNode(int _Value);
	void RemoveNode(int _Value);
	bool SearchValue(int _Value);
	void Show();



	BinarySearchTree() : p_Root(nullptr) {};
	~BinarySearchTree();

private:

	Node* RemoveSystem(Node* pNode, int _Value);
	Node* SearchNode(Node* pNode)
	{
		if (pNode == NULL) return NULL;
		while (pNode->p_Right != NULL)
		{
			pNode = pNode->p_Right;
		}
		return pNode;
	}
	void Inorder(Node* pNode)
	{
		if (pNode != nullptr)
		{
			Inorder(pNode->p_Left);
			std::cout << pNode->Value << " ";
			Inorder(pNode->p_Right);
		}
	}

};
void BinarySearchTree::Show()
{
	Inorder(p_Root);
	std::cout << "\n";
}
Node* BinarySearchTree::RemoveSystem(Node* pNode, int _Value)
{
	if (pNode == nullptr) return pNode;
	else if (pNode->Value > _Value)
		pNode->p_Left = RemoveSystem(pNode->p_Left, _Value);
	else if (pNode->Value < _Value)
		pNode->p_Right = RemoveSystem(pNode->p_Right, _Value);
	else
	{
		Node* ptr = pNode;
		if (pNode->p_Right == nullptr && pNode->p_Left == nullptr)
		{
			delete pNode;
			pNode = nullptr;
		}
		else if (pNode->p_Right == nullptr)
		{
			pNode = pNode->p_Left;
			delete ptr;
		}
		else if (pNode->p_Left == nullptr)
		{
			pNode = pNode->p_Right;
			delete ptr;
		}
		else
		{
			ptr = SearchNode(pNode->p_Left);
			pNode->Value = ptr->Value;
			pNode->p_Left = RemoveSystem(pNode->p_Left, ptr->Value);

		}
	}
	return pNode;
}
bool BinarySearchTree::SearchValue(int _Value)
{
	Node* ptr = p_Root;
	Node* Temp = nullptr;

	while (ptr != nullptr)
	{
		if (ptr->Value == _Value)
		{
			std::cout << "Find!\n";
			return true;
		}
		else if(ptr->Value > _Value)
		{
			ptr = ptr->p_Left;
		}
		else
		{
			ptr = ptr->p_Right;
		}
	}
	std::cout << "Not Find\n";
	return false;
}
void BinarySearchTree::RemoveNode(int _Value)
{
	Node* ptr = p_Root;
	RemoveSystem(ptr, _Value);

}
void BinarySearchTree::AddNode(int _Value)
{
	Node* node = new Node;
	Node* temp = nullptr;

	node->Value = _Value;

	if (p_Root == nullptr)
	{
		p_Root = node;
	}
	else
	{
		Node* ptr = p_Root;

		while (ptr != nullptr)
		{
			temp = ptr;
			if (node->Value < ptr->Value)
			{
				ptr = ptr->p_Left;
			}
			else
			{
				ptr = ptr->p_Right;
			}

		}
		if (node->Value < temp->Value)
		{
			temp->p_Left = node;
		}
		else
		{
			temp->p_Right = node;
		}

	}

}
int main()
{
	BinarySearchTree* bst = new BinarySearchTree;
	for (int i = 0; i < 10; i++)
	{
		bst->AddNode(i);
	}
	bst->Show();
	bst->SearchValue(4);
	bst->SearchValue(11);
	bst->RemoveNode(4);
	bst->Show();
	bst->SearchValue(4);
	return 0;
}
#include <iostream>

template <typename T>
class Node
{
public:
	Node* p_Left;
	Node* p_Right;
	T Value;
	Node();
	~Node();

};
template <typename T>
Node<T>::Node() : p_Left(nullptr), p_Right(nullptr), Value(NULL) {};
template <typename T>
Node<T>::~Node() {};

template <typename T>
class BinarySearchTree
{
public:
	Node<T>* p_Root;

	void AddNode(T _Value);
	void RemoveNode(T _Value);
	bool SearchValue(T _Value);
	void Show();



	BinarySearchTree() : p_Root(nullptr) {};
	~BinarySearchTree();

private:

	Node<T>* RemoveSystem(Node<T>* pNode, T _Value);
	Node<T>* SearchNode(Node<T>* pNode)
	{
		if (pNode == NULL) return NULL;
		while (pNode->p_Right != NULL)
		{
			pNode = pNode->p_Right;
		}
		return pNode;
	}
	void Inorder(Node<T>* pNode)
	{
		if (pNode != nullptr)
		{
			Inorder(pNode->p_Left);
			std::cout << pNode->Value << " ";
			Inorder(pNode->p_Right);
		}
	}

};
template <typename T>
void BinarySearchTree<T>::Show()
{
	Inorder(p_Root);
	std::cout << "\n";
}
template <typename T>
Node<T>* BinarySearchTree<T>::RemoveSystem(Node<T>* pNode, T _Value)
{
	if (pNode == nullptr) return pNode;
	else if (pNode->Value > _Value)
		pNode->p_Left = RemoveSystem(pNode->p_Left, _Value);
	else if (pNode->Value < _Value)
		pNode->p_Right = RemoveSystem(pNode->p_Right, _Value);
	else
	{
		Node<T>* ptr = pNode;
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
template <typename T>
bool BinarySearchTree<T>::SearchValue(T _Value)
{
	Node<T>* ptr = p_Root;
	Node<T>* Temp = nullptr;

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
template <typename T>
void BinarySearchTree<T>::RemoveNode(T _Value)
{
	Node<T>* ptr = p_Root;
	RemoveSystem(ptr, _Value);

}
template <typename T>
void BinarySearchTree<T>::AddNode(T _Value)
{
	Node<T>* node = new Node<T>;
	Node<T>* temp = nullptr;

	node->Value = _Value;

	if (p_Root == nullptr)
	{
		p_Root = node;
	}
	else
	{
		Node<T>* ptr = p_Root;

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
	BinarySearchTree<int>* bst = new BinarySearchTree<int>;
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
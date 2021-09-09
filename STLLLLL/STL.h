#pragma once
#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<map>
#include<stack>
#include<deque>
#include<algorithm>

template <typename T>
class S_vector
{
public:
	void vector_Show(T _Value);

};
template <typename T>
void S_vector<T>::vector_Show(T _Value)
{
	std::vector<T> _vector;

	for (int i = 0; i < 10; i++)
	{
		_vector.push_back(i);
	}
	_vector.push_back(_Value);
	_vector.erase(_vector.begin()+3);
	for (int i = 0; i < _vector.size(); i++)
	{
		std::cout << _vector[i] << " ";
	}
	std::cout << "\n";
}

template <typename T>
class S_Stack
{
public:
	void Stack_Show(T _Value);

};
template <typename T>
void S_Stack<T>::Stack_Show(T _Value)
{
	std::stack<T> _stack;

	for (int i = 0; i < 10; i++)
	{
		_stack.push(i+0.5);
	}
	_stack.pop();
	_stack.push(_Value);
	
	int Max_Size = _stack.size();
	for (int i = 0; i < Max_Size; i++)
	{
		std::cout << _stack.top() << " ";
		_stack.pop();
	}
	std::cout << "\n";
}

template <typename T>
class S_List
{
public:
	void List_Show(T _Value);

};
template <typename T>
void S_List<T>::List_Show(T _Value)
{
	std::list<T> _List;

	for (int i = 0; i < 10; i++)
	{
		_List.push_back(i);
	}
	_List.pop_back();
	_List.push_back(_Value);
	_List.sort();

	int Max_Size = _List.size();
	for (int i = 0; i < Max_Size; i++)
	{
		std::cout << _List.front() << " ";
		_List.pop_front();
	}
	std::cout << "\n";
}

template <typename T>
class S_Queue
{
public:
	void Queue_Show(T _Value);

};
template <typename T>
void S_Queue<T>::Queue_Show(T _Value)
{
	std::queue<T> _queue;

	_queue.push(_Value);

	for (int i = 0; i < 10; i++)
	{
		_queue.push(i);
	}
	

	int Max_Size = _queue.size();
	for (int i = 0; i < Max_Size; i++)
	{
		std::cout << _queue.front() << " ";
		_queue.pop();
	}
	std::cout << "\n";
}

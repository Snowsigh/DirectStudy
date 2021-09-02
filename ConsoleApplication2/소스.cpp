#include <iostream>
class MyClass
{
public:
	MyClass();
	~MyClass();

private:

};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

class MyClass2 : MyClass
{
public:
	MyClass2();
	~MyClass2();

private:

};

MyClass2::MyClass2()
{
}

MyClass2::~MyClass2()
{
}
int main()
{

	return 0;
}
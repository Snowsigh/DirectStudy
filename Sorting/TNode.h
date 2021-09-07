
#include <iostream>

class TNode
{
public:
	int m_iDepth;
	int m_iValue;
	TNode* m_pChildnode[2];
	void AddBinaryNode(TNode* pNode, int iValue);
	TNode* Find(TNode* pNode, int iValue);
	TNode();
	~TNode();

private:

};
#pragma once

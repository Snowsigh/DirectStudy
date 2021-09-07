#include "TNode.h"

TNode::TNode() : m_iDepth(0), m_iValue(-1)
{
	m_pChildnode[0] = nullptr;
	m_pChildnode[1] = nullptr;
}
TNode::~TNode()
{
	int iDelData = this->m_iValue;
	if (m_pChildnode[0] != nullptr)
	{
		delete m_pChildnode[0];
		m_pChildnode[0] = nullptr;
	}
	if (m_pChildnode[1] != nullptr)
	{
		delete m_pChildnode[1];
		m_pChildnode[1] = nullptr;
	}
}
void TNode::AddBinaryNode(TNode* pNode, int iValue)
{

}
TNode* TNode::Find(TNode* pNode, int iValue)
{

}
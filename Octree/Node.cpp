#pragma once
#include "Node.h"

TNode::TNode(TVector _vPivot, TVector _vSize) // Init Node
{
	for (int iChild = 0; iChild < 8; iChild++)
	{
		m_pChildNode[iChild] = nullptr;
	}
	m_iNodeCount = 0;
	m_pParent = nullptr;
	m_iDepth = 0;
	this->m_TBox.vPivot = _vPivot;
	this->m_TBox.vMin = TVector(_vPivot.x, _vPivot.y, _vPivot.z - _vSize.z);
	this->m_TBox.vMax = TVector(_vPivot.x + _vSize.x, _vPivot.y + _vSize.y, _vPivot.z + _vSize.z);
	this->m_TBox.vSize = _vSize;
}
TNode::~TNode()
{
	for (int iChild = 0; iChild < 8; iChild++)
	{
		delete m_pChildNode[iChild];
		m_pChildNode[iChild] = nullptr;
	}

}

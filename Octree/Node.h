#pragma once
#include "TObject.h"

static int g_NewNodecount;

class TNode
{
public:
	
	
	int m_iNodeCount; // ���° ������� üũ
	TBox m_TBox; // ����� ����
	int m_iDepth; // ����, Leaf���
	TNode* m_pParent; 
	TNode* m_pChildNode[8]; 

public:

	TNode(TVector _vPivot, TVector _Size);
	~TNode();

private:

};

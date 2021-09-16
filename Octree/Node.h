#pragma once
#include "TObject.h"

static int g_NewNodecount;

class TNode
{
public:
	
	
	int m_iNodeCount; // 몇번째 노드인지 체크
	TBox m_TBox; // 노드의 영역
	int m_iDepth; // 깊이, Leaf노드
	TNode* m_pParent; 
	TNode* m_pChildNode[8]; 

public:

	TNode(TVector _vPivot, TVector _Size);
	~TNode();

private:

};

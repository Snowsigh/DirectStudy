#pragma once
#include "TObject.h"

static int g_NewNodecount; // Node Count

class TNode
{
public:
	
	
	int m_iNodeCount; // Node Numbering <- NewNodeCount
	TBox m_TBox;      // Area
	int m_iDepth; 
	TNode* m_pParent; 
	TNode* m_pChildNode[8]; 

public:

	TNode(TVector _vPivot, TVector _Size);
	~TNode();

private:

};

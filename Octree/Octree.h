#pragma once
#include "Node.h"

class TOctree
{
public:
	TNode* m_pRootNode;
	TVector m_vSize; 
	std::map<TNode*, TObject*>m_ObjectList; // ������ ������Ʈ (��ġ, ������)
	TObject* m_pPlayer;
public:
	bool Init(float _x, float _y, float _z);
	TNode* SetNode(TNode* _Parent, TVector _Min, TVector _Max);
	bool SetUpNode(TNode* _pNode);
	bool CheakObject(TNode* _pNode, TObject* _Obj);
	TNode* FindNode(TNode* _pNode, TObject* _Obj);
	bool AddObject(TObject* _Obj);
	bool DeleteObject(TObject* _Obj);
	void ClearNode();

public:
	void Frame(float _time);
	TOctree();
	virtual ~TOctree();
	
private:

};

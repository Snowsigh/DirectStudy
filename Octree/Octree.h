#pragma once
#include "Node.h"

//Octree Info
class TOctree
{
public:
	TNode* m_pRootNode; 
	TNode* m_pLastNode; // last Object Position Node
	TVector m_vSize; // Rootnode Size
	std::map<TNode*, TObject*>m_ObjectList; // List of bjects in the node.
	TObject* m_pPlayer;
	std::queue<TNode*> m_pQueue; //Object Position Node

public:
	bool Init(float _x, float _y, float _z);
	TNode* SetNode(TNode* _Parent, TVector _Min, TVector _Max);
	bool SetUpNode(TNode* _pNode);
	bool CheakObject(TNode* _pNode, TObject* _Obj);
	TNode* FindNode(TNode* _pNode, TObject* _Obj);
	bool AddObject(TObject* _Obj);
	bool DeleteObject(TObject* _Obj);
	void ClearNode();
	void Frame(float _time);
public:
	
	TOctree();
	virtual ~TOctree();
	
private:

};

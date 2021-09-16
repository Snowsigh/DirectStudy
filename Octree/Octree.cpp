#pragma once
#include "Octree.h"
TOctree::TOctree()
{

	m_pRootNode = nullptr;
}

TOctree::~TOctree()
{
}
void TOctree::Frame(float _time)
{
	static float fDirection = 1.0f;
	if (m_pPlayer->m_vPos.x > 100.0f || m_pPlayer->m_vPos.x < 0.0f)
	{
		fDirection *= 1.0f;
	}
	m_pPlayer->m_vVelocity.x = 10.0f * fDirection;
	m_pPlayer->m_vVelocity.y = 0.0f;
	m_pPlayer->m_vPos += m_pPlayer->m_vVelocity * _time;

	TVector vHalf = m_pPlayer->m_tBox.vSize / 2.0f;
	m_pPlayer->m_tBox.vPivot = { m_pPlayer->m_vPos.x - vHalf.x, m_pPlayer->m_vPos.y - vHalf.y, m_pPlayer->m_vPos.z + vHalf.z};
	m_pPlayer->m_tBox.vMin = { m_pPlayer->m_vPos.x - vHalf.x, m_pPlayer->m_vPos.y - vHalf.y, m_pPlayer->m_vPos.z - vHalf.z };
	m_pPlayer->m_tBox.vMax = { m_pPlayer->m_vPos.x + vHalf.x, m_pPlayer->m_vPos.y + vHalf.y, m_pPlayer->m_vPos.z + vHalf.z };
	
	TNode* pFind = FindNode(m_pRootNode, m_pPlayer);
	if (pFind != nullptr)
	{
		std::cout << pFind->m_iNodeCount << " ";
		std::cout << "( " << m_pPlayer->m_vPos.x << "," << m_pPlayer->m_vPos.y << "," << m_pPlayer->m_vPos.z << " )";
	}
}
bool TOctree::Init(float _x, float _y, float _z)
{
	m_pPlayer = new TObject();
	m_vSize = { _x,_y,_z };
	m_pRootNode = SetNode(nullptr, TVector(0, 0, 0), m_vSize);
	SetUpNode(m_pRootNode);

	return true;
}

TNode* TOctree::SetNode(TNode* _Parent, TVector _vPivot, TVector _vSize)
{
	TNode* pNode = new TNode(_vPivot, _vSize);
	
	if (_Parent != nullptr)
	{
		pNode->m_iDepth = _Parent->m_iDepth + 1;
		pNode->m_pParent = _Parent;
	}
	pNode->m_iNodeCount = g_NewNodecount;
	g_NewNodecount++;
	return pNode;
}
bool TOctree::SetUpNode(TNode* _pNode)
{
	if (_pNode->m_TBox.vSize.x >= 30.0f && _pNode->m_TBox.vSize.y >= 30.0f && _pNode->m_TBox.vSize.z >= 30.0f)
	{
		TVector vHalf = _pNode->m_TBox.vSize / 2.0f;

		_pNode->m_pChildNode[0] = SetNode(_pNode, _pNode->m_TBox.vPivot, vHalf);
		SetUpNode(_pNode->m_pChildNode[0]);

		_pNode->m_pChildNode[1] = SetNode(_pNode, TVector(_pNode->m_TBox.vPivot.x + vHalf.x, _pNode->m_TBox.vPivot.y, _pNode->m_TBox.vPivot.z), vHalf);
		SetUpNode(_pNode->m_pChildNode[1]);

		_pNode->m_pChildNode[2] = SetNode(_pNode, TVector(_pNode->m_TBox.vPivot.x + vHalf.x, _pNode->m_TBox.vPivot.y, _pNode->m_TBox.vPivot.z - vHalf.z), vHalf);
		SetUpNode(_pNode->m_pChildNode[2]);

		_pNode->m_pChildNode[3] = SetNode(_pNode, TVector(_pNode->m_TBox.vPivot.x, _pNode->m_TBox.vPivot.y, _pNode->m_TBox.vPivot.z - vHalf.z), vHalf);
		SetUpNode(_pNode->m_pChildNode[3]);

		_pNode->m_pChildNode[4] = SetNode(_pNode, TVector(_pNode->m_TBox.vPivot.x, _pNode->m_TBox.vPivot.y + vHalf.y, _pNode->m_TBox.vPivot.z), vHalf);
		SetUpNode(_pNode->m_pChildNode[4]);

		_pNode->m_pChildNode[5] = SetNode(_pNode, TVector(_pNode->m_TBox.vPivot.x + vHalf.x, _pNode->m_TBox.vPivot.y + vHalf.y, _pNode->m_TBox.vPivot.z), vHalf);
		SetUpNode(_pNode->m_pChildNode[5]);

		_pNode->m_pChildNode[6] = SetNode(_pNode, TVector(_pNode->m_TBox.vPivot.x + vHalf.x, _pNode->m_TBox.vPivot.y + vHalf.y, _pNode->m_TBox.vPivot.z - vHalf.z), vHalf);
		SetUpNode(_pNode->m_pChildNode[6]);

		_pNode->m_pChildNode[7] = SetNode(_pNode, TVector(_pNode->m_TBox.vPivot.x, _pNode->m_TBox.vPivot.y + vHalf.y, _pNode->m_TBox.vPivot.z - vHalf.z), vHalf);
		SetUpNode(_pNode->m_pChildNode[7]);
	}
	return true;
}
bool TOctree::CheakObject(TNode* _pNode, TObject* _Obj)
{
	if (_pNode->m_TBox.vMax.x >= _Obj->m_vPos.x && _pNode->m_TBox.vMin.x <= _Obj->m_vPos.x && //맥시멈보다 작고 미니멈보다 클경우, 안에 들어와있다.
		_pNode->m_TBox.vMax.y >= _Obj->m_vPos.y && _pNode->m_TBox.vMin.y <= _Obj->m_vPos.y &&
		_pNode->m_TBox.vMax.z >= _Obj->m_vPos.z && _pNode->m_TBox.vMin.z <= _Obj->m_vPos.z)
	{
		return true;
	}
	return false;
}
TNode* TOctree::FindNode(TNode* _pNode, TObject* _Obj)
{
	if (_pNode->m_pChildNode[0] != nullptr)
	{
		if (CheakObject(_pNode, _Obj))
		{
			for (int iChild = 0; iChild < 8; iChild++)
			{
				if (CheakObject(_pNode->m_pChildNode[iChild], _Obj))
				{
					 FindNode(_pNode->m_pChildNode[iChild], _Obj);
				}
			}
		}
	}
	return _pNode;
}

bool TOctree::AddObject(TObject* _Obj)
{
	TNode* pFindNode = FindNode(m_pRootNode, _Obj);
	if (pFindNode != nullptr)
	{
		_Obj->m_iNodeIndex = m_ObjectList.size();
		m_ObjectList.insert(std::pair<TNode*, TObject*>(pFindNode, _Obj));
		return true;

	}
	return false;
}

bool TOctree::DeleteObject(TObject* _Obj)
{
	TNode* pDeleteNode = FindNode(m_pRootNode, _Obj);
	if(pDeleteNode != nullptr)
	{
		m_ObjectList.erase(pDeleteNode);
		return true;
	}
	return false;
}

void TOctree::ClearNode()
{
	delete m_pRootNode;
	m_pRootNode = nullptr;
	for (auto& obj : m_ObjectList)
	{
		delete obj.second;
	}
	m_ObjectList.clear();
}


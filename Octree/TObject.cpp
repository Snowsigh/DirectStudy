#pragma once
#include "TObject.h"


TObject::TObject() : m_iNodeIndex(0) // Default Object
{
	m_vPos = { 0, 0, 0 };
	
	m_tBox.vSize = { 4.0f, 4.0f, 4.0f };
	TVector vHalf = m_tBox.vSize / 2.0f;
	m_tBox.vPivot = { m_vPos.x - vHalf.x, m_vPos.y - vHalf.y, m_vPos.z + vHalf.z };
	m_tBox.vMin = { m_vPos.x - vHalf.x, m_vPos.y - vHalf.y, m_vPos.z - vHalf.z };
	m_tBox.vMax = { m_vPos.x + vHalf.x, m_vPos.y + vHalf.y, m_vPos.z + vHalf.z };
}
TObject::TObject(TVector _Pos, TVector _vSize) : m_iNodeIndex(0) // Create Static Object
{
	m_vPos = _Pos;

	m_tBox.vSize = _vSize;
	TVector vHalf = m_tBox.vSize / 2.0f;
	m_tBox.vPivot = { m_vPos.x - vHalf.x, m_vPos.y - vHalf.y, m_vPos.z + vHalf.z };
	m_tBox.vMin = { m_vPos.x - vHalf.x, m_vPos.y - vHalf.y, m_vPos.z - vHalf.z };
	m_tBox.vMax = { m_vPos.x + vHalf.x, m_vPos.y + vHalf.y, m_vPos.z + vHalf.z };

}
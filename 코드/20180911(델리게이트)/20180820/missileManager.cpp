#include "stdafx.h"
#include "missileManager.h"


HRESULT missileManager::init(const char* szImageName, float range, int maxCount)
{
	m_fRange = range;
	m_nMaxCount = maxCount;
	m_szImageName = szImageName;

	//m_vecMissile.resize(m_nMaxCount);
	m_vecMissile.reserve(m_nMaxCount);

	// 벡터의 원소의 갯수
	//int size = m_vecMissile.size();

	return S_OK;
}

void missileManager::release()
{
	for (m_iter = m_vecMissile.begin(); 
		m_iter != m_vecMissile.end(); m_iter++)
	{
		delete (*m_iter);
	}
	m_vecMissile.clear();
}

void missileManager::update()
{
	for (m_iter = m_vecMissile.begin(); m_iter != m_vecMissile.end(); m_iter++)
	{
		(*m_iter)->update();
	}
}

void missileManager::render(HDC hdc)
{
	for (m_iter = m_vecMissile.begin(); m_iter != m_vecMissile.end(); m_iter++)
	{
		(*m_iter)->render(hdc);
	}
}

void missileManager::fire(float x, float y, float angle, float speed)
{
	//if (m_vecMissile.size() > m_nMaxCount)	return;

	missile* pMissile = new missile;
	//missile* pMissile = new enemyMissile;

	// 1. reserve 했을 때
	pMissile->init(m_szImageName, speed, x, y, angle, 1000);
	m_vecMissile.push_back(pMissile);

	// 타겟을 설정해 준다
	pMissile->setTarget(m_pTarget);

	pMissile->fire(x, y);

	//// 2. resize 했을 때
	//m_vecMissile[0]->init(m_szImageName, speed,
	//	x, y, angle, 100);
}

void missileManager::move()
{
}

missileManager::missileManager()
{
}


missileManager::~missileManager()
{
}

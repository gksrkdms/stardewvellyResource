#include "stdafx.h"
#include "enemy.h"
#include "missileManager.h"

HRESULT enemy::init()
{
	m_nCount = 0;
	m_nCurrFrameX = 0;
	m_nCurrFrameY = 0;
	m_pImg = NULL;

	ZeroMemory(&m_rc, sizeof(m_rc));

	m_pMissileMgr = new missileManager;
	m_pMissileMgr->init("image/bullet.bmp", 200.0f, 10);
	m_nFireCount = 0;
	m_nRandFireCount = 10;
	m_fX = 0;
	m_fY = 0;

	return S_OK;
}

HRESULT enemy::init(const char * szFileName, POINT position)
{
	m_nCount = 0;
	m_nCurrFrameX = 0;
	m_nCurrFrameY = 0;
	std::string strFile = std::string(szFileName);
	m_pImg = IMAGEMANAGER->addImage(strFile, szFileName,
		530, 32, 10, 1, true, RGB(255, 0, 255));

	m_rc = RectMakeCenter(position.x, position.y,
		m_pImg->getFrameWidth(), m_pImg->getFrameHeight());

	m_pMissileMgr = new missileManager;
	m_pMissileMgr->init("image/bullet.bmp", 200.0f, 10);
	m_nFireCount = 0;
	m_nRandFireCount = 10;
	m_fX = position.x;
	m_fY = position.y;

	return S_OK;
}

void enemy::release()
{
	if (m_pMissileMgr)
	{
		m_pMissileMgr->release();
		delete m_pMissileMgr;
	}
}

void enemy::update()
{
	if (m_pImg)
	{
		m_nCount++;
		if (m_nCount % 5 == 0)
		{
			m_nCurrFrameX++;
			m_pImg->setFrameX(m_nCurrFrameX);
			if (m_nCurrFrameX > m_pImg->getMaxFrameX())
			{
				m_nCurrFrameX = 0;
			}
		}
	}

	fire();

	if (m_pMissileMgr)
		m_pMissileMgr->update();
}

void enemy::render(HDC hdc)
{
	if (m_pImg)
	{
		Rectangle(hdc, m_rc.left, m_rc.top, m_rc.right, m_rc.bottom);

		m_pImg->frameRender(hdc,
			m_fX - m_pImg->getFrameWidth() / 2, m_fY - m_pImg->getFrameHeight() / 2,
			m_nCurrFrameX, m_nCurrFrameY);
	}

	if (m_pMissileMgr)
	{
		m_pMissileMgr->render(hdc);
	}
}

void enemy::move()
{
	m_rc = RectMakeCenter(m_fX, m_fY,
		m_pImg->getFrameWidth(), m_pImg->getFrameHeight());
}

void enemy::fire()
{
	m_nFireCount++;
	if (m_nFireCount % m_nRandFireCount == 0)
	{
		m_pMissileMgr->fire(m_fX, m_fY,
			270.0f, 5);

		m_pMissileMgr->setTarget(m_pTarget);

		m_nFireCount = 0;
		m_nRandFireCount = RANDOM->getFromIntTo(150, 250);
	}
}

enemy::enemy()
{
}


enemy::~enemy()
{
}

#include "stdafx.h"
#include "spaceShip.h"
#include "missile.h"
#include "progressBar.h"
#include "action.h"

POINT starPos[5] = {
	{ WINSIZEX / 2, WINSIZEY / 2 - 100 },
	{ WINSIZEX / 2 + 100, WINSIZEY / 2 + 100 },
	{ WINSIZEX / 2 - 100, WINSIZEY / 2 - 60 },
	{ WINSIZEX / 2 + 100, WINSIZEY / 2 - 60 },
	{ WINSIZEX / 2 - 100, WINSIZEY / 2 + 100 }
};
static void setNextTarget1(int posIdx, LONG* pX, LONG* pY)
{
	(*pX) = starPos[posIdx % 5].x;
	(*pY) = starPos[posIdx % 5].y;
}

static void setNextTarget2()
{

}

HRESULT spaceShip::init()
{
	m_img = IMAGEMANAGER->addImage("spaceShip", "image/rocket.bmp",
		52, 64, true, RGB(255, 0, 255));
	//m_img->setX(WINSIZEX / 2 - m_img->getWidth() / 2);
	//m_img->setY(WINSIZEY / 2 - m_img->getHeight() / 2 + 200);

	m_fSpeed = 5.0f;
	m_fX = WINSIZEX / 2;// -m_img->getWidth() / 2;
	m_fY = WINSIZEY / 2 + 200;// -m_img->getHeight() / 2 + 200;

	m_rc = RectMakeCenter(m_fX, m_fY, m_img->getWidth(), m_img->getHeight());

	// 미사일
	m_pMissile = new missile;
	m_pMissile->init();

	// 액션 미사일
	m_pActionMissile = new action;
	m_pActionMissile->init("image/bullet.bmp", 5.0f, m_fX, m_fY, 0.0f, 100.0f);

	// 체력바
	m_pHPBar = new progressBar;
	m_pHPBar->init(m_fX - (m_img->getWidth() / 2),
		m_fY - (m_img->getHeight() / 2) - 10,
		53, 5);

	m_nCurrHP = m_nMaxHP = 100;

	return S_OK;
}

void spaceShip::release()
{
	SAFE_DELETE(m_pActionMissile);
	delete m_pHPBar;
	delete m_pMissile;
}

void spaceShip::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_SPACE))
	{
		if (m_pMissile)
			m_pMissile->fire(m_fX, m_fY);
	}

	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		if (m_pActionMissile)
			m_pActionMissile->moveTo(
				PointMake(m_fX, m_fY), PointMake(m_fX, m_fY - 200), 
				1.0f, setNextTarget1);
	}


	if (KEYMANAGER->isStayKeyDown(VK_LEFT)
		&& (m_fX > 0))
	{
		//m_img->setX(m_img->getX() - m_fSpeed);
		m_fX -= m_fSpeed;
	}
	else if (KEYMANAGER->isStayKeyDown(VK_RIGHT)
		&& (m_fX + m_img->getWidth() < WINSIZEX))
	{
		//m_img->setX(m_img->getX() + m_fSpeed);
		m_fX += m_fSpeed;
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP)
		&& (m_fY > 0))
	{
		//m_img->setY(m_img->getY() - m_fSpeed);
		m_fY -= m_fSpeed;
	}
	else if (KEYMANAGER->isStayKeyDown(VK_DOWN)
		&& (m_fY + m_img->getHeight() < WINSIZEY))
	{
		//m_img->setY(m_img->getY() + m_fSpeed);
		m_fY += m_fSpeed;
	}


	m_rc = RectMakeCenter(m_fX, m_fY, 
		m_img->getWidth(), m_img->getHeight());

	if (m_pMissile)
		m_pMissile->update();

	if (m_pActionMissile)
		m_pActionMissile->update();

	if (m_pHPBar)
	{
		m_pHPBar->setX(m_fX - m_img->getWidth() / 2);
		m_pHPBar->setY(m_fY - m_img->getHeight() / 2 - 10);
		m_pHPBar->update();
	}
}

void spaceShip::render(HDC hdc)
{
	//Rectangle(hdc, m_rc.left, m_rc.top, m_rc.right, m_rc.bottom);

	//m_img->render(hdc, m_fX - m_img->getWidth() / 2, m_fY - m_img->getHeight() / 2);
	m_img->alphaRender(hdc, 
		m_fX - m_img->getWidth() / 2, m_fY - m_img->getHeight() / 2, 150);
	//m_fX - m_img->getWidth() / 2, m_fY - m_img->getHeight() / 2);

	if (m_pMissile)
		m_pMissile->render(hdc);

	if (m_pActionMissile)
		m_pActionMissile->render(hdc);

	if (m_pHPBar)
		m_pHPBar->render(hdc);
}

void spaceShip::damaged(int damage)
{
	m_nCurrHP -= damage;
	if (m_nCurrHP <= 0)
	{
		m_nCurrHP = 0;
	}

	if (m_pHPBar)
	{
		m_pHPBar->setGauge(m_nCurrHP, m_nMaxHP);
	}
}

spaceShip::spaceShip()
{
}


spaceShip::~spaceShip()
{
}

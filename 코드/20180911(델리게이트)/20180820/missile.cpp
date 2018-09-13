#include "stdafx.h"
#include "missile.h"
#include "spaceShip.h"

//using namespace MY_UTIL;

HRESULT missile::init()
{
	m_fAngle = 0.0f;
	m_fRange = 500.0f;
	m_fSpeed = 5.0f;
	m_fX = 0.0f;
	m_fY = 0.0f;
	m_fFiredX = 0.0f;
	m_fFiredY = 0.0f;
	m_isFire = false;

	//memset(&m_rc, 3, sizeof(m_rc));
	ZeroMemory(&m_rc, sizeof(m_rc));

	m_pImg = IMAGEMANAGER->addImage("missile_1", "image/missile.bmp",
		26, 124, true, RGB(255, 0, 255));

	return S_OK;
}

HRESULT missile::init(const char * szImageName, float speed,
	float x, float y, float angle, float range)
{
	m_fAngle = angle;
	m_fRange = range;
	m_fSpeed = speed;
	m_fX = x;
	m_fY = y;
	m_fFiredX = x;
	m_fFiredY = y;
	m_isFire = false;

	//memset(&m_rc, 3, sizeof(m_rc));
	ZeroMemory(&m_rc, sizeof(m_rc));

	m_pImg = IMAGEMANAGER->findImage("enemy_missile_1");

	return S_OK;
}

void missile::release()
{
}

void missile::update()
{
	move();
}

void missile::render(HDC hdc)
{
	if (m_isFire)
	{
		Rectangle(hdc, m_rc.left, m_rc.top, m_rc.right, m_rc.bottom);
		m_pImg->render(hdc, m_fX - m_pImg->getWidth() / 2, m_fY - m_pImg->getHeight() / 2);
	}
}

void missile::fire(float x, float y)
{
	if (!m_isFire)
	{
		m_isFire = true;
		// 시작 위치
		m_fFiredX = m_fX = x;
		m_fFiredY = m_fY = y;

		m_rc = RectMakeCenter(m_fX, m_fY, 
			m_pImg->getWidth(), m_pImg->getHeight());

		// 플레이어의 위치를 알아야 각도를 구할 수 있다
		if (m_pTarget)
		{
			m_fAngle = MY_UTIL::getAngle(
				m_fX, m_fY,
				m_pTarget->getX(), m_pTarget->getY());
		}

		int a = 0;
	}
}

void missile::move()
{
	if (m_isFire)
	{
		m_fX += cosf(m_fAngle) * m_fSpeed;
		m_fY += -sinf(m_fAngle) * m_fSpeed;

		m_rc = RectMakeCenter(m_fX, m_fY,
			m_pImg->getWidth(), m_pImg->getHeight());

		if (m_fRange < MY_UTIL::getDistance(m_fFiredX, m_fFiredY, m_fX, m_fY))
		{
			m_isFire = false;
		}
	}
}

missile::missile()
{
}


missile::~missile()
{
}

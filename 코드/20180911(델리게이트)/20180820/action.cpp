#include "stdafx.h"
#include "action.h"


void action::moveTo(POINT start, POINT end, float moveTime, CALLBACK_FUNC_MOVE cb)
{
	m_isFire = true;
	m_rc = RectMakeCenter(m_fX, m_fY,
		m_pImg->getWidth(), m_pImg->getHeight());

	m_fX = start.x;
	m_fY = start.y;
	m_ptStart = start;
	m_ptEnd = end;
	m_fAngle = MY_UTIL::getAngle(start.x, start.y, end.x, end.y);
	m_fMoveTime = moveTime;
	m_fSpeed = MY_UTIL::getDistance(start.x, start.y, end.x, end.y) / 
		m_fMoveTime * TIMEMANAGER->getElapsedTime();
	m_cb = cb;
	//m_nPosIdx = 0;
}

void action::move()
{
	if (m_isFire)
	{
		m_fX += cosf(m_fAngle) * m_fSpeed;
		m_fY += -sinf(m_fAngle) * m_fSpeed;

		m_rc = RectMakeCenter(m_fX, m_fY,
			m_pImg->getWidth(), m_pImg->getHeight());

		if (MY_UTIL::getDistance(m_fX, m_fY, m_ptEnd.x, m_ptEnd.y) < 0.3f)
		{
			m_fX = m_ptEnd.x;
			m_fY = m_ptEnd.y;

			if (m_cb)
			{
				m_cb(m_nPosIdx, &m_ptEnd.x, &m_ptEnd.y);
				moveTo(PointMake(m_fX, m_fY), PointMake(m_ptEnd.x, m_ptEnd.y),
					1.0f, m_cb);
				m_nPosIdx++;
			}

			//m_isFire = false;
		}
	}
}

action::action()
	: m_cb(NULL)
	, m_fMoveTime(0.0f)
	//, m_fAngle(0.0f)
	//, m_fSpeed(0.0f)
	, m_isMoving(false)
	, m_nPosIdx(0)
{
	m_ptStart = { 0, 0 };
	m_ptEnd = { 0, 0 };
}


action::~action()
{
}

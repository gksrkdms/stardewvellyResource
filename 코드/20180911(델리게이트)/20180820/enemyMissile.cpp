#include "stdafx.h"
#include "enemyMissile.h"


void enemyMissile::move()
{
	if (m_isFire)
	{
		m_fY += m_fSpeed;

		if (m_fRange < MY_UTIL::getDistance(m_fFiredX, m_fFiredY, m_fX, m_fY))
		{
			m_isFire = false;
		}
	}
}

enemyMissile::enemyMissile()
{
}


enemyMissile::~enemyMissile()
{
}

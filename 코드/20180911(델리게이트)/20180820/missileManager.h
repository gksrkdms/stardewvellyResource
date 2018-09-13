#pragma once
#include <vector>
#include "missile.h"
#include "enemyMissile.h"

class missileManager
{
private:
	std::vector<missile*>	m_vecMissile;
	std::vector<missile*>::iterator	m_iter;

	const char* m_szImageName;
	float		m_fRange;
	int			m_nMaxCount;

	// Å¸°Ù
	spaceShip*	m_pTarget;

public:
	HRESULT init(const char* szImageName, float range, int maxCount);
	void release();
	void update();
	void render(HDC hdc);

	void fire(float x, float y, float angle, float speed);
	void move();

	inline std::vector<missile*> getVecMissile()
	{
		return m_vecMissile;
	}
	inline void setTarget(spaceShip* pTarget) { m_pTarget = pTarget; }

	missileManager();
	~missileManager();
};


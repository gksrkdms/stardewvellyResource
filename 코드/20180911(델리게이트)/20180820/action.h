#pragma once
#include "missile.h"

typedef void(*CALLBACK_FUNC)(void);
typedef void(*CALLBACK_FUNC_MOVE)(int, LONG*, LONG*);

class action : public missile
{
private:
	//float	m_fX;
	//float	m_fY;
	//float	m_fEndX;
	//float	m_fEndY;
	POINT	m_ptStart;
	POINT	m_ptEnd;
	//float	m_fAngle;
	//float	m_fSpeed;
	float	m_fMoveTime;

	bool	m_isMoving;

	int		m_nPosIdx;
	CALLBACK_FUNC_MOVE	m_cb;

public:
	//virtual HRESULT init();
	//virtual HRESULT init(const char* szImageName, float speed,
	//	float x, float y, float angle, float range);
	//virtual void release();
	//virtual void update();
	//virtual void render(HDC hdc);

	void moveTo(POINT start, POINT end, float moveTime, CALLBACK_FUNC_MOVE cb = NULL);
	virtual void move() override;

	action();
	~action();
};


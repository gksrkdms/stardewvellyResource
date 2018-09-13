#pragma once
class spaceShip;

class missile
{
protected:
	image * m_pImg;
	RECT	m_rc;
	//int		m_radius;
	float	m_fSpeed;
	float	m_fX, m_fY;
	float	m_fFiredX, m_fFiredY;
	float	m_fAngle;
	float	m_fRange;
	bool	m_isFire;

	spaceShip*	m_pTarget;

public:
	virtual HRESULT init();
	virtual HRESULT init(const char* szImageName, float speed,
		float x, float y, float angle, float range);
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	void fire(float x, float y);
	virtual void move();

	inline RECT getRect() { return m_rc; }
	inline void setIsFire(bool isFire) { m_isFire = isFire; }
	inline bool getIsFire() { return m_isFire; }
	inline void setTarget(spaceShip* pTarget) { m_pTarget = pTarget; }

	missile();
	virtual ~missile();
};


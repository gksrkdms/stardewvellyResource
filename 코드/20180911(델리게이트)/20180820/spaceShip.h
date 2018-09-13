#pragma once

class missile;
class progressBar;
class action;

class spaceShip
{
private:
	image * m_img;
	RECT	m_rc;
	float	m_fSpeed;
	float	m_fX;
	float	m_fY;

	missile*	m_pMissile;
	action*		m_pActionMissile;

	progressBar*	m_pHPBar;
	int				m_nCurrHP;
	int				m_nMaxHP;

public:
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	inline RECT getRect() { return m_rc; }
	inline float getX() { return m_fX; }
	inline float getY() { return m_fY; }

	//inline progressBar* getHPBar() { return m_pHPBar; }
	inline void setCurrHP(int hp) { m_nCurrHP = hp; }
	//inline void damaged(int damage) { m_nCurrHP -= damage; }
	void damaged(int damage);

	spaceShip();
	~spaceShip();
};


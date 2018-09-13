#pragma once
#include "scene.h"

class spaceShip;
class enemyManager;
class camel;
class button;

class battleScene : public scene
{
private:
	image *			m_imgMap;
	spaceShip*		m_pSpaceShip;
	enemyManager*	m_pEnemyMgr;
	camel*			m_pCamel;

	// save load test
	std::vector<std::string> m_vecLoad;

	// UI test
	button*		m_pButton1;
	button*		m_pButton2;

	//int			m_idxBG;
	static int	m_idxBG;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	void checkCollision();

	//void buttonFunc1(void);
	//void buttonFunc2(void);

	friend void buttonFunc1(void);
	friend void buttonFunc2(void);

	battleScene();
	~battleScene();
};


#pragma once
#include "scene.h"

class loadingScene_1 : public scene
{
private:
	image * m_pBG;
	char	m_szText[128];
	float	m_fElapsedTime;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	loadingScene_1();
	~loadingScene_1();
};


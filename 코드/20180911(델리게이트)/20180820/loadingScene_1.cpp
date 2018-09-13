#include "stdafx.h"
#include "loadingScene_1.h"


HRESULT loadingScene_1::init()
{
	m_pBG = IMAGEMANAGER->addImage("loading_1", "image/¼öÁö2.bmp",
		600, 800);
	m_fElapsedTime = 0.0f;

	return S_OK;
}

void loadingScene_1::release()
{
}

void loadingScene_1::update()
{
	m_fElapsedTime += TIMEMANAGER->getElapsedTime();
}

void loadingScene_1::render(HDC hdc)
{
	m_pBG->render(hdc, 0, 0);
	sprintf_s(m_szText, 128, "%d", (int)m_fElapsedTime);
	TextOut(hdc, 100, 60, m_szText, strlen(m_szText));
}

loadingScene_1::loadingScene_1()
{
}


loadingScene_1::~loadingScene_1()
{
}

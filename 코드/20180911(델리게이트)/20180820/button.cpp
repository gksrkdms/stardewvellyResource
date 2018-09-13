#include "stdafx.h"
#include "button.h"
#include "battleScene.h"

HRESULT button::init(const char * szImageName, 
	int x, int y, POINT ptBtnDown, POINT ptBtnUp, CALLBACK_FUNC cb)
{
	m_strImgName = szImageName;
	// 기존에 하던 이미지 로드 방식
	//m_pImg = IMAGEMANAGER->addImage(m_strImgName, szImageName, )

	// 이미지 로드는 씬로드에서 모두 처리
	m_pImg = IMAGEMANAGER->findImage(m_strImgName);
	m_fX = x;
	m_fY = y;

	m_rc = RectMakeCenter(x, y,
		m_pImg->getFrameWidth(), m_pImg->getFrameHeight());

	m_ptBtnDown = ptBtnDown;
	m_ptBtnUp = ptBtnUp;

	m_callbackFunction = cb;

	m_state = BUTTON_STATE::IDLE;

	return S_OK;
}

void button::release()
{
}

void button::update()
{
	if (PtInRect(&m_rc, g_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			m_state = BUTTON_STATE::DOWN;
		}
		else if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON)
			&& m_state == BUTTON_STATE::DOWN)
		{
			m_state = BUTTON_STATE::UP;
			//m_callbackFunction();
			//((battleScene*)m_pScene->*m_callbackFunction)();
			//((battleScene*)m_pScene)->buttonFunc1();
		}
	}
	else
	{
		m_state = BUTTON_STATE::IDLE;
	}
}

void button::render(HDC hdc)
{
	switch (m_state)
	{
	case BUTTON_STATE::IDLE:
	case BUTTON_STATE::UP:
		m_pImg->frameRender(hdc, m_rc.left, m_rc.top,
			m_ptBtnUp.x, m_ptBtnUp.y);
		break;
	case BUTTON_STATE::DOWN:
		m_pImg->frameRender(hdc, m_rc.left, m_rc.top,
			m_ptBtnDown.x, m_ptBtnDown.y);
		break;
	}
}

button::button()
{
}


button::~button()
{
}

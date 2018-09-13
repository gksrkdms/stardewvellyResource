#include "stdafx.h"
#include "uiButton.h"


HRESULT uiButton::init(const char* szImageName, float x, float y, POINT ptBtnDown, POINT ptBtnUp, int num)
{
	string str = szImageName;
	m_pImg = IMAGEMANAGER->findImage(str);
	m_position.x = x;
	m_position.y = y;

	m_rc = RectMake(m_position.x, m_position.y, m_pImg->getWidth(), m_pImg->getHeight());
	m_ptBtnDown = ptBtnDown;
	m_ptBtnUp = ptBtnUp;
	m_state = ButtonState::IDLE;

	m_nTag = num;

	return S_OK;
}

void uiButton::update()
{
	if (true)
	{
		
	}
	if (PtInRect(&m_rc, g_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			m_state = ButtonState::DOWN;
		}
		else if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON)
			&& m_state == ButtonState::DOWN)
		{
			if (m_pDelegate)
				m_pDelegate->OnClick(this);
			m_state = ButtonState::UP;
			//m_callbackFunction();
			//((battleScene*)m_pScene->*m_callbackFunction)();
			//((battleScene*)m_pScene)->buttonFunc1();
		}
	}
	else
	{
		m_state = ButtonState::IDLE;
	}

}

void uiButton::render(HDC hdc)
{
	switch (m_state)
	{
	case ButtonState::IDLE:
	case ButtonState::UP:
		m_pImg->frameRender(hdc, m_rc.left, m_rc.top,
			m_ptBtnUp.x, m_ptBtnUp.y);
		break;
	case ButtonState::DOWN:
		m_pImg->frameRender(hdc, m_rc.left, m_rc.top,
			m_ptBtnDown.x, m_ptBtnDown.y);
		break;
	}
}

uiButton::uiButton()
	:m_pImg(NULL)
{
}


uiButton::~uiButton()
{
}

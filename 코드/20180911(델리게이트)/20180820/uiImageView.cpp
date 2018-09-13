#include "stdafx.h"
#include "uiImageView.h"


HRESULT uiImageView::init(const char * szImageName, float x, float y, bool hidden, int num)
{
	string str = szImageName;
	m_pImg = IMAGEMANAGER->findImage(str);
	m_position.x = x;
	m_position.y = y;

	m_rc = RectMake(m_position.x, m_position.y, m_pImg->getWidth(), m_pImg->getHeight());

	m_isHidden = hidden;

	return S_OK;
}

void uiImageView::update()
{
	uiObject::update();
}

void uiImageView::render(HDC hdc)
{
	if (m_isHidden) return;

	m_pImg->render(hdc, m_position.x, m_position.y);

	uiObject::render(hdc);
}

uiImageView::uiImageView()
	:m_pImg(NULL)
{
}


uiImageView::~uiImageView()
{
}

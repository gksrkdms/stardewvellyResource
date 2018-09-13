#include "stdafx.h"
#include "uiManager.h"


HRESULT uiManager::init()
{
	m_isChangeScene = false;
	m_isPopUp = false;
	return S_OK;
}

void uiManager::release()
{
	//m_iter = m_vecUIObjects.begin();
	//for (; m_iter != m_vecUIObjects.end(); m_iter++)
	//{
	//	(*m_iter)->release();
	//}
}

void uiManager::update()
{
	//m_iter = m_vecUIObjects.begin();
	//for (; m_iter != m_vecUIObjects.end(); m_iter++)
	//{
	//	(*m_iter)->update();
	//}
	if (m_isPopUp)
	{
		m_iter = m_vecUIObjects.begin();
		for (; m_iter != m_vecUIObjects.end(); m_iter++)
		{
			if ((*m_iter)->getnTag() == 2)
			{
				(*m_iter)->m_isHidden = false;
			}
		}
	}

	if(m_isChangeScene)
		SCENEMANAGER->changeScene("battle");

}

void uiManager::render(HDC hdc)
{
	//m_iter = m_vecUIObjects.begin();
	//for (; m_iter != m_vecUIObjects.end(); m_iter++)
	//{
	//	(*m_iter)->render(hdc);
	//}
}

void uiManager::addUIObject(uiObject * pUI)
{
	((uiButton*)pUI)->setDelegate(this);
	m_vecUIObjects.push_back(pUI);

}

void uiManager::OnClick(uiButton * pSender)
{
	switch (pSender->getnTag())
	{
	case 1:
		m_isChangeScene = true;
		break;

	case 2:
		m_isPopUp = true;
		break;

	case 3:
		break;
	}
}

uiManager::uiManager()
{
}


uiManager::~uiManager()
{
}

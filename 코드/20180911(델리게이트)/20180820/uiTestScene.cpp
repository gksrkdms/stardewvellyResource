#include "stdafx.h"
#include "uiTestScene.h"
#include "uiObject.h"
#include "uiImageView.h"
#include "uiButton.h"

HRESULT uiTestScene::init()
{
	IMAGEMANAGER->addImage("image/ui/pop.bmp", "image/ui/pop.bmp", 600, 340);
	IMAGEMANAGER->addImage("image/ui/button.bmp", "image/ui/button.bmp", 122, 62, 1, 2, true, RGB(255,0,255));

	UIMANAGER->init();
	// 루트 ui
	m_pUiPopup = new uiObject;
	// 배경이미지
	uiImageView* pImageView = new uiImageView; // 왜 지역변수일까?
	pImageView->init("image/ui/pop.bmp", 0, 0, false, 4);
	m_pUiPopup->addChild(pImageView);
	UIMANAGER->addUIObject(pImageView);

	 //버튼 1
	pImageView = new uiImageView;
	pImageView->init("image/ui/button.bmp", 300, 200, true, 5);
	m_pUiPopup->addChild(pImageView);
	UIMANAGER->addUIObject(pImageView);

	//// 버튼 2
	//pImageView = new uiImageView;
	//pImageView->init("image/ui/button.bmp", 50, 200);
	//m_pUiPopup->addChild(pImageView);

	uiButton* pButton = new uiButton;
	pButton->init("image/ui/button.bmp", 100, 100, PointMake(0, 1), PointMake(0, 0), 1);
	m_pUiPopup->addChild(pButton);
	UIMANAGER->addUIObject(pButton);

	pButton = new uiButton;
	pButton->init("image/ui/button.bmp", 100, 200, PointMake(0, 1), PointMake(0, 0), 2);
	m_pUiPopup->addChild(pButton);
	UIMANAGER->addUIObject(pButton);

	pButton = new uiButton;
	pButton->init("image/ui/button.bmp", 100, 300, PointMake(0, 1), PointMake(0, 0), 3);
	m_pUiPopup->addChild(pButton);
	UIMANAGER->addUIObject(pButton);

	//UIMANAGER->addUIObject(m_pUiPopup);

	return S_OK;
}

void uiTestScene::release()
{
	//SAFE_DELETE(pImageView);
	m_pUiPopup->release();
	SAFE_DELETE(m_pUiPopup);
	UIMANAGER->release();
}

void uiTestScene::update()
{
	m_pUiPopup->update();
	UIMANAGER->update();

}

void uiTestScene::render(HDC hdc)
{
	m_pUiPopup->render(hdc);
	UIMANAGER->render(hdc);
}

uiTestScene::uiTestScene()
	:m_pUiPopup(NULL)
{
}


uiTestScene::~uiTestScene()
{
}

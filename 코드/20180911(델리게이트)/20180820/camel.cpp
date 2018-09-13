#include "stdafx.h"
#include "camel.h"
#include "animation.h"


HRESULT camel::init()
{
	//m_pImg = IMAGEMANAGER->addImage("camel", "image/camel.bmp", 300, 267, true, RGB(255, 0, 255));
	m_pImg = IMAGEMANAGER->addImage("time",
		"image/Time.bmp", 170, 16, 10, 1, true, RGB(255, 0, 255));
	
	m_pAni_1 = new animation;
	m_pAni_1->init(m_pImg->getWidth(), m_pImg->getHeight(), 17, 16);
	m_pAni_1->setPlayFrame(3, 8, true, true);
	m_pAni_1->setFPS(1);

	//m_pAni_1 = new animation;
	//m_pAni_1->init(m_pImg->getWidth(), m_pImg->getHeight(), 75, 89);
	//m_pAni_1->setDefPlayFrame(true, true);
	//m_pAni_1->setFPS(30);

	//m_pAni_2 = new animation;
	//m_pAni_2->init(m_pImg->getWidth(), m_pImg->getHeight(), 75, 89);
	//m_pAni_2->setPlayFrame(3, 8, false, true);
	//m_pAni_2->setFPS(1);

	//m_pAni_3 = new animation;
	//m_pAni_3->init(m_pImg->getWidth(), m_pImg->getHeight(), 75, 89);
	//int arrAni[] = { 0, 3, 6, 8, 10 };
	//m_pAni_3->setPlayFrame(arrAni, 5, true);
	//m_pAni_3->setFPS(15);


	return S_OK;
}

void camel::release()
{
	delete m_pAni_1;
	//delete m_pAni_2;
	//delete m_pAni_3;
}

void camel::update()
{
	// 1번 애니 테스트
	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		m_pAni_1->start();
	}
	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		m_pAni_1->pause();
	}
	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		m_pAni_1->resume();
	}

	//// 2번 애니 테스트
	//if (KEYMANAGER->isOnceKeyDown('W'))
	//{
	//	m_pAni_2->start();
	//}
	//if (KEYMANAGER->isOnceKeyDown('S'))
	//{
	//	m_pAni_2->pause();
	//}
	//if (KEYMANAGER->isOnceKeyDown('X'))
	//{
	//	m_pAni_2->resume();
	//}

	//// 3번 애니 테스트
	//if (KEYMANAGER->isOnceKeyDown('E'))
	//{
	//	m_pAni_3->start();
	//}
	//if (KEYMANAGER->isOnceKeyDown('D'))
	//{
	//	m_pAni_3->pause();
	//}
	//if (KEYMANAGER->isOnceKeyDown('C'))
	//{
	//	m_pAni_3->resume();
	//}

	m_pAni_1->frameUpdate(TIMEMANAGER->getElapsedTime());
	//m_pAni_2->frameUpdate(TIMEMANAGER->getElapsedTime());
	//m_pAni_3->frameUpdate(TIMEMANAGER->getElapsedTime());
}

void camel::render(HDC hdc)
{
	// 실습 : 낙타 세마리를 띄워라
	m_pImg->aniRender(hdc, 100, 100, m_pAni_1, 3);
	//m_pImg->aniRender(hdc, 100, 300, m_pAni_2);
	//m_pImg->aniRender(hdc, 100, 500, m_pAni_3);
}

camel::camel()
{
}


camel::~camel()
{
}

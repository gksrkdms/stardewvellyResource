#include "stdafx.h"
#include "battleScene.h"
#include "spaceShip.h"
#include "enemyManager.h"
#include "missileManager.h"
#include "camel.h"
#include "button.h"

int battleScene::m_idxBG = 0;

static void buttonFunc1(void)
{
	battleScene::m_idxBG = 0;
}

static void buttonFunc2(void)
{
	battleScene::m_idxBG = 1;
}

HRESULT battleScene::init()
{
	//Sleep(2500);

	IMAGEMANAGER->addImage("background", "image/background.bmp", WINSIZEX, WINSIZEY, false, 0);
	IMAGEMANAGER->addImage("background2", "image/수지2.bmp", 601, 801, false, 0);
	IMAGEMANAGER->addImage("missile_1", "image/missile.bmp",
		26, 124, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("enemy_missile_1", "image/bullet.bmp",
		21, 21, true, RGB(255, 0, 255));

	// UI image load
	m_idxBG = 0;
	IMAGEMANAGER->addImage("button_1", "image/button.bmp",
		122, 62, 1, 2, true, RGB(255, 0, 255));

	// button
	m_pButton1 = new button;
	m_pButton1->init("button_1", 100, 100,
		PointMake(0, 1), PointMake(0, 0), 
		buttonFunc1);

	m_pButton2 = new button;
	m_pButton2->init("button_1", 400, 100,
		PointMake(0, 1), PointMake(0, 0),  
		buttonFunc2);

	// 우주선
	switch (g_saveData.selected_player_id)
	{
	case 1:
		break;
	case 2:
		break;
	}
	m_pSpaceShip = new spaceShip;
	m_pSpaceShip->init();

	// 적
	m_pEnemyMgr = new enemyManager;
	m_pEnemyMgr->setEnemy(6, 3);
	m_pEnemyMgr->setTarget(m_pSpaceShip);

	// 낙타 애니메이션 테스트
	m_pCamel = new camel;
	m_pCamel->init();

	// 파일 생성 테스트
	//TXTDATA->txtSave("test.txt");
	//TXTDATA->txtLoad("test.txt");

	// 0 ) 오류 수정
	// 1 )우리반 학생 이름 전부를 넣은 파일 생성
	vector<string> vec;
	vec.push_back("이순현");
	vec.push_back("정지수");
	vec.push_back("정민욱");
	vec.push_back("최정수");
	TXTDATA->txtSave("test1.txt", vec);

	// 2) 세이브 파일 로드해서 vector에 다시 넣어서 화면에 출력
	m_vecLoad = TXTDATA->txtLoad("test1.txt");

	return S_OK;
}

void battleScene::release()
{
	m_pCamel->release();

	SAFE_DELETE(m_pButton1);
	SAFE_DELETE(m_pButton2);
	SAFE_DELETE(m_pCamel);
	SAFE_DELETE(m_pSpaceShip);
	SAFE_DELETE(m_pEnemyMgr);
}

void battleScene::update()
{
	m_pSpaceShip->update();
	//m_pEnemyMgr->update();

	//if (m_pButton1)
	//	m_pButton1->update();
	//if (m_pButton2)
	//	m_pButton2->update();

	//for (int i = 0; i < 버튼 갯수; i++)
	//{
	//	if (m_pButton[i]->getIsFind())
	//	{
	//		함수 호출;
	//	}
	//}

	//if (m_pCamel)
	//{
	//	m_pCamel->update();
	//}

	checkCollision();

	// 씬 전환
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		//SCENEMANAGER->changeScene("title");
		SCENEMANAGER->changeScene("title", "loading_1");
	}
}

void battleScene::render(HDC hdc)
{
	switch (m_idxBG)
	{
	case 0:
		IMAGEMANAGER->findImage("background")->render(hdc, 0, 0);
		break;
	case 1:
		IMAGEMANAGER->findImage("background2")->render(hdc, 0, 0);
		break;
	}
	

	m_pSpaceShip->render(hdc);
	//m_pEnemyMgr->render(hdc);

	//TIMEMANAGER->render(hdc);

	//if (m_pButton1)
	//	m_pButton1->render(hdc);
	//if (m_pButton2)
	//	m_pButton2->render(hdc);

	//if (m_pCamel)
	//{
	//	m_pCamel->render(hdc);
	//}

	// save load test
	char str[128];
	for (int i = 0; i < m_vecLoad.size(); i++)
	{
	// string type과 char 배열은 엄연히 다른 타입이다
	sprintf_s(str, 128, "이름_%d : %s", i, m_vecLoad[i].c_str());
	TextOut(hdc, 100, 100 + i * 30, str, strlen(str));
	}
}

void battleScene::checkCollision()
{
	// 적 미사일과 플레이어 확인
	std::vector<enemy*> vEnemy = m_pEnemyMgr->getVecEnemy();
	std::vector<enemy*>::iterator iter;

	for (iter = vEnemy.begin(); iter != vEnemy.end(); iter++)
	{
		std::vector<missile*> vMissile
			= (*iter)->getMissileMgr()->getVecMissile();
		std::vector<missile*>::iterator iterMissile;

		for (iterMissile = vMissile.begin();
			iterMissile != vMissile.end();
			iterMissile++)
		{
			RECT rc;
			if ((*iterMissile)->getIsFire() &&
				IntersectRect(&rc, &m_pSpaceShip->getRect(), &(*iterMissile)->getRect()))
			{
				// 미사일 삭제
				(*iterMissile)->setIsFire(false);

				// 플레이어 HP 감소
				m_pSpaceShip->damaged(1);
			}
		}
	}

	// 플레이어 미사일과 적 확인
}

//void battleScene::buttonFunc1(void)
//{
//	m_idxBG = 0;
//}
//
//void battleScene::buttonFunc2(void)
//{
//	m_idxBG = 1;
//}

battleScene::battleScene()
{
}


battleScene::~battleScene()
{
}

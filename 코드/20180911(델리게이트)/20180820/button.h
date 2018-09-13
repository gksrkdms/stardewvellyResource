#pragma once
class battleScene;
// 함수 포인터
//int a;
//int* pA;
//pA = &a;
//
//void(*pFunc)(void);
//void init(void);
//pFunc = init;
//
//int(*pFunc1)(int, int);
//int sum(int a, int b);
//
//pFunc1 = sum;
typedef void(*CALLBACK_FUNC)(void);
typedef void(battleScene::*CALLBACK_FUNC1)(void);

enum BUTTON_STATE
{
	IDLE,
	UP,
	DOWN,
	NUM
};

class button
{
private:
	string		m_strImgName;
	image*		m_pImg;
	RECT		m_rc;
	float		m_fX;
	float		m_fY;
	POINT		m_ptBtnDown;
	POINT		m_ptBtnUp;
	CALLBACK_FUNC	m_callbackFunction;

	scene*			m_pScene;
	BUTTON_STATE	m_state;

public:
	HRESULT init(const char* szImageName, int x, int y,
		POINT ptBtnDown, POINT ptBtnUp, CALLBACK_FUNC cb);
	//HRESULT init(const char* szImageName, int x, int y,
	//	POINT ptBtnDown, POINT ptBtnUp,
	//	battleScene* pScene, CALLBACK_FUNC1 cb);
	void release();
	void update();
	void render(HDC hdc);

	button();
	~button();
};


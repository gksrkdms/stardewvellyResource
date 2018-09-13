#pragma once
class titleScene;
class battleScene;
class loadingScene_1;
class uiTestScene;

class mainGame
{
private:
	// DC
	HDC hdc;

	// ¹é¹öÆÛ
	image * m_pBackBuffer;
	void setBackBuffer();

	char m_szText[128];

	// scene test
	titleScene*		m_pTitleScene;
	battleScene*	m_pBattleScene;

	loadingScene_1*	m_pLoadingScene;

	//ui test
	uiTestScene*	m_pUiTestScene;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

	mainGame();
	~mainGame();
};


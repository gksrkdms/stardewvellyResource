#pragma once
#include "uiObject.h"
class uiButton;

class iButtonDelegate
{
public:
	virtual void OnClick(uiButton* pSender) = 0;
};

class uiButton : public uiObject
{
protected:
	image *		m_pImg;
	POINT		m_ptBtnDown;
	POINT		m_ptBtnUp;
private:
	enum ButtonState
	{
		IDLE,
		UP,
		DOWN,
		NUM
	};
	SYNTHESIZE(iButtonDelegate*, m_pDelegate, Delegate);
	ButtonState			m_state;

public:
	HRESULT init(const char* szImageName, float x, float y,POINT ptBtnDown, POINT ptBtnUp, int num);
	virtual void update() override;
	virtual void render(HDC hdc) override;

	uiButton();
	virtual ~uiButton();
};


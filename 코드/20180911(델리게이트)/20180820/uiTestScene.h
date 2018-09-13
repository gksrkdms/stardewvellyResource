#pragma once
#include "scene.h"

class uiObject;
class uiTestScene : public scene
{
protected:
	uiObject * m_pUiPopup;
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
	uiTestScene();
	virtual ~uiTestScene();
};


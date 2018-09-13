#pragma once
#include "uiObject.h"

// ui 이미지를 출력하는 클래스
class uiImageView : public uiObject
{
protected:
	image * m_pImg;
public:
	HRESULT init(const char* szImageName, float x, float y, bool hidden, int num);
	virtual void update() override;
	virtual void render(HDC hdc) override;
	uiImageView();
	virtual ~uiImageView();
};


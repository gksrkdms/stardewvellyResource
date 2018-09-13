#pragma once
class animation;

class camel
{
private:
	animation * m_pAni_1;
	animation * m_pAni_2;
	animation * m_pAni_3;

	image*		m_pImg;

public:
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	camel();
	~camel();
};


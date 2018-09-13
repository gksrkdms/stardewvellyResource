#pragma once

// 모든 ui 클래스의 기본 클래스
// 모든 ui의 공통 특성을 정의한다
class uiObject
{
protected:

	//uiObject* 를 원소로 삼는 벡터
	vector<uiObject*>	m_vecChild;
	vector<uiObject*>::iterator	m_iter;

	SYNTHESIZE(FPOINT, m_position, Position);
	SYNTHESIZE(uiObject*, m_pParent, Parent);
	RECT		m_rc;
	SYNTHESIZE(int, m_nTag, nTag);
	bool		m_isHidden;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	virtual void addChild(uiObject* pChild);

	uiObject();
	virtual ~uiObject();
};


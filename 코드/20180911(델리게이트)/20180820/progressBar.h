#pragma once
class progressBar
{
private:
	RECT	m_rc;
	float	m_fX, m_fY;
	float	m_fWidth;

	image*	m_imgTop;
	image*	m_imgBottom;

public:
	HRESULT init(float x, float y, float width, float height);
	void release();
	void update();
	void render(HDC hdc);

	void setGauge(float currGauge, float maxGauge);

	inline void setX(float x) { m_fX = x; }
	inline void setY(float y) { m_fY = y; }

	progressBar();
	~progressBar();
};


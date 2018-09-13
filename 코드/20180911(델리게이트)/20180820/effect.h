#pragma once
class image;
class animation;

class effect
{
private:
	image * m_pImg;
	animation*	m_pAnimation;
	bool	m_isAlive;
	float	m_fElapsedTime;

	int		m_nX;
	int		m_nY;

public:
	HRESULT init(image* effectImage, 
		int frameWidth, int frameHeight,
		int fps, float elapsedTime);
	void release();
	void update();
	void render(HDC hdc);

	void startEffect(int x, int y);
	void endEffect();

	effect();
	~effect();
};


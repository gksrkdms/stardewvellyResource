#pragma once
#include "singletonBase.h"

class effect;
class effectManager : public singletonBase<effectManager>
{
private:
	typedef vector<effect*>		vecEffect;
	//map<string, vector<effect*>>	m_mapEffects;
	map<string, vecEffect>			m_mapEffects;
	map<string, vecEffect>::iterator	m_iter;

public:
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void addEffect(string effectName, const char* imageName,
		int imageWidth, int imageHeight, int frameWidth, int frameHeight,
		int fps, int bufferCount, float elapsedTime = 0.0f);

	void play(string effectName, int x, int y);

	effectManager();
	~effectManager();
};


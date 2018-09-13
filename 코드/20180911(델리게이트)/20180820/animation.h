#pragma once
#include <vector>

class animation
{
private:
	int		m_nFrameNum;				// 총 프레임 수
	std::vector<POINT>	m_vecFrameList;	// 각 프레임의 시작 x,y 
	std::vector<int>	m_vecPlayList;	// 플레이 시킬 프레임 인덱스 모음

	int		m_nFrameWidth;				// 각 프레임 너비
	int		m_nFrameHeight;				// 각 프레임 높이

	bool	m_isLoop;			// 반복 실행 여부
	float	m_fFrameUpdateSec;	// 프레임 업데이트 시간
	float	m_fElapsedSec;		// 누적시간

	int		m_nNowPlayIdx;		// 현재 플레이 인덱스
								// (m_vecPlayList 값을 참조한다)

	bool	m_isPlaying;		// 현재 플레이 여부

public:
	HRESULT init(int totalWidth, int totalHeight,
		int frameWidth, int frameHeight);

	void setDefPlayFrame(bool reverse = false, bool loop = false);	// 기본셋팅
	void setPlayFrame(int* arrPlay, int arrLen, bool loop = false);
	void setPlayFrame(int start, int end, bool reverse = false, bool loop = false);

	void setFPS(int fps);		// 초당 갱신 횟수 설정

	void frameUpdate(float elapsedTime);	// 프레임 업데이트

	void start();
	void stop();
	void pause();
	void resume();

	inline POINT getFramePos() { return m_vecFrameList[m_vecPlayList[m_nNowPlayIdx]]; }

	//m_vecFrameList[0];		// 가져오고 싶은 프레임의 인덱스를 넣는다
	// 플레이 리스트 원소 : 9, 10, 11, 0, 1, 2 
	// m_nNowPlayIdx == 0 => 9 
	// m_nNowPlayIdx == 1 => 10
	// 0 == m_vecPlayList[m_nNowPlayIdx];

	inline int getFrameWidth() { return m_nFrameWidth; }
	inline int getFrameHeight() { return m_nFrameHeight; }

	inline bool getIsPlaying() { return m_isPlaying; }


	animation();
	~animation();
};


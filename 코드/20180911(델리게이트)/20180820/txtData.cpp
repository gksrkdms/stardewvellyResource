#include "stdafx.h"
#include "txtData.h"


HRESULT txtData::init()
{
	return S_OK;
}

void txtData::release()
{
}

void txtData::txtSave(const char * saveFileName, vector<string> vecStr)
{
	char str[128];// = { 'h', 'e', 'l', 'l', 'o' };
	DWORD write;

	strncpy_s(str, 128, vectorArrayCombine(vecStr), 126);

	// 파일 생성 (실제 txt 파일이 만들어진다)
	HANDLE hFile;
	hFile = CreateFile(saveFileName,	// 세이브할 파일 경로 / 파일이름
		GENERIC_WRITE,			// 접근 방식 지정
		0,						// 파일 공유 방식 지정 (0) : 공유 안함
								// FILE_SHARE_DELETE : 삭제 접근 요청시 공유
		NULL,					// 보안 관련 옵션
		CREATE_ALWAYS,			// CREATE_ALWAYS : 새로운 파일 생성, 동일한 이름의 파일이 있으면 덮어쓴다
								// CREATE_NEW : 새로운 파일 생성
								// OPEN_EXISTING : 파일이 존재하면 오픈, 없으면 에러코드 리턴
		FILE_ATTRIBUTE_NORMAL,	// FILE_ATTRIBUTE_NORMAL : 다른 속성이 없다
								// FILE_ATTRIBUTE_READONLY : 읽기 전용 파일
								// FILE_ATTRIBUTE_HIDDEN : 숨김 파일 생성
		NULL);

	// 파일에 내용을 쓴다
	WriteFile(hFile, str, 128, &write, NULL);

	// 다 쓴 파일 핸들을 삭제
	CloseHandle(hFile);
}

// string을 원소로 갖는 vector => 하나의 문자열
char * txtData::vectorArrayCombine(vector<string> vecArray)
{
	//이순현
	//정지수
	//정민욱
	char str[128];
	ZeroMemory(str, sizeof(str));
	//memset(str, 0, sizeof(str));

	for (int i = 0; i < vecArray.size(); i++)
	{
		strncat_s(str, 128, vecArray[i].c_str(), 126);
		if (i + 1 < vecArray.size())
			strcat_s(str, ",");
	}

	//이순현,정지수,정민욱

	return str;
}

vector<string> txtData::txtLoad(const char * loadFileName)
{
	char str[128];
	DWORD read;

	HANDLE hFile;
	hFile = CreateFile(loadFileName,
		GENERIC_READ,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	ReadFile(hFile, str, 128, &read, NULL);

	CloseHandle(hFile);

	return charArraySeparation(str);
}

// 하나의 문자열 => string을 원소로 갖는 vector
vector<string> txtData::charArraySeparation(char charArray[])
{
	//이순현,정지수,정민욱
	vector<string> vecStr;
	const char* separator = ",";
	char* token;
	char* temp;

	token = strtok_s(charArray, separator, &temp);
	// token = "이순현";
	vecStr.push_back(token);

	while ((token = strtok_s(NULL, separator, &temp)) != NULL)
	{
		vecStr.push_back(token);
	}

	return vecStr;
}

txtData::txtData()
{
}


txtData::~txtData()
{
}

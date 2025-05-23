// MemScript.h: interface for the CMemScript class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#define MEM_SCRIPT_ALLOC_ERROR "[%s] Could not alloc memory for MemScript\n"
#define MEM_SCRIPT_ERROR_CODE0 "[%s] Could not open file\n"
#define MEM_SCRIPT_ERROR_CODE1 "[%s] Could not alloc file buffer\n"
#define MEM_SCRIPT_ERROR_CODE2 "[%s] Could not read file\n"
#define MEM_SCRIPT_ERROR_CODE3 "[%s] Could not get file buffer\n"
#define MEM_SCRIPT_ERROR_CODE4 "[%s] The file were not configured correctly\n"
#define MEM_SCRIPT_ERROR_CODE5 "[%s] The file is codified in UTF-8 BOM and cannot be read. Change it to UTF-8 and try again\n"
#define MEM_SCRIPT_ERROR_CODEX "[%s] Unknow error code: %d\n"

enum eTokenResult
{
	TOKEN_NUMBER = 0,
	TOKEN_STRING = 1,
	TOKEN_END = 2,
	TOKEN_ERROR = 3,
};

class CMemScript
{
public:
	CMemScript();
	virtual ~CMemScript();
	bool SetBuffer(char* path);
	bool GetBuffer(char* buff,DWORD* size);
	char GetChar();
	void UnGetChar(char ch);
	char CheckComment(char ch);
	eTokenResult GetToken();
	eTokenResult GetTokenNumber(char ch);
	eTokenResult GetTokenString(char ch);
	eTokenResult GetTokenCommon(char ch);
	void SetLastError(int error);
	char* GetLastError();
	int GetNumber();
	int GetAsNumber();
	float GetFloatNumber();
	float GetAsFloatNumber();
	char* GetString();
	char* GetAsString();
private:
	char* m_buff;
	DWORD m_size;
	char m_path[256];
	DWORD m_count;
	float m_number;
	char m_string[256];
	DWORD m_tick;
	char m_LastError[256];
};

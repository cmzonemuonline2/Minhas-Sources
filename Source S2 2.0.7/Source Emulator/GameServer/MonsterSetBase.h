// MonsterSetBase.h: interface for the CMonsterSetBase class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#define MAX_MSB_MONSTER 10000

struct MONSTER_SET_BASE_INFO
{
	int Type;
	int MonsterClass;
	int Map;
	int Dis;
	int X;
	int Y;
	int Dir;
	int TX;
	int TY;
};

class CMonsterSetBase
{
public:
	CMonsterSetBase();
	virtual ~CMonsterSetBase();
	void LoadSpawn();
	void Load(char* path,int MapNumber);
	void SetInfo(MONSTER_SET_BASE_INFO info);
	bool GetPosition(int index,short map,short* ox,short* oy);
	bool GetBoxPosition(int map,int x,int y,int tx,int ty,short* ox,short* oy);
public:
	MONSTER_SET_BASE_INFO m_MonsterSetBaseInfo[MAX_MSB_MONSTER];
	int m_count;
};

extern CMonsterSetBase gMonsterSetBase;

#pragma once

#define MIN_PORT 50000
#define MAX_PORT 65000

#define PORT_RANGE(x) (((x)<MIN_PORT)?0:((x)>MAX_PORT)?0:1)

void DecryptData(BYTE* lpMsg,int size);
void EncryptData(BYTE* lpMsg,int size);
bool CheckSocketPort(SOCKET s);
int WINAPI MyRecv(SOCKET s,char* buf,int len,int flags);
int WINAPI MySend(SOCKET s,char* buf,int len,int flags);
void InitHackCheck();

#include "iostream"
#include <map>
#include "windows.h"
#include <string>
using namespace std;

#define MAX_SIZE 200
/*
��ȡ��Ϣ������Map��
config.exe.ini
NUMBER_0
Camera   = ����ͷA
Ethernet = 10.168.2.204
NUMBER_1
Camera   = ����ͷB
Ethernet = 10.168.2.205
NUMBER_2
Camera   = ����ͷC
Ethernet = 10.168.2.206
NUMBER_3
Camera   = ����ͷD
Ethernet = 10.168.2.207
*/
inline map<string, string> getConfig()
{
	map<string, string> sMap;

	char cPath[MAX_SIZE] = { 0 };

	GetModuleFileNameA(NULL, cPath, MAX_SIZE);

	lstrcatA(cPath, ".ini");

	int idx = 0;
	while(1)
	{
		char cArrSec[MAX_SIZE] = {0};
		wsprintfA(cArrSec, "NUMBER_%d", idx);

		char cArrCam[MAX_SIZE] = {0};
		char cArrNet[MAX_SIZE] = {0};

		::GetPrivateProfileStringA(cArrSec, "Camera", "", cArrCam, ARRAYSIZE(cArrCam), cPath);
		::GetPrivateProfileStringA(cArrSec, "Ethernet", "", cArrNet, ARRAYSIZE(cArrNet), cPath);

		if (strlen(cArrCam) == 0 || strlen(cArrNet) == 0)
		{
			break;
		}

		sMap[cArrCam] = cArrNet;
		idx++;
	}

	return sMap;
}

void main()
{

	map<string, string> mapNet = getConfig();
}
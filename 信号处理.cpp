#include <iostream>
#include <csignal>
#include "unistd.h"
#include <windows.h>

using namespace std;

void signalHandler(int signum)
{
	cout << "Tnterrupt signal (" << signum << ") received.\n";

	//�����ر�
	//��ֹ����
	Sleep(3000);
	exit(signum);
}

int main()
{
	int i = 0;
	//ע���ź�SIGINT ���źŴ������
	signal(SIGINT, signalHandler);

	while(++i)
	{
		cout << "Going to sleep..." << endl;
		if (3 == i)
		{
			raise(SIGINT);
		}
		Sleep(1000);
	}

	return 0;
}
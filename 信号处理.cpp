#include <iostream>
#include <csignal>
#include "unistd.h"
#include <windows.h>

using namespace std;

void signalHandler(int signum)
{
	cout << "Tnterrupt signal (" << signum << ") received.\n";

	//清理并关闭
	//终止程序
	Sleep(3000);
	exit(signum);
}

int main()
{
	int i = 0;
	//注册信号SIGINT 和信号处理程序
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
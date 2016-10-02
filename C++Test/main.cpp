#include<iostream>
#include<string>
#include<vector>
#include "Thread.h"
#include "ThreadPoolExecutor.h"

using namespace std;

class R : public Runnable
{
public:
	~R()
	{
	}
	void Run()
	{
		printf("Hello World\n");
	}
};

int main()
{
	CThreadPoolExecutor * pExecutor = new CThreadPoolExecutor();
	pExecutor->Init(1, 10, 50);
	R r;
	for (int i = 0; i<100; i++)
	{
		while (!pExecutor->Execute(&r))
		{
		}
	}
	pExecutor->Terminate();
	delete pExecutor;
	getchar();
	return 0;
}
#include <Windows.h>
#include <stdio.h>
/*
本程序是dll与导出函数与应用程序通讯的例子
*/

//#pragma comment(lib, "FIRSTDLL2")
//extern "C" void ccc();

//指向函数指针
typedef void(*PMessage_Box)();

int main()
{
	HMODULE hModule = LoadLibrary("FirstDll2.dll");

	if (hModule == NULL)
	{
		MessageBox(NULL, "句柄出错!", "标题：", MB_OK);
		return -1;
	}
	//指定动态链接库中检索导出函数ccc的地址
	PMessage_Box pMsg = (PMessage_Box)GetProcAddress(hModule, "ccc");

	//执行函数
	pMsg();

	//自己的程序自己调用，字节擦除，卸载模块,与LoadLibrary对应
	//FreeLibrary(hModule);

	getchar();
	return 0;
}
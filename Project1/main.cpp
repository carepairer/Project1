#include <Windows.h>
#include <stdio.h>
/*
��������dll�뵼��������Ӧ�ó���ͨѶ������
*/

//#pragma comment(lib, "FIRSTDLL2")
//extern "C" void ccc();

//ָ����ָ��
typedef void(*PMessage_Box)();

int main()
{
	HMODULE hModule = LoadLibrary("FirstDll2.dll");

	if (hModule == NULL)
	{
		MessageBox(NULL, "�������!", "���⣺", MB_OK);
		return -1;
	}
	//ָ����̬���ӿ��м�����������ccc�ĵ�ַ
	PMessage_Box pMsg = (PMessage_Box)GetProcAddress(hModule, "ccc");

	//ִ�к���
	pMsg();

	//�Լ��ĳ����Լ����ã��ֽڲ�����ж��ģ��,��LoadLibrary��Ӧ
	//FreeLibrary(hModule);

	getchar();
	return 0;
}
/*!
 * \file: ��򵥵�Win32����+ͼ����Դ.cpp
 * \author: Daito
 * \date: 2021/12/26 15:21
 * \version: 1.0.0
 * \CSDN: https://blog.csdn.net/zhd5120153951
 * \GitHub: https://github.com/zhd5120153951
 * \e-mail: 2462491568@qq.com
 * \description:
 */
#include "resource.h"
#include<windows.h>
LRESULT CALLBACK WndProc(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam);
HINSTANCE g_hInstance;
//�ڶ�����ע�ᴰ������
BOOL MyRegister(LPSTR pszClassName)
{
	ATOM nAtom;
	WNDCLASS wndClass{ 0 };//����һ���������͵Ĵ��ڶ���
	wndClass.style = CS_VREDRAW | CS_HREDRAW;//���ڷ��������������޸ģ����в����ϣ�
	wndClass.lpfnWndProc = WndProc;//���ڵ���Ϣ��������ǰ�涨����ĳ����Ϣ�Ĵ�����������Ѻ�����
	// ���ݸ�ĳ�����ڣ�����������ڰ����˶�Ӧ�İ�ť���ͻ�ִ�иú�����
	wndClass.cbClsExtra = 0;//������������
	wndClass.cbWndExtra = 0;//������������
	wndClass.hInstance = g_hInstance;//���ڳ���ľ��
	//wndClass.hIcon = NULL;//����Ĭ��ͼ��û��
	wndClass.hIcon = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_APPLICATIONICON));
	wndClass.hCursor = NULL;//����Ĭ�Ϲ��û��
	wndClass.hbrBackground = (HBRUSH)(COLOR_BTNFACE);//����Ĭ�ϱ�����ɫ
	wndClass.lpszMenuName = NULL;//����Ĭ�ϲ˵���--ʹ��ϵͳ��
	wndClass.lpszClassName = pszClassName;//����ע��ľ���������
	//����Ϊֹ��������һ�����ڵĻ���Ԫ�أ���������ע��������͵Ĵ���
	nAtom = RegisterClass(&wndClass);
	if (!nAtom)//���ע��ʧ��
	{
		MessageBox(NULL, "��Ǹ��ע�ᴰ��ʧ��", "��ܰ��ʾ", MB_OK);
		return FALSE;
	}
	else
	{
		MessageBox(NULL, "��ϲ��ע�ᴰ�ڳɹ�", "��ܰ��ʾ", MB_OK);
	}
	return TRUE;
}
//������������һ������
HWND MyCreate(LPSTR pasClassName) {
	HWND hWnd = CreateWindow(pasClassName, "��򵥵�Win32����",
		WS_OVERLAPPEDWINDOW, 100, 100, 300, 500, NULL, NULL,
		g_hInstance, NULL);
	if (!hWnd) {
		MessageBox(NULL, "��Ǹ����������ʧ��", "��ܰ��ʾ", MB_OK);
		return NULL;
	}
	else
	{
		MessageBox(NULL, "��ϲ���������ڳɹ�", "��ܰ��ʾ", MB_OK);
	}
	return hWnd;//�ص㣺�����ɹ����Ҫ�Ѹô��ھͷ��س���
}
//���Ĳ�:��ʾ����
void ShowWnd(HWND hWnd)
{
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
}
//���岽:�Ӵ����л����Ϣ
void Message()
{
	MSG msg = { 0 };//MSG��һ����Ϣ�ṹ��
	while (GetMessage(&msg, NULL, 0, 0))//����Ϣ�����л����Ϣ
	{
		DispatchMessage(&msg);//�ַ���Ϣ����Ӧ����Ϣ�ص�����
	}
}
//������:������Ϣ�Ĵ�����-->�ص�����
LRESULT CALLBACK WndProc(HWND hWnd,//���ڵľ��--����ĳһ������
	UINT nMsg,//��Ϣ��ID
	WPARAM wParam,//��Ϣ��Ӧ�Ĳ���
	LPARAM lParam)//��Ϣ��Ӧ�Ĳ���
{
	switch (nMsg)
	{
	case WM_DESTROY://����ڴ��ڵ���˹ر��ఴť----�������ٵ���Ϣ
		PostQuitMessage(0);//�����˳���Ϣ
		return 0;
		break;
	}
	//����ϵͳĬ����Ϣ������
	return DefWindowProc(hWnd, nMsg, wParam, lParam);//��������������ť--����βδ������Ĭ����Ϣ����
													  //������
}
//��һ��:���������
int WINAPI WinMain( _In_ HINSTANCE hInstance, 
					_In_opt_ HINSTANCE hPrevInstance,
					_In_ LPSTR lpCmdLine,
					_In_ int nShowCmd)
{
	HWND hwnd = NULL;//���ڱ���
	BOOL bRet = FALSE;
	CHAR tempLPSTR[] = "��򵥵�Win32����";
	bRet = MyRegister(tempLPSTR);
	if (!bRet) {
		MessageBox(NULL, "ע��ʧ��", "��ܰ��ʾ", MB_OK);
		return -1;//ʧ�ܷ���-1
	}
	else
	{
		MessageBox(NULL, "ע��ɹ�", "��ܰ��ʾ", MB_OK);
	}
	g_hInstance = hInstance;
	hwnd = MyCreate(tempLPSTR);
	if (!hwnd) {
		MessageBox(NULL, "��������ʧ��", "��ܰ��ʾ", MB_OK);
	}
	ShowWnd(hwnd);//�ɹ�--ֱ����ʾ����
	Message();//��ʼ��ȡ��Ϣ
	return 0;
}

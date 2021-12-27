/*!
 * \file: 窗口注册和创�?cpp
 * \author: Daito
 * \date: 2021/12/27 13:59
 * \version: 1.0.0
 * \CSDN: https://blog.csdn.net/zhd5120153951
 * \GitHub: https://github.com/zhd5120153951
 * \e-mail: 2462491568@qq.com
 * \description:
 */
#define  _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
LRESULT CALLBACK  WndProc(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam);
HINSTANCE g_hInstance = NULL;
//注册窗口---自己写的,不是vs生成的
ATOM RegisterWnd(LPSTR pszClassName)
{
	WNDCLASSEX wcx = { 0 };//这是一个窗口结构体--代表这整个窗口的属性
	wcx.cbSize = sizeof(wcx);
	wcx.style = CS_HREDRAW | CS_VREDRAW;
	wcx.lpfnWndProc = WndProc;//把消息回到关联到具体的窗口上
	wcx.cbClsExtra = 100;//保存窗口类信息
	wcx.cbWndExtra = 100;
	wcx.hCursor = NULL;
	wcx.hIcon = NULL;
	wcx.hbrBackground = HBRUSH(COLOR_BTNFACE + 1);
	wcx.lpszClassName = pszClassName;
	ATOM nAtom = RegisterClassEx(&wcx);
	if (!nAtom)return FALSE;
	return TRUE;
}
//给窗口设置附加消息
void SetExtra(HWND hWnd)
{
	SetClassLong(hWnd, 0, 100);
	SetWindowLong(hWnd, 0, 200);
}
void GetExtra(HWND hWnd)
{
	DWORD nClass = GetClassLong(hWnd, 0);
	DWORD nWnd = GetWindowLong(hWnd, 0);
	CHAR szText[1024] = { 0 };
	sprintf(szText, "%d %d", nClass, nWnd);
	MessageBox(hWnd, szText, "Tip", MB_OK);
}
//创建窗口
HWND CreateWnd(LPSTR pszClassName)
{
	HWND hWnd = CreateWindow(pszClassName, "我的窗口", WS_OVERLAPPEDWINDOW, 0, 0,
		1000, 500, NULL, NULL, g_hInstance, NULL);
	return hWnd;
}
//显示窗口
void DisplayWnd(HWND hWnd)
{
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
}
//消息循环--->捕获消息--消息分发
void Message()
{
	MSG msg = { 0 };
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	 }
}

int WINAPI WinMain( _In_ HINSTANCE hInstance, 
					_In_opt_ HINSTANCE hPrevInstance, 
					_In_ LPSTR lpCmdLine, 
					_In_ int nShowCmd )
{
	g_hInstance = hInstance;
	char temp[] = "我的窗口";
	RegisterWnd(temp);
	HWND hMyWnd1 = CreateWnd(temp);
	HWND hMyWnd2 = CreateWnd(temp);
	SetExtra(hMyWnd1);
	GetExtra(hMyWnd1);
	SetExtra(hMyWnd2);
	GetExtra(hMyWnd2);
	DisplayWnd(hMyWnd1);
	Message();
	return 0;
}
//窗口消息处理函数--回调
LRESULT CALLBACK  WndProc(HWND hWnd,UINT nMsg,WPARAM wParam,LPARAM lParam)
{
	switch (nMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(WM_QUIT);
		return 0;
	}
	return DefWindowProc(hWnd, nMsg, wParam, lParam);//直接调用系统的窗口处理回调函数
}
//
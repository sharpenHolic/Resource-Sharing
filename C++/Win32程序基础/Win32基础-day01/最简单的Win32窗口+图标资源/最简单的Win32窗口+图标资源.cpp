/*!
 * \file: 最简单的Win32窗口+图标资源.cpp
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
//第二步：注册窗口类型
BOOL MyRegister(LPSTR pszClassName)
{
	ATOM nAtom;
	WNDCLASS wndClass{ 0 };//定义一个窗口类型的窗口对象
	wndClass.style = CS_VREDRAW | CS_HREDRAW;//窗口风格，这个参数可以修改（自行查资料）
	wndClass.lpfnWndProc = WndProc;//窗口的消息处理函数（前面定义了某个消息的处理函数，这里把函数名
	// 传递给某个窗口，当在这个窗口按下了对应的按钮，就会执行该函数）
	wndClass.cbClsExtra = 0;//窗口其他参数
	wndClass.cbWndExtra = 0;//窗口其他参数
	wndClass.hInstance = g_hInstance;//窗口程序的句柄
	//wndClass.hIcon = NULL;//窗口默认图标没有
	wndClass.hIcon = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_APPLICATIONICON));
	wndClass.hCursor = NULL;//窗口默认光标没有
	wndClass.hbrBackground = (HBRUSH)(COLOR_BTNFACE);//窗口默认背景颜色
	wndClass.lpszMenuName = NULL;//窗口默认菜单名--使用系统的
	wndClass.lpszClassName = pszClassName;//窗口注册的具体类型名
	//到此为止就声明了一个窗口的基本元素，接下来是注册这个类型的窗口
	nAtom = RegisterClass(&wndClass);
	if (!nAtom)//如果注册失败
	{
		MessageBox(NULL, "抱歉，注册窗口失败", "温馨提示", MB_OK);
		return FALSE;
	}
	else
	{
		MessageBox(NULL, "恭喜，注册窗口成功", "温馨提示", MB_OK);
	}
	return TRUE;
}
//第三步：创建一个窗口
HWND MyCreate(LPSTR pasClassName) {
	HWND hWnd = CreateWindow(pasClassName, "最简单的Win32窗口",
		WS_OVERLAPPEDWINDOW, 100, 100, 300, 500, NULL, NULL,
		g_hInstance, NULL);
	if (!hWnd) {
		MessageBox(NULL, "抱歉，创建窗口失败", "温馨提示", MB_OK);
		return NULL;
	}
	else
	{
		MessageBox(NULL, "恭喜，创建窗口成功", "温馨提示", MB_OK);
	}
	return hWnd;//重点：创建成功后必要把该窗口就返回出来
}
//第四步:显示窗口
void ShowWnd(HWND hWnd)
{
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
}
//第五步:从窗口中获得消息
void Message()
{
	MSG msg = { 0 };//MSG是一个消息结构体
	while (GetMessage(&msg, NULL, 0, 0))//从消息队列中获得消息
	{
		DispatchMessage(&msg);//分发消息到对应的消息回调函数
	}
}
//第六步:窗口消息的处理函数-->回调函数
LRESULT CALLBACK WndProc(HWND hWnd,//窗口的句柄--代表某一个窗口
	UINT nMsg,//消息的ID
	WPARAM wParam,//消息对应的参数
	LPARAM lParam)//消息对应的参数
{
	switch (nMsg)
	{
	case WM_DESTROY://如果在窗口点击了关闭类按钮----窗口销毁的消息
		PostQuitMessage(0);//发送退出消息
		return 0;
		break;
	}
	//调用系统默认消息处理函数
	return DefWindowProc(hWnd, nMsg, wParam, lParam);//如果点击了其他按钮--则把形参传入这个默认消息处理
													  //函数中
}
//第一步:主函数入口
int WINAPI WinMain( _In_ HINSTANCE hInstance, 
					_In_opt_ HINSTANCE hPrevInstance,
					_In_ LPSTR lpCmdLine,
					_In_ int nShowCmd)
{
	HWND hwnd = NULL;//窗口变量
	BOOL bRet = FALSE;
	CHAR tempLPSTR[] = "最简单的Win32窗口";
	bRet = MyRegister(tempLPSTR);
	if (!bRet) {
		MessageBox(NULL, "注册失败", "温馨提示", MB_OK);
		return -1;//失败返回-1
	}
	else
	{
		MessageBox(NULL, "注册成功", "温馨提示", MB_OK);
	}
	g_hInstance = hInstance;
	hwnd = MyCreate(tempLPSTR);
	if (!hwnd) {
		MessageBox(NULL, "创建窗口失败", "温馨提示", MB_OK);
	}
	ShowWnd(hwnd);//成功--直接显示出来
	Message();//开始获取消息
	return 0;
}

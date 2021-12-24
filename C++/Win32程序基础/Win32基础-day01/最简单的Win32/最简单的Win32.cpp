/*!
 * \file: 最简单的Win32.cpp
 * \author: Daito
 * \date: 2021/12/24 14:56
 * \version: 1.0.0
 * \CSDN: https://blog.csdn.net/zhd5120153951
 * \GitHub: https://github.com/zhd5120153951
 * \e-mail: 2462491568@qq.com
 * \description:
 */
#include <windows.h>
//1、WinAPI是标准回调函数的宏定义，winmain是入口函数（窗口函数的统一入口）
int WINAPI WinMain( _In_ HINSTANCE hInstance, //当前程序的实例句柄——可理解为代表这个程序
					_In_opt_ HINSTANCE hPrevInstance, //当前程序的前一个实例句柄
					_In_ LPSTR lpCmdLine, //命令行参数
					_In_ int nShowCmd )//窗口的显示方式//以上参数都是缺省值
{
	MessageBox(NULL, "Hello,my first windows!", "曾贺东出品", MB_OK);
	return 0;
}

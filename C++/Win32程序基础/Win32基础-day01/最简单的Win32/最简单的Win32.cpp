/*!
 * \file: ��򵥵�Win32.cpp
 * \author: Daito
 * \date: 2021/12/24 14:56
 * \version: 1.0.0
 * \CSDN: https://blog.csdn.net/zhd5120153951
 * \GitHub: https://github.com/zhd5120153951
 * \e-mail: 2462491568@qq.com
 * \description:
 */
#include <windows.h>
//1��WinAPI�Ǳ�׼�ص������ĺ궨�壬winmain����ں��������ں�����ͳһ��ڣ�
int WINAPI WinMain( _In_ HINSTANCE hInstance, //��ǰ�����ʵ��������������Ϊ�����������
					_In_opt_ HINSTANCE hPrevInstance, //��ǰ�����ǰһ��ʵ�����
					_In_ LPSTR lpCmdLine, //�����в���
					_In_ int nShowCmd )//���ڵ���ʾ��ʽ//���ϲ�������ȱʡֵ
{
	MessageBox(NULL, "Hello,my first windows!", "���ض���Ʒ", MB_OK);
	return 0;
}

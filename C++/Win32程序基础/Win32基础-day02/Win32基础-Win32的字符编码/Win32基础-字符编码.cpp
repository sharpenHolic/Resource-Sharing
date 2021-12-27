/*!
 * \file: Win32����-�ַ�����.cpp
 * \author: Daito
 * \date: 2021/12/26 16:44
 * \version: 1.0.0
 * \CSDN: https://blog.csdn.net/zhd5120153951
 * \GitHub: https://github.com/zhd5120153951
 * \e-mail: 2462491568@qq.com
 * \description:
 */

#include "StdAfx.h"
#include <windows.h>
#include <stdlib.h>
//���ַ�--->���ֽ�
void WideToMulti()
{
	WCHAR ch[] = L"wide to multi";
	WCHAR *pwszText = ch;
	//1.�Ȼ�ȡת����ĳ���
	int iLen = WideCharToMultiByte(CP_ACP, 0, pwszText, wcslen(pwszText), NULL, 0, NULL, NULL);
	char *pszText = (char*)malloc(iLen);
	//2.Ȼ��Ż�ȡ����ֲ
	WideCharToMultiByte(CP_ACP, 0, pwszText, wcslen(pwszText), pszText, iLen, NULL, NULL);
	MessageBox(NULL, pszText, "Multi", MB_OK);
	free(pszText);
}
//���ֽ�--->���ַ�
void MultiToWide()
{
	CHAR ch[] = "Multi to Wide";
	CHAR *pszText = ch;
	//1.�Ȼ�ȡת����ĳ���
	int iLen = MultiByteToWideChar(CP_ACP/*ascii code page*/, 0, pszText, strlen(pszText), NULL/* ���ؽ��*/, 0);
	WCHAR *pwszText = (WCHAR *)malloc(iLen * sizeof(WCHAR));
	memset(pwszText, 0, sizeof(pwszText));
	//2.Ȼ��Ż�ȡ����ֲ
	MultiByteToWideChar(CP_ACP/*ascii code page*/, 0, pszText, strlen(pszText), pwszText/* ���ؽ��*/, iLen);


	MessageBoxW(NULL, pwszText, L"Wide", MB_OK);
	free(pwszText);
}
int APIENTRY WinMain( _In_ HINSTANCE hInstance, 
	_In_opt_ HINSTANCE hPrevInstance, 
	_In_ LPSTR lpCmdLine, 
	_In_ int nShowCmd )
{
	//WideToMulti();
	MultiToWide();
	return 0;

}
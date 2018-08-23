// CSGO_BHOP.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "windows.h"
#include "iostream"
using namespace std;
#include "stdio.h"


void potato (void)
{

	//"client.dll"+04A0D1E4
	int abc = 0;
	int jumpval = 0;

	HANDLE hdl = GetModuleHandleA("client.dll");
	//GetLastError();

	hdl = (HANDLE)((char *)(hdl) + 0x04A0D1E4);
	
	ReadProcessMemory(GetCurrentProcess(), (void*)hdl, &abc, sizeof(int), NULL);

	abc += 0xF8;

	ReadProcessMemory(GetCurrentProcess(), (void*) abc, &abc, sizeof(int), NULL);
	
	int *p = (int*)abc;

	
	HANDLE hdl2 = GetModuleHandleA("client.dll");

	hdl2 = (HANDLE)((char *)(hdl2) + 0x04A7BD20);
	ReadProcessMemory(GetCurrentProcess(), (void*)hdl2, &jumpval, sizeof(int), NULL);

	char pew[MAX_PATH];
	memset(pew, '\0', MAX_PATH);
	sprintf(pew, "%d value and %d", jumpval, *p);
	MessageBox(NULL, "pew", "MAIN", 1);
	/*while(true){
		static int jump = 5;
		static int jump2 = 4;
		if( *p == 257)
		{
			WriteProcessMemory(GetCurrentProcess(),  (void*)hdl2, &jump, sizeof(int), NULL);
			WriteProcessMemory(GetCurrentProcess(),  (void*)hdl2, &(jump2), sizeof(int), NULL);

		}

		
	}*/

	CloseHandle(hdl);
	CloseHandle(hdl2);


}
#include <iostream>
#include "CustomCharString.h"
#include "CustomWCharString.h"

void main()
{
	{
		CustomWCharString aa = L"free testing.";
	}

	CustomWCharString wstr01 = L"TEST";
	CustomWCharString wstr02 = L"const wchar string";
	CustomWCharString wstr03 = wstr02;

	CustomWCharString wstr04 = wstr01 + wstr02;
	wstr04 += L" something...";

	CustomWCharString wstr05 = L"0123456789";
	CustomWCharString wstr06 = std::move(wstr05);

	std::wcout << wstr01.GetString() << std::endl;
	std::wcout << wstr02.GetString() << std::endl;
	std::wcout << wstr02.Reverse().GetString() << std::endl;
	std::wcout << wstr03.GetString() << std::endl;
	
	std::wcout << (wstr04 += L"??").GetString() << std::endl;

	std::wcout << wstr02.RemoveAt(1).GetString() << std::endl;
	
	std::wcout << wstr06.GetString() << std::endl;


	std::cout << "end.." << std::endl;
	getchar();
}
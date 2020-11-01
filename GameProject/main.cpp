#include "CustomWCharString.h"
#include <iostream>
#include <zstd.h>

void main()
{
	CustomWCharString str = L"some";
	std::wcout << str.GetString() << std::endl;
	std::getchar();
}
#include "CustomCharString.h"
#include <memory>


int strlenA(const char* str)
{
	int size = 0;
	while (str[size])
	{
		size++;
	}

	return size;
}

CustomCharString::CustomCharString()
{
	this->str = 0;
	this->length = 0;
}

CustomCharString::~CustomCharString()
{
	if (str != 0)
		delete[]this->str;
}

CustomCharString::CustomCharString(const CustomCharString & customStr)
{
	this->length = customStr.length;
	this->str = new char[length];
	memcpy_s(this->str, this->length, customStr.str, customStr.length);
}

CustomCharString::CustomCharString(const char * customStr)
{
	this->length = (unsigned int)strlenA(customStr) + 1;
	this->str = new char[length];
	memcpy_s(this->str, this->length, customStr, this->length);
}

CustomCharString & CustomCharString::operator=(const CustomCharString & customStr)
{
	if (this->str != 0)
		delete[]this->str;

	this->length = customStr.length;
	this->str = new char[length];
	memcpy_s(this->str, this->length, customStr.str, this->length);

	return *this;
}

const char * CustomCharString::GetBuffer() const
{
	if (this->str == 0)
		return "";

	return this->str;
}

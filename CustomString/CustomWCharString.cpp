#include "CustomWCharString.h"
#include <memory>


CustomWCharString::CustomWCharString() :
	str(nullptr),
	length(0)
{
}

CustomWCharString::~CustomWCharString()
{
	if (str != nullptr)
		free(str);
}

size_t CustomWCharString::GetLength(const wchar_t* str)
{
	size_t size = 0;
	while (str[size])
		size++;

	return size;
}

CustomWCharString::CustomWCharString(const CustomWCharString& customStr)
{
	this->length = customStr.length;
	this->str = (wchar_t*)malloc((length + 1) * sizeof(wchar_t));
	wmemcpy_s(this->str, this->length + 1, customStr.str, customStr.length + 1);
}

CustomWCharString::CustomWCharString(CustomWCharString && customStr) noexcept
{
	this->length = customStr.length;
	this->str = customStr.str;

	customStr.str = nullptr;
}

CustomWCharString::CustomWCharString(const wchar_t* wstr)
{
	this->length = GetLength(wstr);
	this->str = (wchar_t*)malloc((length+1) * sizeof(wchar_t));
	wmemcpy_s(this->str, this->length+1, wstr, this->length+1);
	this->str[length] = '\0';
}

CustomWCharString & CustomWCharString::operator=(const CustomWCharString & wstr)
{
	if (this->str != 0)
		delete[]this->str;

	this->length = wstr.length;
	this->str = new wchar_t[length];
	wmemcpy_s(this->str, this->length, wstr.str, this->length);

	return *this;
}

CustomWCharString & CustomWCharString::operator+=(const CustomWCharString & wstr)
{
	if (str == nullptr)
		return *this;

	int tempLength = length + wstr.length;

	realloc(str, (tempLength + 1) * sizeof(wchar_t));
	wmemcpy_s(str + length, wstr.length, wstr.str, wstr.length);
	str[tempLength] = '\0';
	
	length = GetLength(str);

	return *this;
}

CustomWCharString CustomWCharString::operator+(const CustomWCharString & wstr)
{
	wchar_t* temp = (wchar_t*)malloc((length + wstr.length+1) * sizeof(wchar_t));
	temp[length + wstr.length] = '\0';

	wmemcpy_s(temp, length, str, length);
	wmemcpy_s(temp + length, wstr.length, wstr.str, wstr.length);

	return CustomWCharString(temp);
}

CustomWCharString & CustomWCharString::Reverse()
{
	wchar_t* reverse = (wchar_t*)malloc((length+1) * sizeof(wchar_t));
	for (int i = 0; i < length; ++i)
	{
		reverse[i] = std::move(str[length - 1 - i]);
	}
	reverse[length] = '\0';

	str = reverse;

	return *this;
}

CustomWCharString& CustomWCharString::RemoveAt(int index)
{
	if (index >= length)
		return *this;

	str = (wchar_t*)realloc(str, (index + 1) * sizeof(wchar_t));
	str[index] = '\0';
	length = GetLength(str);

	return *this;
}

CustomWCharString & CustomWCharString::RemoveAt(int index, size_t len)
{
	if (index >= length || index + len > length)
		return *this;

	str[length - len] = '\0';

	int i = 0;
	while (str[index + len + i])
	{
		str[index + i] = std::move(str[index + len + i]);
		++i;
	}
	str = (wchar_t*)realloc(str, (length - len + 1) * sizeof(wchar_t));
	length = GetLength(str);

	return *this;
}

const wchar_t* CustomWCharString::GetString() const
{
	return this->str;
}
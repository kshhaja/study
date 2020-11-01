#pragma once

class CustomWCharString
{
public:
	CustomWCharString();
	~CustomWCharString();

	CustomWCharString(const wchar_t* wstr);
	CustomWCharString(const CustomWCharString& customStr);
	CustomWCharString(CustomWCharString&& customStr) noexcept;

	CustomWCharString& operator=(const CustomWCharString& wstr);
	CustomWCharString& operator+=(const CustomWCharString& wstr);
	CustomWCharString operator+(const CustomWCharString& wstr);

	CustomWCharString& Reverse();
	CustomWCharString& RemoveAt(int index);
	CustomWCharString& RemoveAt(int index, size_t len);

	static size_t GetLength(const wchar_t* str);
	const wchar_t* GetString() const;

private:
	wchar_t* str;
	size_t length;
};


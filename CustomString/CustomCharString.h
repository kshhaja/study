#pragma once
#include "stdafx.h"

class SHFRAMEWORK_API CustomCharString
{
public:
	CustomCharString();
	~CustomCharString();

	// 복사생성자
	CustomCharString(const CustomCharString& customStr);
	CustomCharString(const char* customStr);

	// 대입연산자
	CustomCharString& operator=(const CustomCharString& customStr);

	const char* GetBuffer() const;

private:
	char* str;
	unsigned int length;
};


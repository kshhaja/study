#pragma once
#include "stdafx.h"

class SHFRAMEWORK_API CustomCharString
{
public:
	CustomCharString();
	~CustomCharString();

	// ���������
	CustomCharString(const CustomCharString& customStr);
	CustomCharString(const char* customStr);

	// ���Կ�����
	CustomCharString& operator=(const CustomCharString& customStr);

	const char* GetBuffer() const;

private:
	char* str;
	unsigned int length;
};


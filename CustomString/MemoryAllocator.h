#pragma once
#include "stdafx.h"
#include <cstddef>

namespace SHFramework
{
	namespace Allocator
	{
		class SHFRAMEWORK_API Allocator
		{
		public:
			Allocator(const size_t totalSize)
				: totalSize{ totalSize }
				, used{ 0 }
				, peak{ 0 }
			{
			}

			virtual ~Allocator()
			{
				totalSize = 0;
			}

			virtual void* allocate(const size_t size, const size_t alignment = 4) = 0;
			virtual void deallocate(void* ptr) = 0;
			virtual void init() = 0;
			size_t Peak() { return peak; }

			static size_t CalculatePadding(const size_t baseAddress, const size_t alignment);

		protected:
			size_t totalSize;
			size_t used;
			size_t peak;
		};
	}
}
#pragma once
#include "MemoryAllocator.h"

namespace SHFramework
{
	namespace Allocator
	{
		class SHFRAMEWORK_API LinearAllocator : public Allocator
		{
		public:
			LinearAllocator(const size_t totalSize);
			virtual ~LinearAllocator();

			virtual void* allocate(const size_t size, const size_t alignment = 4) override;
			virtual void deallocate(void* ptr) override;
			virtual void init() override;
			virtual void reset();

		private:
			LinearAllocator(LinearAllocator& linearAllocator);

		protected:
			void* startPtr = nullptr;
			size_t offset;
		};
	}
}


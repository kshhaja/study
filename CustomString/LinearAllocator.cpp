#include "LinearAllocator.h"
#include <cassert>
#include <memory>

using namespace SHFramework::Allocator;

LinearAllocator::LinearAllocator(const size_t totalSize) : Allocator(totalSize)
{
}

void LinearAllocator::init()
{
	if (startPtr != nullptr)
		free(startPtr);

	startPtr = malloc(totalSize);
	offset = 0;
}

LinearAllocator::~LinearAllocator() 
{
	free(startPtr);
	startPtr = nullptr;
}

void* LinearAllocator::allocate(const size_t size, const size_t alignment)
{
	size_t padding = 0;
	size_t paddedAddress = 0;

	const size_t currentAddress = (size_t)startPtr + offset;

	if (alignment != 0 && offset % alignment != 0)
	{
		padding = CalculatePadding(currentAddress, alignment);
	}

	if (offset + padding + size > totalSize)
	{
		return nullptr;
	}

	offset += padding;
	const size_t nextAddress = currentAddress + padding;
	offset += size;

	used = offset;
	peak = std::fmax(peak, used);

	return (void*)nextAddress;
}

void LinearAllocator::deallocate(void* ptr)
{
	assert(false && "use reset() method");
}

void LinearAllocator::reset()
{
	offset = 0;
	used = 0;
	peak = 0;
}
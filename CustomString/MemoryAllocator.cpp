#include "MemoryAllocator.h"
#include <cassert>

using namespace SHFramework::Allocator;

size_t Allocator::CalculatePadding(const size_t baseAddress, const size_t alignment)
{
	const size_t multiplier = (baseAddress / alignment) + 1;
	const size_t alignedAddress = multiplier * alignment;
	const std::size_t padding = alignedAddress - baseAddress;
	return padding;
}

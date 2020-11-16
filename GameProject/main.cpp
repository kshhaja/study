#include "CustomWCharString.h"
#include "LinearAllocator.h"
#include <iostream>
#include <string>
#include <vector>
#include <zstd.h>
#include <chrono>

using namespace SHFramework::Allocator;


void SingleAllocation(Allocator* allocator, const std::size_t size, const std::size_t alignment) {
	//std::cout << "BENCHMARK: ALLOCATION" << std::endl;
	//std::cout << "\tSize:     \t" << size << std::endl;
	//std::cout << "\tAlignment\t" << alignment << std::endl;

	allocator->init();

	auto operations = 0u;

	while (operations < operations) {
		allocator->allocate(size, alignment);
		++operations;
	}

}

void MultipleAllocation(Allocator* allocator, const std::vector<std::size_t>& allocationSizes, const std::vector<std::size_t>& alignments) {
	for (auto i = 0u; i < allocationSizes.size(); ++i) {
		SingleAllocation(allocator, allocationSizes[i], alignments[i]);
	}
}


void main()
{
	const std::vector<std::size_t> ALLOCATION_SIZES{ 32, 64, 256, 512, 1024, 2048, 4096, 4096*4096, 4096*4096*4096 };
	const std::vector<std::size_t> ALIGNMENTS{ 8, 8, 8, 8, 8, 8, 8, 8, 8 };

	// Some computation here
	Allocator* linearAllocator = new LinearAllocator(static_cast<size_t>(2));
	
	MultipleAllocation(linearAllocator, ALLOCATION_SIZES, ALIGNMENTS);
	
	auto start = std::chrono::system_clock::now();

	// 1억번 메모리 할당, 해제 반복 27.7초... 메모리 사용량 변화없음.
	for (int i = 0; i < 100000000; ++i)
	{
		SingleAllocation(linearAllocator, 64, 8);
	}

	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	time_t end_time = std::chrono::system_clock::to_time_t(end);

	std::cout << "finished computation at " << ctime(&end_time)
		<< "elapsed time: " << elapsed_seconds.count() << "s\n" << std::endl;


	CustomWCharString str = L"some";
	std::wcout << str.GetString() << std::endl;
	
	std::getchar();
}
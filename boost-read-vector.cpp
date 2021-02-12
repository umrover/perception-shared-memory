#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace boost::interprocess;

typedef allocator<int, managed_shared_memory::segment_manager>  ShmemAllocator;
typedef vector<int, ShmemAllocator> SharedVector;

int main(int argc, char *argv[]) {
    managed_shared_memory segment(open_only, "MySharedMemory");  

    //Find the vector using the c-string name
    SharedVector *vec = segment.find<SharedVector>("vec").first;

    //Use vector in reverse order
    std::cout << "first 3 vector elements: " << vec->at(0) << " " << vec->at(1) << " " << vec->at(2) << std::endl;

    //When done, destroy the vector from the segment
    segment.destroy<SharedVector>("vec");
}
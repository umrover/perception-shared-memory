#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
using namespace boost::interprocess;

typedef allocator<int, managed_shared_memory::segment_manager>  ShmemAllocator;
typedef vector<int, ShmemAllocator> SharedVector;

int main(int argc, char *argv[]) {

    managed_shared_memory segment(create_only, "MySharedMemory", 65536);

    const ShmemAllocator alloc_inst (segment.get_segment_manager());

    SharedVector *vec = segment.construct<SharedVector>("vec")(alloc_inst);

    for(int i = 0; i < 100; ++i)  //Insert data in the vector
         vec->push_back(i);

    return 0;
}
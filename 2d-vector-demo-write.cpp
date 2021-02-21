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

typedef allocator<vector<float>, managed_shared_memory::segment_manager>  ShmemAllocator;
typedef vector<vector<float>, ShmemAllocator> SharedVector;

int main(int argc, char *argv[]) {

    shared_memory_object::remove("Demo2dVec");

    managed_shared_memory segment(create_only, "Demo2dVec", 50000000);

    const ShmemAllocator alloc_inst (segment.get_segment_manager());

    SharedVector *vec = segment.construct<SharedVector>("vec")(alloc_inst);

    for(int i = 0; i < 100; ++i) {  //Insert data in the vector 
        vector<float> tmp;
        tmp.push_back(0.5);
        tmp.push_back(.25);
        vec->push_back(&tmp);
    }

    return 0;
}
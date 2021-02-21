#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace boost::interprocess;

typedef allocator<vector<float>, managed_shared_memory::segment_manager>  ShmemAllocator;
typedef vector<vector<float>, ShmemAllocator> SharedVector;

int main(int argc, char *argv[]) {
    managed_shared_memory segment(open_only, "Demo2dVec");  

    SharedVector *vec = segment.find<SharedVector>("vec").first;

    vector<float> vec2 = vec->at(0);

    //std::cout << vec2.at(0) << std::endl;

    //std::cout << "first 3 vector elements: " << vec->at(0).at(0) << " " << vec->at(1).at(0) << " " << vec->at(2).at(0) << std::endl;

    //segment.destroy<SharedVector>("vec");
}
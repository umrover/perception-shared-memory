#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <cstring>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    using namespace boost::interprocess;
    //Open already created shared memory object.
    shared_memory_object shm (open_only, "MySharedMemory", read_only);

    //Map the whole shared memory in this process
    mapped_region region(shm, read_only);

    //Check that memory was initialized to 1
    vector<int> *mem = new vector<int>();
    mem = static_cast<std::vector<int> *>(region.get_address());
    //printf("%d", *mem);
    std::cout << mem->at(0) << std::endl;
    shared_memory_object::remove("MySharedMemory");
    return 0;
}
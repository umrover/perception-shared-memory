#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <string>
#include <iostream>
#include <vector>

using namespace boost::interprocess;

int main(int argc, char *argv[]) {
    shared_memory_object shm (open_only, "DemoArr", read_only);

    mapped_region region(shm, read_only);

    int *mem;
    mem = static_cast<int *>(region.get_address());

    for(int i = 0; i <= 20; ++i) {
        int old = 0;
        int current = 0;
        while(current == old) {
            current = *(mem + i);
        }
        std::cout << "Index " << i << " changed, moving on" << std::endl;
    }
}
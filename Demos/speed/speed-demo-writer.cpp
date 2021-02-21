#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <string>
#include <iostream>
#include <vector>

using namespace boost::interprocess;

int main(int argc, char *argv[]) {

int arr[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int value = 1;

shared_memory_object::remove("DemoArr");

shared_memory_object shm (create_only, "DemoArr", read_write);

shm.truncate(1000);

mapped_region region(shm, read_write);

for(int i = 0; i < 20; ++i) { //write all 20 elements to shared memory
    std::memcpy(static_cast<int*>(region.get_address())+i, arr+i, region.get_size());
}

std::cout << "Waiting 10 seconds, start reader..." << std::endl; 

sleep(10);

std::cout << "Starting to overwrite..." << std::endl;

for(int i = 0; i <= 20; ++i) {
    sleep(3);
    arr[i] = value;
    std::memcpy(static_cast<int*>(region.get_address())+i, arr+i, region.get_size());
    std::cout << "writing " << value << " to index " << i << std::endl;
}

}
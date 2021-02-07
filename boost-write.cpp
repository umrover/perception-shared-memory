#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
   int arr[3] = {5, 2, 7};
   std::vector<int> *vec = new std::vector<int>();
   vec->push_back(2);
   vec->push_back(10);
   vec->push_back(2000);
   vec->push_back(1);
   vec->push_back(21);

   //std::vector<int> *ptr = &vec;

   using namespace boost::interprocess;
   shared_memory_object::remove("MySharedMemory");

   //Create a shared memory object.
   shared_memory_object shm (create_only, "MySharedMemory", read_write);

   //Set size
   shm.truncate(1000);

   //Map the whole shared memory in this process
   mapped_region region(shm, read_write);

   std::memcpy(static_cast<int*>(region.get_address()), vec, region.get_size());


   //Write all the memory to 1
   //for(int i = 0; i < 3; ++i) {
   //   std::memcpy(static_cast<int*>(region.get_address())+i, arr+i, region.get_size());
   //}
   return 0;
}
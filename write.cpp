#include "shared_memory.hpp"
  
int main() { 
   char* data = "lets go";
   int block_size = 1024;
   int block_id = 64;
   char* filename = "shmfile";
   publish_ptr(data, filename,  block_size, block_id);
   std::cout << "wrote " << data << " to shared memory with reference file " << filename << " and id " 
   << block_id << std::endl; 

}
#include "shared_memory.hpp"

int main() { 
   int block_size = 1024;
   int block_id = 64;
   char* filename = "shmfile";
   char* data = read_ptr<char>(filename, block_size, block_id);
   std::cout << "Read data from shared memory with reference file " << filename << " and id " 
   << block_id << " with value: " << data << std::endl;
} 

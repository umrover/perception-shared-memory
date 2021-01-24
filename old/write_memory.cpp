#include "shared_memory.h"

int main(int argc, char *argv[]) {
    if(argc != 2) {
        std::cerr << "usage - %s [stuff to write]" << std::endl;
    }

    char *block = attach_memory_block(FILENAME, BLOCK_SIZE);
    if(block == NULL) {
        std::cerr << "ERROR: couldn't access memory block" << std::endl;
    }

    std::cout << "Writing: " << argv[1] << std::endl;

    detach_memory_block(block);

    return 0;
}
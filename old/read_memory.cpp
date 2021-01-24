/*#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<iostream>

int main(int argc, char *argv[]) {
    /*if(argc != 1){
        std::cout << "usage - %s //no args" << argv[0] << std::endl;    
    }

    //grab shared memory block
    char *block = attach_memory_block(FILENAME, BLOCK_SIZE);
    if(block == NULL){
        std::cout << "ERROR: couldn't get block\n" << std::endl;
        return -1;
    }

    std::cout << "Reading: \"%s\"\n", block << std::endl;

    detach_memory_block(block);*/


//}
#include "shared_memory.h"

int main(int argc, char *argv[]) {
    if(argc != 1) {
        std::cerr << "usage - %s //no args" << std::endl;
    }

    char *block = attach_memory_block(FILENAME, BLOCK_SIZE);
    if(block == NULL) {
        std::cerr << "ERROR: couldn't access memory block" << std::endl;
    }

    std::cout << "Reading: " << block << std::endl; 

    detach_memory_block(block);

    return 0;
}


#include <iostream> 
#include <sys/ipc.h> 
#include <sys/shm.h> 

void publish_ptr(void *ptr, char* filename, int block_size, int block_id);

void *read_ptr(char* filename, int block_size, int block_id);
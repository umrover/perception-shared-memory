#include <cstring>
#include <iostream>
#include <sys/shm.h>

#define IPC_RESULT_ERROR (-1)
#define FILENAME "shmfile"
#define BLOCK_SIZE 1024

static int get_shared_block(char *filename, int size);

char * attach_memory_block(char *filename, int size);

bool detach_memory_block(char *block);

bool destroy_memory_block(char *filename);
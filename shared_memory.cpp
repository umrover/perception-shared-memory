#include "shared_memory.hpp"

void publish_ptr(void *ptr, char* filename, int block_size, int block_id) {
    key_t key = ftok(filename, block_id); 
  
    // shmget returns an identifier in shmid 
    int shmid = shmget(key, block_size, 0666 | IPC_CREAT);
  
    // shmat to attach to shared memory 
    void *pointer = shmat(shmid, (void*)0, 0); 
  
    pointer = ptr;
      
    //detach from shared memory  
    shmdt(pointer); 
}

void *read_ptr(char* filename, int block_size, int block_id) {
    // ftok to generate unique key 
    key_t key = ftok(filename, block_id); 
  
    // shmget returns an identifier in shmid 
    int shmid = shmget(key, block_size, 0666 | IPC_CREAT); 
  
    // shmat to attach to shared memory 
    void *pointer = shmat(shmid,(void*)0,0); 
      
    //detach from shared memory  
    shmdt(pointer); 
    return pointer;
}
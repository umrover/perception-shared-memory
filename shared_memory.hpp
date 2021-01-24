#include <iostream> 
#include <sys/ipc.h> 
#include <sys/shm.h> 

template <class T>
void publish_ptr(T *ptr, char* filename, int block_size, int block_id) {
    key_t key = ftok(filename, block_id); 
  
    // shmget returns an identifier in shmid 
    int shmid = shmget(key, block_size, 0666|IPC_CREAT);
  
    // shmat to attach to shared memory 
    T *pointer = (T*) shmat(shmid, (void*)0, 0); 
    
    memcpy(pointer, ptr, sizeof(ptr));
      
    //detach from shared memory  
    shmdt(pointer); 
}

template <class T>
T *read_ptr(char* filename, int block_size, int block_id) {
    // ftok to generate unique key 
    key_t key = ftok(filename, block_id); 
  
    // shmget returns an identifier in shmid 
    int shmid = shmget(key, block_size, 0666|IPC_CREAT); 
  
    // shmat to attach to shared memory 
    T *pointer = (T*)shmat(shmid,(void*)0,0); 
    
    //return the found data
    return pointer;
}

template <class T>
void detach_memory_block(T *pointer) {
    shmdt(pointer); 
}
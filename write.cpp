#include "shared_memory.hpp"
using namespace std; 
  
int main() { 
    /*
    // ftok to generate unique key 
    key_t key = ftok("shmfile",64); 
  
    // shmget returns an identifier in shmid 
    int shmid = shmget(key,1024,0666|IPC_CREAT);
  
    // shmat to attach to shared memory 
    char *str = (char*) shmat(shmid,(void*)0,0); 
  
    cout<<"Write Data : "; 
    cin >> str; 
  
    printf("Data written in memory: %s\n",str); 
      
    //detach from shared memory  
    shmdt(str); 
  
    return 0; 
    */

   char* data = "hello";
   int block_size = 1024;
   int block_id = 64;
   char* filename = "shmfile";
   publish_ptr(data, filename,  block_size, block_id);
   cout << "wrote " << data << " to shared memory with reference file " << filename << " and id " << block_id << endl; 

}
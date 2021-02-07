#include "shared_memory.hpp"
//#include <opencv2/opencv.hpp>
//using namespace cv;
using namespace std;

int main() { 
   int *ptr;
   int data = 1234;
   ptr = &data;
   int block_size = 1024;
   int block_id = 64;
   char* filename = "shmfile";

   publish_ptr(ptr, filename,  block_size, block_id);

   std::cout << "wrote " << data << " to shared memory with reference file " << filename << " and id " 
   << block_id << std::endl; 
   /*
   Mat image = imread("test.jpg");
   uchar* data = image.data;
   int block_size = 1024;
   cout << block_size << endl;
   int block_id = 64;
   char* filename = "shmfile";

   publish_ptr(data, filename,  block_size, block_id);

   /*
   String windowName = "Test"; //Name of the window

   namedWindow(windowName); // Create a window

   imshow(windowName, image); // Show our image inside the created window.

   waitKey(0); // Wait for any keystroke in the window

   destroyWindow(windowName); //destroy the created window
   */
  
   return 0;

}
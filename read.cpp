#include "shared_memory.hpp"
//#include <opencv2/opencv.hpp>
//using namespace cv;
using namespace std;

int main() { 
   
   int block_size = 1024;
   int block_id = 64;
   char* filename = "shmfile";

   int* data = read_ptr<int>(filename, block_size, block_id);

   std::cout << "Read data from shared memory with reference file " << filename << " and id " 
   << block_id << " with value: " << *data << std::endl;
   
   /*int block_size = 1024;
   int block_id = 64;
   char* filename = "shmfile";

   uchar* data = read_ptr<uchar>(filename, block_size, block_id);
   cout << *data;
   //Mat image = ConvertToMat(data, 2316, 3088);
   Mat image(3088, 2316, CV_8UC3, *data);

   String windowName = "Test"; //Name of the window

   namedWindow(windowName); // Create a window

   imshow(windowName, image); // Show our image inside the created window.

   waitKey(0); // Wait for any keystroke in the window

   destroyWindow(windowName); //destroy the created window
   detach_memory_block(data);
   */
} 

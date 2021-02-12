#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace boost::interprocess;

int main() {

    //Create a shared memory object.
    shared_memory_object shm (open_only, "SharedMat", read_only);

    //Map the whole shared memory in this process
    mapped_region region(shm, read_only);

    int *mem;
    mem = static_cast<int *>(region.get_address());

    Mat image = Mat(3088, 2316,  CV_8UC3, mem);

    String windowName = "Test"; //Name of the window

    namedWindow(windowName); // Create a window

    imshow(windowName, image); // Show our image inside the created window.

    waitKey(0); // Wait for any keystroke in the window

    destroyWindow(windowName); //destroy the created window

    return 0;
}
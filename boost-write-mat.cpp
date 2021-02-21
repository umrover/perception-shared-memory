#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <opencv2/opencv.hpp>
#include <string>

using namespace cv;
using namespace boost::interprocess;

int main() {
    Mat image = imread("test.jpg");

    shared_memory_object::remove("SharedMat");

    //Create a shared memory object.
    shared_memory_object shm (create_only, "SharedMat", read_write);

    Size mat_size = image.size();
    int mem_size = 3 * mat_size.width * mat_size.height;
    //Set size
    shm.truncate(mem_size);

    //Map the whole shared memory in this process
    mapped_region region(shm, read_write);

    if(image.isContinuous()) {
        std::memcpy(region.get_address(), image.ptr(), image.channels()*image.rows*image.cols);
    } else {
        Mat cont_image = image.clone();
        std::memcpy(region.get_address(), cont_image.ptr(), cont_image.channels()*cont_image.rows*cont_image.cols);
    }

    return 0;
}

//g++ $(pkg-config --cflags --libs opencv4) -std=c++11 -o writemat boost-write-mat.cpp
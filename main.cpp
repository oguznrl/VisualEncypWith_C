#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <iostream>
#include "sbox.h"
#include "EncryptionModel.h"
using namespace cv;

int main()
{   EncryptionModel e;
    e.image_path="/home/xenon136/phmm_encryption/veriseti_test/uydu2.jpg";
    e.get_randomarr();
    //e.getIV();
    e.get_maxChaind();
    //e.getColorMatrix();
    e.getPHMM();
    //e.getPV();
    e.applyEncyp("ResultDir/baboonEncyp.png");
    e.applyDecyp("ResultDir/baboonDencyp.png");
    /*sbox s;
    s.generate_box();
*/

    /* std::string image_path = samples::findFile("/home/seuz/Desktop/phmm_encryption/lena_selectedImage.jpg");
     Mat_<Vec3b> img = imread(image_path, IMREAD_COLOR);
     Vec3b intensity = img.at<Vec3b>(15, 15);
     int blue = intensity.val[0];
     std::cout<<blue<<std::endl;
     uchar green = intensity.val[1];
     uchar red = intensity.val[2];
     //Vec3b x = img(10, 29);
     //std::cout << x << " "<<img.cols<< std::endl;

     if(img.empty())
     {
         std::cout << "Could not read the image: " << image_path << std::endl;
         return 1;
     }
     imshow("Display window", img);

     //std::cout << "R (numpy)   = " << std::endl << format(img, Formatter::FMT_NUMPY ) << std::endl << std::endl;
     int k = waitKey(0); // Wait for a keystroke in the window
     if(k == 's')
     {
         imwrite("starry_night.png", img);
     }*/
    return 0;

}
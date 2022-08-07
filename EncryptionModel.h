#ifndef IMAGE_ENCYP_ENCRYPTIONMODEL_H
#define IMAGE_ENCYP_ENCRYPTIONMODEL_H
#include "string"
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include "sbox.h"
using namespace std;
using namespace cv;
class EncryptionModel {
public:
    sbox s_box;
    string image_path="/home/xenon136/phmm_encryption/veriseti_test/baboon_selectedImage.png";
    Mat_<Vec3b> img = imread(image_path, IMREAD_COLOR);
    int column=img.cols;
    int row=img.rows;
    int *random_array;
    int *IV;
    char **max_indcha=new char*[row];
    char *pv;
    void get_randomarr();
    void get_maxChaind();
    void getPHMM();
    void getIV();
    void getColorMatrix();
    void getPV();
    void applyEncyp(string saved_name);
    void applyDecyp(string saved_name);



};


#endif //IMAGE_ENCYP_ENCRYPTIONMODEL_H
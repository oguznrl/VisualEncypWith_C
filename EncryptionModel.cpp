//
// Created by seuz on 13.09.2021.
//
#include "iostream"
#include "EncryptionModel.h"

using namespace std;

void EncryptionModel::get_randomarr() {
    random_array=new int[column];
    srand (time(NULL));
    for (int i = 0; i <column ; ++i) {
        int random_number=rand() % 256;
        random_array[i]=random_number;
    }
    IV=new int[column];
    for (int i = 0; i <column ; ++i) {
        IV[i]=random_array[i];
    }

}
void EncryptionModel::getIV() {
    cout<<"Initialize Vector"<<endl;
    for (int i = 0; i <column ; ++i) {
        cout<<random_array[i]<<endl;
    }
}
void EncryptionModel::get_maxChaind() {
    for (int i = 0; i <row ; ++i) {
        max_indcha[i]=new char[column];
        for (int j = 0; j <column ; ++j) {
            Vec3b &intensity = img.at<Vec3b>(i, j);
            int b=intensity[0];
            int g=intensity[1];
            int r=intensity[2];
            if(b>=g&&b>=r){
                max_indcha[i][j]='B';
            }
            else if(g>=b&&g>=r){
                max_indcha[i][j]='G';
            }
            else if (r>=b&&r>=g){
                max_indcha[i][j]='R';
            }
        }
    }


}

void EncryptionModel::getColorMatrix() {
    cout<<"Color Matrix"<<endl;
    for (int i = 0; i <row ; ++i) {
        for (int j = 0; j <column ; ++j) {
            cout<<max_indcha[i][j]<<" ";
        }
        cout<<endl;
    }
}
void EncryptionModel::getPHMM() {
    pv=new char[column];
    char last='0';
    int bgr[3]={0,0,0};
    for (int i = 0; i <column ; ++i) {
        if (i==0){
            for (int j = 0; j <row ; ++j) {

                if (max_indcha[j][i]=='B'){
                    bgr[0]++;
                    last='B';
                }
                else if (max_indcha[j][i]=='G'){
                    bgr[1]++;
                    last='G';
                }
                else if (max_indcha[j][i]=='R'){
                    bgr[2]++;
                    last='R';
                }

            }
            if (bgr[0]>=bgr[1]&&bgr[0]>=bgr[2]){
                pv[i]='B';
            }
            else if (bgr[1]>=bgr[0]&&bgr[1]>=bgr[2]){
                pv[i]='G';
            }
            else if (bgr[2]>=bgr[0]&&bgr[2]>=bgr[1]){
                pv[i]='R';
            }
        }
        else{
            for (int j = 0; j <row ; ++j) {
                if (max_indcha[j][i-1]==last){
                    if (max_indcha[j][i]=='B'){
                        bgr[0]++;
                        last='B';
                    }
                    else if (max_indcha[j][i]=='G'){
                        bgr[1]++;
                        last='G';
                    }
                    else if (max_indcha[j][i]=='R'){
                        bgr[2]++;
                        last='R';
                    }
                }
                if (bgr[0]>=bgr[1]&&bgr[0]>=bgr[2]){
                    pv[i]='B';
                }
                else if (bgr[1]>=bgr[0]&&bgr[1]>=bgr[2]){
                    pv[i]='G';
                }
                else if (bgr[2]>=bgr[0]&&bgr[2]>=bgr[1]){
                    pv[i]='R';
                }
            }
        }
        bgr[0]=0;
        bgr[1]=0;
        bgr[2]=0;
    }
}


void EncryptionModel::getPV() {
    cout<<"Probility Vector"<<endl;
    for (int i = 0; i <column ; ++i) {
        cout<<pv[i]<<" ";
    }
}

void EncryptionModel::applyEncyp(string saved_name) {
    s_box.generate_box();

    for (int i = 0; i <row ; ++i) {
        for (int j = 0; j < column; ++j) {
            Vec3b &intensity = img.at<Vec3b>(i, j);
            int b=intensity[0];
            int g=intensity[1];
            int r=intensity[2];
            b^=random_array[j];
            b=s_box.s_box[b];
            g^=random_array[j];
            g=s_box.s_box[g];
            r^=random_array[j];
            r=s_box.s_box[r];
            if (pv[j]=='B'){
                random_array[j]^=intensity[0];
            }
            else if (pv[j]=='G'){
                random_array[j]^=intensity[1];
            }
            else if (pv[j]=='R'){
                random_array[j]^=intensity[2];
            }
            intensity[0]=b;
            intensity[1]=g;
            intensity[2]=r;

        }
    }
    imshow("Encyp",img);
    int k = waitKey(0);
    if(k == 's')
    {
        imwrite(saved_name, img);
    }
}

void EncryptionModel::applyDecyp(string saved_name) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            Vec3b &intensity = img.at<Vec3b>(i, j);
            int blue=intensity[0];
            int green=intensity[1];
            int red=intensity[2];
            int b=s_box.reverse_sbox[blue];
            intensity[0]=b^IV[j];
            int g=s_box.reverse_sbox[green];
            intensity[1]=g^IV[j];
            int r=s_box.reverse_sbox[red];
            intensity[2]=r^IV[j];
            if(pv[j]=='B'){
                IV[j]=b;
            }
            else if(pv[j]=='G'){
                IV[j]=g;
            }
            else if(pv[j]=='R'){
                IV[j]=r;
            }
        }
    }
    imshow("Decyp",img);
    int k = waitKey(0);
    if(k == 's')
    {
        imwrite(saved_name, img);
    }
}
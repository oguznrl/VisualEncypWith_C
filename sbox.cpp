//
// Created by seuz on 13.09.2021.
//

#include "sbox.h"
#include <stdlib.h>
#include <time.h>
#include "iostream"
#include "vector"
using namespace std;
void sbox::generate_box() {
    int pool_len=256;
    vector<int> pool;
    srand (time(NULL));
    for (int i = 0; i <pool_len ; ++i) {
        pool.push_back(i);
    }
    for (int i = 0; i <256 ; ++i) {
        int random_number=rand() % pool_len;
        s_box[i]=pool[random_number];
        reverse_sbox[s_box[i]]=i;
        pool.erase(pool.begin()+random_number);
        pool_len--;
    }
}
void sbox::get_Sbox() {
    cout<<"S-Box"<<endl;
    for (int i = 0; i <256 ; ++i) {
        cout<<i<<" , "<< s_box[i]<<endl ;
    }
}

void sbox::get_RSbox() {
    cout<<"Reverse S-Box"<<endl;
    for (int i = 0; i <256 ; ++i) {
        cout<<i<<" , "<< reverse_sbox[i]<<endl ;
    }
}
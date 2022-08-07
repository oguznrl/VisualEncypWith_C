//
// Created by seuz on 13.09.2021.
//

#ifndef IMAGE_ENCYP_SBOX_H
#define IMAGE_ENCYP_SBOX_H

#include "inttypes.h"
class sbox{
public:
    int s_box[256];
    int reverse_sbox[256];
    void get_Sbox();
    void get_RSbox();
    void generate_box();

};

#endif //IMAGE_ENCYP_SBOX_H
//
//  main.cpp
//  RobustConvolution
//
//  Created by Derrick Reyes on 10/6/19.
//  Copyright © 2019 Derrick Reyes. All rights reserved.
//
/*
 A more robust algorithm for performing convoution operations on a signal.
 */


#include <iostream>
#include <fstream>
#include <stdint.h>
#include "convolution.hpp"
#define BLOCKSIZE 320
#define IMP_RSP_LENGTH 29
using namespace std;


extern double InputSignal_f32_1kHz_15kHz[BLOCKSIZE];
extern double  Impulse_response[IMP_RSP_LENGTH];
double outputSignal[BLOCKSIZE + IMP_RSP_LENGTH];


int main()
{
    ofstream file1, file2;
    
    Conv(InputSignal_f32_1kHz_15kHz,
         BLOCKSIZE,
         Impulse_response,
         IMP_RSP_LENGTH,
         outputSignal);
    
    file1.open("output_signal.dat");
    file2.open("input_signal.dat");
    
    for (int i = 0; i < BLOCKSIZE + IMP_RSP_LENGTH; i++)
    {
        file1 << outputSignal[i] << endl;
        
        if (i < BLOCKSIZE)
        {
            file2 << InputSignal_f32_1kHz_15kHz[i] << endl;
        }
    }
    
    file1.close();
    file2.close();
    
    return 0;
}

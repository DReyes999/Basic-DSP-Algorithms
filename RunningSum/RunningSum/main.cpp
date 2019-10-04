//
//  main.cpp
//  RunningSum
//
//  Created by Derrick Reyes on 10/4/19.
//  Copyright © 2019 Derrick Reyes. All rights reserved.
//

/*
An algorithm for calculating the running sum of an input signal. The running sum algorithm can be thought of as a general smoothing filter and is useful for things like peak detection.
 
 Takes 3 arguments:
 - A pointer to signal source array
 - A pointer to the destination array
 - our signal length
 */

#include <iostream>
#include <fstream> // allows us to write to files
#include <cmath> // Allows us to use complex math functions
#define SIG_LENGTH 320
using namespace std;

extern double InputSignal_f32_1kHz_15kHz[SIG_LENGTH];

//Arr to store our output
double outputSignal[SIG_LENGTH];

void Calc_Running_Sum(double *sig_src_arr, double *sig_dest_arr, int sig_length);



int main()
{
    ofstream file1,file2;
    
    Calc_Running_Sum((double*)&InputSignal_f32_1kHz_15kHz[0], (double*)&outputSignal[0], (int)SIG_LENGTH);
    
    //Open our files for writing
    file1.open("output_signal.dat");
    file2.open("input_signal.dat");
    
    //Write the input and out signals to files
    for (int i = 0; i < SIG_LENGTH; i++)
    {
        file1 << outputSignal[i] << endl;
        file2 << InputSignal_f32_1kHz_15kHz[i] << endl;
    }
    
    file1.close();
    file2.close();
    
    return 0;
}

void Calc_Running_Sum(double *sig_src_arr, double *sig_dest_arr, int sig_length)
{
    for (int i = 0; i < sig_length; i++)
    {
        sig_dest_arr[i] = sig_dest_arr[i-1] + sig_src_arr[i];
    }
}

//
//  main.cpp
//  First Difference
//
//  Created by Derrick Reyes on 10/4/19.
//  Copyright © 2019 Derrick Reyes. All rights reserved.
//

/*
 An algorithm for calculating the first difference of a given signal
 */

#include <iostream>
#include <fstream> // allows us to write to files
#include <cmath> // Allows us to use complex math functions
#define SIG_LENGTH 320
using namespace std;

extern double InputSignal_f32_1kHz_15kHz[SIG_LENGTH];

//Arr to store our output
double runningSumOutput[SIG_LENGTH];
double firstDifferenceOutput[SIG_LENGTH];

void Calc_Running_Sum(double *sig_src_arr, double *sig_dest_arr, int sig_length);
void Calc_First_Difference(double *sig_src_arr, double *sig_dest_arr, int sig_length);

int main()
{
    ofstream file1,file2,file3;
    
    Calc_Running_Sum((double*)&InputSignal_f32_1kHz_15kHz[0], (double*)&runningSumOutput[0], (int)SIG_LENGTH);
    Calc_First_Difference((double*)&InputSignal_f32_1kHz_15kHz[0], (double*)&firstDifferenceOutput[0], (int)SIG_LENGTH);
    
    //Open our files for writing
    file1.open("running_sum_signal.dat");
    file2.open("first_diff_signal.dat");
    file3.open("input_signal");
    
    //Write the input and out signals to files
    for (int i = 0; i < SIG_LENGTH; i++)
    {
        file1 << runningSumOutput[i] << endl;
        file2 << firstDifferenceOutput[i] << endl;
        file3 << InputSignal_f32_1kHz_15kHz[i] << endl;
    }
    
    file1.close();
    file2.close();
    file3.close();
    
    return 0;
}

void Calc_Running_Sum(double *sig_src_arr, double *sig_dest_arr, int sig_length)
{
    for (int i = 0; i < sig_length; i++)
    {
        sig_dest_arr[i] = sig_dest_arr[i-1] + sig_src_arr[i];
    }
}

void Calc_First_Difference(double *sig_src_arr, double *sig_dest_arr, int sig_length)
{
    for (int i = 0; i < sig_length; i++)
    {
        sig_dest_arr[i] = sig_src_arr[i] - sig_src_arr[i-1];
    }

}

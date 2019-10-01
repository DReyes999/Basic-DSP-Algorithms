//
//  main.cpp
//  SignalMeanAlgorithm
//
//  Created by Derrick Reyes on 7/15/19.
//  Copyright © 2019 Derrick Reyes. All rights reserved.
//

/*
 This project is part of the course where we learn signal statistics.
 In this project we learn an algorithm for deriving the mean of the signal.
 
 First we import a signal and compute the mean of that signal
*/

// Defines the term SIG_LENGTH as 320. Our Signal containes 320 samples
#define SIG_LENGTH 320
#include <iostream>
#include <cmath>
using namespace std;

/*
 'InputSignal_f32_1kHz_15kHz' means the input signal is 32b floating point
 it has a 1khz component and a 15khz component.
*/

extern double InputSignal_f32_1kHz_15kHz[SIG_LENGTH];
double CalcSignalMean(double *sig_src_arr, int sig_length);
double CalcSignalVariance(double *sig_src_arr,double sig_mean, int sig_length);

double signal_mean;
double signal_variance;

int main(int argc, const char * argv[])
{
    signal_mean = CalcSignalMean(&InputSignal_f32_1kHz_15kHz[0], SIG_LENGTH);
    signal_variance = CalcSignalVariance(&InputSignal_f32_1kHz_15kHz[0], signal_mean, SIG_LENGTH);
    
    cout << "\nMean = " << signal_mean << endl;
    cout << "Variance = " << signal_variance << "\n\n";
    
    return 0;
}

/* Here we will define the function for calculating our mean
 It will take two arguments. The first is a pointer to the array that contains
 our input signal and the second is the length of our inout signal.
 
 It will return our mean, which is a double type
 
 'sig_src_arr' is short for 'signal source array'. The array which contains our signal
 */

double CalcSignalMean(double *sig_src_arr, int sig_length)
{
    double _mean = 0.0;
    for (int i = 0 ; i < sig_length; i++)
    {
        // Take each value from the array (sample) and add it to _mean
        _mean += sig_src_arr[i];
    }
    
    _mean = _mean / (double)sig_length;
    
    return _mean;
}

/*
 Here we will define a function for finding the signal variance
 
 This function will take 3 parameters. The signal source array, the mean, and the signal length
 
 This function will take each sample, and find how much it 'varies' from the mean of
 our data set, which was calculated with the function CalcSignalMean(). Then it will square
 that amount.
 
 It will add the sum of all of the squares and then divide it by the number of samples.
*/

double CalcSignalVariance(double *sig_src_arr,double sig_mean, int sig_length)
{
    double _variance = 0.0;
    
    for (int i = 0; i < sig_length; i++)
    {
        _variance = _variance + pow((sig_src_arr[i] - sig_mean), 2);
    }
    
    _variance = _variance / (double)(sig_length - 1);
    
    return _variance;
}



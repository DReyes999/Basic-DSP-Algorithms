//
//  SignalStatistics.cpp
//  SignalStatisticsClass
//
//  Created by Derrick Reyes on 7/16/19.
//  Copyright © 2019 Derrick Reyes. All rights reserved.
//

#include "SignalStatistics.hpp"
#include <cmath>


/* Constructor for SignalStatistics class */
SignalStatistics::SignalStatistics(double* _sig_src_arr, int _sig_length)
{
    sig_src_arr = _sig_src_arr;
    sig_length = _sig_length;
}

double SignalStatistics::CalcSignalMean()
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

double SignalStatistics::CalcsignalVariance()
{
    double sig_mean = CalcSignalMean();
    double _variance = 0.0;
    
    for (int i = 0; i < sig_length; i++)
    {
        _variance = _variance + pow((sig_src_arr[i] - sig_mean), 2);
    }
    
    _variance = _variance / (sig_length - 1);
    
    return _variance;
}

double SignalStatistics::CalcSignalSTD()
{
    double sig_variance = CalcsignalVariance();
    double _std = sqrt(sig_variance);
    
    return _std;
}

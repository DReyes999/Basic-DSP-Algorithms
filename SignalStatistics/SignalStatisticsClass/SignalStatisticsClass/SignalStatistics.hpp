//
//  SignalStatistics.hpp
//  SignalStatisticsClass
//
//  Created by Derrick Reyes on 7/16/19.
//  Copyright © 2019 Derrick Reyes. All rights reserved.
//

#ifndef SignalStatistics_hpp
#define SignalStatistics_hpp

#include <stdio.h>

class SignalStatistics
{
private:
    /*
     Below are the parameters necessary for finding our
     Signal Statistics
     */
    
    double* sig_src_arr;
    int sig_length;
    
    /* Below are the methods for finding signal stats */
public:
    SignalStatistics(double* _sig_src_arr, int _sig_length);
    
    double CalcSignalMean();
    double CalcsignalVariance();
    double CalcSignalSTD();
    
};

#endif /* SignalStatistics_hpp */

//
//  main.cpp
//  SignalStatisticsClass
//
//  Created by Derrick Reyes on 7/16/19.
//  Copyright © 2019 Derrick Reyes. All rights reserved.
//

#include <iostream>
using namespace std;
#include "SignalStatistics.hpp"

extern double InputSignal_f32_1kHz_15kHz[320];

int main(int argc, const char * argv[])
{
    double mean;
    double variance;
    double std;
    
    SignalStatistics *testSignal = new SignalStatistics(&InputSignal_f32_1kHz_15kHz[0], (sizeof(InputSignal_f32_1kHz_15kHz)/sizeof(InputSignal_f32_1kHz_15kHz[0])));
    
    mean = testSignal->CalcSignalMean();
    variance = testSignal->CalcsignalVariance();
    std = testSignal->CalcSignalSTD();
    
    cout << mean << endl;
    cout << variance << endl;
    cout << std << endl;
    
    return 0;
}

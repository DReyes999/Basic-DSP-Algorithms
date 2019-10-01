//
//  main.cpp
//  SignalStatsTest2
//
//  Created by Derrick Reyes on 7/18/19.
//  Copyright © 2019 Derrick Reyes. All rights reserved.
//

#include <iostream>
#include "SignalStatistics.hpp"

using namespace std;
extern double InputSignal_f32_1kHz_15kHz[320];

int main(int argc, const char * argv[]) {
    
    
    double variance;
    double mean;
    double std;
    
    SignalStatistics *testSignal = new SignalStatistics(&InputSignal_f32_1kHz_15kHz[0],
                                                        (sizeof(InputSignal_f32_1kHz_15kHz)/sizeof(InputSignal_f32_1kHz_15kHz[0])));
    variance = testSignal->CalcsignalVariance();
    mean = testSignal->CalcSignalMean();
    std = testSignal->CalcSignalSTD();
    
    cout << "variance: " <<  variance << endl;
    cout << "mean: " <<  mean << endl;
    cout << "STD: " << std << endl;
    
    
    return 0;
}

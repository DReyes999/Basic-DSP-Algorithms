//
//  main.cpp
//  SignalstatisticsTest
//
//  Created by Derrick Reyes on 7/17/19.
//  Copyright © 2019 Derrick Reyes. All rights reserved.
//

#include <iostream>
#include "SignalStatistics.hpp"
using namespace std;

extern double InputSignal_f32_1kHz_15kHz[320];

int main(int argc, const char * argv[]) {
    
    double variance;
    
    SignalStatistics *testSignal = new SignalStatistics(&InputSignal_f32_1kHz_15kHz[0],
                                                        (sizeof(InputSignal_f32_1kHz_15kHz)/sizeof(InputSignal_f32_1kHz_15kHz[0])));
    variance = testSignal->CalcsignalVariance();
    cout << variance << endl;
    
    
    return 0;
}

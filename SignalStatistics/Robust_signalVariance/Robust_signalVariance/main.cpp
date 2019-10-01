//
//  main.cpp
//  Robust_signalVariance
//
//  Created by Derrick Reyes on 8/18/19.
//  Copyright © 2019 Derrick Reyes. All rights reserved.
//

#include <iostream>
#include "variance.hpp"
#define BLOCKSIZE 320
using namespace std;

extern double InputSignal_f32_1kHz_15kHz[320];

double variance;

int main()
{
    Sig_Variance(InputSignal_f32_1kHz_15kHz, BLOCKSIZE, &variance);
    cout << variance << endl;
    
    return 0;
}

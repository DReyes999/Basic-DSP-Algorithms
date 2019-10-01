//
//  main.cpp
//  Robust_SignalMean
//
//  Created by Derrick Reyes on 7/21/19.
//  Copyright © 2019 Derrick Reyes. All rights reserved.
//

/*
 Robust algorithms are the algorithms we should be using in our production code.
 We also introduce a concept called Block size which we will use now instead of signal length.
 */

#include <iostream>
#include "mean.hpp"
#define BLOCKSIZE 320
using namespace std;

extern double InputSignal_f32_1kHz_15kHz[320];
double mean;

int main(int argc, const char * argv[])
{
    
    
    
    Sig_Mean(InputSignal_f32_1kHz_15kHz, BLOCKSIZE, &mean);
    
    
    cout << "mean: " << mean << endl;
    return 0;
}

//
//  main.cpp
//  Robust_SignalRMS
//
//  Created by Derrick Reyes on 8/27/19.
//  Copyright © 2019 Derrick Reyes. All rights reserved.
//

#include <iostream>
#include "rms.hpp"
#define BLOCKSIZE 320

using namespace std;

extern double InputSignal_f32_1kHz_15kHz[320];

double rms;

int main()
{
    Sig_Rms(InputSignal_f32_1kHz_15kHz, BLOCKSIZE, &rms);
    std::cout << rms << endl;
    return 0;
}

//
//  rms.hpp
//  Robust_SignalRMS
//
//  Created by Derrick Reyes on 8/27/19.
//  Copyright © 2019 Derrick Reyes. All rights reserved.
//

#ifndef rms_hpp
#define rms_hpp

#include <stdio.h>
#include <cmath>

void Sig_Rms(double * sig_src_arr, u_int32_t blocksize, double * pResult);

#endif /* rms_hpp */

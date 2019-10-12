//
//  convolution.hpp
//  RobustConvolution
//
//  Created by Derrick Reyes on 10/6/19.
//  Copyright © 2019 Derrick Reyes. All rights reserved.
//

#ifndef convolution_hpp
#define convolution_hpp

#include <stdio.h>
#include <stdint.h>

void Conv(double * pSrcA,u_int32_t srcALen,double * pSrcB,u_int32_t srcBLen,double * pDst);

#endif /* convolution_hpp */

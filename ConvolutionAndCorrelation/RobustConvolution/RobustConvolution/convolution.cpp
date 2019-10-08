//
//  convolution.cpp
//  RobustConvolution
//
//  Created by Derrick Reyes on 10/6/19.
//  Copyright © 2019 Derrick Reyes. All rights reserved.
//

/**Convolution is a mathematical operation that operates on two finite length vectors to generate a finite length output vector.
 * Convolution is similar to correlation and is frequently used in filtering and data analysis. */

/**
 * @brief Convolution of floating-point sequences.
 * @param[in] *pSrcA points to the first input sequence.
 * @param[in] srcALen length of the first input sequence.
 * @param[in] *pSrcB points to the second input sequence.
 * @param[in] srcBLen length of the second input sequence.
 * @param[out] *pDst points to the location where the output result is written.  Length srcALen+srcBLen-1.
 * @return none.
 */


#include "convolution.hpp"

void Conv(double * pSrcA,
          u_int32_t srcALen,
          double * pSrcB,
          u_int32_t srcBLen,
          double * pDst)
{
    // Intermediate variables for computation
    double *pIn1;           //InputA pointer
    double *pIn2;           //InputB pointer
    double *pOut = pDst;    //Output pointer
    double *px;             //Intermediate InputA pointer
    double *py;             //Intermediate InputB pointer
    
    double *pSrc1, *pSrc2;  //Intermediate pointers
    double sum,             //Accumulators
            acc0,
            acc1,
            acc2,
            acc3;
    double x0,x1,x2,x3,c0;
    u_int32_t j,k,count,    //Loop counters
            blkCount,
            blocksize1,
            blocksize2,
            blocksize3;
    
    /* Check which signal length is shorter
     The shorter signal length acts as the signal response
     and is slid across the larger signal*/
    
    if (srcALen > srcBLen)
    {
        pIn1 = pSrcA;
        pIn2 = pSrcB;
    }else
    {
        pIn1 = pSrcB;
        pIn2 = pSrcA;
        
        j = srcBLen;
        srcBLen = srcALen;
        srcALen = j;
    }
    
    /* Start the actual convolution algorithm */
    
    blocksize1 = srcBLen -1;
    blocksize2 = srcALen - (srcBLen-1);
    blocksize3 = blocksize1;
    
    
  
}

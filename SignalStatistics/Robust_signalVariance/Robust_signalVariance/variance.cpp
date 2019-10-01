//
//  variance.cpp
//  Robust_signalVariance
//
//  Created by Derrick Reyes on 8/18/19.
//  Copyright © 2019 Derrick Reyes. All rights reserved.
//

/*
 @ brief Variance of the elements of a floating point vector
 @param[in] *pSig src arr points to the input vector
 @param[in] blocksize length of the input vector
 @param[out] *pResult variance value returned here
 @return none:
 */

#include "variance.hpp"
#include <stdint.h>

void Sig_Variance(double * pSig_Src_Arr, uint32_t blocksize, double *pResult)
{
    double fMean, fValue;
    uint32_t blkCnt;
    double * pInput = pSig_Src_Arr;
    
    double sum = 0.0;
    double fSum = 0.0;
    
    double in1, in2, in3, in4;
    
    if(blocksize <= 1)
    {
        *pResult = 0;
        return;
    }
    
    /* divide signal length into 4 and store it in loop counter to begin our loop unrolling */
    
    /* Initialize blkCnt
     blocksize is same as signal length. We are dividing it by 4.
     blkCnt is our loopcounter.
     
     '>' means right shift means divide the number on the left
     by 2 raised to the power of the number on the right of the shift
     
     */
    
    blkCnt = blocksize >>2; // blkCnt = blocksize / 2^2 = blocksize /4
    
    /* Begin Loop Unrolling */
    
    while (blkCnt > 0)
    {
        in1 = *pInput++;
        in2 = *pInput++;
        in3 = *pInput++;
        in4 = *pInput++;
        
        sum += in1;
        sum += in2;
        sum += in3;
        sum += in4;
        
        
        blkCnt--;
    }
    
    blkCnt = blocksize %0x4;
    
    while (blkCnt > 0)
    {
        sum += *pInput++;
        
        blkCnt--;
    }
    
    fMean = sum / (double)blocksize;
    
    pInput = pSig_Src_Arr;
    blkCnt = blocksize >>2;
    
    while (blkCnt >0)
    {
        
        fValue = *pInput++ - fMean;
        fSum += fValue * fValue;
        
        fValue = *pInput++ - fMean;
        fSum += fValue * fValue;
        
        fValue = *pInput++ - fMean;
        fSum += fValue * fValue;
        
        fValue = *pInput++ - fMean;
        fSum += fValue * fValue;
        
        blkCnt--;
    }
    
    /* Handle the remaining samples if the signal size is not a multiple of 4 */
    
    blkCnt = blocksize % 0x4;
    while (blkCnt>0)
    {
        fValue = *pInput++ - fMean;
        fSum += fValue * fValue;
        
        blkCnt--;
    }
    
    *pResult = fSum/(double)(blocksize - 1.0);
    
    
}

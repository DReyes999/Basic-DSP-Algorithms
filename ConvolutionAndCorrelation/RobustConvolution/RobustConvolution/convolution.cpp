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
            blkCnt,
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
    
    /*---------------------------*/
    /* Initialization of stage 1 */
    /*---------------------------*/
    
    /*
     In this stage the Multiply and Accumulate operations are
     increased by 1 for every iteration. The count variable holds the number of
     MAC operations performed
     */
    
    count = 1;
    px = pIn1;
    py = pIn2;
    
    while (blocksize1 > 0)
    {
        sum = 0.0;
        
        
        k = count >>2;
        
        // loop unrolling
        while (k > 0)
        {
            /* x[0] * y[srcBLen - 1] */
            sum += *px++ * *py--;
            
            /* x[1] * y[srcBLen - 2] */
            sum += *px++ * *py--;
            
            /* x[2] * y[srcBLen - 3] */
            sum += *px++ * *py--;
            
            /* x[3] * y[srcBLen - 4] */
            sum += *px++ * *py--;
            
            /* decrement the loop counter */
            k--;
        }
        
        // check if count is a multiple of 4
        k = count % 0x4;
        
        // Compute the remainder
        
        while (k > 0)
        {
            // Perform the multiply accumulate once more on the remainder
            sum += *px++ * *py--;
            k--;
        }
        
        // Store the accumulator in the output buffer
        *pOut++ = sum;
        
        // Update input A and input B pointers for the next multiply accumulate calculation
        py = pIn2;
        px = pIn1;
        count++;
        blocksize1--;
    }
    
    /*---------------------------*/
    /* Initialization of stage 2 */
    /*---------------------------*/
    
    px = pIn1;
    pSrcB = pIn2 + (srcBLen -1);
    py = pSrc2;
    
    count = 0;
    
    if (srcBLen >= 4)
    {
        blkCnt = blocksize2>>2;
    }
    
    while (blkCnt > 0)
    {
        acc0 = 0.0;
        acc1 = 0.0;
        acc2 = 0.0;
        acc3 = 0.0;
        
        x0 = *(px++);
        x1 = *(px++);
        x2 = *(px++);
        
        k = srcBLen >>2;
        do {
            /* Read y[srcBLen - 1] sample */
            c0 = *(py--);
            /* Perform the multiply accumulate */
            /* acc0 += x[0] * y[srcBLen-1] */
            acc0 += x0 * c0;
            /* acc1 += x[1] * y[srcBLen-1] */
            acc1 += x1 * c0;
            /* acc2 += x[2] * y[srcBLen-1] */
            acc2 += x2 * c0;
            /* acc2 += x[2] * y[srcBLen-1] */
            acc3 += x3 * c0;
            
            /* Read y[srcBLen - 2] sample */
            c0 = *(py--);
            /* Read x[4] sample */
            x0 = *(px + 1);
            
            /* Perform the multiply accumulate */
            /* acc0 += x[1] * y[srcBLen-2] */
            acc0 += x1 * c0;
            /* acc1 += x[2] * y[srcBLen-2] */
            acc1 += x2 * c0;
            /* acc2 += x[3] * y[srcBLen-2] */
            acc2 += x3 * c0;
            /* acc2 += x[4] * y[srcBLen-2] */
            acc3 += x0 * c0;
            
            /* Read y[srcBLen - 3] sample */
            c0 = *(py--);
            /* Read x[5] sample */
            x1 = *(px + 2);
            
            /* Perform the multiply accumulate */
            /* acc0 += x[2] * y[srcBLen-3] */
            acc0 += x2 * c0;
            /* acc1 += x[3] * y[srcBLen-3] */
            acc1 += x3 * c0;
            /* acc2 += x[4] * y[srcBLen-3] */
            acc2 += x0 * c0;
            /* acc2 += x[5] * y[srcBLen-3] */
            acc3 += x1 * c0;
            
            /* Read y[srcBLen - 4] sample */
            c0 = *(py--);
            /* Read x[6] sample */
            x2 = *(px + 3);
            px += 4;
            
            /* Perform the multiply accumulate */
            /* acc0 += x[3] * y[srcBLen-4] */
            acc0 += x3 * c0;
            /* acc1 += x[4] * y[srcBLen-4] */
            acc1 += x0 * c0;
            /* acc2 += x[5] * y[srcBLen-4] */
            acc2 += x1 * c0;
            /* acc2 += x[6] * y[srcBLen-4] */
            acc3 += x2 * c0;
            
        } while (--k);
        
        // TODO: Address situation where 2nd signal's length is not a multiple of 4
            
    }
  
}

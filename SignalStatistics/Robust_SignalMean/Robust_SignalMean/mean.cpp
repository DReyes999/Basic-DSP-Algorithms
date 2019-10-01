//
//  mean.cpp
//  Robust_SignalMean
//
//  Created by Derrick Reyes on 7/21/19.
//  Copyright © 2019 Derrick Reyes. All rights reserved.
//

/*
 Pointers:
 
 Required for reading and manipulating memory constantly. Pointers are the only way we can see and understand data that is greater than a few bytes in size.
 
 Pointers make it possible to read and manipulate data in memory that is larger and more complex than a simple data type.
 
 A pointer is like the needle on a record player.
 
 */

#include "mean.hpp"

void Sig_Mean(double *sig_src_arr, u_int32_t blocksize, double * result)
{
    double sum = 0.0;
    u_int32_t blkCnt; // loop counter
    
    /* We are using the concept of loop unrolling.Loop unrolling, also known as loop unwinding, is a loop transformation technique that attempts to optimize a program's execution speed at the expense of its binary size, which is an approach known as space–time tradeoff.
     
        We can do the calculations faster at a cost of using more memory.
     */
    
    // In loop unrolling we compute 4 inputs at a time
    double in1, in2, in3, in4;
    
    /* Initialize blkCnt
     blocksize is same as signal length. We are dividing it by 4.
     blkCnt is our loopcounter.
     
     '>' means right shift means divide the number on the left
     by 2 raised to the power of the number on the right of the shift
     the 'U' suffix simply declares it as an unsigned Int
     */
    
    blkCnt = blocksize >>2U; // blkCnt = blocksize / 2^2 = blocksize /4
    
    while (blkCnt > 0)
    {
        in1 = *sig_src_arr++;
        in2 = *sig_src_arr++;
        in3 = *sig_src_arr++;
        in4 = *sig_src_arr++;
        
        sum += in1;
        sum += in2;
        sum += in3;
        sum += in4;
        
        blkCnt--;
    }
    
    /* If our blocksize (signal length) is not a multiple of 4, we will have
     some samples leftover. We add the following operation to add the remaining samples to our sum
     */
    
    blkCnt = blocksize % 0x4;
    
    while (blkCnt > 0)
    {
        sum += *sig_src_arr++;
        blkCnt--;
    }
    
    *result = sum/(double)blocksize;
}

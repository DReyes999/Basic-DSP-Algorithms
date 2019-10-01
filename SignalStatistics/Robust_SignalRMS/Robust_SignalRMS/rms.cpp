//
//  rms.cpp
//  Robust_SignalRMS
//
//  Created by Derrick Reyes on 8/27/19.
//  Copyright © 2019 Derrick Reyes. All rights reserved.
//

#include "rms.hpp"
#include <cmath>

void Sig_Rms(double * pSig_src_arr, u_int32_t blocksize, double * pResult)
{
    double sum = 0.0;
    u_int32_t blkCnt;
    double in;
    
    /* loop unrolling */
    
    blkCnt = blocksize >>2; /* blkCnt = blocksize / 4*/
    
    while (blkCnt > 0)
    {
        in = *pSig_src_arr++;
        sum += in*in;
        
        in = *pSig_src_arr++;
        sum += in*in;
        
        in = *pSig_src_arr++;
        sum += in*in;
        
        in = *pSig_src_arr++;
        sum += in*in;
        
        blkCnt--;
    }
    
    /* handle leftover samples if signal is not a multiple of 4 */
    
    blkCnt = blocksize % 0x4;
    
    while (blkCnt > 0)
    {
        in = *pSig_src_arr++;
        sum += in*in;
        
        blkCnt--;
    }
    
    *pResult = sqrt(sum / (double)blocksize);
}

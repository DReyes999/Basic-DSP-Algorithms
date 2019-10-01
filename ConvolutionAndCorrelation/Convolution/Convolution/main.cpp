//
//  main.cpp
//  Convolution
//
//  Created by Derrick Reyes on 8/31/19.
//  Copyright © 2019 Derrick Reyes. All rights reserved.
//

#include <iostream>
#include <fstream>
#define SIG_LENGTH 320
#define IMP_RSP_LENGTH 29
using namespace std;

extern double InputSignal_f32_1kHz_15kHz[SIG_LENGTH];
extern double  Impulse_response[IMP_RSP_LENGTH];
double OutPutSignal[SIG_LENGTH+IMP_RSP_LENGTH];

void Convolution (
                  double *sig_src_arr,
                  double *sig_dest_arr,
                  double *imp_response_arr,
                  int sig_src_length,
                  int imp_response_length
                  );


int main()
{
    // Create two files to write to
    ofstream file1, file2, file3;
    
    // Perform the convolution
    Convolution (
                      (double *)&InputSignal_f32_1kHz_15kHz[0],
                      (double *)&OutPutSignal[0],
                      (double *)&Impulse_response[0],
                      (int) SIG_LENGTH,
                      (int) IMP_RSP_LENGTH
                      );
    
    // Open the files
    file1.open("outputsignal.dat");
    file2.open("Input_signal.dat");
    file3.open("Impulse_Response.dat");
    
    // Write the output and iput signals to the created files so we can compare
    for (int i = 0; i < (SIG_LENGTH + IMP_RSP_LENGTH); i++)
    {
        file1 << OutPutSignal[i] << endl;
        
        if (i < IMP_RSP_LENGTH) {
            file3 << Impulse_response[i] << endl;
        }
        
        if (i < SIG_LENGTH)
        {
            file2 << InputSignal_f32_1kHz_15kHz[i] << endl;
        }
        
        
    }
    
    // close files
    file1.close();
    file2.close();
    file3.close();
}

/* Developing the algorithm for convolution */

/*
 1. pointer to the input array
 2. pointer to the output array
 3. pointer to impulse response array
 4. signal length
 5. length of impulse response.
 */



void Convolution (
                  double *sig_src_arr,
                  double *sig_dest_arr,
                  double *imp_response_arr,
                  int sig_src_length,
                  int imp_response_length
                  )
{
    /*
     The length of our signal destination array will be the length of our signal source array
     + the length of our impulse response. So the first thing we have to do is initialize
     all members of our output array to 0 using a for loop.
     */
    
    int i,j;
    
    for (i = 0; i < (sig_src_length + imp_response_length); i++)
    {
        sig_dest_arr[i] = 0;
    }
    
    /* Now we use a nested for loop to convolve the signals and set the values
     of our output signal*/
    
    for (i = 0; i < sig_src_length; i++)
    {
        for (j = 0; j < imp_response_length; j++)
        {
            // Actual convolution algorithm
            sig_dest_arr[i+j] = sig_dest_arr[i+j] + sig_src_arr[i]*imp_response_arr[j];
        }
    }
    
}

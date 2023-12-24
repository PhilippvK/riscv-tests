// See LICENSE for license details.

//**************************************************************************
// Vector-vector add benchmark
//--------------------------------------------------------------------------
// Author  : Andrew Waterman
// TA      : Christopher Celio
// Student :
//
// This benchmark adds two vectors and writes the results to a
// third vector. The input data (and reference data) should be
// generated using the vvadd_gendata.pl perl script and dumped
// to a file named dataset.h

//--------------------------------------------------------------------------
// Includes

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


//--------------------------------------------------------------------------
// Input/Reference Data

#include "dataset.h"


//--------------------------------------------------------------------------
// Basic Utilities and Multi-thread Support

#include "util.h"


//--------------------------------------------------------------------------
// vvadd function

extern void __attribute__((noinline)) vvadd(int coreid, int ncores, size_t n, const data_t* x, const data_t* y, data_t* z);


//--------------------------------------------------------------------------
// Main
//
// all threads start executing thread_entry(). Use their "coreid" to
// differentiate between threads (each thread is running on a separate core).

void thread_entry(int cid, int nc) {
  // static allocates data in the binary, which is visible to both threads
  static data_t results_data[DATA_SIZE];

  if(cid == 0) {
    int res;
    // First do out-of-place vvadd
    barrier(nc);
    stats(vvadd(cid, nc, DATA_SIZE, input1_data, input2_data, results_data); barrier(nc), DATA_SIZE);
    res = verifyDouble(DATA_SIZE, results_data, verify_data);
    // printf("res=%d\n", res);
    if(res) exit(res);
    // printf("[0] copy\n");
    size_t i;
    for (i = 0; i < DATA_SIZE; i++)
          results_data[i] = input1_data[i];
    barrier(nc);
    // Second do in-place vvadd
    // Copying input
    // printf("[%d] vvadd\n", cid);
    stats(vvadd(cid, nc, DATA_SIZE, results_data, input2_data, results_data); barrier(nc), DATA_SIZE);
    res = verifyDouble(DATA_SIZE, results_data, verify_data);
    // printf("res=%d\n", res);
    if(res) exit(res);
    barrier(nc);
  } else {
    barrier(nc);
    stats(vvadd(cid, nc, DATA_SIZE, input1_data, input2_data, results_data); barrier(nc), DATA_SIZE);
    barrier(nc);
    stats(vvadd(cid, nc, DATA_SIZE, results_data, input2_data, results_data); barrier(nc), DATA_SIZE);
    barrier(nc);
  }


  exit(0);
}

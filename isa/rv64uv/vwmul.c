// Copyright 2021 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// Author: Matheus Cavalcante <matheusd@iis.ee.ethz.ch>
//         Basile Bougenot <bbougenot@student.ethz.ch>

#include "vector_macros.h"

void TEST_CASE1(void) {
  VSET(16, e8, m1);
  VLOAD_8(v2, 0xee, 0xfe, 0xbd, 0xc2, 0x02, 0xa4, 0x34, 0x33, 0x2b, 0x35, 0x16,
          0x9b, 0x3b, 0x5f, 0xfc, 0x8b);
  VLOAD_8(v4, 0xcb, 0x24, 0xe8, 0xb2, 0xeb, 0x24, 0x80, 0x67, 0x43, 0x11, 0x7c,
          0x94, 0x22, 0x71, 0xca, 0x80);
  asm volatile("vwmul.vv v6, v2, v4");
  VSET(16, e16, m1);
  VCMP_I16(1, v6, 0x03ba, 0xffb8, 0x0648, 0x12e4, 0xffd6, 0xf310, 0xe600,
           0x1485, 0x0b41, 0x0385, 0x0aa8, 0x2a9c, 0x07d6, 0x29ef, 0x00d8,
           0x3a80);

  VSET(16, e16, m1);
  VLOAD_16(v2, 0x8aed, 0x2153, 0x5377, 0xc19c, 0x1051, 0x1b75, 0xbafd, 0xb200,
           0xb209, 0xa9a2, 0xbdc4, 0x1653, 0x5965, 0x145e, 0xb626, 0xd79c);
  VLOAD_16(v4, 0x778d, 0xc104, 0x6eac, 0x78e8, 0xacd2, 0x698b, 0xc7d3, 0x1e29,
           0x0a58, 0x58b5, 0x29f9, 0x2fb0, 0x2166, 0x0ac4, 0x44e5, 0xbc40);
  asm volatile("vwmul.vv v6, v2, v4");
  VSET(16, e32, m1);
  VCMP_I32(2, v6, 0xc953af89, 0xf7cd184c, 0x241535f4, 0xe2889560, 0xfab2ce72,
           0x0b51e587, 0x0f24c987, 0xf6cf8200, 0xfcd98d18, 0xe2129f8a,
           0xf523f7a4, 0x04289610, 0x0ba9a33e, 0x00db43f8, 0xec2007fe,
           0x0ab07700);

  // VSET(16, e32, m1);
  // VLOAD_32(v2, 0xbbc467cb, 0xfbb3efda, 0x652f8490, 0x5e7ea848, 0x21fbc400,
  //          0xbb409fde, 0x98413836, 0x14652ba4, 0xc3d3c86f, 0xc84d3ae3,
  //          0x3df53027, 0xbda29a2c, 0xa1d7d949, 0x60a3d06e, 0xa91e405d,
  //          0x7eea498f);
  // VLOAD_32(v4, 0x80407791, 0x3e51b6e0, 0xd0be8bc1, 0x683f33bd, 0xeddda6c8,
  //          0x34e351f2, 0xa6a93ab2, 0xc8893cb8, 0xcb61ddc1, 0x341a4cdc,
  //          0xd377dc52, 0x2f3f3dbf, 0xa97f8c35, 0x38a44020, 0x28e1cc8b,
  //          0x52d0e17a);
  // asm volatile("vwmul.vv v6, v2, v4");
  // VSET(16, e64, m1);
  // VCMP_I64(3, v6, 0x220c9d56193e26fb, 0xfef434f3d9f0dac0, 0xed5267a678ad2090,
  //          0x267ac8a1a8c09528, 0xfd97bcf001c92000, 0xf1cc14c54f865ddc,
  //          0x24347d81c3bb518c, 0xfb94cd6ed9b5cde0, 0x0c5e26a06dc0eeaf,
  //          0xf4a9f71526e7ff14, 0xf538e8d5150bf07e, 0xf3c075503fe182d4,
  //          0x1fd0bbab88bae81d, 0x1561d6be9f0d8dc0, 0xf220183a08740e7f,
  //          0x290e99b3f87dbd26);
};

void TEST_CASE2(void) {
  VSET(16, e8, m1);
  VLOAD_8(v2, 0xee, 0xfe, 0xbd, 0xc2, 0x02, 0xa4, 0x34, 0x33, 0x2b, 0x35, 0x16,
          0x9b, 0x3b, 0x5f, 0xfc, 0x8b);
  VLOAD_8(v4, 0xcb, 0x24, 0xe8, 0xb2, 0xeb, 0x24, 0x80, 0x67, 0x43, 0x11, 0x7c,
          0x94, 0x22, 0x71, 0xca, 0x80);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v6);
  asm volatile("vwmul.vv v6, v2, v4, v0.t");
  VSET(16, e16, m1);
  VCMP_I16(4, v6, 0, 0xffb8, 0, 0x12e4, 0, 0xf310, 0, 0x1485, 0, 0x0385, 0,
           0x2a9c, 0, 0x29ef, 0, 0x3a80);

  VSET(16, e16, m1);
  VLOAD_16(v2, 0x8aed, 0x2153, 0x5377, 0xc19c, 0x1051, 0x1b75, 0xbafd, 0xb200,
           0xb209, 0xa9a2, 0xbdc4, 0x1653, 0x5965, 0x145e, 0xb626, 0xd79c);
  VLOAD_16(v4, 0x778d, 0xc104, 0x6eac, 0x78e8, 0xacd2, 0x698b, 0xc7d3, 0x1e29,
           0x0a58, 0x58b5, 0x29f9, 0x2fb0, 0x2166, 0x0ac4, 0x44e5, 0xbc40);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v6);
  asm volatile("vwmul.vv v6, v2, v4, v0.t");
  VSET(16, e32, m1);
  VCMP_I32(5, v6, 0, 0xf7cd184c, 0, 0xe2889560, 0, 0x0b51e587, 0, 0xf6cf8200, 0,
           0xe2129f8a, 0, 0x04289610, 0, 0x00db43f8, 0, 0x0ab07700);

  // VSET(16, e32, m1);
  // VLOAD_32(v2, 0xbbc467cb, 0xfbb3efda, 0x652f8490, 0x5e7ea848, 0x21fbc400,
  //          0xbb409fde, 0x98413836, 0x14652ba4, 0xc3d3c86f, 0xc84d3ae3,
  //          0x3df53027, 0xbda29a2c, 0xa1d7d949, 0x60a3d06e, 0xa91e405d,
  //          0x7eea498f);
  // VLOAD_32(v4, 0x80407791, 0x3e51b6e0, 0xd0be8bc1, 0x683f33bd, 0xeddda6c8,
  //          0x34e351f2, 0xa6a93ab2, 0xc8893cb8, 0xcb61ddc1, 0x341a4cdc,
  //          0xd377dc52, 0x2f3f3dbf, 0xa97f8c35, 0x38a44020, 0x28e1cc8b,
  //          0x52d0e17a);
  // VLOAD_8(v0, 0xAA, 0xAA);
  // VCLEAR(v6);
  // asm volatile("vwmul.vv v6, v2, v4, v0.t");
  // VSET(16, e64, m1);
  // VCMP_I64(6, v6, 0, 0xfef434f3d9f0dac0, 0, 0x267ac8a1a8c09528, 0,
  //          0xf1cc14c54f865ddc, 0, 0xfb94cd6ed9b5cde0, 0, 0xf4a9f71526e7ff14, 0,
  //          0xf3c075503fe182d4, 0, 0x1561d6be9f0d8dc0, 0, 0x290e99b3f87dbd26);
};

void TEST_CASE3(void) {
  VSET(16, e8, m1);
  VLOAD_8(v2, 0x86, 0x79, 0xa0, 0x8a, 0x3e, 0xc3, 0x3e, 0x0c, 0x1b, 0xca, 0x80,
          0x41, 0x0e, 0xee, 0x94, 0xdf);
  int64_t scalar = 5;
  asm volatile("vwmul.vx v6, v2, %[A]" ::[A] "r"(scalar));
  VSET(16, e16, m1);
  VCMP_I16(7, v6, 0xfd9e, 0x025d, 0xfe20, 0xfdb2, 0x0136, 0xfecf, 0x0136,
           0x003c, 0x0087, 0xfef2, 0xfd80, 0x0145, 0x0046, 0xffa6, 0xfde4,
           0xff5b);

  VSET(16, e16, m1);
  VLOAD_16(v2, 0xb0ab, 0xcccb, 0x5fad, 0x9e24, 0x1496, 0xd4a0, 0x2552, 0xcef6,
           0x34b8, 0xef22, 0x69c3, 0xbb05, 0xbe72, 0x315b, 0x3f03, 0xf58b);
  scalar = -5383;
  asm volatile("vwmul.vx v6, v2, %[A]" ::[A] "r"(scalar));
  VSET(16, e32, m1);
  VCMP_I32(8, v6, 0x06842453, 0x0434bf73, 0xf8243145, 0x0809b904, 0xfe4f21e6,
           0x03900fa0, 0xfcef40c2, 0x04072946, 0xfbab76f8, 0x0162ac12,
           0xf7501cab, 0x05aa79dd, 0x056270e2, 0xfbf22f83, 0xfad307eb,
           0x00dbe233);

  // VSET(16, e32, m1);
  // VLOAD_32(v2, 0x71c6753d, 0x66646cc2, 0x23065c23, 0xde594cad, 0xa2f87c53,
  //          0xaebb2bcb, 0xc53688b8, 0xf0c161dd, 0x2d856780, 0xa520cce5,
  //          0x677c5e13, 0x83d288f4, 0x78b6acdc, 0x5b635dd1, 0x97dc75c8,
  //          0x1a1aa6d4);
  // scalar = 6474219;
  // asm volatile("vwmul.vx v6, v2, %[A]" ::[A] "r"(scalar));
  // VSET(16, e64, m1);
  // VCMP_I64(9, v6, 0x002be7b6249483ff, 0x0027833479d82816, 0x000d840f6a940f21,
  //          0xfff303a4936737cf, 0xffdc19bf4b7d4b31, 0xffe0a38d1ee99659,
  //          0xffe9508230d7f8e8, 0xfffa1e014df55adf, 0x001190f926b98280,
  //          0xffdceee1c5a5e337, 0x0027ef3ba84d4671, 0xffd014a6bd334bfc,
  //          0x002e952469a169f4, 0x0023441ed2e237db, 0xffd7d041966a2698,
  //          0x000a12cac09b989c);
};

void TEST_CASE4(void) {
  VSET(16, e8, m1);
  VLOAD_8(v2, 0x86, 0x79, 0xa0, 0x8a, 0x3e, 0xc3, 0x3e, 0x0c, 0x1b, 0xca, 0x80,
          0x41, 0x0e, 0xee, 0x94, 0xdf);
  int64_t scalar = 5;
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v6);
  asm volatile("vwmul.vx v6, v2, %[A], v0.t" ::[A] "r"(scalar));
  VSET(16, e16, m1);
  VCMP_I16(10, v6, 0, 0x025d, 0, 0xfdb2, 0, 0xfecf, 0, 0x003c, 0, 0xfef2, 0,
           0x0145, 0, 0xffa6, 0, 0xff5b);

  VSET(16, e16, m1);
  VLOAD_16(v2, 0xb0ab, 0xcccb, 0x5fad, 0x9e24, 0x1496, 0xd4a0, 0x2552, 0xcef6,
           0x34b8, 0xef22, 0x69c3, 0xbb05, 0xbe72, 0x315b, 0x3f03, 0xf58b);
  scalar = -5383;
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v6);
  asm volatile("vwmul.vx v6, v2, %[A], v0.t" ::[A] "r"(scalar));
  VSET(16, e32, m1);
  VCMP_I32(11, v6, 0, 0x0434bf73, 0, 0x0809b904, 0, 0x03900fa0, 0, 0x04072946,
           0, 0x0162ac12, 0, 0x05aa79dd, 0, 0xfbf22f83, 0, 0x00dbe233);

  // VSET(16, e32, m1);
  // VLOAD_32(v2, 0x71c6753d, 0x66646cc2, 0x23065c23, 0xde594cad, 0xa2f87c53,
  //          0xaebb2bcb, 0xc53688b8, 0xf0c161dd, 0x2d856780, 0xa520cce5,
  //          0x677c5e13, 0x83d288f4, 0x78b6acdc, 0x5b635dd1, 0x97dc75c8,
  //          0x1a1aa6d4);
  // scalar = 6474219;
  // VLOAD_8(v0, 0xAA, 0xAA);
  // VCLEAR(v6);
  // asm volatile("vwmul.vx v6, v2, %[A], v0.t" ::[A] "r"(scalar));
  // VSET(16, e64, m1);
  // VCMP_I64(12, v6, 0, 0x0027833479d82816, 0, 0xfff303a4936737cf, 0,
  //          0xffe0a38d1ee99659, 0, 0xfffa1e014df55adf, 0, 0xffdceee1c5a5e337, 0,
  //          0xffd014a6bd334bfc, 0, 0x0023441ed2e237db, 0, 0x000a12cac09b989c);
};

int main(void) {
  INIT_CHECK();
  enable_vec();

  TEST_CASE1();
  TEST_CASE2();
  TEST_CASE3();
  TEST_CASE4();

  EXIT_CHECK();
}

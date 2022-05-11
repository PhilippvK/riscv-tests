// Copyright 2021 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// Author: Matheus Cavalcante <matheusd@iis.ee.ethz.ch>
//         Basile Bougenot <bbougenot@student.ethz.ch>

#include "vector_macros.h"

void TEST_CASE1(void) {
  VSET(16, e8, m1);
  VLOAD_8(v2, 0xff, 0x00, 0xf0, 0x0f, 0xff, 0x00, 0xf0, 0x0f, 0xff, 0x00, 0xf0,
          0x0f, 0xff, 0x00, 0xf0, 0x0f);
  VLOAD_8(v3, 0xf2, 0x01, 0xf0, 0x0f, 0xf2, 0x01, 0xf0, 0x0f, 0xf2, 0x01, 0xf0,
          0x0f, 0xf2, 0x01, 0xf0, 0x0f);
  VCLEAR(v1);
  asm volatile("vmsne.vv v1, v2, v3");
  VSET(2, e8, m1);
  VCMP_U8(1, v1, 0x33, 0x33);

  VSET(16, e16, m1);
  VLOAD_16(v2, 0xffff, 0x0000, 0xf0f0, 0x0f0f, 0xffff, 0x0000, 0xf0f0, 0x0f0f,
           0xffff, 0x0000, 0xf0f0, 0x0f0f, 0xffff, 0x0000, 0xf0f0, 0x0f0f);
  VLOAD_16(v3, 0xf2ff, 0x0100, 0xf0f0, 0x0f0f, 0xf2ff, 0x0100, 0xf0f0, 0x0f0f,
           0xf2ff, 0x0100, 0xf0f0, 0x0f0f, 0xf2ff, 0x0100, 0xf0f0, 0x0f0f);
  VCLEAR(v1);
  asm volatile("vmsne.vv v1, v2, v3");
  VSET(2, e8, m1);
  VCMP_U8(2, v1, 0x33, 0x33);

  VSET(16, e32, m1);
  VLOAD_32(v2, 0xffffffff, 0x00000000, 0xf0f0f0f0, 0x0f0f0f0f, 0xffffffff,
           0x00000000, 0xf0f0f0f0, 0x0f0f0f0f, 0xffffffff, 0x00000000,
           0xf0f0f0f0, 0x0f0f0f0f, 0xffffffff, 0x00000000, 0xf0f0f0f0,
           0x0f0f0f0f);
  VLOAD_32(v3, 0xfff2ffff, 0x01000000, 0xf0f0f0f0, 0x0f0f0f0f, 0xfff2ffff,
           0x01000000, 0xf0f0f0f0, 0x0f0f0f0f, 0xfff2ffff, 0x01000000,
           0xf0f0f0f0, 0x0f0f0f0f, 0xfff2ffff, 0x01000000, 0xf0f0f0f0,
           0x0f0f0f0f);
  VCLEAR(v1);
  asm volatile("vmsne.vv v1, v2, v3");
  VSET(2, e8, m1);
  VCMP_U8(3, v1, 0x33, 0x33);

  // VSET(16, e64, m1);
  // VLOAD_64(v2, 0xffffffffffffffff, 0x0000000000000000, 0xf0f0f0f0f0f0f0f0,
  //          0x0f0f0f0f0f0f0f0f, 0xffffffffffffffff, 0x0000000000000000,
  //          0xf0f0f0f0f0f0f0f0, 0x0f0f0f0f0f0f0f0f, 0xffffffffffffffff,
  //          0x0000000000000000, 0xf0f0f0f0f0f0f0f0, 0x0f0f0f0f0f0f0f0f,
  //          0xffffffffffffffff, 0x0000000000000000, 0xf0f0f0f0f0f0f0f0,
  //          0x0f0f0f0f0f0f0f0f);
  // VLOAD_64(v3, 0xfff2ffffffffffff, 0x0100000000000000, 0xf0f0f0f0f0f0f0f0,
  //          0x0f0f0f0f0f0f0f0f, 0xfff2ffffffffffff, 0x0100000000000000,
  //          0xf0f0f0f0f0f0f0f0, 0x0f0f0f0f0f0f0f0f, 0xfff2ffffffffffff,
  //          0x0100000000000000, 0xf0f0f0f0f0f0f0f0, 0x0f0f0f0f0f0f0f0f,
  //          0xfff2ffffffffffff, 0x0100000000000000, 0xf0f0f0f0f0f0f0f0,
  //          0x0f0f0f0f0f0f0f0f);
  // VCLEAR(v1);
  // asm volatile("vmsne.vv v1, v2, v3");
  // VSET(2, e8, m1);
  // VCMP_U8(4, v1, 0x33, 0x33);
};

void TEST_CASE2(void) {
  VSET(16, e8, m1);
  VLOAD_8(v2, 0xff, 0x00, 0xf0, 0x0f, 0xff, 0x00, 0xf0, 0x0f, 0xff, 0x00, 0xf0,
          0x0f, 0xff, 0x00, 0xf0, 0x0f);
  VLOAD_8(v3, 0xf2, 0x01, 0xf0, 0x0f, 0xf2, 0x01, 0xf0, 0x0f, 0xf2, 0x01, 0xf0,
          0x0f, 0xf2, 0x01, 0xf0, 0x0f);
  VLOAD_8(v0, 0xaa, 0xaa);
  VCLEAR(v1);
  asm volatile("vmsne.vv v1, v2, v3, v0.t");
  VSET(2, e8, m1);
  VCMP_U8(5, v1, 0x22, 0x22);

  VSET(16, e16, m1);
  VLOAD_16(v2, 0xffff, 0x0000, 0xf0f0, 0x0f0f, 0xffff, 0x0000, 0xf0f0, 0x0f0f,
           0xffff, 0x0000, 0xf0f0, 0x0f0f, 0xffff, 0x0000, 0xf0f0, 0x0f0f);
  VLOAD_16(v3, 0xf2ff, 0x0100, 0xf0f0, 0x0f0f, 0xf2ff, 0x0100, 0xf0f0, 0x0f0f,
           0xf2ff, 0x0100, 0xf0f0, 0x0f0f, 0xf2ff, 0x0100, 0xf0f0, 0x0f0f);
  VLOAD_8(v0, 0xaa, 0xaa);
  VCLEAR(v1);
  asm volatile("vmsne.vv v1, v2, v3, v0.t");
  VSET(2, e8, m1);
  VCMP_U8(6, v1, 0x22, 0x22);

  VSET(16, e32, m1);
  VLOAD_32(v2, 0xffffffff, 0x00000000, 0xf0f0f0f0, 0x0f0f0f0f, 0xffffffff,
           0x00000000, 0xf0f0f0f0, 0x0f0f0f0f, 0xffffffff, 0x00000000,
           0xf0f0f0f0, 0x0f0f0f0f, 0xffffffff, 0x00000000, 0xf0f0f0f0,
           0x0f0f0f0f);
  VLOAD_32(v3, 0xfff2ffff, 0x01000000, 0xf0f0f0f0, 0x0f0f0f0f, 0xfff2ffff,
           0x01000000, 0xf0f0f0f0, 0x0f0f0f0f, 0xfff2ffff, 0x01000000,
           0xf0f0f0f0, 0x0f0f0f0f, 0xfff2ffff, 0x01000000, 0xf0f0f0f0,
           0x0f0f0f0f);
  VLOAD_8(v0, 0xaa, 0xaa);
  VCLEAR(v1);
  asm volatile("vmsne.vv v1, v2, v3, v0.t");
  VSET(2, e8, m1);
  VCMP_U8(7, v1, 0x22, 0x22);

  // VSET(16, e64, m1);
  // VLOAD_64(v2, 0xffffffffffffffff, 0x0000000000000000, 0xf0f0f0f0f0f0f0f0,
  //          0x0f0f0f0f0f0f0f0f, 0xffffffffffffffff, 0x0000000000000000,
  //          0xf0f0f0f0f0f0f0f0, 0x0f0f0f0f0f0f0f0f, 0xffffffffffffffff,
  //          0x0000000000000000, 0xf0f0f0f0f0f0f0f0, 0x0f0f0f0f0f0f0f0f,
  //          0xffffffffffffffff, 0x0000000000000000, 0xf0f0f0f0f0f0f0f0,
  //          0x0f0f0f0f0f0f0f0f);
  // VLOAD_64(v3, 0xfff2ffffffffffff, 0x0100000000000000, 0xf0f0f0f0f0f0f0f0,
  //          0x0f0f0f0f0f0f0f0f, 0xfff2ffffffffffff, 0x0100000000000000,
  //          0xf0f0f0f0f0f0f0f0, 0x0f0f0f0f0f0f0f0f, 0xfff2ffffffffffff,
  //          0x0100000000000000, 0xf0f0f0f0f0f0f0f0, 0x0f0f0f0f0f0f0f0f,
  //          0xfff2ffffffffffff, 0x0100000000000000, 0xf0f0f0f0f0f0f0f0,
  //          0x0f0f0f0f0f0f0f0f);
  // VLOAD_8(v0, 0xaa, 0xaa);
  // VCLEAR(v1);
  // asm volatile("vmsne.vv v1, v2, v3, v0.t");
  // VSET(2, e8, m1);
  // VCMP_U8(8, v1, 0x22, 0x22);
};

void TEST_CASE3(void) {
  const uint64_t scalar = 0x00000000ffffffff;

  VSET(16, e8, m1);
  VLOAD_8(v2, 0xff, 0x00, 0xf0, 0x0f, 0xff, 0x00, 0xf0, 0x0f, 0xff, 0x00, 0xf0,
          0x0f, 0xff, 0x00, 0xf0, 0x0f);
  VCLEAR(v1);
  asm volatile("vmsne.vx v1, v2, %[A]" ::[A] "r"(scalar));
  VSET(2, e8, m1);
  VCMP_U8(9, v1, 0xee, 0xee);

  VSET(16, e16, m1);
  VLOAD_16(v2, 0xffff, 0x0000, 0xf0f0, 0x0f0f, 0xffff, 0x0000, 0xf0f0, 0x0f0f,
           0xffff, 0x0000, 0xf0f0, 0x0f0f, 0xffff, 0x0000, 0xf0f0, 0x0f0f);
  VCLEAR(v1);
  asm volatile("vmsne.vx v1, v2, %[A]" ::[A] "r"(scalar));
  VSET(2, e8, m1);
  VCMP_U8(10, v1, 0xee, 0xee);

  VSET(16, e32, m1);
  VLOAD_32(v2, 0xffffffff, 0x00000000, 0xf0f0f0f0, 0x0f0f0f0f, 0xffffffff,
           0x00000000, 0xf0f0f0f0, 0x0f0f0f0f, 0xffffffff, 0x00000000,
           0xf0f0f0f0, 0x0f0f0f0f, 0xffffffff, 0x00000000, 0xf0f0f0f0,
           0x0f0f0f0f);
  VCLEAR(v1);
  asm volatile("vmsne.vx v1, v2, %[A]" ::[A] "r"(scalar));
  VSET(2, e8, m1);
  VCMP_U8(11, v1, 0xee, 0xee);

  // VSET(16, e64, m1);
  // VLOAD_64(v2, 0xffffffffffffffff, 0x0000000000000000, 0xf0f0f0f0f0f0f0f0,
  //          0x0f0f0f0f0f0f0f0f, 0xffffffffffffffff, 0x0000000000000000,
  //          0xf0f0f0f0f0f0f0f0, 0x0f0f0f0f0f0f0f0f, 0xffffffffffffffff,
  //          0x0000000000000000, 0xf0f0f0f0f0f0f0f0, 0x0f0f0f0f0f0f0f0f,
  //          0xffffffffffffffff, 0x0000000000000000, 0xf0f0f0f0f0f0f0f0,
  //          0x0f0f0f0f0f0f0f0f);
  // VCLEAR(v1);
  // asm volatile("vmsne.vx v1, v2, %[A]" ::[A] "r"(scalar));
  // VSET(2, e8, m1);
  // VCMP_U8(12, v1, 0xff, 0xff);
};

void TEST_CASE4(void) {
  const uint64_t scalar = 0x00000000ffffffff;

  VSET(16, e8, m1);
  VLOAD_8(v2, 0xff, 0x00, 0xf0, 0x0f, 0xff, 0x00, 0xf0, 0x0f, 0xff, 0x00, 0xf0,
          0x0f, 0xff, 0x00, 0xf0, 0x0f);
  VLOAD_8(v0, 0x10, 0x10);
  VCLEAR(v1);
  asm volatile("vmsne.vx v1, v2, %[A], v0.t" ::[A] "r"(scalar));
  VSET(2, e8, m1);
  VCMP_U8(13, v1, 0x00, 0x00);

  VSET(16, e16, m1);
  VLOAD_16(v2, 0xffff, 0x0000, 0xf0f0, 0x0f0f, 0xffff, 0x0000, 0xf0f0, 0x0f0f,
           0xffff, 0x0000, 0xf0f0, 0x0f0f, 0xffff, 0x0000, 0xf0f0, 0x0f0f);
  VLOAD_8(v0, 0x10, 0x10);
  VCLEAR(v1);
  asm volatile("vmsne.vx v1, v2, %[A], v0.t" ::[A] "r"(scalar));
  VSET(2, e8, m1);
  VCMP_U8(14, v1, 0x00, 0x00);

  VSET(16, e32, m1);
  VLOAD_32(v2, 0xffffffff, 0x00000000, 0xf0f0f0f0, 0x0f0f0f0f, 0xffffffff,
           0x00000000, 0xf0f0f0f0, 0x0f0f0f0f, 0xffffffff, 0x00000000,
           0xf0f0f0f0, 0x0f0f0f0f, 0xffffffff, 0x00000000, 0xf0f0f0f0,
           0x0f0f0f0f);
  VLOAD_8(v0, 0x10, 0x10);
  VCLEAR(v1);
  asm volatile("vmsne.vx v1, v2, %[A], v0.t" ::[A] "r"(scalar));
  VSET(2, e8, m1);
  VCMP_U8(15, v1, 0x00, 0x00);

  // VSET(16, e64, m1);
  // VLOAD_64(v2, 0xffffffffffffffff, 0x0000000000000000, 0xf0f0f0f0f0f0f0f0,
  //          0x0f0f0f0f0f0f0f0f, 0xffffffffffffffff, 0x0000000000000000,
  //          0xf0f0f0f0f0f0f0f0, 0x0f0f0f0f0f0f0f0f, 0xffffffffffffffff,
  //          0x0000000000000000, 0xf0f0f0f0f0f0f0f0, 0x0f0f0f0f0f0f0f0f,
  //          0xffffffffffffffff, 0x0000000000000000, 0xf0f0f0f0f0f0f0f0,
  //          0x0f0f0f0f0f0f0f0f);
  // VLOAD_8(v0, 0x10, 0x10);
  // VCLEAR(v1);
  // asm volatile("vmsne.vx v1, v2, %[A], v0.t" ::[A] "r"(scalar));
  // VSET(2, e8, m1);
  // VCMP_U8(16, v1, 0x10, 0x10);
};

void TEST_CASE5(void) {
  VSET(16, e8, m1);
  VLOAD_8(v2, 0x0f, 0x00, 0xf0, 0x0f, 0x0f, 0x00, 0xf0, 0x0f, 0x0f, 0x00, 0xf0,
          0x0f, 0x0f, 0x00, 0xf0, 0x0f);
  VCLEAR(v1);
  asm volatile("vmsne.vi v1, v2, 15");
  VSET(2, e8, m1);
  VCMP_U8(17, v1, 0x66, 0x66);

  VSET(16, e16, m1);
  VLOAD_16(v2, 0x000f, 0x0000, 0xf0f0, 0x0f0f, 0x000f, 0x0000, 0xf0f0, 0x0f0f,
           0x000f, 0x0000, 0xf0f0, 0x0f0f, 0x000f, 0x0000, 0xf0f0, 0x0f0f);
  VCLEAR(v1);
  asm volatile("vmsne.vi v1, v2, 15");
  VSET(2, e8, m1);
  VCMP_U8(18, v1, 0xee, 0xee);

  VSET(16, e32, m1);
  VLOAD_32(v2, 0x0000000f, 0x00000000, 0xf0f0f0f0, 0x0f0f0f0f, 0x0000000f,
           0x00000000, 0xf0f0f0f0, 0x0f0f0f0f, 0x0000000f, 0x00000000,
           0xf0f0f0f0, 0x0f0f0f0f, 0x0000000f, 0x00000000, 0xf0f0f0f0,
           0x0f0f0f0f);
  VCLEAR(v1);
  asm volatile("vmsne.vi v1, v2, 15");
  VSET(2, e8, m1);
  VCMP_U8(19, v1, 0xee, 0xee);

  // VSET(16, e64, m1);
  // VLOAD_64(v2, 0x000000000000000f, 0x0000000000000000, 0xf0f0f0f0f0f0f0f0,
  //          0x0f0f0f0f0f0f0f0f, 0x000000000000000f, 0x0000000000000000,
  //          0xf0f0f0f0f0f0f0f0, 0x0f0f0f0f0f0f0f0f, 0x000000000000000f,
  //          0x0000000000000000, 0xf0f0f0f0f0f0f0f0, 0x0f0f0f0f0f0f0f0f,
  //          0x000000000000000f, 0x0000000000000000, 0xf0f0f0f0f0f0f0f0,
  //          0x0f0f0f0f0f0f0f0f);
  // VCLEAR(v1);
  // asm volatile("vmsne.vi v1, v2, 15");
  // VSET(2, e8, m1);
  // VCMP_U8(20, v1, 0xee, 0xee);
};

void TEST_CASE6(void) {
  VSET(16, e8, m1);
  VLOAD_8(v2, 0x0f, 0x00, 0xf0, 0x0f, 0x0f, 0x00, 0xf0, 0x0f, 0x0f, 0x00, 0xf0,
          0x0f, 0x0f, 0x00, 0xf0, 0x0f);
  VLOAD_8(v0, 0x10, 0x10);
  VCLEAR(v1);
  asm volatile("vmsne.vi v1, v2, 15, v0.t");
  VSET(2, e8, m1);
  VCMP_U8(21, v1, 0x00, 0x00);

  VSET(16, e16, m1);
  VLOAD_16(v2, 0x000f, 0x0000, 0xf0f0, 0x0f0f, 0x000f, 0x0000, 0xf0f0, 0x0f0f,
           0x000f, 0x0000, 0xf0f0, 0x0f0f, 0x000f, 0x0000, 0xf0f0, 0x0f0f);
  VLOAD_8(v0, 0x10, 0x10);
  VCLEAR(v1);
  asm volatile("vmsne.vi v1, v2, 15, v0.t");
  VSET(2, e8, m1);
  VCMP_U8(22, v1, 0x00, 0x00);

  VSET(16, e32, m1);
  VLOAD_32(v2, 0x0000000f, 0x00000000, 0xf0f0f0f0, 0x0f0f0f0f, 0x0000000f,
           0x00000000, 0xf0f0f0f0, 0x0f0f0f0f, 0x0000000f, 0x00000000,
           0xf0f0f0f0, 0x0f0f0f0f, 0x0000000f, 0x00000000, 0xf0f0f0f0,
           0x0f0f0f0f);
  VLOAD_8(v0, 0x10, 0x10);
  VCLEAR(v1);
  asm volatile("vmsne.vi v1, v2, 15, v0.t");
  VSET(2, e8, m1);
  VCMP_U8(23, v1, 0x00, 0x00);

  // VSET(16, e64, m1);
  // VLOAD_64(v2, 0x000000000000000f, 0x0000000000000000, 0xf0f0f0f0f0f0f0f0,
  //          0x0f0f0f0f0f0f0f0f, 0x000000000000000f, 0x0000000000000000,
  //          0xf0f0f0f0f0f0f0f0, 0x0f0f0f0f0f0f0f0f, 0x000000000000000f,
  //          0x0000000000000000, 0xf0f0f0f0f0f0f0f0, 0x0f0f0f0f0f0f0f0f,
  //          0x000000000000000f, 0x0000000000000000, 0xf0f0f0f0f0f0f0f0,
  //          0x0f0f0f0f0f0f0f0f);
  // VLOAD_8(v0, 0x10, 0x10);
  // VCLEAR(v1);
  // asm volatile("vmsne.vi v1, v2, 15, v0.t");
  // VSET(2, e8, m1);
  // VCMP_U8(24, v1, 0x00, 0x00);
};

int main(void) {
  INIT_CHECK();
  enable_vec();

  TEST_CASE1();
  TEST_CASE2();
  TEST_CASE3();
  TEST_CASE4();
  TEST_CASE5();
  TEST_CASE6();

  EXIT_CHECK();
}

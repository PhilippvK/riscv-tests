// Copyright 2021 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// Author: Matheus Cavalcante <matheusd@iis.ee.ethz.ch>
//         Basile Bougenot <bbougenot@student.ethz.ch>

#include "vector_macros.h"

void TEST_CASE1(void) {
  VSET(16, e8, m1);
  VLOAD_8(v2, 0x74, 0xfb, 0xf4, 0xe9, 0xe5, 0x4e, 0x02, 0x27, 0xe9, 0x83, 0xfe,
          0x03, 0xb2, 0xb9, 0x9a, 0x71);
  VLOAD_8(v4, 0x67, 0xa9, 0x07, 0x0f, 0xe3, 0x0d, 0xce, 0x81, 0xa2, 0xa5, 0x59,
          0x18, 0x0d, 0xac, 0x80, 0x31);
  asm volatile("vwmulu.vv v6, v2, v4");
  VSET(16, e16, m1);
  VCMP_U16(1, v6, 0x2eac, 0xa5b3, 0x06ac, 0x0da7, 0xcb0f, 0x03f6, 0x019c,
           0x13a7, 0x9372, 0x546f, 0x584e, 0x0048, 0x090a, 0x7c4c, 0x4d00,
           0x15a1);

  VSET(16, e16, m1);
  VLOAD_16(v2, 0xcf44, 0x249f, 0x3b1d, 0xea59, 0x0c47, 0xd24b, 0xce3e, 0xdb61,
           0x3506, 0xcee2, 0x3c7e, 0xc169, 0x05fd, 0x7fe6, 0xf7db, 0xb7cd);
  VLOAD_16(v4, 0xaa0b, 0x2176, 0x34bc, 0x4aa6, 0x221e, 0x9f98, 0x63f5, 0x8da7,
           0x001d, 0x18d7, 0x1dbb, 0x5f2d, 0x0783, 0xd756, 0xa08d, 0x9c49);
  asm volatile("vwmulu.vv v6, v2, v4");
  VSET(16, e32, m1);
  VCMP_U32(2, v6, 0x89ac0fec, 0x04c9604a, 0x0c2d4d4c, 0x4455afb6, 0x01a2de52,
           0x83197188, 0x50875b56, 0x79638947, 0x000601ae, 0x1412efce,
           0x0706760a, 0x47e7f675, 0x002cfb77, 0x6b952144, 0x9b71639f,
           0x70355575);

  // VSET(16, e32, m1);
  // VLOAD_32(v2, 0xd6f59ab7, 0x3b760112, 0x185928a9, 0x344f2f98, 0x07084e45,
  //          0x0af492c5, 0x5de6f51a, 0x76783522, 0x36835490, 0x043d016f,
  //          0xf583b765, 0xd8796652, 0x1bd09e8f, 0xeecf0026, 0xdb725a7d,
  //          0x3a4c3ab3);
  // VLOAD_32(v4, 0x19f9f18b, 0x801fde9f, 0xaf759e4c, 0x9206cfd4, 0x2dc70e82,
  //          0xb57cb666, 0xc4ab14ac, 0xbf231e21, 0xdc6caaf4, 0x5bbc4031,
  //          0x2021a0db, 0x4e68ad25, 0xb090da86, 0xe32bd2c2, 0xf45e06d0,
  //          0xa5320284);
  // asm volatile("vwmulu.vv v6, v2, v4");
  // VSET(16, e64, m1);
  // VCMP_U64(3, v6, 0x15cfdbd14900485d, 0x1dc267886466462e, 0x10b022995dcd602c,
  //          0x1dd68d77269f51e0, 0x0141ed9cff22850a, 0x07c4420a9e36887e,
  //          0x48239482c2b0b578, 0x5873f004fd5ed562, 0x2ef0007a98143940,
  //          0x0184cd5f928d063f, 0x1ed0b72b9e520367, 0x424d80e7e10133da,
  //          0x132f2a19b6a8c4da, 0xd3ea6e817f5f48cc, 0xd179981358ee7390,
  //          0x259e854b7db9aa4c);
};

void TEST_CASE2(void) {
  VSET(16, e8, m1);
  VLOAD_8(v2, 0x74, 0xfb, 0xf4, 0xe9, 0xe5, 0x4e, 0x02, 0x27, 0xe9, 0x83, 0xfe,
          0x03, 0xb2, 0xb9, 0x9a, 0x71);
  VLOAD_8(v4, 0x67, 0xa9, 0x07, 0x0f, 0xe3, 0x0d, 0xce, 0x81, 0xa2, 0xa5, 0x59,
          0x18, 0x0d, 0xac, 0x80, 0x31);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v6);
  asm volatile("vwmulu.vv v6, v2, v4, v0.t");
  VSET(16, e16, m1);
  VCMP_U16(4, v6, 0, 0xa5b3, 0, 0x0da7, 0, 0x03f6, 0, 0x13a7, 0, 0x546f, 0,
           0x0048, 0, 0x7c4c, 0, 0x15a1);

  VSET(16, e16, m1);
  VLOAD_16(v2, 0xcf44, 0x249f, 0x3b1d, 0xea59, 0x0c47, 0xd24b, 0xce3e, 0xdb61,
           0x3506, 0xcee2, 0x3c7e, 0xc169, 0x05fd, 0x7fe6, 0xf7db, 0xb7cd);
  VLOAD_16(v4, 0xaa0b, 0x2176, 0x34bc, 0x4aa6, 0x221e, 0x9f98, 0x63f5, 0x8da7,
           0x001d, 0x18d7, 0x1dbb, 0x5f2d, 0x0783, 0xd756, 0xa08d, 0x9c49);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v6);
  asm volatile("vwmulu.vv v6, v2, v4, v0.t");
  VSET(16, e32, m1);
  VCMP_U32(5, v6, 0, 0x04c9604a, 0, 0x4455afb6, 0, 0x83197188, 0, 0x79638947, 0,
           0x1412efce, 0, 0x47e7f675, 0, 0x6b952144, 0, 0x70355575);

  // VSET(16, e32, m1);
  // VLOAD_32(v2, 0xd6f59ab7, 0x3b760112, 0x185928a9, 0x344f2f98, 0x07084e45,
  //          0x0af492c5, 0x5de6f51a, 0x76783522, 0x36835490, 0x043d016f,
  //          0xf583b765, 0xd8796652, 0x1bd09e8f, 0xeecf0026, 0xdb725a7d,
  //          0x3a4c3ab3);
  // VLOAD_32(v4, 0x19f9f18b, 0x801fde9f, 0xaf759e4c, 0x9206cfd4, 0x2dc70e82,
  //          0xb57cb666, 0xc4ab14ac, 0xbf231e21, 0xdc6caaf4, 0x5bbc4031,
  //          0x2021a0db, 0x4e68ad25, 0xb090da86, 0xe32bd2c2, 0xf45e06d0,
  //          0xa5320284);
  // VLOAD_8(v0, 0xAA, 0xAA);
  // VCLEAR(v6);
  // asm volatile("vwmulu.vv v6, v2, v4, v0.t");
  // VSET(16, e64, m1);
  // VCMP_U64(6, v6, 0, 0x1dc267886466462e, 0, 0x1dd68d77269f51e0, 0,
  //          0x07c4420a9e36887e, 0, 0x5873f004fd5ed562, 0, 0x0184cd5f928d063f, 0,
  //          0x424d80e7e10133da, 0, 0xd3ea6e817f5f48cc, 0, 0x259e854b7db9aa4c);
};

void TEST_CASE3(void) {
  VSET(16, e8, m1);
  VLOAD_8(v2, 0xf8, 0x11, 0x12, 0xf1, 0x63, 0x21, 0x88, 0x3b, 0x01, 0xf5, 0x6d,
          0xf5, 0xb1, 0x54, 0xcd, 0xb0);
  uint64_t scalar = 5;
  asm volatile("vwmulu.vx v6, v2, %[A]" ::[A] "r"(scalar));
  VSET(16, e16, m1);
  VCMP_U16(7, v6, 0x04d8, 0x0055, 0x005a, 0x04b5, 0x01ef, 0x00a5, 0x02a8,
           0x0127, 0x0005, 0x04c9, 0x0221, 0x04c9, 0x0375, 0x01a4, 0x0401,
           0x0370);

  VSET(16, e16, m1);
  VLOAD_16(v2, 0xf8e5, 0x6a23, 0xb52f, 0x8838, 0xb6d4, 0x5279, 0xf80e, 0xa450,
           0x13ec, 0x916f, 0x8edd, 0x0162, 0x9350, 0x9f74, 0xe1e7, 0x2719);
  scalar = 5383;
  asm volatile("vwmulu.vx v6, v2, %[A]" ::[A] "r"(scalar));
  VSET(16, e32, m1);
  VCMP_U32(8, v6, 0x14719743, 0x08b7c5f5, 0x0ee1cf49, 0x0b305188, 0x0f0463cc,
           0x06c62e4f, 0x145fee62, 0x0d7f0e30, 0x01a2e774, 0x0bf21509,
           0x0bbc090b, 0x001d13ae, 0x0c199730, 0x0d18e02c, 0x128e2051,
           0x03361eaf);

  // VSET(16, e32, m1);
  // VLOAD_32(v2, 0xc41bf344, 0xad5aef4c, 0xf2b11789, 0xeb0d7526, 0xd6c67427,
  //          0x73724130, 0x440f954a, 0x0661455f, 0x450070ca, 0xc258c90c,
  //          0xf095d838, 0x358b0916, 0x6e1f1918, 0x4ebf2685, 0x3805d683,
  //          0x73715886);
  // scalar = 6474219;
  // asm volatile("vwmulu.vx v6, v2, %[A]" ::[A] "r"(scalar));
  // VSET(16, e64, m1);
  // VCMP_U64(9, v6, 0x004bad6117b0b36c, 0x0042e58b237456c4, 0x005da736d67d2bc3,
  //          0x005ab48c2ee15fe2, 0x0052e15f704d3ecd, 0x002c8ccba3708710,
  //          0x001a43a5dcd924ee, 0x00027644c9204535, 0x001aa097dd4a236e,
  //          0x004aff4713f2fa04, 0x005cd71f45c17368, 0x0014a974cb2f9d32,
  //          0x002a7ec31c6fe108, 0x001e63491da0c917, 0x00159e6c20eec541,
  //          0x002c8c71dad97902);
};

void TEST_CASE4(void) {
  VSET(16, e8, m1);
  VLOAD_8(v2, 0xf8, 0x11, 0x12, 0xf1, 0x63, 0x21, 0x88, 0x3b, 0x01, 0xf5, 0x6d,
          0xf5, 0xb1, 0x54, 0xcd, 0xb0);
  uint64_t scalar = 5;
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v6);
  asm volatile("vwmulu.vx v6, v2, %[A], v0.t" ::[A] "r"(scalar));
  VSET(16, e16, m1);
  VCMP_U16(10, v6, 0, 0x0055, 0, 0x04b5, 0, 0x00a5, 0, 0x0127, 0, 0x04c9, 0,
           0x04c9, 0, 0x01a4, 0, 0x0370);

  VSET(16, e16, m1);
  VLOAD_16(v2, 0xf8e5, 0x6a23, 0xb52f, 0x8838, 0xb6d4, 0x5279, 0xf80e, 0xa450,
           0x13ec, 0x916f, 0x8edd, 0x0162, 0x9350, 0x9f74, 0xe1e7, 0x2719);
  scalar = 5383;
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v6);
  asm volatile("vwmulu.vx v6, v2, %[A], v0.t" ::[A] "r"(scalar));
  VSET(16, e32, m1);
  VCMP_U32(11, v6, 0, 0x08b7c5f5, 0, 0x0b305188, 0, 0x06c62e4f, 0, 0x0d7f0e30,
           0, 0x0bf21509, 0, 0x001d13ae, 0, 0x0d18e02c, 0, 0x03361eaf);

  // VSET(16, e32, m1);
  // VLOAD_32(v2, 0xc41bf344, 0xad5aef4c, 0xf2b11789, 0xeb0d7526, 0xd6c67427,
  //          0x73724130, 0x440f954a, 0x0661455f, 0x450070ca, 0xc258c90c,
  //          0xf095d838, 0x358b0916, 0x6e1f1918, 0x4ebf2685, 0x3805d683,
  //          0x73715886);
  // scalar = 6474219;
  // VLOAD_8(v0, 0xAA, 0xAA);
  // VCLEAR(v6);
  // asm volatile("vwmulu.vx v6, v2, %[A], v0.t" ::[A] "r"(scalar));
  // VSET(16, e64, m1);
  // VCMP_U64(12, v6, 0, 0x0042e58b237456c4, 0, 0x005ab48c2ee15fe2, 0,
  //          0x002c8ccba3708710, 0, 0x00027644c9204535, 0, 0x004aff4713f2fa04, 0,
  //          0x0014a974cb2f9d32, 0, 0x001e63491da0c917, 0, 0x002c8c71dad97902);
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

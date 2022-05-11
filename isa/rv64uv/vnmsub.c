// Copyright 2021 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// Author: Matteo Perotti <mperotti@iis.ee.ethz.ch>
//         Basile Bougenot <bbougenot@student.ethz.ch>

#include "vector_macros.h"

void TEST_CASE1() {
  VSET(16, e8, m1);
  VLOAD_8(v1, 0x41, 0x5b, 0xd0, 0x04, 0xc4, 0x7a, 0x91, 0xd1, 0x7b, 0x09, 0x85,
          0x59, 0x2b, 0xe3, 0x33, 0xb9);
  VLOAD_8(v2, 0xc5, 0x4d, 0xad, 0x35, 0x81, 0x18, 0x48, 0x50, 0xe7, 0x95, 0x7b,
          0x18, 0xe6, 0x44, 0x57, 0xaf);
  VLOAD_8(v3, 0x53, 0x13, 0x2c, 0xd8, 0x4a, 0xc3, 0xa3, 0xd7, 0x7e, 0x1f, 0x4c,
          0x4e, 0x2e, 0x7d, 0x13, 0x5a);
  asm volatile("vnmsub.vv v1, v2, v3");
  VCMP_U8(1, v1, 0x4e, 0xb4, 0x9c, 0x04, 0x86, 0x53, 0xdb, 0x87, 0x81, 0xe2,
          0x65, 0xf6, 0x8c, 0x31, 0xbe, 0xe3);

  VSET(16, e16, m1);
  VLOAD_16(v1, 0x9904, 0x5982, 0xa6cb, 0x73a1, 0x227e, 0xc8f6, 0x3eeb, 0xb010,
           0x14a1, 0xef2d, 0x3376, 0x371a, 0x4fc8, 0xbcca, 0xccd7, 0x9097);
  VLOAD_16(v2, 0xb2dd, 0x9ca4, 0x72fe, 0xecab, 0x9909, 0xe1b0, 0x1769, 0x6759,
           0x9500, 0x3aae, 0x0637, 0xeadc, 0x7523, 0xa53c, 0xecc7, 0xaccc);
  VLOAD_16(v3, 0xb917, 0x6a27, 0x0f0c, 0x04a2, 0xe0b6, 0x9fb1, 0x5c69, 0x21e2,
           0x3588, 0x8d19, 0x65d9, 0x6458, 0xfbff, 0xf949, 0x34a4, 0x0710);
  asm volatile("vnmsub.vv v1, v2, v3");
  VCMP_U16(2, v1, 0xd8a3, 0xdadf, 0x2ba2, 0x5c17, 0x5c48, 0x4091, 0x7106,
           0x7c52, 0x8088, 0xca83, 0x937f, 0x4600, 0xaba7, 0x87f1, 0xc583,
           0x5abc);

  VSET(16, e32, m1);
  VLOAD_32(v1, 0xe6f4ff60, 0xbf6a38db, 0x30f2ea92, 0x1763619e, 0x815c1c28,
           0x5f1b57db, 0xdb2cdc06, 0xab577f4a, 0x214746ac, 0xd3a08c15,
           0x35887ce9, 0x9d5a0f65, 0x76adea2b, 0x91b7f299, 0x6e2977fe,
           0xdcbcb1d7);
  VLOAD_32(v2, 0x885c8baa, 0xbe200324, 0x9eaa49d7, 0x4e208dde, 0x802bbe9f,
           0x7633680e, 0xf1a79717, 0xe62e371e, 0x0fc25b48, 0x11067f38,
           0xc654ccb4, 0x6702a66c, 0x7a0b229d, 0x25c2b688, 0x82b68b3d,
           0x4224aa5e);
  VLOAD_32(v3, 0x3a582428, 0x61c55f94, 0xb445799b, 0xcca5a657, 0x51a7fe9e,
           0x0840b4f8, 0xfb0a701b, 0x1b5361d7, 0xd10c9064, 0xa899d63d,
           0xbb1779fd, 0x1b35390c, 0xd04c0f6c, 0xd8c9db62, 0x90a09dc8,
           0x463438b4);
  asm volatile("vnmsub.vv v1, v2, v3");
  VCMP_U32(3, v1, 0x0e7d6e68, 0x92cacfc8, 0x726ad6fd, 0x6ff2f953, 0xe1d4d1c6,
           0x466feefe, 0xa6512191, 0xdf6d912b, 0x7c898c04, 0x0a7ec6a5,
           0x2121fa29, 0x91713c70, 0x60b0bd0d, 0xb3a6341a, 0x82041c42,
           0x7a9625c2);

  // VSET(16, e64, m1);
  // VLOAD_64(v1, 0xb8d79a755b98580a, 0xceefb8be6deb3a3d, 0x670688aed7c97cdd,
  //          0x0ced1db5e1b7da8f, 0x58993c2ae4a62e89, 0x864439a0768dce1b,
  //          0x7882d6539128d119, 0xfe6469348911945b, 0x6da189493780c328,
  //          0xf8c4931b61dc54dc, 0xd5ac914ccbf735f0, 0xba0a5bf3b2b528d1,
  //          0x74d814e6ebcebe81, 0xfc44af3a74cfee8c, 0xea0cb63d1bf7d5dc,
  //          0xbe98c841d80bd077);
  // VLOAD_64(v2, 0x5517b401c8fbd5ec, 0x021c52c329edd200, 0xff61d899305d1423,
  //          0xd886035fdcfe3186, 0x694b857cb1cc3bc3, 0x52376b9a996e1925,
  //          0x5785c45d41ec230d, 0x950f08c23f6da73d, 0xe5dc4e9a35834719,
  //          0x9a08d0e965e96a19, 0xb80c2107151bdcf6, 0xd0612e4d4bc314b7,
  //          0xdfb23a142b750482, 0xedc5e4b79881bdaf, 0x72c493d9df55bf13,
  //          0xfd4b1328b8f7773a);
  // VLOAD_64(v3, 0xc265b2d19ad92bbb, 0x81a4ef527fc2e042, 0xe490f5981f64a313,
  //          0xf12edb410132b013, 0xc475df4b52276fe9, 0x069e283bf74ca195,
  //          0x8dd5189f3a66f166, 0x297726422e620380, 0x7b74d167bd1b22fd,
  //          0x08e88e9642656a52, 0x0ab0c3f0f7ddeb66, 0x00b155918c8646c0,
  //          0x84d4df4b2a3768c7, 0xc31234734867ae09, 0x79320b8da693a84e,
  //          0x30727b2d1bccd396);
  // asm volatile("vnmsub.vv v1, v2, v3");
  // VCMP_U64(4, v1, 0x231a763b4759b083, 0x68b16397da83d642, 0x7081592414ce4cdc,
  //          0x084dc189ec3eea39, 0x72cb55f70cac6a8e, 0xc713321c491334ae,
  //          0xa21580bb2ab1e821, 0x3d84da5e7dab4cd1, 0x735a758175effc15,
  //          0x91e8df24708208d6, 0x5133f0cd25a5d6c6, 0x2f1a889653a2c559,
  //          0x5f9f0ac7744ba745, 0xba1bbac1969a4055, 0x275025160493a4fa,
  //          0x21c02801006747a0);
}

void TEST_CASE2() {
  VSET(16, e8, m1);
  VLOAD_8(v1, 0x41, 0x5b, 0xd0, 0x04, 0xc4, 0x7a, 0x91, 0xd1, 0x7b, 0x09, 0x85,
          0x59, 0x2b, 0xe3, 0x33, 0xb9);
  VLOAD_8(v2, 0xc5, 0x4d, 0xad, 0x35, 0x81, 0x18, 0x48, 0x50, 0xe7, 0x95, 0x7b,
          0x18, 0xe6, 0x44, 0x57, 0xaf);
  VLOAD_8(v3, 0x53, 0x13, 0x2c, 0xd8, 0x4a, 0xc3, 0xa3, 0xd7, 0x7e, 0x1f, 0x4c,
          0x4e, 0x2e, 0x7d, 0x13, 0x5a);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vnmsub.vv v1, v2, v3, v0.t");
  VCMP_U8(5, v1, 0x41, 0xb4, 0xd0, 0x04, 0xc4, 0x53, 0x91, 0x87, 0x7b, 0xe2,
          0x85, 0xf6, 0x2b, 0x31, 0x33, 0xe3);

  VSET(16, e16, m1);
  VLOAD_16(v1, 0x9904, 0x5982, 0xa6cb, 0x73a1, 0x227e, 0xc8f6, 0x3eeb, 0xb010,
           0x14a1, 0xef2d, 0x3376, 0x371a, 0x4fc8, 0xbcca, 0xccd7, 0x9097);
  VLOAD_16(v2, 0xb2dd, 0x9ca4, 0x72fe, 0xecab, 0x9909, 0xe1b0, 0x1769, 0x6759,
           0x9500, 0x3aae, 0x0637, 0xeadc, 0x7523, 0xa53c, 0xecc7, 0xaccc);
  VLOAD_16(v3, 0xb917, 0x6a27, 0x0f0c, 0x04a2, 0xe0b6, 0x9fb1, 0x5c69, 0x21e2,
           0x3588, 0x8d19, 0x65d9, 0x6458, 0xfbff, 0xf949, 0x34a4, 0x0710);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vnmsub.vv v1, v2, v3, v0.t");
  VCMP_U16(6, v1, 0x9904, 0xdadf, 0xa6cb, 0x5c17, 0x227e, 0x4091, 0x3eeb,
           0x7c52, 0x14a1, 0xca83, 0x3376, 0x4600, 0x4fc8, 0x87f1, 0xccd7,
           0x5abc);

  VSET(16, e32, m1);
  VLOAD_32(v1, 0xe6f4ff60, 0xbf6a38db, 0x30f2ea92, 0x1763619e, 0x815c1c28,
           0x5f1b57db, 0xdb2cdc06, 0xab577f4a, 0x214746ac, 0xd3a08c15,
           0x35887ce9, 0x9d5a0f65, 0x76adea2b, 0x91b7f299, 0x6e2977fe,
           0xdcbcb1d7);
  VLOAD_32(v2, 0x885c8baa, 0xbe200324, 0x9eaa49d7, 0x4e208dde, 0x802bbe9f,
           0x7633680e, 0xf1a79717, 0xe62e371e, 0x0fc25b48, 0x11067f38,
           0xc654ccb4, 0x6702a66c, 0x7a0b229d, 0x25c2b688, 0x82b68b3d,
           0x4224aa5e);
  VLOAD_32(v3, 0x3a582428, 0x61c55f94, 0xb445799b, 0xcca5a657, 0x51a7fe9e,
           0x0840b4f8, 0xfb0a701b, 0x1b5361d7, 0xd10c9064, 0xa899d63d,
           0xbb1779fd, 0x1b35390c, 0xd04c0f6c, 0xd8c9db62, 0x90a09dc8,
           0x463438b4);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vnmsub.vv v1, v2, v3, v0.t");
  VCMP_U32(7, v1, 0xe6f4ff60, 0x92cacfc8, 0x30f2ea92, 0x6ff2f953, 0x815c1c28,
           0x466feefe, 0xdb2cdc06, 0xdf6d912b, 0x214746ac, 0x0a7ec6a5,
           0x35887ce9, 0x91713c70, 0x76adea2b, 0xb3a6341a, 0x6e2977fe,
           0x7a9625c2);

  // VSET(16, e64, m1);
  // VLOAD_64(v1, 0xb8d79a755b98580a, 0xceefb8be6deb3a3d, 0x670688aed7c97cdd,
  //          0x0ced1db5e1b7da8f, 0x58993c2ae4a62e89, 0x864439a0768dce1b,
  //          0x7882d6539128d119, 0xfe6469348911945b, 0x6da189493780c328,
  //          0xf8c4931b61dc54dc, 0xd5ac914ccbf735f0, 0xba0a5bf3b2b528d1,
  //          0x74d814e6ebcebe81, 0xfc44af3a74cfee8c, 0xea0cb63d1bf7d5dc,
  //          0xbe98c841d80bd077);
  // VLOAD_64(v2, 0x5517b401c8fbd5ec, 0x021c52c329edd200, 0xff61d899305d1423,
  //          0xd886035fdcfe3186, 0x694b857cb1cc3bc3, 0x52376b9a996e1925,
  //          0x5785c45d41ec230d, 0x950f08c23f6da73d, 0xe5dc4e9a35834719,
  //          0x9a08d0e965e96a19, 0xb80c2107151bdcf6, 0xd0612e4d4bc314b7,
  //          0xdfb23a142b750482, 0xedc5e4b79881bdaf, 0x72c493d9df55bf13,
  //          0xfd4b1328b8f7773a);
  // VLOAD_64(v3, 0xc265b2d19ad92bbb, 0x81a4ef527fc2e042, 0xe490f5981f64a313,
  //          0xf12edb410132b013, 0xc475df4b52276fe9, 0x069e283bf74ca195,
  //          0x8dd5189f3a66f166, 0x297726422e620380, 0x7b74d167bd1b22fd,
  //          0x08e88e9642656a52, 0x0ab0c3f0f7ddeb66, 0x00b155918c8646c0,
  //          0x84d4df4b2a3768c7, 0xc31234734867ae09, 0x79320b8da693a84e,
  //          0x30727b2d1bccd396);
  // VLOAD_8(v0, 0xAA, 0xAA);
  // asm volatile("vnmsub.vv v1, v2, v3, v0.t");
  // VCMP_U64(8, v1, 0xb8d79a755b98580a, 0x68b16397da83d642, 0x670688aed7c97cdd,
  //          0x084dc189ec3eea39, 0x58993c2ae4a62e89, 0xc713321c491334ae,
  //          0x7882d6539128d119, 0x3d84da5e7dab4cd1, 0x6da189493780c328,
  //          0x91e8df24708208d6, 0xd5ac914ccbf735f0, 0x2f1a889653a2c559,
  //          0x74d814e6ebcebe81, 0xba1bbac1969a4055, 0xea0cb63d1bf7d5dc,
  //          0x21c02801006747a0);
}

void TEST_CASE3() {
  VSET(16, e8, m1);
  int64_t scalar = 5;
  VLOAD_8(v1, 0x5e, 0xf5, 0xa9, 0x0b, 0x14, 0x3c, 0x84, 0x22, 0xd7, 0xb6, 0x5c,
          0x90, 0xa2, 0x67, 0x3d, 0xf5);
  VLOAD_8(v3, 0xfa, 0xd9, 0x2a, 0xe2, 0xe7, 0x1f, 0x8c, 0xbd, 0x40, 0x5d, 0x50,
          0x1f, 0xe0, 0xdd, 0x1f, 0xd7);
  asm volatile("vnmsub.vx v1, %[A], v3" ::[A] "r"(scalar));
  VCMP_U8(9, v1, 0x24, 0x10, 0xdd, 0xab, 0x83, 0xf3, 0xf8, 0x13, 0x0d, 0xcf,
          0x84, 0x4f, 0xb6, 0xda, 0xee, 0x0e);

  VSET(16, e16, m1);
  scalar = -5383;
  VLOAD_16(v1, 0xfe80, 0x3910, 0x5313, 0xefef, 0xecfc, 0x7983, 0xcc0d, 0x731f,
           0xf384, 0xfde3, 0x9cd1, 0xf20b, 0xa41b, 0x949a, 0x5886, 0xa1a9);
  VLOAD_16(v3, 0xe886, 0xf1f9, 0x1857, 0xd0bb, 0x522e, 0x2de0, 0xa6c2, 0xd624,
           0xd024, 0x40a2, 0xdd99, 0xd517, 0xf00a, 0xae8d, 0x79a5, 0x519d);
  asm volatile("vnmsub.vx v1, %[A], v3" ::[A] "r"(scalar));
  VCMP_U16(10, v1, 0x5e06, 0xd169, 0xecdc, 0xfb44, 0x7912, 0x3f75, 0x4c1d,
           0x86fd, 0x4cc0, 0xd0d7, 0x4c50, 0x5a64, 0xa3c7, 0x60c3, 0xe34f,
           0x9a3c);

  VSET(16, e32, m1);
  scalar = 6474219;
  VLOAD_32(v1, 0x48da7aac, 0x54e98600, 0xf49f26e5, 0x338e8406, 0x40ca82f5,
           0x75d0b8f6, 0x38c88af2, 0x96bb5c03, 0x6f61c0a9, 0x3626dd69,
           0x31aba619, 0x7d974a55, 0xbc63c280, 0x502334bf, 0x9451b955,
           0x6a8bae19);
  VLOAD_32(v3, 0xcbd8537e, 0x36928a6c, 0x60cf8444, 0xa19ea650, 0x8f2a8694,
           0x050956bf, 0x1ef799f5, 0x43c0f327, 0x4bfd5a25, 0x7be439e4,
           0xed89a52a, 0x2bbf028d, 0x872392b9, 0x0ad55495, 0x865c7264,
           0xfcce4b64);
  asm volatile("vnmsub.vx v1, %[A], v3" ::[A] "r"(scalar));
  VCMP_U32(11, v1, 0x6b20ab9a, 0x9dfe886c, 0xf983030d, 0xddd6bece, 0xf2a7f2ad,
           0x2f0a66ed, 0x59240bcf, 0x915f2166, 0x8c4ace02, 0x802d8981,
           0xf9fc8b37, 0xa3f70986, 0xced98739, 0xa4fbf240, 0x4249945d,
           0xdd51d971);

  // VSET(16, e64, m1);
  // scalar = -598189234597999223;
  // VLOAD_64(v1, 0x93adc14539897782, 0xa8d5d41c19b1455a, 0x55e01165195d2d9b,
  //          0xe81a26a17fef30f2, 0x33a71ede19aec0aa, 0x49598be14c5bc1cd,
  //          0x1c27bde3f488bfc6, 0x4188f9b8611e5d90, 0xd53289cca28a3b6b,
  //          0x3b435e1078e3bee9, 0x5e3f4c08c869abf4, 0x3c004920e9c39fb6,
  //          0x4b42a451b264b153, 0x110a6db11a7c2801, 0x7c0f358ac41d49fa,
  //          0x6e8c6ae4d14bd1a5);
  // VLOAD_64(v3, 0x3b0c6a3a651beecc, 0xb612caa033bc9bca, 0xda94340ac428ca78,
  //          0xf774b16ef94a22ea, 0x87df3c47c8113e43, 0x38487d57a064f677,
  //          0x358706b57ce6d6c7, 0xda111b3ac946811c, 0xe9ffed5b39f1ea1d,
  //          0x3c7e5a675c779870, 0x5d2ea63ac910e42e, 0xb3e832dbe2332203,
  //          0x05d366b426005f47, 0x00b3b58815a860d8, 0x023bbf8109263e1d,
  //          0x5fbc2f647d6c1153);
  // asm volatile("vnmsub.vx v1, %[A], v3" ::[A] "r"(scalar));
  // VCMP_U64(12, v1, 0x60dd7609c833e03a, 0x79abe3a30a816ca0, 0x983ca4c97f204385,
  //          0x59a9303f04932768, 0x59c29659b4d00149, 0x59a15b1bb66f16c2,
  //          0x37b0445a8ebaa7d1, 0x65e0c3ab56fa1f0c, 0x94a740971b1d6eda,
  //          0xa1c7ff743113d8bf, 0xe8198a4799a97a9a, 0x5ccf06fd8751eb9d,
  //          0xa36557d05e8802dc, 0x10aae67f31dc2b4f, 0xe878939fd1287553,
  //          0x594538a8571dbf06);
}

void TEST_CASE4() {
  VSET(16, e8, m1);
  int64_t scalar = 5;
  VLOAD_8(v1, 0x5e, 0xf5, 0xa9, 0x0b, 0x14, 0x3c, 0x84, 0x22, 0xd7, 0xb6, 0x5c,
          0x90, 0xa2, 0x67, 0x3d, 0xf5);
  VLOAD_8(v3, 0xfa, 0xd9, 0x2a, 0xe2, 0xe7, 0x1f, 0x8c, 0xbd, 0x40, 0x5d, 0x50,
          0x1f, 0xe0, 0xdd, 0x1f, 0xd7);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vnmsub.vx v1, %[A], v3, v0.t" ::[A] "r"(scalar));
  VCMP_U8(13, v1, 0x5e, 0x10, 0xa9, 0xab, 0x14, 0xf3, 0x84, 0x13, 0xd7, 0xcf,
          0x5c, 0x4f, 0xa2, 0xda, 0x3d, 0x0e);

  VSET(16, e16, m1);
  scalar = -5383;
  VLOAD_16(v1, 0xfe80, 0x3910, 0x5313, 0xefef, 0xecfc, 0x7983, 0xcc0d, 0x731f,
           0xf384, 0xfde3, 0x9cd1, 0xf20b, 0xa41b, 0x949a, 0x5886, 0xa1a9);
  VLOAD_16(v3, 0xe886, 0xf1f9, 0x1857, 0xd0bb, 0x522e, 0x2de0, 0xa6c2, 0xd624,
           0xd024, 0x40a2, 0xdd99, 0xd517, 0xf00a, 0xae8d, 0x79a5, 0x519d);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vnmsub.vx v1, %[A], v3, v0.t" ::[A] "r"(scalar));
  VCMP_U16(14, v1, 0xfe80, 0xd169, 0x5313, 0xfb44, 0xecfc, 0x3f75, 0xcc0d,
           0x86fd, 0xf384, 0xd0d7, 0x9cd1, 0x5a64, 0xa41b, 0x60c3, 0x5886,
           0x9a3c);

  VSET(16, e32, m1);
  scalar = 6474219;
  VLOAD_32(v1, 0x48da7aac, 0x54e98600, 0xf49f26e5, 0x338e8406, 0x40ca82f5,
           0x75d0b8f6, 0x38c88af2, 0x96bb5c03, 0x6f61c0a9, 0x3626dd69,
           0x31aba619, 0x7d974a55, 0xbc63c280, 0x502334bf, 0x9451b955,
           0x6a8bae19);
  VLOAD_32(v3, 0xcbd8537e, 0x36928a6c, 0x60cf8444, 0xa19ea650, 0x8f2a8694,
           0x050956bf, 0x1ef799f5, 0x43c0f327, 0x4bfd5a25, 0x7be439e4,
           0xed89a52a, 0x2bbf028d, 0x872392b9, 0x0ad55495, 0x865c7264,
           0xfcce4b64);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vnmsub.vx v1, %[A], v3, v0.t" ::[A] "r"(scalar));
  VCMP_U32(15, v1, 0x48da7aac, 0x9dfe886c, 0xf49f26e5, 0xddd6bece, 0x40ca82f5,
           0x2f0a66ed, 0x38c88af2, 0x915f2166, 0x6f61c0a9, 0x802d8981,
           0x31aba619, 0xa3f70986, 0xbc63c280, 0xa4fbf240, 0x9451b955,
           0xdd51d971);

  // VSET(16, e64, m1);
  // scalar = -598189234597999223;
  // VLOAD_64(v1, 0x93adc14539897782, 0xa8d5d41c19b1455a, 0x55e01165195d2d9b,
  //          0xe81a26a17fef30f2, 0x33a71ede19aec0aa, 0x49598be14c5bc1cd,
  //          0x1c27bde3f488bfc6, 0x4188f9b8611e5d90, 0xd53289cca28a3b6b,
  //          0x3b435e1078e3bee9, 0x5e3f4c08c869abf4, 0x3c004920e9c39fb6,
  //          0x4b42a451b264b153, 0x110a6db11a7c2801, 0x7c0f358ac41d49fa,
  //          0x6e8c6ae4d14bd1a5);
  // VLOAD_64(v3, 0x3b0c6a3a651beecc, 0xb612caa033bc9bca, 0xda94340ac428ca78,
  //          0xf774b16ef94a22ea, 0x87df3c47c8113e43, 0x38487d57a064f677,
  //          0x358706b57ce6d6c7, 0xda111b3ac946811c, 0xe9ffed5b39f1ea1d,
  //          0x3c7e5a675c779870, 0x5d2ea63ac910e42e, 0xb3e832dbe2332203,
  //          0x05d366b426005f47, 0x00b3b58815a860d8, 0x023bbf8109263e1d,
  //          0x5fbc2f647d6c1153);
  // VLOAD_8(v0, 0xAA, 0xAA);
  // asm volatile("vnmsub.vx v1, %[A], v3, v0.t" ::[A] "r"(scalar));
  // VCMP_U64(16, v1, 0x93adc14539897782, 0x79abe3a30a816ca0, 0x55e01165195d2d9b,
  //          0x59a9303f04932768, 0x33a71ede19aec0aa, 0x59a15b1bb66f16c2,
  //          0x1c27bde3f488bfc6, 0x65e0c3ab56fa1f0c, 0xd53289cca28a3b6b,
  //          0xa1c7ff743113d8bf, 0x5e3f4c08c869abf4, 0x5ccf06fd8751eb9d,
  //          0x4b42a451b264b153, 0x10aae67f31dc2b4f, 0x7c0f358ac41d49fa,
  //          0x594538a8571dbf06);
}

int main(void) {
  INIT_CHECK();
  enable_vec();

  TEST_CASE1();
  TEST_CASE2();
  TEST_CASE3();
  TEST_CASE4();

  EXIT_CHECK();
}

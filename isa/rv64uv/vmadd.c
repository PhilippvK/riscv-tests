// Copyright 2021 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// Author: Matheus Cavalcante <matheusd@iis.ee.ethz.ch>
//         Basile Bougenot <bbougenot@student.ethz.ch>

#include "vector_macros.h"

void TEST_CASE1() {
  VSET(16, e8, m1);
  VLOAD_8(v1, 0x21, 0x75, 0x7f, 0x3a, 0x50, 0x6d, 0x3f, 0x3e, 0x74, 0x11, 0x29,
          0xea, 0x14, 0xce, 0xb0, 0x37);
  VLOAD_8(v2, 0xfe, 0xa7, 0x06, 0xaa, 0x35, 0x3c, 0x2c, 0x58, 0xa1, 0xc4, 0x40,
          0x42, 0x52, 0x40, 0xa8, 0x53);
  VLOAD_8(v3, 0x30, 0xef, 0xb4, 0x12, 0x6d, 0x3b, 0x2c, 0x5e, 0xf0, 0x25, 0xd7,
          0x70, 0xc2, 0x62, 0xe0, 0x99);
  asm volatile("vmadd.vv v1, v2, v3");
  VCMP_U8(1, v1, 0xee, 0x42, 0xae, 0x96, 0xfd, 0xc7, 0x00, 0xae, 0xe4, 0x29,
          0x17, 0xc4, 0x2a, 0xe2, 0x60, 0x6e);

  VSET(16, e16, m1);
  VLOAD_16(v1, 0x1c20, 0x11e4, 0xde38, 0x642f, 0x3eb5, 0xa0af, 0x48e1, 0x5fc4,
           0x3d2a, 0x67d5, 0x3f07, 0x2889, 0x8812, 0x0bd9, 0x56f4, 0xe068);
  VLOAD_16(v2, 0x02cc, 0xd99c, 0xdba2, 0xf282, 0x0f99, 0xa219, 0x2dcc, 0x17cc,
           0xe8fb, 0x1e83, 0xed20, 0xbfee, 0xee87, 0x6b0f, 0xf6cf, 0x4cd1);
  VLOAD_16(v3, 0xe3f0, 0x42db, 0x2fde, 0x1983, 0x910c, 0x853b, 0x82aa, 0x9ac2,
           0x4631, 0x1f8b, 0x68c3, 0x6fbc, 0x3b5c, 0xf98b, 0x2db1, 0x8e75);
  asm volatile("vmadd.vv v1, v2, v3");
  VCMP_U16(2, v1, 0x8d70, 0x6dcb, 0xb74e, 0x6761, 0xa639, 0xf452, 0x22f6,
           0x86f2, 0x4e5f, 0x378a, 0xc4a3, 0x561a, 0xb8da, 0x5e42, 0xf4fd,
           0xa35d);

  VSET(16, e32, m1);
  VLOAD_32(v1, 0x0401c584, 0x69049955, 0x4a71aa0c, 0xc651666f, 0x273fcd5d,
           0x23ca1d7d, 0x599c994e, 0xb2d8adc5, 0x4710afae, 0x69c61cad,
           0x96ee5026, 0x2c197996, 0xd95da451, 0x3a654fb9, 0xbe990e4b,
           0xc41fd55a);
  VLOAD_32(v2, 0x39d5b56a, 0xc578a540, 0x51283b5c, 0x07b4ba9d, 0xe5aba5e4,
           0x28720dc8, 0x600fb42b, 0xf2937fa7, 0x4032d36f, 0xc676e3b3,
           0xf1cd5f96, 0x1c14bcbf, 0x7dea81ed, 0x40270562, 0x9577b3be,
           0xea615f0a);
  VLOAD_32(v3, 0xa055bbb6, 0x71f9a668, 0x0be640c9, 0x2336ca55, 0xca121638,
           0xbf234fb5, 0xe7c83142, 0xb7048f12, 0x8eb340e3, 0xef253e93,
           0xffef4a03, 0xdf346833, 0xd0922181, 0xf159ee1d, 0xf86a7c06,
           0xfcb24a2d);
  asm volatile("vmadd.vv v1, v2, v3");
  VCMP_U32(3, v1, 0x448bd85e, 0xf2cbc4a8, 0x5cd02119, 0xf69b4268, 0x3c60ee0c,
           0xa233b25d, 0x4c72c95c, 0xe2b1a595, 0xefb7d755, 0x95d6b28a,
           0xd3be5a47, 0x6338471d, 0xfb1a117e, 0xabe00fef, 0xbede88b0,
           0x913705b1);

  // VSET(16, e64, m1);
  // VLOAD_64(v1, 0x9cffef345b95f00b, 0x85d366e07e4bbc6b, 0xadfda1d2464c6433,
  //          0x610bf2c1435b3cf6, 0x8a0c6e4bc950e81f, 0x4296e7147ef94d7a,
  //          0x27d7ec90ba159756, 0x2a6c87932c3aef86, 0xbfd90c33e58a8fe3,
  //          0x1114f7672cf625c1, 0x1a7b72dd8ac39fab, 0xdb80f952e5fd2e5b,
  //          0x6b01c18a3daf288b, 0x69b4b0e4335f26d5, 0x0c059f365ec6d3d5,
  //          0xc22568276f1dcdd0);
  // VLOAD_64(v2, 0x6dc8e88769e54465, 0xce8cda83d16c3859, 0x1465ee5b6eb0d2b8,
  //          0x4827a9b40add2507, 0xd24c4005695a64d6, 0xb97c8e41e912f84a,
  //          0xc8c22e3b3b2e2fa1, 0x26712aa325bd00b6, 0xdf7ad19151df27b5,
  //          0x68ba6d050ffcba1e, 0x94448979a2b854e6, 0x84bf5d544f97f739,
  //          0x6d4bfa429e9d6ef0, 0xdb6c54b9a91ab935, 0x1a0051ca72162c5e,
  //          0xe04b73fdf1b61f9c);
  // VLOAD_64(v3, 0x32a4c1edbbfe5591, 0xf6baf4e747f4a120, 0x3a29727ae38b9b92,
  //          0xf173f78d09c997e4, 0xaab9d34e4aeaa57a, 0xa8fe3bf12b7c95e8,
  //          0xc4bd99b066821092, 0x9c2f1daf5fe2db9d, 0xa8b041a876aabcae,
  //          0xb9a2e6f9ded9a60a, 0x8bdf55954f50101d, 0x704f0e648c11d63f,
  //          0x0c8ca4d0a6d1a982, 0xa74d01c12ae6aea5, 0x3f2cd5d2e2f5b538,
  //          0x79803b24efa2caa3);
  // asm volatile("vmadd.vv v1, v2, v3");
  // VCMP_U64(4, v1, 0xf7c2044aeebff5e8, 0xad447a1b99a48a53, 0x78676efbe1b5763a,
  //          0x813582af4d75d09e, 0x483adf8d811ecb64, 0x36d90fe4df2f2b2c,
  //          0xf833b173685307a8, 0x955c2ac405b724e1, 0xdcf9681f074b0d2d,
  //          0x10277404741c4ca8, 0x25d9bca0245d9fbf, 0x58439c4175d7f582,
  //          0x27ae9e3365b265d2, 0xabfe86591f4ba5be, 0xd964de90eaae196e,
  //          0xfb655e2263986563);
}

void TEST_CASE2() {
  VSET(16, e8, m1);
  VLOAD_8(v1, 0x21, 0x75, 0x7f, 0x3a, 0x50, 0x6d, 0x3f, 0x3e, 0x74, 0x11, 0x29,
          0xea, 0x14, 0xce, 0xb0, 0x37);
  VLOAD_8(v2, 0xfe, 0xa7, 0x06, 0xaa, 0x35, 0x3c, 0x2c, 0x58, 0xa1, 0xc4, 0x40,
          0x42, 0x52, 0x40, 0xa8, 0x53);
  VLOAD_8(v3, 0x30, 0xef, 0xb4, 0x12, 0x6d, 0x3b, 0x2c, 0x5e, 0xf0, 0x25, 0xd7,
          0x70, 0xc2, 0x62, 0xe0, 0x99);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vmadd.vv v1, v2, v3, v0.t");
  VCMP_U8(5, v1, 0x21, 0x42, 0x7f, 0x96, 0x50, 0xc7, 0x3f, 0xae, 0x74, 0x29,
          0x29, 0xc4, 0x14, 0xe2, 0xb0, 0x6e);

  VSET(16, e16, m1);
  VLOAD_16(v1, 0x1c20, 0x11e4, 0xde38, 0x642f, 0x3eb5, 0xa0af, 0x48e1, 0x5fc4,
           0x3d2a, 0x67d5, 0x3f07, 0x2889, 0x8812, 0x0bd9, 0x56f4, 0xe068);
  VLOAD_16(v2, 0x02cc, 0xd99c, 0xdba2, 0xf282, 0x0f99, 0xa219, 0x2dcc, 0x17cc,
           0xe8fb, 0x1e83, 0xed20, 0xbfee, 0xee87, 0x6b0f, 0xf6cf, 0x4cd1);
  VLOAD_16(v3, 0xe3f0, 0x42db, 0x2fde, 0x1983, 0x910c, 0x853b, 0x82aa, 0x9ac2,
           0x4631, 0x1f8b, 0x68c3, 0x6fbc, 0x3b5c, 0xf98b, 0x2db1, 0x8e75);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vmadd.vv v1, v2, v3, v0.t");
  VCMP_U16(6, v1, 0x1c20, 0x6dcb, 0xde38, 0x6761, 0x3eb5, 0xf452, 0x48e1,
           0x86f2, 0x3d2a, 0x378a, 0x3f07, 0x561a, 0x8812, 0x5e42, 0x56f4,
           0xa35d);

  VSET(16, e32, m1);
  VLOAD_32(v1, 0x0401c584, 0x69049955, 0x4a71aa0c, 0xc651666f, 0x273fcd5d,
           0x23ca1d7d, 0x599c994e, 0xb2d8adc5, 0x4710afae, 0x69c61cad,
           0x96ee5026, 0x2c197996, 0xd95da451, 0x3a654fb9, 0xbe990e4b,
           0xc41fd55a);
  VLOAD_32(v2, 0x39d5b56a, 0xc578a540, 0x51283b5c, 0x07b4ba9d, 0xe5aba5e4,
           0x28720dc8, 0x600fb42b, 0xf2937fa7, 0x4032d36f, 0xc676e3b3,
           0xf1cd5f96, 0x1c14bcbf, 0x7dea81ed, 0x40270562, 0x9577b3be,
           0xea615f0a);
  VLOAD_32(v3, 0xa055bbb6, 0x71f9a668, 0x0be640c9, 0x2336ca55, 0xca121638,
           0xbf234fb5, 0xe7c83142, 0xb7048f12, 0x8eb340e3, 0xef253e93,
           0xffef4a03, 0xdf346833, 0xd0922181, 0xf159ee1d, 0xf86a7c06,
           0xfcb24a2d);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vmadd.vv v1, v2, v3, v0.t");
  VCMP_U32(7, v1, 0x0401c584, 0xf2cbc4a8, 0x4a71aa0c, 0xf69b4268, 0x273fcd5d,
           0xa233b25d, 0x599c994e, 0xe2b1a595, 0x4710afae, 0x95d6b28a,
           0x96ee5026, 0x6338471d, 0xd95da451, 0xabe00fef, 0xbe990e4b,
           0x913705b1);

  // VSET(16, e64, m1);
  // VLOAD_64(v1, 0x9cffef345b95f00b, 0x85d366e07e4bbc6b, 0xadfda1d2464c6433,
  //          0x610bf2c1435b3cf6, 0x8a0c6e4bc950e81f, 0x4296e7147ef94d7a,
  //          0x27d7ec90ba159756, 0x2a6c87932c3aef86, 0xbfd90c33e58a8fe3,
  //          0x1114f7672cf625c1, 0x1a7b72dd8ac39fab, 0xdb80f952e5fd2e5b,
  //          0x6b01c18a3daf288b, 0x69b4b0e4335f26d5, 0x0c059f365ec6d3d5,
  //          0xc22568276f1dcdd0);
  // VLOAD_64(v2, 0x6dc8e88769e54465, 0xce8cda83d16c3859, 0x1465ee5b6eb0d2b8,
  //          0x4827a9b40add2507, 0xd24c4005695a64d6, 0xb97c8e41e912f84a,
  //          0xc8c22e3b3b2e2fa1, 0x26712aa325bd00b6, 0xdf7ad19151df27b5,
  //          0x68ba6d050ffcba1e, 0x94448979a2b854e6, 0x84bf5d544f97f739,
  //          0x6d4bfa429e9d6ef0, 0xdb6c54b9a91ab935, 0x1a0051ca72162c5e,
  //          0xe04b73fdf1b61f9c);
  // VLOAD_64(v3, 0x32a4c1edbbfe5591, 0xf6baf4e747f4a120, 0x3a29727ae38b9b92,
  //          0xf173f78d09c997e4, 0xaab9d34e4aeaa57a, 0xa8fe3bf12b7c95e8,
  //          0xc4bd99b066821092, 0x9c2f1daf5fe2db9d, 0xa8b041a876aabcae,
  //          0xb9a2e6f9ded9a60a, 0x8bdf55954f50101d, 0x704f0e648c11d63f,
  //          0x0c8ca4d0a6d1a982, 0xa74d01c12ae6aea5, 0x3f2cd5d2e2f5b538,
  //          0x79803b24efa2caa3);
  // VLOAD_8(v0, 0xAA, 0xAA);
  // asm volatile("vmadd.vv v1, v2, v3, v0.t");
  // VCMP_U64(8, v1, 0x9cffef345b95f00b, 0xad447a1b99a48a53, 0xadfda1d2464c6433,
  //          0x813582af4d75d09e, 0x8a0c6e4bc950e81f, 0x36d90fe4df2f2b2c,
  //          0x27d7ec90ba159756, 0x955c2ac405b724e1, 0xbfd90c33e58a8fe3,
  //          0x10277404741c4ca8, 0x1a7b72dd8ac39fab, 0x58439c4175d7f582,
  //          0x6b01c18a3daf288b, 0xabfe86591f4ba5be, 0x0c059f365ec6d3d5,
  //          0xfb655e2263986563);
}

void TEST_CASE3() {
  VSET(16, e8, m1);
  int64_t scalar = 5;
  VLOAD_8(v1, 0x60, 0xe3, 0xa0, 0xb7, 0x35, 0x23, 0xa3, 0xf4, 0x5f, 0x6e, 0x07,
          0x01, 0xe7, 0x51, 0x53, 0x29);
  VLOAD_8(v2, 0xfb, 0x1b, 0xc0, 0x36, 0xa7, 0xe0, 0xc8, 0x47, 0x57, 0xe0, 0x51,
          0xaa, 0xd2, 0x93, 0x83, 0xa8);
  asm volatile("vmadd.vx v1, %[A], v2" ::[A] "r"(scalar));
  VCMP_U8(9, v1, 0xdb, 0x8a, 0xe0, 0xc9, 0xb0, 0x8f, 0xf7, 0x0b, 0x32, 0x06,
          0x74, 0xaf, 0x55, 0x28, 0x22, 0x75);

  VSET(16, e16, m1);
  scalar = -5383;
  VLOAD_16(v1, 0x992e, 0x9a07, 0x90c3, 0xf1ce, 0xd53c, 0x8f07, 0x2d2f, 0x5ab1,
           0x0a79, 0x0523, 0x6f34, 0xe5fd, 0xc95a, 0xca1c, 0x36bf, 0x16a1);
  VLOAD_16(v2, 0x0a9f, 0x7ee0, 0x494e, 0xb6d0, 0x394c, 0xc8e7, 0xc117, 0x8108,
           0xb1af, 0x9f16, 0x22ab, 0xa244, 0xf1c9, 0xe363, 0x9bed, 0xa06f);
  asm volatile("vmadd.vx v1, %[A], v2" ::[A] "r"(scalar));
  VCMP_U16(10, v1, 0x145d, 0xb5af, 0x54f9, 0x342e, 0x78a8, 0x4cb6, 0xa9ce,
           0x8131, 0x7b60, 0x9c21, 0xd43f, 0x9759, 0x0e53, 0x109f, 0x71b4,
           0xcd08);

  VSET(16, e32, m1);
  scalar = 6474219;
  VLOAD_32(v1, 0x709e784e, 0x8e13e48a, 0xad5df7fd, 0x738c8997, 0x0a0030d0,
           0x7569b952, 0x507fd5c7, 0x5d09af12, 0x0bf1c209, 0x7be6ed49,
           0x842ba667, 0x53360ec0, 0xd85d7415, 0xf20de61f, 0x153e7e16,
           0xec5512e4);
  VLOAD_32(v2, 0xb2436fad, 0x6b162382, 0xd94eebe7, 0x9c43d906, 0xb80f178d,
           0x5cf91d42, 0x7764b8a3, 0x6269f72c, 0xb0dff3a6, 0x838d6893,
           0xa98a861e, 0x758b63de, 0xde488617, 0x371696ab, 0xc3ba8192,
           0x7ca33236);
  asm volatile("vmadd.vx v1, %[A], v2" ::[A] "r"(scalar));
  VCMP_U32(11, v1, 0x8e0d1d47, 0xf29d4830, 0xb5213626, 0xb21bb5a3, 0xbc2f367d,
           0x18eb9d88, 0x91c53550, 0x69a6ceb2, 0xc09822e9, 0x66c98b96,
           0xf6b125ab, 0xef3fae1e, 0x4c40925e, 0x6b652c20, 0x998385c4,
           0x75d88d82);

  // VSET(16, e64, m1);
  // scalar = -598189234597999223;
  // VLOAD_64(v1, 0x2a47beb4fd7729c5, 0x401c187818b15d1e, 0xbbaf5fe50c41f22a,
  //          0x31eaddea171055a9, 0x609cbc4a78316c29, 0xd7bb8f31d8b59d88,
  //          0x97860fd5fba018c0, 0x724cecf178bd2125, 0x866d16f96d3d8b67,
  //          0x56153b0315164a5a, 0x6962bde49e3edf3f, 0x9b3f792bfbf5f343,
  //          0x64cf433b239e7764, 0x583c3a4ae481fef0, 0x217e2df75fcf0d8d,
  //          0x935ac02069fe54ce);
  // VLOAD_64(v2, 0x0dc8fa1b817237e5, 0xc817934370de904d, 0xb015bdbf0f39ec01,
  //          0x3c7e70a75643cce5, 0x80c45834a5026c02, 0xcdf1fcd83b8133a0,
  //          0x9d31b9b802ae2db1, 0xba7e57975c5febf5, 0x8732f75adf268ddb,
  //          0x5ff488a4187bd3f3, 0x6a259fe666091333, 0x5afc4de057de51c4,
  //          0x8a479b7e3558e399, 0xbc21e79022996c26, 0xe2c7432cd7e3e81d,
  //          0xdab377ddbdfb2df7);
  // asm volatile("vmadd.vx v1, %[A], v2" ::[A] "r"(scalar));
  // VCMP_U64(12, v1, 0x093861b79ac45352, 0xfd3c909decf66b5b, 0x04eb13132ce4267b,
  //          0xb258e6b065bbf956, 0x62775181e33422f3, 0xdc0ae0e371686968,
  //          0xf8db06270cad2c71, 0x6c3cc52cd1fb49c2, 0x41c19c0ac1b5a2fa,
  //          0x8867d35049c7b01d, 0x6d71fe0f35a1feea, 0xace16ac43ec0279f,
  //          0x82faf4a574c9dc1d, 0xa875c9d17e310a96, 0x1f75616001b61192,
  //          0x16ce205f44fb8635);
}

void TEST_CASE4() {
  VSET(16, e8, m1);
  int64_t scalar = 5;
  VLOAD_8(v1, 0x60, 0xe3, 0xa0, 0xb7, 0x35, 0x23, 0xa3, 0xf4, 0x5f, 0x6e, 0x07,
          0x01, 0xe7, 0x51, 0x53, 0x29);
  VLOAD_8(v2, 0xfb, 0x1b, 0xc0, 0x36, 0xa7, 0xe0, 0xc8, 0x47, 0x57, 0xe0, 0x51,
          0xaa, 0xd2, 0x93, 0x83, 0xa8);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vmadd.vx v1, %[A], v2, v0.t" ::[A] "r"(scalar));
  VCMP_U8(13, v1, 0x60, 0x8a, 0xa0, 0xc9, 0x35, 0x8f, 0xa3, 0x0b, 0x5f, 0x06,
          0x07, 0xaf, 0xe7, 0x28, 0x53, 0x75);

  VSET(16, e16, m1);
  scalar = -5383;
  VLOAD_16(v1, 0x992e, 0x9a07, 0x90c3, 0xf1ce, 0xd53c, 0x8f07, 0x2d2f, 0x5ab1,
           0x0a79, 0x0523, 0x6f34, 0xe5fd, 0xc95a, 0xca1c, 0x36bf, 0x16a1);
  VLOAD_16(v2, 0x0a9f, 0x7ee0, 0x494e, 0xb6d0, 0x394c, 0xc8e7, 0xc117, 0x8108,
           0xb1af, 0x9f16, 0x22ab, 0xa244, 0xf1c9, 0xe363, 0x9bed, 0xa06f);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vmadd.vx v1, %[A], v2, v0.t" ::[A] "r"(scalar));
  VCMP_U16(14, v1, 0x992e, 0xb5af, 0x90c3, 0x342e, 0xd53c, 0x4cb6, 0x2d2f,
           0x8131, 0x0a79, 0x9c21, 0x6f34, 0x9759, 0xc95a, 0x109f, 0x36bf,
           0xcd08);

  VSET(16, e32, m1);
  scalar = 6474219;
  VLOAD_32(v1, 0x709e784e, 0x8e13e48a, 0xad5df7fd, 0x738c8997, 0x0a0030d0,
           0x7569b952, 0x507fd5c7, 0x5d09af12, 0x0bf1c209, 0x7be6ed49,
           0x842ba667, 0x53360ec0, 0xd85d7415, 0xf20de61f, 0x153e7e16,
           0xec5512e4);
  VLOAD_32(v2, 0xb2436fad, 0x6b162382, 0xd94eebe7, 0x9c43d906, 0xb80f178d,
           0x5cf91d42, 0x7764b8a3, 0x6269f72c, 0xb0dff3a6, 0x838d6893,
           0xa98a861e, 0x758b63de, 0xde488617, 0x371696ab, 0xc3ba8192,
           0x7ca33236);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vmadd.vx v1, %[A], v2, v0.t" ::[A] "r"(scalar));
  VCMP_U32(15, v1, 0x709e784e, 0xf29d4830, 0xad5df7fd, 0xb21bb5a3, 0x0a0030d0,
           0x18eb9d88, 0x507fd5c7, 0x69a6ceb2, 0x0bf1c209, 0x66c98b96,
           0x842ba667, 0xef3fae1e, 0xd85d7415, 0x6b652c20, 0x153e7e16,
           0x75d88d82);

  // VSET(16, e64, m1);
  // scalar = -598189234597999223;
  // VLOAD_64(v1, 0x2a47beb4fd7729c5, 0x401c187818b15d1e, 0xbbaf5fe50c41f22a,
  //          0x31eaddea171055a9, 0x609cbc4a78316c29, 0xd7bb8f31d8b59d88,
  //          0x97860fd5fba018c0, 0x724cecf178bd2125, 0x866d16f96d3d8b67,
  //          0x56153b0315164a5a, 0x6962bde49e3edf3f, 0x9b3f792bfbf5f343,
  //          0x64cf433b239e7764, 0x583c3a4ae481fef0, 0x217e2df75fcf0d8d,
  //          0x935ac02069fe54ce);
  // VLOAD_64(v2, 0x0dc8fa1b817237e5, 0xc817934370de904d, 0xb015bdbf0f39ec01,
  //          0x3c7e70a75643cce5, 0x80c45834a5026c02, 0xcdf1fcd83b8133a0,
  //          0x9d31b9b802ae2db1, 0xba7e57975c5febf5, 0x8732f75adf268ddb,
  //          0x5ff488a4187bd3f3, 0x6a259fe666091333, 0x5afc4de057de51c4,
  //          0x8a479b7e3558e399, 0xbc21e79022996c26, 0xe2c7432cd7e3e81d,
  //          0xdab377ddbdfb2df7);
  // VLOAD_8(v0, 0xAA, 0xAA);
  // asm volatile("vmadd.vx v1, %[A], v2, v0.t" ::[A] "r"(scalar));
  // VCMP_U64(16, v1, 0x2a47beb4fd7729c5, 0xfd3c909decf66b5b, 0xbbaf5fe50c41f22a,
  //          0xb258e6b065bbf956, 0x609cbc4a78316c29, 0xdc0ae0e371686968,
  //          0x97860fd5fba018c0, 0x6c3cc52cd1fb49c2, 0x866d16f96d3d8b67,
  //          0x8867d35049c7b01d, 0x6962bde49e3edf3f, 0xace16ac43ec0279f,
  //          0x64cf433b239e7764, 0xa875c9d17e310a96, 0x217e2df75fcf0d8d,
  //          0x16ce205f44fb8635);
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

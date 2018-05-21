/*
  matmul_kernels_avx.h

  AVX2 Matrix multiplication implementations: R = A x B

  A: n x m
  B: m x p
  R: n x p
*/

#ifndef MATMUL_AVX_KERNELS_H_INCLUDED
#define MATMUL_AVX_KERNELS_H_INCLUDED

// IKJ version with a minimal optimization effort
void matmul_ikj_avx(const basetype arrayA[], const basetype arrayB[],
                    basetype arrayR[], const unsigned int nrowsA,
                    const unsigned int mcolsA, const unsigned int pcolsB);

#endif

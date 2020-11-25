/*
  matmul_kernels_avx.c

  AVX2 Matrix multiplication implementations: R = A x B

  A: n x m
  B: m x p
  R: n x p
*/

#include <immintrin.h>
#include "stuff.h"


/*
  IKJ version with a minimal optimization effort
*/
void matmul_ikj_avx(const basetype arrayA[], const basetype arrayB[],
                    basetype arrayR[], const unsigned int nrowsA,
                    const unsigned int mcolsA, const unsigned int pcolsB)
{
  unsigned int i, j, k, l;

  __m256 ymm0, ymm1, ymm2, ymm3, ymm4, ymm5, ymm6, ymm7,
    ymm8, ymm9, ymm10, ymm11, ymm12, ymm13, ymm14, ymm15;

  __m256i idx[8] = { _mm256_setzero_si256(), _mm256_set1_epi8(1), _mm256_set1_epi8(2), _mm256_set1_epi8(3), _mm256_set1_epi8(4), _mm256_set1_epi8(5), _mm256_set1_epi8(6), _mm256_set1_epi8(7) };

  const basetype *A = arrayA;
  basetype *rowR = arrayR;

  for(i = 0; i < nrowsA; i++) {
    const basetype *B = arrayB;

    for(k = 0; k < mcolsA; k += 8) {
      ymm0 = _mm256_load_ps(A);

      for(l = 0; l < 8; l++) {
        basetype *R = rowR;
        ymm1 = _mm256_permutevar8x32_ps(ymm0, idx[l]);

        for(j = 0; j < pcolsB; j += 56) {
          // arrayR[i*mcolsA+j] += arrayA[i*mcolsA+k] * arrayB[k*pcolsB+j];
          ymm2 = _mm256_load_ps(&B[0]);
          ymm3 = _mm256_load_ps(&B[8]);
          ymm4 = _mm256_load_ps(&B[16]);
          ymm5 = _mm256_load_ps(&B[24]);
          ymm6 = _mm256_load_ps(&B[32]);
          ymm7 = _mm256_load_ps(&B[40]);
          ymm8 = _mm256_load_ps(&B[48]);

          ymm9 = _mm256_load_ps(&R[0]);
          ymm10 = _mm256_load_ps(&R[8]);
          ymm11 = _mm256_load_ps(&R[16]);
          ymm12 = _mm256_load_ps(&R[24]);
          ymm13 = _mm256_load_ps(&R[32]);
          ymm14 = _mm256_load_ps(&R[40]);
          ymm15 = _mm256_load_ps(&R[48]);

          ymm9 = _mm256_fmadd_ps(ymm1, ymm2, ymm9);
          ymm10 = _mm256_fmadd_ps(ymm1, ymm3, ymm10);
          ymm11 = _mm256_fmadd_ps(ymm1, ymm4, ymm11);
          ymm12 = _mm256_fmadd_ps(ymm1, ymm5, ymm12);
          ymm13 = _mm256_fmadd_ps(ymm1, ymm6, ymm13);
          ymm14 = _mm256_fmadd_ps(ymm1, ymm7, ymm14);
          ymm15 = _mm256_fmadd_ps(ymm1, ymm8, ymm15);

          _mm256_store_ps(&R[0], ymm9);
          _mm256_store_ps(&R[8], ymm10);
          _mm256_store_ps(&R[16], ymm11);
          _mm256_store_ps(&R[24], ymm12);
          _mm256_store_ps(&R[32], ymm13);
          _mm256_store_ps(&R[40], ymm14);
          _mm256_store_ps(&R[48], ymm15);

          B += 56;
          R += 56;
        }
      }

      A += 8;
    }
    rowR += pcolsB;
  }
}

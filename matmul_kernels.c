/*
  matmul_kernels.c

  Matrix multiplication implementations: R = A x B

  A: n x m
  B: m x p
  R: n x p
*/

#include "stuff.h"

/*
  Naive version: just an ijk easier for programmer
*/
void matmul(const basetype arrayA[], const basetype arrayB[],
            basetype arrayR[], const unsigned int nrowsA,
            const unsigned int mcolsA, const unsigned int pcolsB)
{
  unsigned int i, j, k;

  for(i = 0; i < nrowsA; i++)
    for(j = 0; j < pcolsB; j++)
      for(k = 0; k < mcolsA; k++)
        arrayR[i*mcolsA+j] += arrayA[i*mcolsA+k] * arrayB[k*pcolsB+j];
}


/*
  IJK version with a minimal optimization effort
*/
void matmul_opt(const basetype arrayA[], const basetype arrayB[],
                basetype arrayR[], const unsigned int nrowsA,
                const unsigned int mcolsA, const unsigned int pcolsB)
{
  unsigned int i, j, k;
  basetype *R = arrayR;
  const basetype *A = arrayA;

  for(i = 0; i < nrowsA; i++) {

    for(j = 0; j < pcolsB; j++) {
      const basetype *B = arrayB + j;
      basetype result = 0;

      for(k = 0; k < mcolsA; k++) {
        result += A[k] * *B;

        B += pcolsB;
      }

      R[j] = result;
    }

    A += mcolsA;
    R += mcolsA;
  }
}


/*
  IKJ version: j in inner loop improves cache access
*/
void matmul_ikj(const basetype arrayA[], const basetype arrayB[],
                basetype arrayR[], const unsigned int nrowsA,
                const unsigned int mcolsA, const unsigned int pcolsB)
{
  unsigned int i, j, k;

  for(i = 0; i < nrowsA; i++)
    for(k = 0; k < mcolsA; k++)
      for(j = 0; j < pcolsB; j++)
        arrayR[i*mcolsA+j] += arrayA[i*mcolsA+k] * arrayB[k*pcolsB+j];
}


/*
  IKJ version with a minimal optimization effort
*/
void matmul_ikj_opt(const basetype arrayA[], const basetype arrayB[],
                    basetype arrayR[], const unsigned int nrowsA,
                    const unsigned int mcolsA, const unsigned int pcolsB)
{
  unsigned int i, j, k;
  basetype *R = arrayR;
  const basetype *A = arrayA;

  for(i = 0; i < nrowsA; i++) {
    const basetype *B = arrayB;

    for(k = 0; k < mcolsA; k++) {

      for(j = 0; j < pcolsB; j++)
        R[j] += A[k] * B[j];

      B += pcolsB;
    }

    A += mcolsA;
    R += mcolsA;
  }
}


/*
  Classic ijk tiling version

  Tiling_block in B: rowsBLK x colsBLK
*/
void matmul_tiling(const basetype arrayA[], const basetype arrayB[],
                   basetype arrayR[], const unsigned int nrowsA,
                   const unsigned int mcolsA, const unsigned int pcolsB,
                   const unsigned int rowsBLK, const unsigned int colsBLK)
{
  unsigned int i, j, k, jj, kk;

  for (jj = 0; jj < pcolsB; jj += colsBLK)
    for (kk = 0; kk < mcolsA; kk += rowsBLK)
      for(i = 0; i < nrowsA; i++)
        for(j = jj; j < min(jj+colsBLK, pcolsB); j++)
          for(k = kk; k < min(kk+rowsBLK, mcolsA); k++)
            arrayR[i*mcolsA+j] += arrayA[i*mcolsA+k] * arrayB[k*pcolsB+j];
}


/*
  Classic ijk tiling version with a minimal optimization effort

  tiling_block in B: rowsBLK x colsBLK
*/
void matmul_tiling_opt(const basetype arrayA[], const basetype arrayB[],
                       basetype arrayR[], const unsigned int nrowsA,
                       const unsigned int mcolsA, const unsigned int pcolsB,
                       const unsigned int rowsBLK, const unsigned int colsBLK)
{
  unsigned int i, j, k, jj, kk, limj, limk;

  for (jj = 0; jj < pcolsB; jj += colsBLK) {
    limj = min(jj+colsBLK, pcolsB);

    for (kk = 0; kk < mcolsA; kk += rowsBLK) {
      limk = min(kk+rowsBLK, mcolsA);

      for(i = 0; i < nrowsA; i++)
        for(j = jj; j < limj; j++) {
          basetype result = (basetype) 0;

          for(k = kk; k < limk; k++)
            result += arrayA[i*mcolsA+k] * arrayB[k*pcolsB+j];

          arrayR[i*mcolsA+j] += result;
        }
    }
  }
}


/*
  ikj tiling version

  Tiling_block in B: rowsBLK x colsBLK
*/
void matmul_tiling_ikj(const basetype arrayA[], const basetype arrayB[],
                       basetype arrayR[], const unsigned int nrowsA,
                       const unsigned int mcolsA, const unsigned int pcolsB,
                       const unsigned int rowsBLK, const unsigned int colsBLK)
{
  unsigned int i, j, k, jj, kk;

  for (jj = 0; jj < pcolsB; jj += colsBLK)
    for (kk = 0; kk < mcolsA; kk += rowsBLK)
      for(i = 0; i < nrowsA; i++)
        for(k = kk; k < min(kk+rowsBLK, mcolsA); k++)
          for(j = jj; j < min(jj+colsBLK, pcolsB); j++)
            arrayR[i*mcolsA+j] += arrayA[i*mcolsA+k] * arrayB[k*pcolsB+j];
}


/*
  ikj tiling version with a minimal optimization effort

  tiling_block in B: rowsBLK x colsBLK
*/
void matmul_tiling_ikj_opt(const basetype arrayA[], const basetype arrayB[],
                           basetype arrayR[], const unsigned int nrowsA,
                           const unsigned int mcolsA, const unsigned int pcolsB,
                           const unsigned int rowsBLK, const unsigned int colsBLK)
{
  unsigned int i, j, k, jj, kk, limj, limk;

  for (jj = 0; jj < pcolsB; jj += colsBLK) {
    limj = min(jj+colsBLK, pcolsB);

    for (kk = 0; kk < mcolsA; kk += rowsBLK) {
      limk = min(kk+rowsBLK, mcolsA);

      for(i = 0; i < nrowsA; i++)
        for(k = kk; k < limk; k++)
          for(j = jj; j < limj; j++)
            arrayR[i*mcolsA+j] += arrayA[i*mcolsA+k] * arrayB[k*pcolsB+j];
    }
  }
}


/*
  ikj tiling version with a medium optimization effort

  tiling_block in B: rowsBLK x colsBLK
*/
void matmul_tiling_ikj_opt2(const basetype arrayA[], const basetype arrayB[],
                            basetype arrayR[], const unsigned int nrowsA,
                            const unsigned int mcolsA, const unsigned int pcolsB,
                            const unsigned int rowsBLK, const unsigned int colsBLK)
{
  unsigned int i, j, k, jj, kk, limj, limk;

  for (jj = 0; jj < pcolsB; jj += colsBLK) {
    limj = min(jj+colsBLK, pcolsB);

    for (kk = 0; kk < mcolsA; kk += rowsBLK) {
      limk = min(kk+rowsBLK, mcolsA);

      const basetype *A = arrayA;
      basetype *R = arrayR;

      for(i = 0; i < nrowsA; i++) {
        for(k = kk; k < limk; k++) {
          const basetype *B = arrayB + k*pcolsB;

          for(j = jj; j < limj; j++)
            R[j] += A[k] * B[j];
          B += pcolsB;
        }
        A += mcolsA;
        R += mcolsA;
      }
    }
  }
}

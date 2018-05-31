/*
  matmul_kernels.h

  Matrix multiplication implementations: R = A x B

  A: n x m
  B: m x p
  R: n x p
*/

#ifndef MATMUL_KERNELS_H_INCLUDED
#define MATMUL_KERNELS_H_INCLUDED

//  Naive version: just an ijk easier for programmer
void matmul(const basetype arrayA[], const basetype arrayB[],
            basetype arrayR[], const unsigned int nrowsA,
            const unsigned int mcolsA, const unsigned int pcolsB);

// IJK version with a minimal optimization effort
void matmul_opt(const basetype arrayA[], const basetype arrayB[],
                basetype arrayR[], const unsigned int nrowsA,
                const unsigned int mcolsA, const unsigned int pcolsB);

// IKJ version: j in inner loop improves cache access
void matmul_ikj(const basetype arrayA[], const basetype arrayB[],
                basetype arrayR[], const unsigned int nrowsA,
                const unsigned int mcolsA, const unsigned int pcolsB);

// IKJ version with a minimal optimization effort
void matmul_ikj_opt(const basetype arrayA[], const basetype arrayB[],
                    basetype arrayR[], const unsigned int nrowsA,
                    const unsigned int mcolsA, const unsigned int pcolsB);

// Classic ijk tiling version
void matmul_tiling(const basetype arrayA[], const basetype arrayB[],
                   basetype arrayR[], const unsigned int nrowsA,
                   const unsigned int mcolsA, const unsigned int pcolsB,
                   const unsigned int rowsBLK, const unsigned int colsBLK);

// Classic ijk tiling version with a minimal optimization effort
void matmul_tiling_opt(const basetype arrayA[], const basetype arrayB[],
                       basetype arrayR[], const unsigned int nrowsA,
                       const unsigned int mcolsA, const unsigned int pcolsB,
                       const unsigned int rowsBLK, const unsigned int colsBLK);

// Classic ijk tiling version with a medium optimization effort
void matmul_tiling_opt2(const basetype arrayA[], const basetype arrayB[],
                        basetype arrayR[], const unsigned int nrowsA,
                        const unsigned int mcolsA, const unsigned int pcolsB,
                        const unsigned int rowsBLK, const unsigned int colsBLK);

// ikj tiling version
void matmul_tiling_ikj(const basetype arrayA[], const basetype arrayB[],
                       basetype arrayR[], const unsigned int nrowsA,
                       const unsigned int mcolsA, const unsigned int pcolsB,
                       const unsigned int rowsBLK, const unsigned int colsBLK);

// ikj tiling version with a minimal optimization effort
void matmul_tiling_ikj_opt(const basetype arrayA[], const basetype arrayB[],
                           basetype arrayR[], const unsigned int nrowsA,
                           const unsigned int mcolsA, const unsigned int pcolsB,
                           const unsigned int rowsBLK, const unsigned int colsBLK);

//  ikj tiling version with a medium optimization effort
void matmul_tiling_ikj_opt2(const basetype arrayA[], const basetype arrayB[],
                            basetype arrayR[], const unsigned int nrowsA,
                            const unsigned int mcolsA, const unsigned int pcolsB,
                            const unsigned int rowsBLK, const unsigned int colsBLK);

#endif

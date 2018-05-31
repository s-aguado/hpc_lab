#include <stdio.h>
#include "stuff.h"
#include "matmul_kernels.h"
#include "matmul_kernels_avx.h"

const int N = 1000; // Default elements per row and col: NxN matrix
const int BLK = 16;

int main(int argc, char *argv[])
{
  resnfo start, end;
  timenfo time;

  // Parameters

  // 0: Elements per row and per column (default: N)
  unsigned int n = (argc > 1)?atoi (argv[1]):N;

  // 1: Tiling: elements per row and per column in block (default: BLK)
  unsigned int blk = (argc > 2)?atoi (argv[2]):BLK;

  adjust_params(&n);

  // Matrices size
  unsigned int numBytes = n * n * sizeof(basetype);


  // Allocate and init matrices (32-byte aligned addresses for AVX2)
  timestamp(&start);
  // basetype *vectorA = (basetype *) malloc(numBytes);
  // basetype *vectorB = (basetype *) malloc(numBytes);
  // basetype *vectorR = (basetype *) malloc(numBytes);
  basetype *vectorA = (basetype *) _mm_malloc (numBytes, 32);
  basetype *vectorB = (basetype *) _mm_malloc (numBytes, 32);
  basetype *vectorR = (basetype *) _mm_malloc (numBytes, 32);
  populating_arrays(vectorA, vectorB, vectorR, n*n);
  timestamp(&end);

  get_walltime(start, end, &time);
  printtime(time);
  printf(" -> Matrices allocation and initialiation (%ux%u %s)\n\n", n, n, labelelem);


  // Naive ijk version
  timestamp(&start);
  matmul(vectorA, vectorB, vectorR, n, n, n);
  timestamp(&end);

  get_walltime(start, end, &time);
  printtime(time);
  printf(" -> Matrix product: naive ijk implementation\n");

  //  reset_matrix(vectorR, n*n);
  basetype check = check_result_and_reset(vectorR, n*n);
  printf("%29s", "Check: "); printdata(check); printf("\n\n");

  // ijk opt version
  timestamp(&start);
  matmul_opt(vectorA, vectorB, vectorR, n, n, n);
  timestamp(&end);

  get_walltime(start, end, &time);
  printtime(time);
  printf(" -> Matrix product: ijk opt implementation\n\n");

  //  reset_matrix(vectorR, n*n);
  check = check_result_and_reset(vectorR, n*n);
  printf("%29s", "Check: "); printdata(check); printf("\n\n");


  // ikj version
  timestamp(&start);
  matmul_ikj(vectorA, vectorB, vectorR, n, n, n);
  timestamp(&end);

  get_walltime(start, end, &time);
  printtime(time);
  printf(" -> Matrix product: ikj implementation\n\n");

  //  reset_matrix(vectorR, n*n);
  check = check_result_and_reset(vectorR, n*n);
  printf("%29s", "Check: "); printdata(check); printf("\n\n");


  // ikj opt version
  timestamp(&start);
  matmul_ikj_opt(vectorA, vectorB, vectorR, n, n, n);
  timestamp(&end);

  get_walltime(start, end, &time);
  printtime(time);
  printf(" -> Matrix product: ikj opt implementation\n\n");

  //  reset_matrix(vectorR, n*n);
  check = check_result_and_reset(vectorR, n*n);
  printf("%29s", "Check: "); printdata(check); printf("\n\n");


  // Tiling version
  timestamp(&start);
  matmul_tiling(vectorA, vectorB, vectorR, n, n, n, blk, blk);
  timestamp(&end);

  get_walltime(start, end, &time);
  printtime(time);
  printf(" -> Matrix product: tiling approach (blk: %dx%d)\n\n", blk, blk);

  //  reset_matrix(vectorR, n*n);
  check = check_result_and_reset(vectorR, n*n);
  printf("%29s", "Check: "); printdata(check); printf("\n\n");


  // Tiling version with additional opt
  timestamp(&start);
  matmul_tiling_opt(vectorA, vectorB, vectorR, n, n, n, blk, blk);
  timestamp(&end);

  get_walltime(start, end, &time);
  printtime(time);
  printf(" -> Matrix product: tiling approach with opt\n\n");

  //  reset_matrix(vectorR, n*n);
  check = check_result_and_reset(vectorR, n*n);
  printf("%29s", "Check: "); printdata(check); printf("\n\n");


  // Tiling version with additional opts
  timestamp(&start);
  matmul_tiling_opt2(vectorA, vectorB, vectorR, n, n, n, blk, blk);
  timestamp(&end);

  get_walltime(start, end, &time);
  printtime(time);
  printf(" -> Matrix product: tiling approach with additional opts\n\n");

  //  reset_matrix(vectorR, n*n);
  check = check_result_and_reset(vectorR, n*n);
  printf("%29s", "Check: "); printdata(check); printf("\n\n");


  // Tiling+ikj version
  timestamp(&start);
  matmul_tiling_ikj(vectorA, vectorB, vectorR, n, n, n, blk, blk);
  timestamp(&end);

  get_walltime(start, end, &time);
  printtime(time);
  printf(" -> Matrix product: tiling+ikj approach\n\n");

  //  reset_matrix(vectorR, n*n);
  check = check_result_and_reset(vectorR, n*n);
  printf("%29s", "Check: "); printdata(check); printf("\n\n");


  // Tiling+ikj with a minimal optimization effort
  timestamp(&start);
  matmul_tiling_ikj_opt(vectorA, vectorB, vectorR, n, n, n, blk, blk);
  timestamp(&end);

  get_walltime(start, end, &time);
  printtime(time);
  printf(" -> Matrix product: tiling+ikj approach with min opts\n\n");

  //  reset_matrix(vectorR, n*n);
  check = check_result_and_reset(vectorR, n*n);
  printf("%29s", "Check: "); printdata(check); printf("\n\n");


  // Tiling+ikj with a medium optimization effort
  timestamp(&start);
  matmul_tiling_ikj_opt2(vectorA, vectorB, vectorR, n, n, n, blk, blk);
  timestamp(&end);

  get_walltime(start, end, &time);
  printtime(time);
  printf(" -> Matrix product: tiling+ikj approach with med opts\n\n");

  //  reset_matrix(vectorR, n*n);
  check = check_result_and_reset(vectorR, n*n);
  printf("%29s", "Check: "); printdata(check); printf("\n\n");


  // ikj AVX version
  timestamp(&start);
  matmul_ikj_avx(vectorA, vectorB, vectorR, n, n, n);
  timestamp(&end);

  get_walltime(start, end, &time);
  printtime(time);
  printf(" -> Matrix product: ikj AVX implementation\n\n");

  //  reset_matrix(vectorR, n*n);
  check = check_result_and_reset(vectorR, n*n);
  printf("%29s", "Check: "); printdata(check); printf("\n\n");

  // free(vectorA);
  // free(vectorB);
  // free(vectorR);
  _mm_free(vectorA);
  _mm_free(vectorB);
  _mm_free(vectorR);

  return(0);
}

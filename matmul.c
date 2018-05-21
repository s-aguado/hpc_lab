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

  // Matrices size
  unsigned int numBytes = n * n * sizeof(basetype);


  // Allocate and init matrices
  timestamp(&start);
  basetype *vectorA = (basetype *) malloc(numBytes);
  basetype *vectorB = (basetype *) malloc(numBytes);
  basetype *vectorR = (basetype *) malloc(numBytes);
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
  printf(" -> Matrix product: naive ijk implementation\n\n");

  reset_matrix(vectorR, n*n);


  // ijk opt version
  timestamp(&start);
  matmul_opt(vectorA, vectorB, vectorR, n, n, n);
  timestamp(&end);

  get_walltime(start, end, &time);
  printtime(time);
  printf(" -> Matrix product: ijk opt implementation\n\n");

  reset_matrix(vectorR, n*n);


  // ikj version
  timestamp(&start);
  matmul_ikj(vectorA, vectorB, vectorR, n, n, n);
  timestamp(&end);

  get_walltime(start, end, &time);
  printtime(time);
  printf(" -> Matrix product: ikj implementation\n\n");

  reset_matrix(vectorR, n*n);


  // ikj opt version
  timestamp(&start);
  matmul_ikj_opt(vectorA, vectorB, vectorR, n, n, n);
  timestamp(&end);

  get_walltime(start, end, &time);
  printtime(time);
  printf(" -> Matrix product: ikj opt implementation\n\n");

  reset_matrix(vectorR, n*n);


  // Tailing version
  timestamp(&start);
  matmul_tiling(vectorA, vectorB, vectorR, n, n, n, blk, blk);
  timestamp(&end);

  get_walltime(start, end, &time);
  printtime(time);
  printf(" -> Matrix product: tailing approach (blk: %dx%d)\n\n", blk, blk);

  reset_matrix(vectorR, n*n);


  // Tailing version with additional opt
  timestamp(&start);
  matmul_tiling_opt(vectorA, vectorB, vectorR, n, n, n, blk, blk);
  timestamp(&end);

  get_walltime(start, end, &time);
  printtime(time);
  printf(" -> Matrix product: tailing approach with opt\n\n");

  reset_matrix(vectorR, n*n);

  // Tailing+ikj version
  timestamp(&start);
  matmul_tiling_ikj(vectorA, vectorB, vectorR, n, n, n, blk, blk);
  timestamp(&end);

  get_walltime(start, end, &time);
  printtime(time);
  printf(" -> Matrix product: tailing+ikj approach\n\n");

  reset_matrix(vectorR, n*n);


  // Tailing+ikj with a minimal optimization effort
  timestamp(&start);
  matmul_tiling_ikj_opt(vectorA, vectorB, vectorR, n, n, n, blk, blk);
  timestamp(&end);

  get_walltime(start, end, &time);
  printtime(time);
  printf(" -> Matrix product: tailing+ikj approach with min opts\n\n");

  reset_matrix(vectorR, n*n);


  // Tailing+ikj with a medium optimization effort
  timestamp(&start);
  matmul_tiling_ikj_opt2(vectorA, vectorB, vectorR, n, n, n, blk, blk);
  timestamp(&end);

  get_walltime(start, end, &time);
  printtime(time);
  printf(" -> Matrix product: tailing+ikj approach with med opts\n\n");

  reset_matrix(vectorR, n*n);


  // ikj AVX version
  timestamp(&start);
  matmul_ikj_avx(vectorA, vectorB, vectorR, n, n, n);
  timestamp(&end);

  get_walltime(start, end, &time);
  printtime(time);
  printf(" -> Matrix product: ikj AVX implementation\n\n");


  free(vectorA);
  free(vectorB);
  free(vectorR);

  return(0);
}

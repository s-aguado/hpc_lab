#include <math.h>
#include "stuff.h"

void get_walltime(const resnfo start, const resnfo end, timenfo *const t)
{
#ifdef _noWALL_
  t->time = (end.ru_utime.tv_sec + (end.ru_utime.tv_usec * 1E-6))
    - (start.ru_utime.tv_sec + (start.ru_utime.tv_usec * 1E-6));
  t->systime = (end.ru_stime.tv_sec + (end.ru_stime.tv_usec * 1E-6))
    - (start.ru_stime.tv_sec + (start.ru_stime.tv_usec * 1E-6));
#else
  *t = (end.tv_sec + (end.tv_usec * 1E-6))
    - (start.tv_sec + (start.tv_usec * 1E-6));
#endif /*_noWALL_*/
}

void populating_arrays(basetype arrayA[], basetype arrayB[],
                       basetype arrayR[], const unsigned int n)
{
  unsigned int i;

  srand(time(NULL));

  for(i = 0; i < n; i++) {
#ifdef _INT_
    arrayA[i] = rand();
    arrayB[i] = rand();
    arrayR[i] = 0;
#else
    arrayA[i] = rand() / (RAND_MAX + 1.);
    arrayB[i] = rand() / (RAND_MAX + 1.);
    arrayR[i] = 0.0;
#endif
  }
}


basetype check_result_and_reset(basetype array[], const unsigned int n)
{
  unsigned int i;
  basetype result = 0;

  for(i = 0; i < n; i++) {
    result += array[i];
    array[i] = (basetype) 0;
  }

  return(result);
}


void reset_matrix(basetype array[], const unsigned int n)
{
  memset(array, 0, n);
}


// Impose some constraints to simplify code
void adjust_params(unsigned int *n)
{
  // AVX-2 constraint: to simplify the code we'll work
  // with n being a multiple of 56, since we're using
  // 7x8=56 32-bit elements in AVX registers
  unsigned int newn = (unsigned int) ceilf(*n / 56);

  *n = newn * 56;
}

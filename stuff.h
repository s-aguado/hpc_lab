#ifndef STUFF_H_INCLUDED
#define STUFF_H_INCLUDED

#include <stdlib.h>
#include <time.h>
#include <string.h>

// Datatype to work with
#ifdef _INT_
typedef int basetype;
#define labelelem    "ints"
#elif _DOUBLE_
typedef double basetype;
#define labelelem    "doubles"
#else
typedef float basetype;       // DEFAULT
#define labelelem    "floats"
#endif

#define min(a,b)                \
  ({ __typeof__ (a) _a = (a);   \
    __typeof__ (b) _b = (b);    \
    _a < _b ? _a : _b; })
#define max(a,b)                \
  ({ __typeof__ (a) _a = (a);   \
    __typeof__ (b) _b = (b);    \
    _a > _b ? _a : _b; })

/*
   Measuring the wall time

   resnfo: tipo de dato definido para abstraer la métrica de recursos a usar
   timenfo: tipo de dato definido para abstraer la métrica de tiempo a usar

   timestamp: abstrae función usada para tomar las muestras del tiempo transcurrido

   printtime: abstrae función usada para imprimir el tiempo transcurrido

   void myElapsedtime(resnfo start, resnfo end, timenfo *t): función para obtener
   el tiempo transcurrido entre dos medidas
*/

#include <sys/time.h>
#include <sys/resource.h>

#ifdef _noWALL_
typedef struct rusage resnfo;
typedef struct _timenfo {
  double time;
  double systime;
} timenfo;
#define timestamp(sample) getrusage(RUSAGE_SELF, (sample))
#define printtime(t) printf("%15f s (%f user + %f sys) ",               \
                            t.time + t.systime, t.time, t.systime);
#else
typedef struct timeval resnfo;
typedef double timenfo;
#define timestamp(sample)     gettimeofday((sample), 0)
#define printtime(t) printf("%15f s ", t);
#endif

void get_walltime(const resnfo start, const resnfo end, timenfo *const t);
void populating_arrays(basetype arrayA[], basetype arrayB[], basetype arrayR[], const unsigned int n);
basetype check_result_and_reset(basetype array[], const unsigned int n);
void reset_matrix(basetype array[], const unsigned int n);

#endif

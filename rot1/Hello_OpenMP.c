#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
 
 int main (int argc, char *argv[]) {
   int th_id, nthreads, nprocs;

   omp_set_num_threads(2); // disparar 4 threads pois se trata de uma m�quina Quad-Core
   
    //OMP_NUM_THREADS=2;

   #pragma omp parallel private(th_id, nthreads) num_threads(2)
   {
     th_id = omp_get_thread_num();
	 nthreads = omp_get_num_threads();
     nprocs = omp_get_num_procs();

     printf("Hello World from thread %d of %d threads. Number of cores: %d \n", th_id, nthreads, nprocs);
   }

   getchar();
   return EXIT_SUCCESS;
 }


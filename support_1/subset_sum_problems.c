//
// AED, October-November 2017
//
// STUDENT NAME
// STUDENT NAME
// ...
//
// Solution of the subset sum problems
//
// Compile with the command "cc -Wall -O2 -march=native subset_sum_problems.c -lm"
//

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>

#include "subset_sum_problems.h"


//
// Measure elapsed time (on GNU/Linux)
//

double elapsed_time(void)
{
  static struct timespec last_time,current_time;

  last_time = current_time;
  if(clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&current_time) != 0)  // the first argument could also be CLOCK_REALTIME
    return -1.0; // clock_gettime() failed!!!
  return ((double)current_time.tv_sec - (double)last_time.tv_sec) +
         1.0e-9 * ((double)current_time.tv_nsec - (double)last_time.tv_nsec);
}


//
// solve all instances for a given n
//

void solve_using_xpto_strategy(subset_sum_problem_t *problem)
{
  int b[max_n]; // the solution
  double dt;
  int i,j;
  u64 sum;

  printf("solutions for n = %d\n",problem->n);
  //
  // pre-processing (optional)
  //
  (void)elapsed_time();
  ...
  dt = elapsed_time();
  printf("  preprocessing done in %.03fs\n",dt);
  ...
  //
  // Solve all problems for the value of n; place the solution in the array b[i] 
  //
  for(i = 0;i < n_sums;i++)
  {
    (void)elapsed_time();
    ...
    dt = elapsed_time();
    sum = 0ull;
    for(j = 0;j < problem->n;j++)
      if(b[j] != 0)
        sum += problem->a[j];
    assert(sum == problem->sums[i]);
    printf("  solved [");
    for(j = problem->n - 1;j >= 0;j--)
      printf("%d",b[j]);
    printf("] in %.03fs\n",dt);
  }
  //
  // cleanup code (optional)
  //
  ...
}


//
// main program
//

int main(void)
{
  int i;

  for(i = 0;i < n_problems;i++)
    solve_using_the_xpto_strategy(&subset_sum_problems[i]);
  return 0;
}

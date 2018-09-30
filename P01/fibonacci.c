//
// Tomás Oliveira e Silva, AED, September 2017
//
// computation of Fibonacci numbers
//

#include <math.h>
#include <stdio.h>
#include <assert.h>

#include "elapsed_time.h"


typedef long long s64; // 64-bit signed integer


//
// Four implementations
//

s64 F_v1(s64 n)
{
  assert(n >= (s64)0);
  return (n < (s64)2) ? n : F_v1(n - (s64)1) + F_v1(n - (s64)2);
}

s64 F_v2(s64 n)
{
  static s64 Fv[101] = { (s64)0,(s64)1 };/* Guarda todos valores anteriores num array  */

  assert(n >= (s64)0 && n <= (s64)100);
  if(n > (s64)1 && Fv[n] == (s64)0)
    Fv[n] = F_v2(n - (s64)1) + F_v2(n - (s64)2);
  return Fv[n];
}

s64 F_v3(s64 n)/* Guarda os ultimos 2 valores  num array  */
{
  s64 a,b,c;

  assert(n >= (s64)0);
  if(n < (s64)2)
    return n;
  for(a = (s64)0,b = (s64)1;n > (s64)1;n--)
  {
    c = a + b;
    a = b;
    b = c;
  }
  return b;
}

s64 F_v4(s64 n)/* Usa a funçao matemática */
{
  const double c1 = 0.44721359549995793928;
  const double c2 = 0.48121182505960344750;

  assert(n >= (s64)0);
  return (s64)round(c1 * exp((double)n * c2));
}


//
// main program
//

int main(void)
{
  double dt1 = 0.0,dt2 = 0.0,dt3 = 0.0,dt4 = 0.0;
  s64 n,f;
  FILE *fd;
  fd=fopen("Output.csv","w");
  fprintf(fd,"%-7s;%-7s;%-7s;%-7s;%-7s\n","n","F_V1","F_V2","F_V3","FV4");
  printf("  n v                   Fn         time\n");
  printf("--- - -------------------- ------------\n");
  for(n = (s64)0;n <= (s64)45;n++)
  {
    if(n < (s64)40 || dt1 < 50.0) { (void)elapsed_time(); f = F_v1(n); dt1 = elapsed_time(); fprintf(fd,"%3d; %12.9f; %12.9f; %12.9f; %12.9f\n",(int)n,dt1,dt2,dt3,dt4); }
    if(n < (s64)40 || dt1 < 50.0) { (void)elapsed_time(); f = F_v1(n); dt1 = elapsed_time(); printf("%3d 1 %20lld %12.9f\n",(int)n,f,dt1); }
    if(n < (s64)40 || dt2 < 50.0) { (void)elapsed_time(); f = F_v2(n); dt2 = elapsed_time(); printf("%3d 2 %20lld %12.9f\n",(int)n,f,dt2); }
    if(n < (s64)40 || dt3 < 50.0) { (void)elapsed_time(); f = F_v3(n); dt3 = elapsed_time(); printf("%3d 3 %20lld %12.9f\n",(int)n,f,dt3); }
    if(n < (s64)40 || dt4 < 50.0) { (void)elapsed_time(); f = F_v4(n); dt4 = elapsed_time(); printf("%3d 4 %20lld %12.9f\n",(int)n,f,dt4); }
    printf("--- -- -------------------- ------------\n");
  }
  fclose(fd);
  return 0;
}

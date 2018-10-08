//
// Tomás Oliveira e Silva, AED, September 2014, September 2015
//
// the functions for the first exercise of class P.03
// (for a given positive value of n, find a formula for the return value of each function)
//


#include <math.h>
#include <stdio.h>
#include <assert.h>

#include "elapsed_time.h"
int f1(int n)
{
  int i,r=0;

  for(i = 1;i <= n;i++)
    r += 1;
  return r;
}

int f2(int n)
{
  int i,j,r=0;

  for(i = 1;i <= n;i++)
    for(j = 1;j <= i;j++)
      r += 1;
  return r;
}

int f3(int n)
{
  int i,j,r=0;

  for(i = 1;i <= n;i++)
    for(j = 1;j <= n;j++)
      r += 1;
  return r;
}

int f4(int n)
{
  int i,r=0;

  for(i = 1;i <= n;i++)
    r += i;
  return r;
}

int f5(int n)
{
  int i,j,r=0;

  for(i = 1;i <= n;i++)
    for(j = i;j <= n;j++)
      r += 1;
  return r;
}

int f6(int n)
{
  int i,j,r=0;

  for(i = 1;i <= n;i++)
    for(j = 1;j <= i;j++)
      r += j;
  return r;
}

int main(void)
{
  int f;
  double dt1 = 0.0,dt2 = 0.0,dt3 = 0.0,dt4 = 0.0,dt5 = 0.0,dt6 = 0.0;
   FILE *fd;
  fd=fopen("Output.csv","w");
  fprintf(fd,"%-7s;%-7s;%-7s;%-7s;%-7s;%-7s;%-7s\n","n","F1","F2","F3","F4","F5","F6");
  for(int n = 10000;n <=100000;n+=10000)
  {
    
    (void)elapsed_time(); f = f1(n); dt1 = elapsed_time(); printf("%3d  %20d %12.9f\n",(int)n,f,dt1); 
    (void)elapsed_time(); f = f2(n); dt2 = elapsed_time(); printf("%3d  %20d %12.9f\n",(int)n,f,dt2);
    if(n<100000)
      {
      (void)elapsed_time(); f = f3(n); dt3 = elapsed_time(); printf("%3d  %20d %12.9f\n",(int)n,f,dt3); 
      }
    else
    {
      dt3=0.0;
    }
    (void)elapsed_time(); f = f4(n); dt4 = elapsed_time(); printf("%3d  %20d %12.9f\n",(int)n,f,dt4);
    (void)elapsed_time(); f = f5(n); dt5 = elapsed_time(); printf("%3d  %20d %12.9f\n",(int)n,f,dt5); 
    (void)elapsed_time(); f = f6(n); dt6 = elapsed_time(); printf("%3d  %20d %12.9f\n",(int)n,f,dt6);
    fprintf(fd,"%3d; %12.9f; %12.9f; %12.9f; %12.9f; %12.9f; %12.9f \n",(int)n,dt1,dt2,dt3,dt4,dt5,dt6);   
    printf("--- -- -------------------- ------------\n");
  }
   fclose(fd);
}

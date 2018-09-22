//
// Tomás Oliveira e Silva, AED, September 2014, September 2017
//
// program to print a table of the squares and square roots of some integers
//
// on GNU/Linux, run the command
//   man 3 printf
// to see how the manual page of the printf function
//

#include <math.h>
#include <stdio.h>

void do_it(int N)
{
  int i;

  printf(" n n*n      sqrt(n)\n");
  printf("-- --- -----------------\n");
  for(i = 1;i <= N;i++)
    printf("%2d %3d %17.15f\n",i,i * i,sqrt((double)i));
}


double d2r (double d)
{
  return d*M_PI/180.0;


}

void do_it1(int from,int to)
{
  int i;
  FILE *fd;
  fd=fopen("Output.txt","w");
  fprintf(fd," n sine                     cosine \n");
  fprintf(fd,"-- ----------------- -----------------\n");
  for(i = from;i <= to;i++)
    fprintf(fd,"%2d  %17.15f  %17.15f\n",i,sin(d2r(i)),cos(d2r(i)));

  fclose(fd);
}

int main(void)
{
  
  do_it(10);
  do_it1(0,90);
  
 

  return 0;

}

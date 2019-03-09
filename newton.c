
#include <stdio.h>
#include <math.h>

#define TOL 1.0E-09
#define MAX 100

double func(double x);
double funcPrime(double x);

int main()
{
  double x, delta, RelError;
  int iterates;
  x  =(3.14)/4;     
  iterates = 0;

  // main part: Newton-Raphson method
  do {
    delta = func(x)/funcPrime(x);
    x -= delta;

     
    RelError = (delta/x);
   
    if(iterates++>MAX) break;

    } while(RelError > TOL);

  printf("root: %.8f\nRelative Error: %.16f\nnumber of iterates: %i\n",
	 x, RelError, iterates);

  return 0;
 }


double func(double x)
{
  return cos(x) - x;
}

double funcPrime(double x)
{
  return -sin(x) - 1;
}

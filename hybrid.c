
#include <stdio.h>
#include <math.h>

#define TOL 1.0E-08
#define MAX 30

double func(double x);
double funcPrime(double x);

int main()
{
  /*  Declaration of variables */
  double left, right, best, fLeft, fRight, fBest, delta, DerfBest, RelError;
  int iterates;

  /* Initialize variables */ 
  left  = 0;
  right = 3; 
  fLeft  = func(left);
  fRight = func(right);
  iterates = 0;

  /* make sure that the root is bracketed */
  if(fLeft * fRight > 0) {
   printf("A root is not bracketed within the [%f,%f] interval.\n",left,right);
  }

  // determine the best value for the root
  best=2;
  if(fabs(fLeft)<fabs(fRight))
  {best=left;
  fBest=fLeft;
  }
  else
  {best=right;
  fBest=fRight;
  }
  DerfBest = funcPrime(best);
  

  
  do {
  	if(((DerfBest)*(best-left)-fBest)*((DerfBest)*(best-right)-fBest)<0)
  	{
  	delta=fBest/DerfBest;
  	best-=delta;
    }
    else
    {
	delta=(right-left)/2;
    best=(right+left)/2;
    }
    
    RelError =fabs(delta/best);
    

    /* check if relative error is small enough */
    if(RelError < TOL) {
      printf("root: %.8f\nRelative Error: %.10f\nnumber of iterates: %i\n",
	     best, RelError, iterates);
      break;
    }
      
    /* Relative error is too big */
    fBest = func(best);
    DerfBest = funcPrime(best);

    /* Determine which half of the interval contains the root 
     */
    if(fLeft*fBest<0)
    {right=best;
    fRight=fBest;
    }
    else
    {left=best;
    fLeft=fBest;
    }

  } while(iterates++ <  MAX);

  return 0;
 }


double func(double x)
{
  return pow(x,2)-2*x-2;
}

double funcPrime(double x)
{
  return 2*x-2;
}

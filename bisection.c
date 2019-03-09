#include <stdio.h>
#include <math.h>

#define TOL 1.0E-09
double func(double x);

int main()
{
  double left, right, middle, fLeft, fRight, fMiddle, RelError;
  int iterates;

  left  = 0.0;
  right =(3.14)/2;
  iterates = 0;

  do {
    fLeft  = func(left);
    fRight = func(right);
    
    middle  = (right+left)/2;
    fMiddle = func(middle);

     double delta;
     delta=(right-left);
    RelError =delta/2;
    
    
    
    
iterates++;
if(fMiddle*fLeft<0)
    right=middle; 
    
    else
    left=middle;
    } while(RelError >  TOL);
printf("\nright=%.9f\nleft=%.9f\nTOL=%.9f\n",right,left,TOL);
  printf("root: %.10f\nRelative Error: %.10f\nnumber of iterates: %i\n",
	 middle, RelError, iterates);

  return 0;
 }


double func(double x)
{
  return cos(x) - x;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define tol 1E-9
double func(double x);
int main()
{printf("tolerance=%.9f\n",tol);
double x0,x1,delta,x2,x3,lastguess;
x0=0;
x1=(3.14/2);
int iterates=0;
double fx1,fx0,fx2,error,realerror;
double a,b,c;

do{
	
fx0=func(x0);
fx1=func(x1);
x2=(x1*fx0-x0*fx1)/(fx0-fx1);

fx2=func(x2);
a=((x1-x2)*(fx0-fx2)-(x0-x2)*(fx1-fx2))/((x0-x1)*(x0-x2)*(x1-x2));
b=((x0-x2)*(x0-x2)*(fx1-fx2)-(x1-x2)*(x1-x2)*(fx0-fx2))/((x0-x1)*(x0-x2)*(x1-x2));
c=fx2;
if(b>0)
{
x3=-2*c/(b+sqrt(b*b-4*a*c))+x2;
}
else if(b<0)
{
x3=2*c/(-b+sqrt(b*b-4*a*c))+x2;
}
error=(x3-x2)/x2;
if(error<0)
{error=-error;
}

iterates++;
if(error<tol)
break;
	realerror=error;
lastguess=x3;
if(fx0*fx1<0)
{
x1=x2;
}
else if(fx1*fx0>0)
{
x0=x2;
}
}while(1);

printf("the root=%.9f\n",lastguess);
printf("error=%.9f\n",realerror);
printf("iterates=%d\n",iterates);
printf("while we used false position method we had 11iterates to find the root of cos(x)-x but now we have just 6iterates to find the root and therefor we conclude that the muller method is faster than false position method  ");
return 0;
}
double func(double x)
{return cos(x)-x;
}

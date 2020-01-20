/*=======================================*/
/* Euler method for system of ODEs (IVP) */
/*    x' = f(t,x,y,z)                      */
/*    y' = g(t,x,y,z)                      */
/*    z' = h(t,x,y,z)                      */
/*    x(T0)=X0,  y(T0)=Y0, z(T0)=Z0      */
/*=======================================*/
#include <stdio.h>
#include <math.h>

/*--- The initial and final times ---*/
#define T0   0.0
#define T1   20.0

/*--- The initial data ---*/
#define X0   1.0
#define Y0   0.0
#define Z0   0.0

/*--- division number ---*/
#define N    1000

//parameter in system
#define a    10
#define b    28
#define c    8/3

/*--- Right-hand sides of the equations: 
         f(t,x,y,z), g(t,x,y,z), h(t,x,y,z)  ---*/
double f(double t, double x, double y, double z) { return -a*x+a*y; }
double g(double t, double x, double y, double z) { return -x*z+b*x-y; }
double h(double t, double x, double y, double z) { return x*y-c*z; }

/*--- Euler scheme ---*/

double eulerx(double dt, double t, double x, double y, double z)
{
 return(x+dt*f(t,x,y,z));
}

double eulery(double dt, double t, double x, double y, double z)
{
 return(y+dt*g(t,x,y,z));
}

double eulerz(double dt, double t, double x, double y, double z)
{
 return(z+dt*h(t,x,y,z));
}

/*--- main ---*/
int main(void)
{
  int i;         
  double dt;      // step size  
  double x,y,z;  // (approx.) solutons
  double t;      // time
  
  dt=(T1-T0)/N;

  /*  Set the initial condition */
  x=X0;
  y=Y0;
  z=Z0;

  for(i=1; i<=N; i++) 
  {
    t=T0+i*dt;

   /* Calculate from (X_n, Y_n, Z_n) to (X_{n+1}, Y_{n+1}, Z_{n+1}) */
    x=eulerx(dt,t,x,y,z); 
    y=eulery(dt,t,x,y,z); 
    z=eulerz(dt,t,x,y,z); 

   /* display a time t_n, X_n, Y_n and Z_n for each step */

    printf("%6.4f %16.14f %16.14f %16.14f \n", t, x, y, z);
  }
}
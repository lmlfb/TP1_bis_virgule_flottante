/* liste les donnees de la chute d'un corps avec calculs en virgule flottante */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int N, char *P[])
{
float g=-9.81, v=0., x=0.;
float dt=0.1, t, dx, dv;

  /* on permet de modifier dt avec le 1er param. */
  if (N>1) dt=atof(P[1]);
  if ((N>2) || (dt <= 0)) {   /* erreurs */
     fprintf(stderr,"Utilisation: %s [dt]\n", P[0]); return 1;
  }
  for (t=0.; t<(10.+dt); t+=dt) { /* on enregistre pendant 10 s */
    dv=g*dt; dx=v*dt;
    v=v+dv; x=x+dx;
    printf("%f %f %f\n",t,x,v);
  }
  return 0;
}


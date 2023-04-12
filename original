/* liste les donnees de la chute d'un corps avec calculs en virgule fixe */
#include <stdio.h>
#include <stdint.h>

/* on choisi un type d'entier pour coder notre virgule fixe */
typedef int32_t vfix; /* a ajuster si besoin */

#define UNITE 1000    /* a ajuster si besoin */

/* toutes ces fonctions retournent un element en virgule fixe */
extern vfix valeur(int part_ent, int part_decim);
extern vfix fraction(int numerateur, int denominateur);
extern vfix somme(vfix, vfix);  /* retourne la somme de 2 elts */
extern vfix produit(vfix, vfix);/* retourne le produit de 2 elts */

/* fonctions speciales */
extern vfix ch2decim(char *); /* retourne la partie decimale en fct de UNITE */
/* exemples : UNITE         1000      100000
           ch="12"           120       12000
           ch="0032"         003       00320
******************************************************************************/
extern int nbdecim(void);     /* retourne le nb de decimales en fct de UNITE */
/* exemples : UNITE         1000      100000
           nbdecim()           3           5
******************************************************************************/


int main(int N, char *P[])
{
vfix g=valeur(-9,81), v=0, x=0;
vfix dt=fraction(1,10), t, dx, dv;

  /* on permet de modifier dt avec le 1er param. */
  if (N>1) {
     t=ch2decim(P[1]);
     if ((N>2) || (t <= 0)) {   /* erreurs */
        fprintf(stderr,"Utilisation: %s [partie decimale de dt]\n", P[0]);
        return 1;
     }
     dt=t;
#ifdef TEST
     printf("UNITE=%d nb decimales:%d dt=%d\n",UNITE,nbdecim(),(int)dt);
     return 0;
#endif
  }
  for (t=0; t<valeur(10,(int)dt); t+=dt) { /* on enregistre pendant 10 s */
    dv=produit(g,dt); dx=produit(v,dt);
    v=somme(v,dv); x=somme(x,dx);
    printf("%d %d %d\n",(int)t,(int)x,(int)v);
  }
  return 0;
}


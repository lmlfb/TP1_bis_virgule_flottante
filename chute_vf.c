/* liste les donnees de la chute d'un corps avec calculs en virgule fixe */
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "vfix.h"


int main(int N, char *P[])
{
    vfix g = valeur(-9, 81), v = 0, x = 0;
    vfix dt = fraction(1, 10), t, dx, dv;

    /* on permet de modifier dt avec le 1er param. */
    if (N > 1) {
        t = ch2decim(P[1]);
        if ((N > 2) || (t <= 0)) {   /* erreurs */
            fprintf(stderr, "Utilisation: %s [partie decimale de dt]\n", P[0]);
            return 1;
        }
        dt = t;
#ifdef TEST
        printf("UNITE=%d nb decimales:%d dt=%d\n", UNITE, nbdecim(), (int)dt);
        return 0;
#endif
    }

    for (t = 0; t < valeur(10, (int)dt); t = somme(t, dt)) { /* on enregistre pendant 10 s */
        dv = produit(g, dt);
        dx = produit(v, dt);
        v = somme(v, dv);
        x = somme(x, dx);
        printf("%d %d %d\n", (int)t, (int)x, (int)v);
    }

    return 0;
}



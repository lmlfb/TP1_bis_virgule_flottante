/* liste les donnees de la chute d'un corps avec calculs en virgule fixe */
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "vfix.h"
/* on choisi un type d'entier pour coder notre virgule fixe */
typedef int32_t vfix; /* a ajuster si besoin */

#define UNITE 100000  /* a ajuster si besoin */

vfix valeur(int part_ent, int part_decim) {
    return part_ent * UNITE + part_decim;
}

vfix fraction(int numerateur, int denominateur) {
    return (numerateur * UNITE) / denominateur;
}

vfix somme(vfix x, vfix y) {
    return x + y;
}

vfix produit(vfix x, vfix y) {
    return (x * y) / UNITE;
}

vfix ch2decim(char *ch) {
    int i, decim = 0;
    for (i = 0; ch[i] != '\0'; i++) {
        if (ch[i] >= '0' && ch[i] <= '9') {
            decim = decim * 10 + (ch[i] - '0');
        }
    }
    return decim * UNITE / pow(10, i);
}

int nbdecim(void) {
    int i, n = UNITE;
    for (i = 0; n > 1; i++) {
        n /= 10;
    }
    return i;
}

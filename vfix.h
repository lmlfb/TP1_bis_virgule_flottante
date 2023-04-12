#ifndef VFIXE_H
#define VFIXE_H

#include <stdint.h>
#include <stdio.h>

/* on choisi un type d'entier pour coder notre virgule fixe */
typedef int32_t vfix; /* a ajuster si besoin */

#define UNITE 1000    /* a ajuster si besoin */

/* toutes ces fonctions retournent un element en virgule fixe */
vfix valeur(int part_ent, int part_decim);
vfix fraction(int numerateur, int denominateur);
vfix somme(vfix a, vfix b);
vfix produit(vfix a, vfix b);

/* fonctions speciales */
vfix ch2decim(char *ch);
int nbdecim(void);

#endif /* VFIXE_H */

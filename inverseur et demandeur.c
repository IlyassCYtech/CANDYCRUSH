void demandeur(struct point *p, struct point *c, size) {
    do {
        printf("Quelles sont les coordonnées du point en longueur ? ");
        scanf("%f", &(p->longueur));
    } while (p->longueur < 0 || p->longueur >= size || p->longueur != (int)p->longueur);

    do {
        printf("Quelles sont les coordonnées du point en largeur ? ");
        scanf("%f", &(p->largeur));
    } while (p->largeur < 0 || p->largeur >= size || p->largeur != (int)p->largeur);

    do {
        printf("Quelles sont les coordonnées du point 2 en longueur ? ");
        scanf("%f", &(c->longueur));
    } while (c->longueur < 0 || c->longueur >= size || c->longueur != (int)c->longueur);

    do {
        printf("Quelles sont les coordonnées du point 2 en largeur ? ");
        scanf("%f", &(c->largeur));
    } while (c->largeur < 0 || c->largeur >= size || c->largeur != (int)c->largeur);
}



void inversé(int tab[size][size]) {
    int r;
  printf("quelle est la ligne de la premiere case");
  
  int temp = tab[i1][j1];
    tab[i1][j1] = tab[i2][j2];
    tab[i2][j2] = temp;
  r= premier_vérificateur(int tab);
  while(r=0)
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int premier_vérificateur(int *tab[][], int taille) {
  int valeur = 0;

  for (int i = 0; i < taille; i++) {
    for (int j = 0; j < taille - 2; j++) {
      if (tab[i][j] == tab[i][j + 1] && tab[i][j] == tab[i][j + 2]) {
        valeur = 1;
      }
    }
  }

  for (int j = 0; j < taille; j++) {
    for (int i = 0; i < taille - 2; i++) {
      if (tab[i][j] == tab[i + 1][j] && tab[i][j] == tab[i + 2][j]) {
        valeur = 1;
      }
    }
  }

  return valeur;
}

struct point {
  int longueur;
  int largeur;
  int longueur2;
  int largeur2;
};

void demandeur(struct point *p, int size) {
  do {
    printf("Quelles sont les coordonnées du point en longueur ? ");
    scanf("%f", &(p->longueur));
  } while (p->longueur < 0 || p->longueur >= size ||
           p->longueur != (int)p->longueur);

  do {
    printf("Quelles sont les coordonnées du point en largeur ? ");
    scanf("%f", &(p->largeur));
  } while (p->largeur < 0 || p->largeur >= size ||
           p->largeur != (int)p->largeur);

  do {
    printf("Quelles sont les coordonnées du point 2 en longueur ? ");
    scanf("%f", &(p->longueur2));
  } while (p->longueur2 < 0 || p->longueur2 >= size ||
           p->longueur2 != (int)p->longueur2);

  do {
    printf("Quelles sont les coordonnées du point 2 en largeur ? ");
    scanf("%f", &(p->largeur2));
  } while (p->largeur2 < 0 || p->largeur2 >= size ||
           p->largeur2 != (int)p->largeur2);
}

void inverse(int *tab[][], int taille, struct point *p) {
  int r = 0;
  int h = 0;
  int *tab1 = (int *)malloc(taille * sizeof(int));

  do {
    for (int i = 0; i < taille; i++) {
      for (int j = 0; j < taille; j++) {
        tab1[i][j] = tab[i][j];
      }
    }

    demandeur(&p, taille);
    int temp = tab1[p->longueur][p->largeur];
    tab1[p->longueur][p->largeur] = tab1[p->longueur2][p->largeur2];
    tab1[p->longueur2][p->largeur2] = temp;

    r = premier_vérificateur(&tab1, taille);
    if (r == 1) {
      for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
          tab[i][j] = tab1[i][j];
        }
      }
      h = 1;
    }
  } while (r == 0);
}

void create_tableau(int *tab[][], int taille, int number) {
  srand(time(NULL));
  for (int i = 0; i < taille; i++) {
    for (int j = 0; j < taille; j++) {
      tab[i][j] = rand() % number;
    }
  }
}

int main() {
  struct point p;

  float a, b;
  int r;
  printf("quel est la taille");
  do {
    scanf("%f", &a);
    if (a < 0) {
      printf("donnez une valeur qui marche");
    }
  } while (a < 0);
  printf("Combien d'élément différent voulez-vous?");
  scanf("%f", &b);
  if (b < 4 || b > 6) {
    do {
      printf("donnez une valeur qui marche");
      scanf("%f", &b);
    } while (b < 4 || b > 6);
  }
  int size, number;
  size = a;
  number = b;

  int *tab = (int *)malloc(size * sizeof(int));
  do {
    create_tableau(&tab, size, number);
    r = premier_vérificateur(tab, size);
  } while (r == 1);

  inverse(&tab, size, p);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d ", tab[i][j]);
    }
    printf("\n");
  }

  return 0;
}




























































#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10

int premier_vérificateur(int tab[size][size], int taille) {
  int valeur = 0;

  for (int i = 0; i < taille; i++) {
    for (int j = 0; j < taille - 2; j++) {
      if (tab[i][j] == tab[i][j + 1] && tab[i][j] == tab[i][j + 2]) {
        valeur = 1;
      }
    }
  }

  for (int j = 0; j < taille; j++) {
    for (int i = 0; i < taille - 2; i++) {
      if (tab[i][j] == tab[i + 1][j] && tab[i][j] == tab[i + 2][j]) {
        valeur = 1;
      }
    }
  }

  return valeur;
}

struct point {
  int longueur;
  int largeur;
  int longueur2;
  int largeur2;
};

void demandeur(struct point *p, int bonjour) {
  do {
    printf("Quelles sont les coordonnées du point en longueur ? ");
    scanf("%d", &(p->longueur));
  } while (p->longueur < 0 || p->longueur >= size ||
           p->longueur != (int)p->longueur);

  do {
    printf("Quelles sont les coordonnées du point en largeur ? ");
    scanf("%d", &(p->largeur));
  } while (p->largeur < 0 || p->largeur >= size ||
           p->largeur != (int)p->largeur);

  do {
    printf("Quelles sont les coordonnées du point 2 en longueur ? ");
    scanf("%d", &(p->longueur2));
  } while (p->longueur2 < 0 || p->longueur2 >= size ||
           p->longueur2 != (int)p->longueur2);

  do {
    printf("Quelles sont les coordonnées du point 2 en largeur ? ");
    scanf("%d", &(p->largeur2));
  } while (p->largeur2 < 0 || p->largeur2 >= size ||
           p->largeur2 != (int)p->largeur2);
}

void inverse(int tab[size][size], int taille, struct point *p) {
  int r = 0;
  int h = 0;
  //int *tab1 = (int *)malloc(taille * sizeof(int));
int tab1[size][size];

  do {
    for (int i = 0; i < taille; i++) {
      for (int j = 0; j < taille; j++) {
        tab1[i][j] = tab[i][j];
      }
    }

    demandeur(p, taille);
    int temp = tab1[p->longueur][p->largeur];
    tab1[p->longueur][p->largeur] = tab1[p->longueur2][p->largeur2];
    tab1[p->longueur2][p->largeur2] = temp;

    r = premier_vérificateur(tab1, taille);
    if (r == 1) {
      for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
          tab[i][j] = tab1[i][j];
        }
      }
      h = 1;
    }
  } while (r == 0);
}

void create_tableau(int tab[size][size], int taille, int number) {
  srand(time(NULL));
  for (int i = 0; i < taille; i++) {
    for (int j = 0; j < taille; j++) {
      tab[i][j] = rand() % number;
    }
  }
}

int main() {
  struct point p;

  float a, b;
  int r;
  printf("quel est la taille");
  do {
    scanf("%f", &a);
    if (a < 0) {
      printf("donnez une valeur qui marche");
    }
  } while (a < 0);
  printf("Combien d'élément différent voulez-vous?");
  scanf("%f", &b);
  if (b < 4 || b > 6) {
    do {
      printf("donnez une valeur qui marche");
      scanf("%f", &b);
    } while (b < 4 || b > 6);
  }
  //int size, 
int number;
 // size = a;
  number = b;

  //int *tab = (int *)malloc(size * sizeof(int));
int tab[size][size];
  do {
    create_tableau(tab, size, number);
    r = premier_vérificateur(tab, size);
  } while (r == 1);

  inverse(tab, size, &p);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d ", tab[i][j]);
    }
    printf("\n");
  }

  return 0;
}

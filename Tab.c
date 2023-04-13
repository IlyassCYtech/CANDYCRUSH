#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#include "Tab.h"

int size;
int elements;
int tab[MAX_SIZE][MAX_SIZE];
int tab1[MAX_SIZE][MAX_SIZE];
struct point
{
    int longueur;
    int largeur;
    int longueur2;
    int largeur2;
};
struct point p;

int r, v;


int verificateurcontinu() {
    int valeur = 0; 

  
   //ligne 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-2; j++) {
            if (tab[i][j] == tab[i][j+1] && tab[i][j] == tab[i][j+2]) {
                valeur = 2;
              r=i;
              v=j;
                }
        }
    }
       //colonne
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size-2; i++) {
            if (tab[i][j] == tab[i+1][j] && tab[i][j] == tab[i+2][j]) {
                valeur = 1;
              r=i;
              v=j;
                }
        }
    }
        return valeur;
}



void createTab()
{
    // VALUE TAB
    float a, b;
    char input[100];

    printf("Quelle est la taille ? ");
    do
    {
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%f", &a) != 1 || a < MIN_SIZE)
        {
            printf("Donnez une valeur qui marche supérieure à %d : ", MIN_SIZE);
        }
    } while (a < MIN_SIZE || a > MAX_SIZE);

    printf("Combien d'elements differents voulez-vous ? ");
    do
    {
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%f", &b) != 1 || b < MIN_ELEMENTS || b > MAX_ELEMENTS)
        {
            printf("Donnez une valeur qui marche entre %d et %d : ", MIN_ELEMENTS, MAX_ELEMENTS);
        }
    } while (b < MIN_ELEMENTS || b > MAX_ELEMENTS);
    size = (int)a;
    elements = (int)b;
    printf("Size : %d\n", size);
    printf("Element : %d\n", elements);
    printf("\n");
}

void fillTab()
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            tab[i][j] = rand() % elements+1;
        }
    }
}

void printTab()
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            switch (tab[i][j])
            {
            case 0:
                printf(RED "%d " RESET, tab[i][j]);
                break;
            case 1:
                printf(GREEN "%d " RESET, tab[i][j]);
                break;
            case 2:
                printf(YELLOW "%d " RESET, tab[i][j]);
                break;
            case 3:
                printf(BLUE "%d " RESET, tab[i][j]);
                break;
            case 4:
                printf(MAGENTA "%d " RESET, tab[i][j]);
                break;
            case 5:
                printf(CYAN "%d " RESET, tab[i][j]);
                break;
            default:
                printf("%d ", tab[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool verifTab(void)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 2; j++)
        {
            if (tab[i][j] == tab[i][j + 1] && tab[i][j] == tab[i][j + 2])
            {
                return true;
            }
        }
    }

    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < size - 2; i++)
        {
            if (tab[i][j] == tab[i + 1][j] && tab[i][j] == tab[i + 2][j])
            {
                return true;
            }
        }
    }

    return false;
}

void demandeur()
{
    do
    {
        printf("Quelles sont les coordonnées du point en longueur ? ");
        scanf("%d", &(p.longueur));
    } while (p.longueur < 0 || p.longueur >= size ||
             p.longueur != (int)p.longueur);

    do
    {
        printf("Quelles sont les coordonnées du point en largeur ? ");
        scanf("%d", &(p.largeur));
    } while (p.largeur < 0 || p.largeur >= size ||
             p.largeur != (int)p.largeur);

    do
    {
        printf("Quelles sont les coordonnées du point 2 en longueur ? ");
        scanf("%d", &(p.longueur2));
    } while (p.longueur2 < 0 || p.longueur2 >= size ||
             p.longueur2 != (int)p.longueur2);

    do
    {
        printf("Quelles sont les coordonnées du point 2 en largeur ? ");
        scanf("%d", &(p.largeur2));
    } while (p.largeur2 < 0 || p.largeur2 >= size ||
             p.largeur2 != (int)p.largeur2);
}

void inverse() {
  bool z = 0;
  int h = 0;
  //int *tab1 = (int *)malloc(taille * sizeof(int));


  
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        tab1[i][j] = tab[i][j];
      }
    }

    demandeur();
    int temp = tab[p.longueur][p.largeur];
    tab[p.longueur][p.largeur] = tab[p.longueur2][p.largeur2];
    tab[p.longueur2][p.largeur2] = temp;

    
    z = verifTab();
    if (z == false) {
      for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
          tab[i][j] = tab1[i][j];
          
        }
       
      }
    inverse();
    }
    printTab(); 
  } 

void supprimeur(){
int g = verificateurcontinu();
if(g==1){
tab[r][v]=0;
tab[r+1][v]=0;
tab[r+2][v]=0;
}
if(g==2){
tab[r][v]=0;
tab[r][v+1]=0;
tab[r][v+2]=0;
}


}

/*void removeAlignedElements()
{
    int score = 0;
    bool removed = true;

    while (removed)
    {
        removed = false;

        // Recherche et suppression d'éléments alignés horizontalement
        for (int i = 0; i < size; i++)
        {
            int count = 1;
            for (int j = 1; j < size; j++)
            {
                if (tab[i][j] == tab[i][j - 1] && tab[i][j] != -1)
                {
                    count++;
                }
                else
                {
                    if (count >= 3)
                    {
                        // Supprimer et remplacer les éléments alignés
                        for (int k = j - count; k < j; k++)
                        {
                            if (tab[i][k] != -1)
                            {
                                score++;
                                tab[i][k] = -1;
                                removed = true;
                            }
                        }
                        count = 1;
                    }
                    else
                    {
                        count = 1;
                    }
                }
            }
            if (count >= 3)
            {
                // Supprimer et remplacer les éléments alignés
                for (int k = size - count; k < size; k++)
                {
                    if (tab[i][k] != -1)
                    {
                        score++;
                        tab[i][k] = -1;
                        removed = true;
                    }
                }
            }
        }

        // Recherche et suppression d'éléments alignés verticalement
        for (int j = 0; j < size; j++)
        {
            int count = 1;
            for (int i = 1; i < size; i++)
            {
                if (tab[i][j] == tab[i - 1][j] && tab[i][j] != -1)
                {
                    count++;
                }
                else
                {
                    if (count >= 3)
                    {
                        // Supprimer et remplacer les éléments alignés
                        for (int k = i - count; k < i; k++)
                        {
                            if (tab[k][j] != -1)
                            {
                                score++;
                                tab[k][j] = -1;
                                removed = true;
                            }
                        }
                        count = 1;
                    }
                    else
                    {
                        count = 1;
                    }
                }
            }
            if (count >= 3)
            {
                // Supprimer et remplacer les éléments alignés
                for (int k = size - count; k < size; k++)
                {
                    if (tab[k][j] != -1)
                    {
                        score++;
                        tab[k][j] = -1;
                        removed = true;
                    }
                }
            }
        }

        // Faire tomber les éléments
        for (int j = 0; j < size; j++)
        {
            int fallHeight = 0;
            for (int i = size - 1; i >= 0; i--)
            {
                if (tab[i][j] == -1)
                {
                    fallHeight++;
                }
                else if (fallHeight > 0)
                {
                    tab[i + fallHeight][j] = tab[i][j];
                    tab[i][j] = -1;
                    removed = true;
                }
            }
        }

        // Ajouter de nouveaux éléments en haut de la grille
        for (int j = 0; j < size; j++)
        {
            if (tab[0][j] == -1)
            {
                tab[0][j] = rand() % elements;
                removed = true;
            }
        }

        // Ajouter la gravité pour faire tomber les éléments
        for (int j = 0; j < size; j++)
        {
            for (int i = size - 1; i > 0; i--)
            {
                if (tab[i][j] == -1)
                {
                    // Chercher l'élément le plus proche au-dessus et l'échanger
                    int k = i - 1;
                    while (k >= 0 && tab[k][j] == -1)
                    {
                        k--;
                    }
                    if (k >= 0)
                    {
                        tab[i][j] = tab[k][j];
                        tab[k][j] = -1;
                        removed = true;
                    }
                }
            }
        }

        // Ajouter de nouveaux éléments en haut de la grille
        for (int j = 0; j < size; j++)
        {
            if (tab[0][j] == -1)
            {
                tab[0][j] = rand() % elements;
                removed = true;
            }
        }
    }
    printf("Score: %d\n", score);
}
*/



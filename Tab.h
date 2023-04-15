#ifndef TAB_H
#define TAB_H

#include <stdbool.h>

#define MAX_SIZE 15
#define MIN_SIZE 4
#define MAX_ELEMENTS 6
#define MIN_ELEMENTS 4

#define RESET "\033[0m"    // Réinitialiser la couleur
#define RED "\033[31m"     // Rouge
#define GREEN "\033[32m"   // Vert
#define YELLOW "\033[33m"  // Jaune
#define BLUE "\033[34m"    // Bleu
#define MAGENTA "\033[35m" // Magenta
#define CYAN "\033[36m"    // Cyan

//bool canSwap(int x1, int y1, int x2, int y2);
//void play();
//void removeAlignedElements();
int navigate_2d_array();
void navigate_2d_array1();
int verificateurevolu();
void demandeur();
void createTab();
int verificateurcontinu();
void inverse();
void fillTab();
void fillTab1();
int verificateurcontinuligne();
int verificateurcontinucolonne();
void printTab();
void supprimeur();
bool verifTab();
void ClearScreen();
void gravity();

#endif // TAB_H

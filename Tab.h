#ifndef TAB_H_INCLUDED
#define TAB_H_INCLUDED
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ncurses.h>
#include <locale.h>
struct point {
  	int lengh;
  	int widht;
  	int lengh2;
  	int widht2;
};

#define MAX_SIZE 35
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

// bool canSwap(int x1, int y1, int x2, int y2);
// void play();
// void removeAlignedElements();
bool calculateurdecout(int tab[MAX_SIZE][MAX_SIZE], int rows, int columns);
int navigate_2d_array(int score, int rows,int columns, int tab[MAX_SIZE][MAX_SIZE],
                      struct point *p, char name[100]);
int load_game(const char* filename, int *score, int *rows,int *columns, int tab[MAX_SIZE][MAX_SIZE], int *bomb,int* elapsedTime, char name[100]);
int save(const char* filename, int score, int rows,int columns, int tab[MAX_SIZE][MAX_SIZE], int bomb, int elapsedTime, char name[100]);
void printTab(int tab[MAX_SIZE][MAX_SIZE],int rows,int columns);
void fillTab(int tab[MAX_SIZE][MAX_SIZE],int rows,int columns,int *elements);
void createTab(int *elements, int *rows,int *columns,int tab[MAX_SIZE][MAX_SIZE],char name[100]);
int supprimeur(int *score, int rows, int columns,int tab[MAX_SIZE][MAX_SIZE],int *xcoord,int *ycoord, int *xcoord2, int *ycoord2, int* bomb);
void Homepage();
void gravity(int rows, int columns, int tab[MAX_SIZE][MAX_SIZE]);
int menu(int game);
int verificateurcontinuligne(int rows,int columns,int tab[MAX_SIZE][MAX_SIZE],int *xcoord,int *ycoord);
int verificateurcontinucolonne(int rows,int columns, int tab[MAX_SIZE][MAX_SIZE],int *xcoord2,int *ycoord2);
bool verifTab(int rows,int columns, int tab[MAX_SIZE][MAX_SIZE]);
int menusauvegarde(int game);
char yourfiles(char filename[1000]);
bool testfile(char* filename);
int countelement(int rows,int columns, int tab[MAX_SIZE][MAX_SIZE]);
int write_score_to_file(int score, const char *filename, int tab_record[1000]);
void sort_array_descending(int tab_record[], int size);
void print_record(int tab_record[100], int score);
void savechoice(char* namesave, int saves,int score,int rows,int columns,int tab[MAX_SIZE][MAX_SIZE],int bomb,int elapsedTime, char name[100]);
void printGameover();
void destroybonus(int tab[MAX_SIZE][MAX_SIZE], struct point p, int rows, int columns, int* score);



#endif // TAB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Tab.h"
#include <time.h>
// Fill the tab matrix with random values between 1 and *elements
void fillTab(int tab[MAX_SIZE][MAX_SIZE],int rows,int columns,int *elements){
    srand(time(NULL));
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            if(tab[i][j] == 0|| tab[i][j]==9){
            	tab [i][j] = rand() % (*elements)+1;
            }
        }
    }
}
// Print the matrix with corresponding symbols for each element
void printTab(int tab[MAX_SIZE][MAX_SIZE],int rows,int columns){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            switch (tab[i][j]){
            case 6:
                printw("\U0001F7E3 ");
                break;
            case 1:
                printw("\U0001F534 ");
                break;
            case 2:
                printw("\U0001F535 ");
                break;
            case 3:
                printw("\U0001F7E2 ");
                break;
            case 4:
                printw("\U0001F7E4 ");
                break;
            case 5:
                printw("\U0001F7E0 ");
                break;
            case 9:
                printw("\U0001F4A3 ");
                break;
            default:
                printw("   ");
            }
        }
        printw("\n");
    }
    printw("\n");
    refresh();
}
//the fonction print the page gameover
void printGameover(){
   	clear();
   	char Gameover[] = " ██████╗  █████╗ ███╗   ███╗███████╗     ██████╗ ██╗   ██╗███████╗██████╗ \n"
                      "██╔════╝ ██╔══██╗████╗ ████║██╔════╝    ██╔═══██╗██║   ██║██╔════╝██╔══██╗\n"
                      "██║  ███╗███████║██╔████╔██║█████╗      ██║   ██║██║   ██║█████╗  ██████╔╝\n"
                      "██║   ██║██╔══██║██║╚██╔╝██║██╔══╝      ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗\n"
                      "╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗    ╚██████╔╝ ╚████╔╝ ███████╗██║  ██║\n"
                      " ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝     ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝\n";

  	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
  	attron(COLOR_PAIR(1));  // Activer la paire de couleurs
  	printw("%s\n",Gameover);
  	attroff(COLOR_PAIR(1));  // Désactiver la paire de couleurs
  	printw("Press 'enter' to leave\n\n");
  	refresh();
	//sleep  
}

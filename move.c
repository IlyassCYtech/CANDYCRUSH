#include "Tab.h"
//this function allows you to move in the grid and validate the values chosen in a structure.
int navigate_2d_array(int score, int rows,int columns, int tab[MAX_SIZE][MAX_SIZE],
                      struct point *p, char name[100]) {
  	int xcoord = 0;
  	int ycoord = 0;
   	char input;
	int loops=1;
	int loop = 1;
  start_color();
  init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	do {
    	clear();
      printw("Name: %s", name);
    	printw("\nScore: %d\n\n\n", score);
// Print the 2D array with symbols for each element
		for (int i = 0; i < rows; i++) {
      		for (int j = 0; j < columns; j++) {
        		if (i == xcoord && j == ycoord) {
          		switch (tab[i][j]) {
    		case 6:
    		       
            attron(A_STANDOUT);
      			printw("\U0001F7E3");
      			attroff(A_STANDOUT);
      			printw(" ");
      			refresh();
      			break;
    		case 1:
    		        
                        
            attron(A_STANDOUT);
      			printw("\U0001F534");
      			attroff(A_STANDOUT);
      			printw(" ");
      			refresh();
      			break;
    		case 2:
    		       
            
            attron(A_STANDOUT);
      			printw("\U0001F535");
      			attroff(A_STANDOUT);
      			printw(" ");
      			refresh();
      			break;
    		case 3:
    		        
                        
            attron(A_STANDOUT);
      			printw("\U0001F7E2");
      			attroff(A_STANDOUT);
      			printw(" ");
      			refresh();
      			break;
    		case 4:
    		        
                       
            attron(A_STANDOUT);
      			printw("\U0001F7E4");
      			attroff(A_STANDOUT);
      			printw(" ");
      			refresh();
      			break;
    		case 5:
    		                            
            attron(A_STANDOUT);
      			printw("\U0001F7E0");
      			attroff(A_STANDOUT);
      			printw(" ");
      			refresh();
      			break;
    		case 9:
    		                          
            attron(A_STANDOUT);
      			printw("\U0001F4A3");
      			attroff(A_STANDOUT);
      			printw(" ");
      			refresh();
      			break;
    		default:
      			printw("\U0001F536");
      			printw(" ");
    	}	
				} 
				else {
          			switch (tab[i][j]) {
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
      		}
      		printw("\n");
    	}
    	printw("\nmoves:\n '↑':up '←':left '↓':down '→':right\n\npress 'm' to open the menu\npress 'enter' to valid a case\n");
		refresh();
 		// Read the input and perform corresponding actions
   		switch (getch()) {
  case 65:  // Flèche haut
    if (xcoord > 0) {
      xcoord--;
      if (loop == 0) {
        p->lengh2 = xcoord;
        p->widht2 = ycoord;
        return 0;
      }
    }
    break;
  case 68:  // Flèche gauche
    if (ycoord > 0) {
      ycoord--;
      if (loop == 0) {
        p->lengh2 = xcoord;
        p->widht2 = ycoord;
        return 0;
      }
    }
    break;
  case 66:  // Flèche bas
    if (xcoord < rows - 1) {
      xcoord++;
      if (loop == 0) {
        p->lengh2 = xcoord;
        p->widht2 = ycoord;
        return 0;
      }
    }
    break;
  case 67:  // Flèche droite
    if (ycoord < columns - 1) {
      ycoord++;
      if (loop == 0) {
        p->lengh2 = xcoord;
        p->widht2 = ycoord;
        return 0;
      }
    }
    break;
  case '\n':  // Touche Entrée
    if (loop == 0) {
      p->lengh2 = xcoord;
      p->widht2 = ycoord;
      return 0;
    }
    loop = 0;
    p->lengh = xcoord;
    p->widht = ycoord;
    break;
  case 'm':
    return 1;
  default:
    printw("Input invalide.\n");
    refresh();
}

  	}while (loops == 1);
	  p->lengh = xcoord;
  	p->widht = ycoord;
  	return 0;
}

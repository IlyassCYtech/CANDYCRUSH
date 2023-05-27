#include "Tab.h"

//this function prints the homepage
void Homepage() {
    initscr();
    clear();
    raw();
    char text[] =     "            ██████╗██╗   ██╗      ██████╗██████╗ ██╗   ██╗███████╗██╗  ██╗\n"
                      "           ██╔════╝╚██╗ ██╔╝     ██╔════╝██╔══██╗██║   ██║██╔════╝██║  ██║\n"
                      "           ██║      ╚████╔╝█████╗██║     ██████╔╝██║   ██║███████╗███████║\n"
                      "           ██║       ╚██╔╝ ╚════╝██║     ██╔══██╗██║   ██║╚════██║██╔══██║\n"
                      "           ╚██████╗   ██║        ╚██████╗██║  ██║╚██████╔╝███████║██║  ██║\n"
                      "            ╚═════╝   ╚═╝         ╚═════╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝\n";


    
    initscr();
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    
    attron(COLOR_PAIR(1));  // Activer la paire de couleurs
    printw("%s", text);
    attroff(COLOR_PAIR(1));  // Désactiver la paire de couleurs  
    refresh();
    init_pair(2, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(2));  // Activer la paire de couleurs
    printw("                           Click on a key to access the menu\n");
    attroff(COLOR_PAIR(2));  // Désactiver la paire de couleurs

    printw("\n\n\n");

    refresh();
    getch();
    printw(" ");

    refresh();
}

//this function is the menu display. it prints the in-game and out-of-game menu. It returns the chosen line
int menu(int game) {
  int line;
  line = 0;
  int y = 1;
  
 char Command[] = "                                              _ \n"
                   "  __   ___   _ __    _ __    __ _   _ _    __| |\n"
                   " / _| / _ \\ | '  \\  | '  \\  / _` | | ' \\  / _` |\n"
                   " \\__| \\___/ |_|_|_| |_|_|_| \\__,_| |_||_| \\__,_|\n";
  char text[] =       "            ██████╗██╗   ██╗      ██████╗██████╗ ██╗   ██╗███████╗██╗  ██╗\n"
                      "           ██╔════╝╚██╗ ██╔╝     ██╔════╝██╔══██╗██║   ██║██╔════╝██║  ██║\n"
                      "           ██║      ╚████╔╝█████╗██║     ██████╔╝██║   ██║███████╗███████║\n"
                      "           ██║       ╚██╔╝ ╚════╝██║     ██╔══██╗██║   ██║╚════██║██╔══██║\n"
                      "           ╚██████╗   ██║        ╚██████╗██║  ██║╚██████╔╝███████║██║  ██║\n"
                      "            ╚═════╝   ╚═╝         ╚═════╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝\n";  
  
  if(game==0){
  	do {
    	srand(time(NULL));
    	clear();

    	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    	initscr();
    	start_color();
 
    
    	attron(COLOR_PAIR(1));  // Activer la paire de couleurs
    	printw("%s", text);
    	attroff(COLOR_PAIR(1));  // Désactiver la paire de couleurs                         
  		refresh();
  
		printw("             Press '↑' to move up, '↓' to move down and 'enter' to valid  \n\n");    

    	if (line == 0) {
      		printw("                                 \U0001F538 New Game \U0001F538\n");
      		printw("                                    Continue\n");
      		printw("                                      Quit\n");
      		printw("                                    Command \n");
      		printw("                                 About the Game\n");
    	}

    	if (line == 1) {
      		printw("                                    New Game\n");
      		printw("                                 \U0001F538 Continue \U0001F538\n");
      		printw("                                      Quit\n");
      		printw("                                    Command \n");
      		printw("                                 About the Game\n");
    	}
    	if (line == 2) {
      		printw("                                    New Game\n");
      		printw("                                    Continue\n");
      		printw("                                   \U0001F538 Quit \U0001F538\n");
      		printw("                                    Command \n");
      		printw("                                 About the Game\n");
    	}
    	if (line == 3) {
      		printw("                                    New Game\n");
      		printw("                                    Continue\n");
      		printw("                                      Quit\n");
      		printw("                                 \U0001F538 Command \U0001F538\n"); 
      		printw("                                 About the Game\n");
    	}
    	if (line == 4) {
      		printw("                                    New Game\n");
      		printw("                                    Continue\n");
      		printw("                                      Quit\n");
      		printw("                                    Command\n"); 
      		printw("                              \U0001F538 About the Game \U0001F538\n");
    	}
    	refresh();
    	
		
    	switch (getch()) {
    		case 65:
        case 'z':  
      			if (line > 0)
        		line--;
				break;
    		case 66:
        case 's': 
      			if (line < 4)
        		line++;
      			break;
    		case '\n':
            	if(line!=3 && line !=4){
      				y = 0;
      				break;
      			}
      			else if(line==3){
        			clear();
      
        			printw("%s", Command);
        			printw("\n\nAll command:\n");
        			printw("Move up:          | ↑ |\n");
        			printw("Move down:        | ↓ |\n");
        			printw("Move right:       | → |\n");
        			printw("Move left:        | ← |\n");
        			printw("Open menu:        | m |\n");
        			printw("Select:           | enter |\n");
        			printw("Bomb:             |\U0001F4A3|\n");
        			printw("Bombs:\n");
        			printw("When a bomb appears, it destroys all tiles of the same color on the board, creating additional combination opportunities.\n");
        			printw("\n\npress enter to leave");
        			refresh();
        			getch();
      			}
      			else{
    				clear();
    				printw("Welcome everyone to CY-Crush, where you'll dive into a sweet world filled with challenges and\ndelights. Get ready to match candies, create spectacular combos, and reach new levels of fun\n in this global gaming phenomenon.");
    				printw("\n\npress enter to continue and an arrow to leave");
    				refresh();
    				getch();
    				clear();
    				printw("Objective of the game:\n");
    				printw("The objective of the game is to match same-colored tiles to make them disappear and score points.\n\n");

    				printw("Chain combinations:\n");
    				printw("If two tiles of the same color are aligned on the left of the same row and a tile of the same color is aligned on the right of the same row (or vice versa), these three tiles are also destroyed.\n\n");
    				printw("Special combinations:\n");
    				printw("When five or more tiles of the same color are aligned horizontally or vertically, they are also destroyed, and a bomb appears on the board.\n\n");
    				printw("Endgame conditions:\n");
    				printw("The game ends when one of the following conditions is met:\n");
    				printw("a) There are no more possible combinations to match tiles and reduce the number of different colors on the board.\n");
    				printw("b) The number of different colors on the board is less than or equal to two.\n\n");
    				printw("Victory:\n");
    				printw("The player wins the game when the number of different elements on the board is less than or equal to two.\n");
    				printw("\n\npress enter to continue and an arrow to leave");
    				refresh();
   				getch();

      			}
    			break;  
    		default:
      			printf("Invalid input.Ividipu.\n");
      			sleep(0.5);
    	}
    }while (y);
    clear();
    return line;
  }
  if(game==1){
		do {
    		srand(time(NULL));
    		clear();
    		init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    		initscr();
    		start_color();
 
    
    		attron(COLOR_PAIR(1));  // Activer la paire de couleurs
    		printw("%s", text);
    		attroff(COLOR_PAIR(1));  // Désactiver la paire de couleurs       

			printw("             Press '↑' to move up, '↓' to move down and 'enter' to valid  \n\n");    


    		if (line == 0) {
     			printw("                                 \U0001F538 Continue \U0001F538\n");
      			printw("                                    New Game\n");
      			printw("                                      Save\n");
      			printw("                                      Quit\n");
      			printw("                                    Command \n");
      			printw("                                 About the Game\n");
			}
    		if (line == 1) {
      			printw("                                    Continue\n");
      			printw("                                 \U0001F538 New Game \U0001F538\n");
      			printw("                                      Save\n");
      			printw("                                      Quit\n");
      			printw("                                    Command \n");
      			printw("                                 About the Game\n");
    		}
    		if (line == 2) {
      			printw("                                    Continue\n");
      			printw("                                    New Game\n");
      			printw("                                   \U0001F538 Save \U0001F538\n");
      			printw("                                      Quit\n");
      			printw("                                    Command \n");
      			printw("                                 About the Game\n");
    		}
    		if (line == 3) {
      			printw("                                    Continue\n");
      			printw("                                    New Game\n");
      			printw("                                      Save\n");
      			printw("                                   \U0001F538 Quit \U0001F538\n");
      			printw("                                    Command \n");
      			printw("                                 About the Game\n");
    		}
			if (line == 4) {
      			printw("                                    Continue\n");
      			printw("                                    New Game\n");
      			printw("                                      Save\n");
      			printw("                                      Quit \n");
      			printw("                                 \U0001F538 Command \U0001F538\n");
      			printw("                                 About the Game\n");
    		}
    		if (line == 5) {
      			printw("                                    Continue\n");
      			printw("                                    New Game\n");
      			printw("                                      Save\n");
      			printw("                                      Quit \n");
      			printw("                                    Command\n");
      			printw("                              \U0001F538 About the Game \U0001F538\n");
    		}
    		refresh();
    		
    		switch (getch()) {
    			case 65:
          case 'z': 
      				if (line > 0)
        			line--;
					break;
    			case 66:
          case 's': 
      				if (line < 5)
        			line++;
      				break;
    			case '\n':
      				if(line!=4 && line !=5){
      				y = 0;
      				return line;
      				break;
      				}
      				else if(line==4){
        				clear();
      					printw("%s", Command);
        			        printw("\n\nAll command:\n");
        			        printw("Move up:          | ↑ |\n");
        			        printw("Move down:        | ↓ |\n");
        			        printw("Move right:       | → |\n");
        			        printw("Move left:        | ← |\n");
        			        printw("Open menu:        | m |\n");
        			        printw("Select:           | enter |\n");
        			        printw("Bomb:             |\U0001F4A3|\n");
        			        printw("Bombs:\n");
        			        printw("When a bomb appears, it destroys all tiles of the same color on the board, creating additional combination opportunities.\n");
        			        printw("\n\npress enter to leave");
        			        refresh();
        			        getch();
      				}
      				else{
    					clear();
    					printw("Welcome everyone to CY-Crush, where you'll dive into a sweet world filled with challenges and\ndelights. Get ready to match candies, create spectacular combos, and reach new levels of fun\n in this global gaming phenomenon.");
    					printw("\n\npress enter to continue and an arrow to leave");
    					refresh();
    					getch();
    					clear();
    					printw("Objective of the game:\n");
    					printw("The objective of the game is to match same-colored tiles to make them disappear and score points.\n\n");
						printw("Chain combinations:\n");
    					printw("If two tiles of the same color are aligned on the left of the same row and a tile of the same color is aligned on the right of the same row (or vice versa), these three tiles are also destroyed.\n\n");
    					printw("Special combinations:\n");
    					printw("When five or more tiles of the same color are aligned horizontally or vertically, they are also destroyed, and a bomb appears on the board.\n\n");
    					printw("Endgame conditions:\n");
    					printw("The game ends when one of the following conditions is met:\n");
    					printw("a) There are no more possible combinations to match tiles and reduce the number of different colors on the board.\n");
    					printw("b) The number of different colors on the board is less than or equal to two.\n\n");
    					printw("Victory:\n");
    					printw("The player wins the game when the number of different elements on the board is less than or equal to two.\n");
    					printw("\n\npress enter to continue and an arrow to leave");
    					refresh();
    					getch();
					}
    				break;
    			default:
      				printw("Invalid input.Ividipu.\n");
      				refresh();
      				sleep(0.5);
    		}
  		}while (y);
		clear();
  	return line;
  }
  return line;
}


//the function allows you to choose the type of action you want to do to load the game or save it
int menusauvegarde(int game){
 int loop=1;
 char saveword[] =    "                       ███████╗ █████╗ ██╗   ██╗███████╗\n"
                      "                       ██╔════╝██╔══██╗██║   ██║██╔════╝\n"
                      "                       ███████╗███████║██║   ██║█████╗  \n"
                      "                       ╚════██║██╔══██║╚██╗ ██╔╝██╔══╝  \n"
                      "                       ███████║██║  ██║ ╚████╔╝ ███████╗\n"
                      "                       ╚══════╝╚═╝  ╚═╝  ╚═══╝  ╚══════╝\n";
  
  
  int line=0;
  if(game==0){
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
  	do{
    	clear();
      attron(COLOR_PAIR(1));  // Activer la paire de couleurs
  	 	printw("%s\n",saveword);
  	  attroff(COLOR_PAIR(1));
  		printw("             Press '↑' to move up, '↓' to move down and 'enter' to valid  \n\n");    		if (line == 0) {
      		printw("                        \U0001F538 Continue with Default Save \U0001F538\n");
      		printw("                          Continue with your own backup\n");
      		printw("                                    New Game\n");
    	}
    	if (line == 1) {
      		printw("                           Continue with Default Save\n");
      		printw("                       \U0001F538 Continue with your own Backup \U0001F538\n");
      		printw("                                    New Game\n");
    	}
    	if (line == 2) {
      		printw("                           Continue with Default Save\n");
      		printw("                          Continue with your own Backup\n");
      		printw("                                 \U0001F538 New Game \U0001F538\n");
      		refresh();
    	}
    	refresh();
    	char input[2];
    	input[0]=getch();
    	switch (input[0]) {
      		case 65:
          case 'z': 
        		if (line > 0)
          		line--;
				break;
      		case 66:
          case 's':   
        		if (line < 2)
          		line++;
        		break;
      		case '\n':
        		loop = 0;
        		return line;
        		break;
      		default:
        		printw("Invalid input.Ividipu.\n");
      	}
  	}while (loop);
    
  }  
  if(game==1){
  	do{
    	clear();
  		attron(COLOR_PAIR(1));  // Activer la paire de couleurs
  	 	printw("%s\n",saveword);
  	  attroff(COLOR_PAIR(1));
  		printw("                Press '↑' to move up, '↓' to move down and 'enter' to valid  \n\n");    		if (line == 0) {
      		printw("                        \U0001F538 Continue with Default Save \U0001F538\n");
      		printw("                          Continue with your own backup\n");
      	}
    	if (line == 1) {
      		printw("                           Continue with Default Save\n");
      		printw("                       \U0001F538 Continue with your own Backup \U0001F538\n");
      	}
    	refresh();
    	
    	switch (getch()) {
      		case 65:
        		if (line > 0)
          		line--;
				break;
      		case 66:
        		if (line < 1)
          		line++;
        		break;
      		case '\n':
        		loop = 0;
        		break;
      		default:
        		printw("Invalid input.Ividipu.\n");
      	}
  	}while (loop);
  }
  return line;  
}

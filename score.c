#include "Tab.h"



//this fonction take all the record save in this files and add you score inside
int write_score_to_file(int score, const char *filename, int tab_record[1000]) {
    FILE *file = fopen(filename, "r+");
    if (file == NULL) {
        printw("opening file error %s.\n", filename);
        return 0;
    }
	char line[256];
    int line_number = 0;
    int empty_line_found = 0;
	while (fgets(line, sizeof(line), file)) {
        line_number++;
        if (line[0] == '\n') {
            empty_line_found = 1;
            break;
        }
        sscanf(line, "%d", &tab_record[line_number]);
    }
	if (empty_line_found) {
        fseek(file, 0, SEEK_CUR);
        for (int i = 1; i < line_number; i++) {
            fgets(line, sizeof(line), file);
            sscanf(line, "%d", &tab_record[i]);
        }
    } 
	else {
        fseek(file, 0, SEEK_END);
    }
	fprintf(file, "%d\n", score);
    tab_record[line_number+1] = score; // Enregistre le score dans tab_record
    fclose(file);
    line_number++;
  	return line_number;
}
//this function sorts the values of the array of records in descending order
void sort_array_descending(int tab_record[], int size) {
    int i, j, temp;
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size+1; j++) {
            if (tab_record[i] < tab_record[j]) {
                temp = tab_record[i];
                tab_record[i] = tab_record[j];
                tab_record[j] = temp;
            }
        }
    }
}
//this fonction is the end page when you win the game.It print best scores
void print_record(int tab_record[100], int score){
  	clear();
  
  	char text[] =     "██████╗ ██████╗  █████╗ ██╗   ██╗ ██████╗ \n"
                      "██╔══██╗██╔══██╗██╔══██╗██║   ██║██╔═══██╗\n"
                      "██████╔╝██████╔╝███████║██║   ██║██║   ██║\n"
                      "██╔══██╗██╔══██╗██╔══██║╚██╗ ██╔╝██║   ██║\n"
                      "██████╔╝██║  ██║██║  ██║ ╚████╔╝ ╚██████╔╝\n"
                      "╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝  ╚═══╝   ╚═════╝ \n";       
  	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
  	attron(COLOR_PAIR(1));  // Activer la paire de couleurs
  	printw("%s\n",text);
  	attroff(COLOR_PAIR(1));  // Désactiver la paire de couleurs
  	printw("Your final score is %d\n", score);
  	refresh();
  	printw("                          Record\n");
  	refresh();
    for (int i = 0; i < 4; i++) {
        if(tab_record[i] != score){                
            printw("                          %d\n", tab_record[i]);
            refresh();
        }
        else{
        	printw("                         \U0001F538 %d \U0001F538\n", tab_record[i]);
            refresh();
        }
    }
        printw("\n\nPress 'enter' to leave\n");
        refresh();
	getch();
}

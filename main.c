#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Tab.h"

int main(void)
{
    bool r = false;
    createTab();
    do
    {

        fillTab();
        r = verifTab();

    } while (r == true);
    
   // bool playAgain = true;
    //while (playAgain)
    //{
     //   play();
    //}

   
int type, score;
score=0;

    printTab();
    do{
    inverse();
    type = verificateurcontinu();
    if(type==1 || type ==2){
        score++;
        printf("score: %d\n", score);
    }
    supprimeur();
    printTab();

    }while(score<10);
     
     inverse();
     type = verificateurcontinu();
   supprimeur();
    printTab();
    return 0;
}


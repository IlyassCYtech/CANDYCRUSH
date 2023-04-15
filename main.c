#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Tab.h"


int main(void)
{
    int r = 0;
    createTab();
     fillTab();
do
{
    r = verificateurcontinu();
    supprimeur();
    fillTab1();
    } while (r == 1 || r==2);
    
   // bool playAgain = true;
    //while (playAgain)
    //{
     //   play();
    //}

   
int type, score;
score=0;

    printTab(score);
    do{
    inverse(score);
    printf("Score: %d\n\n", score);
    type = verificateurcontinu();
    if(type==1 || type ==2){
        score++;
        printf("Score: %d\n", score);
    }
    supprimeur();
    gravity();
    fillTab1();
    do
{
    r = verificateurcontinu();
    if(r==1 || r==2){
        score++;
        printf("Score: %d\n", score);
    }
    supprimeur();
    fillTab1();
    } while (r == 1 || r==2);
    
printf("Score: %d\n", score);
if(score>100){
return 0;

}
 } while(score<100);

     
   
    return 0;
}


/*
   # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
   #                                                       #
   #    AUTHOR: SANTOS, Mateus Henrique                    #
   #    COPYRIGHT (C) MATEUS HENRIQUE DOS SANTOS, 2021     #
   #                                                       #
   # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
*/

#include <stdio.h>
#include <string.h>
#include <ncurses.h>

int main() 
{
    char userName[10]; //username
    char passWord[10]; //password
    
    printf("\nType your username:\n");
    scanf("%s", &userName);
    
    printf("\nEnter your password:\n");
    scanf("%s", &passWord);
    
    if(strcmp(userName, "user")==0){
        if(strcmp(passWord, "246")==0){
            printf("\nLogin succesfull!\n");
        }else{
            printf("\nWrong password!\n"); //'ifs' gone wrong...
        }
    }
    
    return 0;
}

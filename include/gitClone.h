#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool readUrlGitRepo(const char url[]){
    bool result = true;
    const int strT = strlen(url);

    for(int k = 0; k < strT; k++){

        if(strcmp(url[k], "&" || "|" || ";" || ) == 0){

            result = false;

        }


    } 


    return result;
}


#endif 
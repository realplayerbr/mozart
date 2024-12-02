#include "../include/gitClone.h"

int main(int argc, char *argv[]) {
    if(argc<2){
        printf("mozart beta 0.0.1");
    }

    if(strcmp(argv[1], "clone") == 0){
    char url[]="\0";
    printf("url repo: ");
    scanf("%s", url);

    if(readUrlGitRepo(url)){
        char command[200];
        sprintf(command, "git clone %s", url);
        system(command);
    }
    }

    return 0;
}

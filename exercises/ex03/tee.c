#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FILENAME 255
int A_FLAG = 0;
int P_FLAG = 0;

int main(int argc, char *argv[]){
    char ch;
    char f[MAX_FILENAME];
    // parse arguments
    while((ch = getopt(argc, argv, "ap")) != EOF){
        switch (ch){
            case 'a':
                A_FLAG = 1;
            break;
            case 'p':
                P_FLAG = 1;
            break;
            default:
                fprintf(stderr, "Error: unknown flag");
                return 1;
        }
    }
    argc -=optind;
    argv +=optind;

    // if no file name supplied or more than one supplied
    if(argv[0]==NULL || argv[1] != NULL){
        fprintf(stderr, "Error: Exactly one file name required\n");
        return 1;
    }
    // if file name exceeds 255 characters
    if(strlen(argv[0]) > 255){
        fprintf(stderr, "Error: The max character number for file names is 255");
        return 1;
    }
    else{
        strcpy(f,argv[0]);
    }
    
    return 0;
}
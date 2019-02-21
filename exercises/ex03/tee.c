#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FILENAME 255
#define MAX_FILECOUNT 1000
int A_FLAG = 0;
int P_FLAG = 0;

int main(int argc, char *argv[]){
    char ch;
    char f[MAX_FILECOUNT][MAX_FILENAME];
    int file_count = 0;
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
    if(argv[0] == NULL){
        fprintf(stderr, "Error: At least one file required\n");
        return 1;
    }
    while(argv[file_count] != NULL && file_count < MAX_FILECOUNT){
        // if file name exceeds 255 characters
        if(strlen(argv[file_count]) > 255){
            fprintf(stderr, "Error: The max character number for file names is 255");
            return 1;
        }
        else{
            strcpy(f[file_count],argv[file_count]);
        }
        file_count++;
    }
    return 0;
}
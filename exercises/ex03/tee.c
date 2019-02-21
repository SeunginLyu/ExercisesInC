#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FILENAME 255
#define MAX_FILECOUNT 255
int A_FLAG = 0;
int P_FLAG = 0;

void open_files(FILE* file[MAX_FILECOUNT], char f[MAX_FILECOUNT][MAX_FILENAME], int file_count){
    for(int i = 0;i < file_count;i++){
        if(A_FLAG){
            file[i] = fopen(f[i],"a");
        }else{
            file[i] = fopen(f[i],"w");
        }
    }
}
void close_files(FILE* file[MAX_FILECOUNT], char f[MAX_FILECOUNT][MAX_FILENAME], int file_count){
    for(int i = 0;i < file_count;i++){
        fclose(file[i]);
    }
}
int arg_parse(int* argc, char* argv[]){
    // parse arguments
    char ch;
    while((ch = getopt(*argc, argv, "ap")) != EOF){
        switch (ch){
            case 'a':
                A_FLAG = 1;
            break;
            case 'p':
                P_FLAG = 1;
            break;
            default:
                fprintf(stderr, "Error: Unknow Flag");
                return 1;
        }
    }
    (*argc) -=optind;
    argv += optind;
    if(argv[0] == NULL){
        fprintf(stderr, "Error: At least one file required\n");
        return 1;
    }
    return 0;
}
int copy_filename(char* argv[], char file_name[MAX_FILECOUNT][MAX_FILENAME], int* file_count){
    while(argv[(*file_count)+1] != NULL && *file_count < MAX_FILECOUNT){
        // if file name exceeds MAX_FILENAME characters then error else copy to f
        if(strlen(argv[(*file_count)+1]) > MAX_FILENAME){
            fprintf(stderr, "Error: The max character number for file names is 255");
            return 1;
        }
        else{
            strcpy(file_name[*file_count], argv[(*file_count)+1]);
        }
        (*file_count)++;
    }
    return 0;
}
int main(int argc, char *argv[]){
    int file_count = 1;
    int* argc_p = &argc;
    char file_name[MAX_FILECOUNT][MAX_FILENAME];
    FILE* file[MAX_FILECOUNT];
    if(arg_parse(argc_p, argv)){
        return 1;
    }
    if(copy_filename(argv, file_name, &file_count)){
        return 1;
    }
    open_files(file, file_name, file_count);
    close_files(file, file_name, file_count);
    return 0;
}
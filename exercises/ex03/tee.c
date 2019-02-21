#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define MAX_FILENAME 255
#define MAX_FILECOUNT 255
#define BUFSIZE 1000
int A_FLAG = 0;
int I_FLAG = 0;

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
int arg_parse(int argc, char* argv[]){
    // parse arguments
    char ch;
    while((ch = getopt(argc, argv, "ai")) != EOF){
        switch (ch){
            case 'a':
                A_FLAG = 1;
            break;
            case 'i':
                I_FLAG = 1;
            break;
            default:
                fprintf(stderr, "Error: Unknow Flag");
                return 1;
        }
    }
    return 0;
}
int copy_filename(char* argv[], char file_name[MAX_FILECOUNT][MAX_FILENAME], int* file_count){
    while(argv[*file_count] != NULL && *file_count < MAX_FILECOUNT){
        // if file name exceeds MAX_FILENAME characters then error else copy to f
        if(strlen(argv[*file_count]) > MAX_FILENAME){
            fprintf(stderr, "Error: The max character number for file names is 255");
            return 1;
        }
        else{
            strcpy(file_name[*file_count], argv[*file_count]);
        }
        (*file_count)++;
    }
    return 0;
}
int process_tee(FILE* file[MAX_FILECOUNT], int file_count){
    char temp[BUFSIZE];
    int err;
    while((fgets(temp,BUFSIZE,stdin)) != NULL){
        fprintf(stdout, "%s",temp);
        for(int i=0;i<file_count;i++){
            fprintf(file[i], "%s",temp);
        }
    }
    return 0;
}
void ignore(int sig)
{            
    fprintf( stderr, "\n"); // Print a new line
    // This function does nothing except ignore ctrl-c
}
int main(int argc, char *argv[]){
    int file_count = 0;
    char file_name[MAX_FILECOUNT][MAX_FILENAME];
    FILE* file[MAX_FILECOUNT];
    if(arg_parse(argc, argv)){
        return 1;
    } else {
        argc -=optind;
        argv += optind;
        if(argv[0] == NULL){
        fprintf(stderr, "Error: At least one output file required\n");
        return 1;
        }
    }
    // -i will ignore interrup
    if(I_FLAG){
        if (signal(SIGINT, SIG_IGN) != SIG_IGN){
            signal(SIGINT, ignore);
        }
    }
    if(copy_filename(argv, file_name, &file_count)){
        return 1;
    }
    open_files(file, file_name, file_count);
    if(process_tee(file, file_count)){
        return 1;
    }
    close_files(file, file_name, file_count);
    return 0;
}

/* 
Reflection
----------------------------------------------------------------------------------------
Question 3.
I first began by thinking about the different components I need to build tee, which were
1) Argument parser for flags and file names
2) A way to process store file names for opening files and closing files.
3) A function to process stdin and copy to stdout and write to files.
Then I first ended up writing a huge main function that contained all the components,
so I refactored them into several functions. Refactorting defeintely did slow me down a little because
now I had to pass pointers to the new functions and I inevitably made mistakes and spent time debugging
when I began to use more pointers. However, I like the refactored version 
because I can easily comprehend what's going on in this program 
just by looking at the function calls in the main function. 
Thinking about error handling slowed me down a little, 
and I ended up not handling some errors (like file opens) assuming all files would be valid.
Next time, I would like to start by writing out the interfaces of each function so that I don't spend
extra time trying to refactor them, or at least minimize the time taken into refactoring.
----------------------------------------------------------------------------------------
Question 4.
I looked at the professional version, and here are the major differences I found.

1. Header declaration
    void	add __P((int, char *));
    int	main __P((int, char **));
2. The usage of "pipes" -> Open, Read, Write, Warn (#include <unistd.h>)
    instead of using fgets, fprintf
    I guess this is the reason why I could not get the results from 
    ping google.com | ./tee.out ping.txt
    because without establishing the pipes I won't get stdin if I interrupt it?
    (but it works with a -i flag on mine as well, but the original tee works without the -i flag)
3. The usage of linked list(struct) to represent pipes(I think is super cool) 
    instead of using a counter variable for files
4. Dynamic memory allocation for buffers
    instead of defining a maximum buffer length
5. (void)signal(SIGINT, SIG_IGN) for ignoring the interrupt
    instead of 
        if (signal(SIGINT, SIG_IGN) != SIG_IGN){
            signal(SIGINT, ignore);
        }
----------------------------------------------------------------------------------------
*/
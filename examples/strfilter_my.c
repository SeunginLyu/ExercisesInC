#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* strfilter(char* string, char* letters){
    char* string_copy = strdup(string);
    char* letters_copy = strdup(letters);
    char* letters_copy_origin = letters_copy;
    char* res = malloc(sizeof(char)*strlen(string_copy));
    char* res_origin = res;
    for(int j=0;j<strlen(string_copy);j++){
        for(int i=0;i<strlen(letters_copy);i++){
            if(*string_copy==*(letters_copy++)){
                *(res++)=*(string_copy++);
                break;
            }
        }
        letters_copy = letters_copy_origin;
    }
    *res = '\0';
    return res_origin;
}

int main(){
    char* string = "equation";
    char* letters = "aeiou";
    char* res = strfilter(string, letters);
    printf("%s\n", res);
    return 0;
}
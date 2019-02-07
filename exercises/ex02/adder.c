/* This program allows the user to enter integers, one per line,
 * until the user hits Control-D, which is the end-of-file (EOF) character.
 * After the user enters Control-D, the program adds up the numbers in the array and print the result
 * Seungin Lyu, Software Systems SP19, Olin College of Engineering
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
int convert_to_int(char *s){
    int val = atoi(s);
    if (val == 0){
        printf("Error: Your input is either zero or can't be converted to an integer\n");
    }
    return val;
}
void receive_input(char *s){
    puts("Please Enter an Integer Value");
    scanf("%s", s);
}
int main(){
    int num[MAX_SIZE];
    int count = 0;
    int sum = 0;
    char s[100]; 
    do {
        receive_input(s);
        // Check input size
        if(!feof(stdin)){
            if (strlen(s) > 10){
            // max int = 2,147,483,647 (10 digits + null terminator)
            printf("Error: Your input exceeds the length of the input buffer(10)\n");
            }
            else {
                // check if it doesn't exceed the array max size
                if (count < MAX_SIZE) {
                    num[count] = convert_to_int(s);
                    count++;
                } else {
                    printf("Error: You put more numbers than will fit in the array of size %i\n", MAX_SIZE);
                }
            }
        }
    } while(!feof(stdin));
    for (int i = 0; i < count; i++){
        sum += num[i];
    }
    printf("Sum : %i\n", sum);
    return 0;
}

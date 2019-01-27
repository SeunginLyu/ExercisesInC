/* Seungin Lyu, Olin College Softsys SP19, Homework 1
 * This code receives a card name, then evaluates the card value
 * and returns the card count
 * which goes up by 1 if card value is between 3~6(inclusive)
 * and goes down by 1 if cald value is 10, J, Q, or K 
*/

#include <stdio.h>
#include <stdlib.h>

/* Prompts the user for input and puts the reply in the given buffer.

       User input is truncated to the first two characters.

       prompt: string prompt to display
       card_name: buffer where result is stored
*/
void get_card_name(char *prompt, char *card_name){
    puts(prompt);
    scanf("%2s", card_name);
}

/* Returns the integer value for given card_name input.
    Prints error if given unknown card_name

       card_name: buffer where card_name is stored
       val: interger value that corrsponds to given card_name
*/
int get_card_value(char *card_name){
    int val = 0;
    switch(card_name[0]) {
        case 'K':
        case 'Q':
        case 'J':
            val = 10;
            break;
        case 'A':
            val = 11;
            break;
        case 'X':
            break;
        default:
            val = atoi(card_name);
            if ((val < 1) || (val > 10)){
                puts("I don't understand that value");
                break;
            }
    }
    return val;
}
/* Returns the integer card count for given card value

       count: goes up by 1 for val is between 3-6(inclusive)
              goes down by 1 if val is 10
*/
int get_count(int val, int count){
    if ((val > 2) && (val < 7)){
        count++;
    } else if (val == 10) {
        count--;
    }
    return count;
}
/* Main function that runs a while loop to keep card count

       card_name: buffer for given card name
       count: integer representing card count
*/
int main(){
    char card_name[3];
    int count = 0;
    char *prompt = "Enter the card_name: ";
    do {
        get_card_name(prompt, card_name);
        count = get_count(get_card_value(card_name), count);
        printf("Current count: %i\n", count);
    } while (card_name[0] != 'X');
    return 0;
}
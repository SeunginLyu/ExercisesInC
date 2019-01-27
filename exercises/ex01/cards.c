#include <stdio.h>
#include <stdlib.h>
void get_card_name(char *prompt, char *card_name){
    puts(prompt);
    scanf("%2s", card_name);
}
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
int get_count(int val, int count){
    if ((val > 2) && (val < 7)){
        count++;
    } else if (val == 10) {
        count--;
    }
    return count;
}
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
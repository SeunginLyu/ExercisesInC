#include <stdio.h>
#include <stdlib.h>

int card_value(char *card_name){
    int val = -1;
    switch (card_name[0]){
        case 'K':
        case 'Q':
        case 'J':
            val = 10;
            break;
        case 'A':
            val = 11;
            break;
        default:
            val = atoi(card_name);
            if ((val >= 1)) && (val <= 10)) {
                break;
            }
            else {
                val= -1;
                break;
            }
        return val;
    }
}

void update_count(int *val, int *count){
    if ((val >2) && (val <7)){
        *count += 1;
    } else if (val == 10){
        (*count)--;
    }
}

int main(){
    char card_name[3];
    int count = 0;

    while (card_name[0] !='X'){
        puts("eee");
        scanf("%2s", card_name);
        int *val = card_value(card_name);
        update_count(val, &count);
        printf("current count: %i\n", count);
    }
    return 0;
}
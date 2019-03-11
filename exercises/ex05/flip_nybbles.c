#include <stdint.h>
#include <stdio.h>

uint8_t flip_nybbles(uint8_t x){
    uint8_t a = 0;
    uint8_t b = 0;
    for(int i=7;i>0;i=i-2){
        a = a | (x>>i);
    }
    for(int i=0;i<8;i=i+2){
        b = b | (x<<i);
    }
    return a&b;
}
int main(){
    uint8_t a = 1;
    uint8_t b = flip_nybbles(a);
    printf("%d", b);
    return 0;
}
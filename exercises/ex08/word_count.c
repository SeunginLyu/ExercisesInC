#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <glib.h>


void countWords(GHashTable* counter, FILE* target){
    
}
void printCounter(GHashTable* counter){

}

int main(int argc, char** argv) {

    if (argc != 2){
        printf("[*] Usage: %s <file>\n", argv[0]);
        return -1;
    }
    printf("Word Count Target : %s\n", argv[1]);
    FILE* target = fopen(argv[1],"r");
    GHashTable* counter = g_hash_table_new(g_str_hash, g_str_equal);
    countWords(counter, target);
    printCounter(counter);
    fclose(target);
   

    // g_hash_table_insert(hash, "Virginia", "Richmond");
    // g_hash_table_insert(hash, "Texas", "Austin");
    // g_hash_table_insert(hash, "Ohio", "Columbus");
    // printf("There are %d keys in the hash\n", g_hash_table_size(hash));
    // printf("The capital of Texas is %s\n", g_hash_table_lookup(hash, "Texas"));
    // gboolean found = g_hash_table_remove(hash, "Virginia");
    // printf("The value 'Virginia' was %sfound and removed\n", found ? "" : "not ");
    // g_hash_table_destroy(hash);
    return 0;
}

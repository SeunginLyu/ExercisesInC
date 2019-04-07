#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <glib.h>
#include <glib/gstdio.h>


void countWords(char* contents){
    
}
void printCounter(GHashTable* counter){

}

int main(int argc, char** argv) {

    if (argc != 2){
        g_printf("[*] Usage: %s <file>\n", argv[0]);
        return -1;
    }
    char* file = argv[1];
    if (!g_file_test (file, G_FILE_TEST_EXISTS)) {
        g_printf("File <%s> does not exist \n", argv[1]);
        return -1;
    }
    g_printf("Word Count Target : %s\n", argv[1]);
    char* contents;
    GError* get_error;
    gboolean get_success = g_file_get_contents (file, &contents, NULL, &get_error);
    if(!get_success){
        g_error("%s \n", get_error->message);
        g_clear_error (&get_error);
        return -1;
    }
    GHashTable* counter = g_hash_table_new(g_str_hash, g_str_equal);
    countWords(contents);
    printCounter(counter);
   

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

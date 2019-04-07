#include <glib.h>
#include <glib/gstdio.h>


GHashTable* initCounter(gchar* contents){
    gchar** split_contents = g_strsplit (contents, " ", -1);
    GHashTable* counter = g_hash_table_new(g_str_hash, g_str_equal);
    int i =0;
    while(split_contents[i] !='\0'){
        gchar* key = split_contents[i];
        char *pos;
        // remove newline character from key
        if ((pos=strchr(key, '\n')) != NULL) *pos = '\0';
        
        // remove punctuation from key
        size_t pos1 = 0;
        for (char *p = key; *p; ++p){
            if (g_ascii_isalpha(*p)){
                key[pos1++] = *p;
            }
        }
        key[pos1] = '\0';
        gpointer v;
        gboolean exists = g_hash_table_lookup_extended(counter, key, NULL, &v);
        if(!exists){
            // g_printf("init %s : %i\n", key, 1);
            g_hash_table_insert(counter, key, GINT_TO_POINTER(1));
        } else {
            gpointer new_value = GINT_TO_POINTER(GPOINTER_TO_INT(v) + 1);
            // g_printf("replace %s : %i\n", key, GPOINTER_TO_INT(new_value));
            g_hash_table_replace(counter, key, new_value);
        }
        i++;
    }
    return counter;
}
void printKeyValue(gpointer key, gpointer value, gpointer userdata)
{
    g_printf("%s : %i\n", key, GPOINTER_TO_INT(value));
}
void printCounter(GHashTable* counter){
    g_hash_table_foreach(counter, printKeyValue, NULL);
}


int main(int argc, char** argv) {
    if (argc != 2){
        g_error("[*] Usage: %s <file>\n", argv[0]);
        return -1;
    }
    gchar* file = argv[1];

    // check if file exists
    if (!g_file_test (file, G_FILE_TEST_EXISTS)) {
        g_error("File <%s> does not exist \n", argv[1]);
        return -1;
    }
    g_printf("Word Count Target : %s\n", argv[1]);
    
    // get contents from file
    gchar* contents;
    GError* get_error;
    gboolean get_success = g_file_get_contents (file, &contents, NULL, &get_error);
    if(!get_success){
        g_error("%s \n", get_error->message);
        g_clear_error (&get_error);
        return -1;
    }
    

    GHashTable* counter = initCounter(contents);
    printCounter(counter);

    // free stuff
    g_free(contents);
    g_hash_table_destroy(counter);
    return 0;
}

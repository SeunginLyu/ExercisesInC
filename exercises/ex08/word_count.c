#include <glib.h>
#include <glib/gstdio.h>


GHashTable* initCounter(gchar* contents){
    gchar** split_contents = g_strsplit (contents, " ", -1);
    GHashTable* counter = g_hash_table_new(g_str_hash, g_str_equal);
    int i;
    for(i=0; i<sizeof(split_contents);i++){
        gchar* key = split_contents[i];
        gpointer c = g_hash_table_lookup(counter, key);
        gint* new_value = g_new(gint, GPOINTER_TO_INT(c)+1);
        if(c == NULL){
            g_printf("init %s : %i\n", key, 0);
            g_hash_table_insert(counter, key, g_new(gint, 0));
        }else{
            g_printf("replace %s : %i\n", key, GPOINTER_TO_INT(new_value));
            g_hash_table_replace(counter, key, new_value);
        }
    }
    
    g_strfreev(split_contents);
    return counter;
}
void printKeyValue(gpointer key, gpointer value, gpointer userdata)
{
    // g_printf("%s : %i\n", key, GPOINTER_TO_INT(value));
}
void printCounter(GHashTable* counter){
    g_hash_table_foreach(counter, printKeyValue, NULL);
}

int main(int argc, char** argv) {
    if (argc != 2){
        g_printf("[*] Usage: %s <file>\n", argv[0]);
        return -1;
    }
    gchar* file = argv[1];

    // check if file exists
    if (!g_file_test (file, G_FILE_TEST_EXISTS)) {
        g_printf("File <%s> does not exist \n", argv[1]);
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

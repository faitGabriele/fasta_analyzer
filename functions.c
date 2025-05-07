#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Everything come down to pointers, memory and dereferences

char *add_char_to_string(char *old_string, char new_char);
int add_char_to_string2(const char *old_string, char **new_string, char new_char);


int main (void) {

    char *old_str = "Hello";
    char *new_str = NULL;

    char new_char = '!';

    printf("%s\n", old_str);

    int j = add_char_to_string2(old_str, &new_str, new_char);
    printf("%i\n", j);
    if (j == 0) {
        printf("%s and %s\n", old_str, new_str);
        free(new_str);
        new_str = NULL;
    }

    char *string1 = "Hello";
    char c = '!';

    char *string2 = add_char_to_string(string1, c);

    printf("%s, %s\n", string1, string2);
}

int add_char_to_string2(const char *old_string, char **new_string, char new_char) {
    int old_string_length = strlen(old_string);
    int new_string_size = (old_string_length + 2) * sizeof(char);
    *new_string = malloc(new_string_size);

    if (*new_string == NULL) {
        return -1;
    }

    strcpy(*new_string, old_string);
    (*new_string)[old_string_length] = new_char;
    (*new_string)[old_string_length + 1] = '\0';
    return 0;
}

char *add_char_to_string(char *old_string, char new_char) {
    int old_string_length = strlen(old_string);

    int new_string_size = (old_string_length + 1) * sizeof(char);
    char *new_string = malloc(new_string_size);

    for (int i = 0; i < old_string_length; i ++) {
        new_string[i] = old_string[i];
    }
    new_string[old_string_length] = new_char;
    return new_string;
}

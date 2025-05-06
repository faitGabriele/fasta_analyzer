#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Everything come down to pointers, memory and dereferences

char *add_char_to_string(char *old_string, char new_char);

int main (void) {
    char *string1 = "Hello";
    char c = '!';

    char *string2 = add_char_to_string(string1, c);

    printf("%s, %s\n", string1, string2);
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

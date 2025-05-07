#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *start = "La mia casa è grande e luminosa";

    char *str = malloc(sizeof(char)*2);

    int length = strlen(start);
    for (int i = 0; i < length; i ++) {
        if (strlen(str) < 3) {
            str[0] = start[i];
            str[1] = '\0';
            printf("%s\n", str);
        }
        else {
            char *temp = str;
            char *new_str = realloc(str, sizeof(char)*(strlen(str)+2));
            strcpy(new_str, temp);
            new_str[strlen(temp)] = start[i];
            new_str[strlen(temp) + 1]  = '\0';

            str = new_str;
            printf("%s\n", str);
        }
    }
}
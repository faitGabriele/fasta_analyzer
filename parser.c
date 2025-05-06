// C implemented parser for FASTA file

// Importing libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int defline_parser(char *sequence, int sequence_length);
char *add_char_to_string(char *old_string, char new_char);

// Data structure for every token
typedef struct {
    char* type;
    char* value;
    int line;
    int column;
} Token;

// Grammar rules of FASTA
char* token_spec[4][2] = {{"OPERATORS", "\n+"}, {"DEFLINE", "^>.(\r\n|\r|\n)"}, {"NUC", "[ATGCU]"}, {"SPEC_NUC", "[NKMBVSWDYRH-]"}};

// Function that go through the text or string and divide it in token and put all the token in an array

int main(void) {
    // Standard line of text 
    char* standard_sequence = ">Sequence1 Homo_sapiens chromosome 1\nATGCATGCATGCATGCATGCATGCATGCATGCATGCATGCATGCATGCATGCATGCATGC\nCGTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAG\nTATATATATATATATATATATATATATATATATATATATATATATATATATATATATAT\n";
    
    printf("%s\n", standard_sequence);
    // Iterate through the sequence and print each element of the string
    int sequence_length = strlen(standard_sequence);
    printf("%i\n", sequence_length);

    for (int i = 0; i < sequence_length; i++) {
        char c1 = standard_sequence[i];
        
        if (c1 == '>') {
            // Start the defline
            char *string1 = "";
            for (int j = i; j < sequence_length; j ++) {
                char c2 = standard_sequence[j];
                char *temp;
                strcpy(temp, string1);
                string1 = add_char_to_string(temp, c2);

                if (c2 == '\n') {
                    printf("%s\n", string1);
                }
            }            
        }
    }

    defline_parser(standard_sequence, sequence_length);

    char *old_str = "Hello";
    char new_char = '!';

    char *new_str = add_char_to_string(old_str, new_char);

    printf("%s\n", new_str);
}

// Function to recognize each defline in the file
int defline_parser(char *sequence, int sequence_length) {
    char *defline;
    for (int i = 0; i < sequence_length; i++) {
        char c = sequence[i];

        if (c == '>') {
            // Here starts the defline
            int defline_size = sizeof(char) * strlen(defline);
            defline += c;
            printf("%s\n", defline);
        }
        else if ( c == '\n') {
            printf("\n");
            return 0;
        }
    }
}
// increase a string's size to add a new char in the end
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
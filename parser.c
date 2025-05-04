// C implemented parser for FASTA file

// Importing libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
    char* standard_sequence = ">Sequence1 Homo_sapiens chromosome 1 ATGCATGCATGCATGCATGCATGCATGCATGCATGCATGCATGCATGCATGCATGCATGC CGTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAG TATATATATATATATATATATATATATATATATATATATATATATATATATATATATAT";
    
    // Iterate through the sequence and print each element of the string
    int sequence_length = strlen(standard_sequence);
    printf("%i\n", sequence_length);

    for (int i = 0; i < sequence_length; i++) {
        char c = standard_sequence[i];
        printf("%c\n", c);
    }
}

char* name = "Luca";

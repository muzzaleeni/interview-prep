#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool vowel(char c) {
    switch(tolower(c)){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}


char* munch(char* sentence) {
    char* response = malloc(sizeof(char) * 100);
    // TODO eat those vowels!
    for (int i = 0; i < strlen(sentence); i++) {
        response[i] = sentence[i];
        if (vowel(sentence[i])) {
            response[i] = 'X';
        }
    }
    return response;
}

int main() {
    char sentence[100];
    // TODO read input
    if (fgets(sentence, sizeof(sentence), stdin) == NULL) {
        printf("Error reading the user input");
    }
    printf("INPUT: %s\n", sentence);
    printf("OUTPUT: %s\n", munch(sentence));
}
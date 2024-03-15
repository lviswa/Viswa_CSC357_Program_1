#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *fp = stdin; 
    int lines = 0, words = 0, chars = 0;
    int counter = 0; 
    char ch;

    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            fprintf(stderr, "No file %s\n", argv[1]);
            return 1;
        }
    }

    while ((ch = getc(fp)) != EOF) {
        chars++;

        if (ch == '\n') {
            lines++; 
        }

        if (isspace(ch)) {
            if (counter) {
                words++; 
                counter = 0; 
            }
        } else {
            counter = 1; 
        }
    }

    if (counter) {
        words++;
    }

    printf("Lines: %d, Words: %d, Characters: %d\n", lines, words, chars);

    if (fp != stdin) {
        fclose(fp); 
    }

    return 0;
}

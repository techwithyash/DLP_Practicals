#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_LEN 256


const char *keywords[] = {
    "int", "float", "char", "if", "else", "while", "return", "for", "void", "struct"
};

int isKeyword(char *word) {
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isOperator(char ch) {
    char operators[] = "+-*/=<>!&|";
    for (int i = 0; i < strlen(operators); i++) {
        if (ch == operators[i]) {
            return 1;
        }
    }
    return 0;
}
void lexicalAnalyzer(FILE *file) {
    char buffer[MAX_LEN];
    char ch;
    int i = 0;

    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch)) {
            continue;
        }
        if (isalpha(ch)) {
            buffer[i++] = ch;
            while ((ch = fgetc(file)) != EOF && (isalnum(ch) || ch == '_')) {
                buffer[i++] = ch;
            }
            buffer[i] = '\0';
            i = 0;
            ungetc(ch, file);

            if (isKeyword(buffer)) {
                printf("Keyword: %s\n", buffer);
            } else {
                printf("Identifier: %s\n", buffer);
            }
        }

        else if (isdigit(ch)) {
            buffer[i++] = ch;
            while ((ch = fgetc(file)) != EOF && isdigit(ch)) {
                buffer[i++] = ch;
            }
            buffer[i] = '\0';
            i = 0;
            ungetc(ch, file);

            printf("Constant: %s\n", buffer);
        }
        else if (isOperator(ch)) {
            printf("Operator: %c\n", ch);
        }
        else if (strchr("(){};,.[]", ch)) {
            printf("Punctuation: %c\n", ch);
        }
        else {
            printf("Lexical Error: Invalid character '%c'\n", ch);
        }
    }
}
int main() {
    char filename[MAX_LEN];
    FILE *file;
    printf("Enter the C source file name: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return 1;
    }

    printf("\nLexical Analysis Output:\n");
    lexicalAnalyzer(file);
    fclose(file);

    return 0;
}

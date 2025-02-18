%{
#include <stdio.h>

int char_count = 0, word_count = 0, line_count = 0, tab_count = 0, ident_count = 0, special_count = 0, space_count = 0;
extern FILE *yyin;
%}

DIGIT    [0-9]+
IDENT    [a-zA-Z_][a-zA-Z0-9_]*
SPECIAL  [!@#$%^&*()_+\-=\[\]{};':"\\|,.<>\/?]+

%%

\n      { line_count++; char_count++; }  // Increment lines and count newline as a character
\t      { tab_count++; char_count++; }  // Count tabs
[ ]     { space_count++; char_count++; }  // Count spaces
{IDENT} { ident_count++; word_count++; char_count += yyleng; }  // Count identifiers as words and add their length to character count
{DIGIT} { word_count++; char_count += yyleng; }  // Count digits as words and add their length to character count
{SPECIAL} { special_count++; char_count += yyleng; }  // Count special characters and add their length to character count
.       { char_count++; }  // Count every other character including spaces

%%

int main() {
    char filename[100];
    printf("Enter the name of the file: ");
    scanf("%s", filename);

    yyin = fopen(filename, "r");
    if (!yyin) {
        perror("Error opening file");
        return 1;
    }

    yylex();  // Run lexical analysis
    fclose(yyin);

    printf("Characters : %d\n", char_count);
    printf("Words : %d\n", word_count);
    printf("Lines : %d\n", line_count);
    printf("Tabs : %d\n", tab_count);
    printf("Identifiers : %d\n", ident_count);
    printf("Special Characters : %d\n", special_count);
    printf("Spaces : %d\n", space_count);

    return 0;
}

int yywrap() {
    return 1;
}
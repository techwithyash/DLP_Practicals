%{
#include <stdio.h>

int char_count = 0, word_count = 0, line_count = 0;
%}

%%

\n      { line_count++; char_count++; }  // Increment lines and count newline as a character
[^\n\t ]+  { word_count++; char_count += yyleng; }  // Count words and add their length to character count
.       { char_count++; }  // Count every other character including spaces

%%

int main() {
    yylex();  // Run lexical analysis

    printf("Characters : %d\n", char_count);
    printf("Words : %d\n", word_count);
    printf("Lines : %d\n", line_count);

    return 0;
}

int yywrap() {
    return 1;
}

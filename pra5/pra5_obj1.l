%{
#include <stdio.h>
#include <stdlib.h>

extern FILE *yyin;
%}

DIGIT    [0-9]+
IDENT    [a-zA-Z_][a-zA-Z0-9_]*
KEYWORD  "int"|"char"|"return"|"if"|"else"|"while"|"for"|"do"|"void"
OPERATOR [+\-*/=<>!&|]
PUNCT    [(){};,]
STRING   \"([^\\"]|\\.)*\"
COMMENT_SINGLE  "//".*
COMMENT_MULTI   "/*"([^*]|\*+[^*/])*\*+"/"

%%  // FIRST `%%` MUST BE HERE

{KEYWORD}       { printf("Keyword: %s\n", yytext); }

{IDENT}         { printf("Identifier: %s\n", yytext); }

{DIGIT}         { printf("Constant: %s\n", yytext); }

{STRING}        { printf("String: %s\n", yytext); }

{OPERATOR}      { printf("Operator: %s\n", yytext); }

{PUNCT}         { printf("Punctuation: %s\n", yytext); }

{COMMENT_SINGLE} { /* Ignore single-line comments */ }

{COMMENT_MULTI}  { /* Ignore multi-line comments */ }

[ \t\n]+        { /* Ignore whitespace */ }

.               { printf("Lexical Error: %s\n", yytext); }

%%  // SECOND `%%` MUST BE HERE

int main() {
    char filename[100];
    printf("Enter the name of the file: ");
    scanf("%s", filename);

    yyin = fopen(filename, "r");
    if (!yyin) {
        perror("Error opening file");
        return 1;
    }

    yylex();  // Start lexical analysis
    fclose(yyin);
    return 0;
}

int yywrap() {
    return 1;
}
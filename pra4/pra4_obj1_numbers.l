%{
#include <stdio.h>
%}

%%
[0-9]+    { printf("%s\n", yytext); } // Print numbers
.|\n       { /* Ignore all other characters */ }
%%

int main() {
    yylex(); // Call lexical analyzer
    return 0;
}

int yywrap() {
    return 1; // End of input
}

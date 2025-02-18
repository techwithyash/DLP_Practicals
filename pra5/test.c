#include <stdio.h>

int main() {
    int a = 10; // This is a single-line comment
    char b = 'c';
    char str[] = "Hello, World!";
    if (a > 5) {
        a = a + 1;
    } else {
        a = a - 1;
    }
    /* This is a
       multi-line comment */
    while (a < 20) {
        a++;
    }
    return 0;
}
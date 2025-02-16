#include <stdio.h>
#define MAX_STATES 10
#define MAX_SYMBOLS 10

int transitionTable[MAX_STATES][MAX_SYMBOLS];
int acceptingStates[MAX_STATES];
int numStates, numSymbols, initialState, numAcceptingStates;
char symbols[MAX_SYMBOLS];

int getSymbolIndex(char symbol) {
    for (int i = 0; i < numSymbols; i++) {
        if (symbols[i] == symbol) {
            return i;
        }
    }
    return -1;
}

int isValidString(char *inputString) {
    int currentState = initialState;
    for (int i = 0; inputString[i] != '\0'; i++) {
        int symbolIndex = getSymbolIndex(inputString[i]);
        if (symbolIndex == -1) return 0;
        currentState = transitionTable[currentState][symbolIndex];
    }
    for (int i = 0; i < numAcceptingStates; i++) {
        if (currentState == acceptingStates[i]) return 1;
    }
    return 0;
}

int main() {
    printf("Enter number of input symbols: ");
    scanf("%d", &numSymbols);
    printf("Enter input symbols: ");
    for (int i = 0; i < numSymbols; i++) {
        scanf(" %c", &symbols[i]);
    }
    printf("Enter number of states: ");
    scanf("%d", &numStates);
    printf("Enter initial state: ");
    scanf("%d", &initialState);
    printf("Enter number of accepting states: ");
    scanf("%d", &numAcceptingStates);
    printf("Enter accepting states: ");
    for (int i = 0; i < numAcceptingStates; i++) {
        scanf("%d", &acceptingStates[i]);
    }
    printf("Enter transition table:");
    for (int i = 0; i < numStates; i++) {
        for (int j = 0; j < numSymbols; j++) {
            printf("State %d on '%c' goes to: ", i + 1, symbols[j]);
            scanf("%d", &transitionTable[i][j]);
        }
    }
    char inputString[50];
    printf("Enter input string: ");
    scanf("%s", inputString);
    if (isValidString(inputString)) {
        printf("Valid String\n");
    } else {
        printf("Invalid String\n");
    }
    return 0;
}

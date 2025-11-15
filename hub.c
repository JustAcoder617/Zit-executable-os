#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void operaction_selection(int n1, int n2);

void hub_start(void) {
    printf("Logged sucefully.\n");
}

void calculator_launch(void) {
    int n1, n2;
    printf("Please type the first number: ");
    scanf("%d", &n1);
    printf("Now type the second number to do the operation with %d: ", n1);
    scanf("%d", &n2);
    operaction_selection(n1, n2);
}
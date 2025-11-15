#include <stdio.h>
#include <stdlib.h>

void operaction_selection(int n1, int n2);
void do_opr(int opr, int n1, int n2);
void add(int a, int b);
void sub(int a, int b);
void divi(int a, int b);
void mult(int a, int b);
void pot(int a, int b);

int main(void) {
    int n1, n2;

    printf("Please type the first number: ");
    scanf("%d", &n1);

    printf("Now type the second number to do the operation with %d: ", n1);
    scanf("%d", &n2);

    operaction_selection(n1, n2);

    return 0;
}

void operaction_selection(int n1, int n2) {
    int choice;

    printf("Now select the operation that you want to do with %d and %d:\n", n1, n2);
    puts("1. Add");
    puts("2. Subtract");
    puts("3. Divide");
    puts("4. Multiply");
    puts("5. Power");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    do_opr(choice, n1, n2);
}

void do_opr(int opr, int n1, int n2) {
    switch (opr) {
        case 1:
            add(n1, n2);
            break;
        case 2:
            sub(n1, n2);
            break;
        case 3:
            divi(n1, n2);
            break;
        case 4:
            mult(n1, n2);
            break;
        case 5:
            pot(n1, n2);
            break;
        default:
            printf("Invalid option.\n");
    }
}

void add(int a, int b) {
    printf("Result: %d\n", a + b);
    system("Hub.exe");
}

void sub(int a, int b) {
    printf("Result: %d\n", a - b);
    system("hub.exe");
}

void divi(int a, int b) {
    if (b != 0){
        printf("Result: %d\n", a / b);
        system("Hub.exe");
    }else{
        printf("Cannot divide by zero.\n");
        main();
    }
}

void mult(int a, int b) {
    printf("Result: %d\n", a * b);
}

void pot(int a, int b) {
    int result = 1;
    for (int i = 0; i < b; i++)
        result *= a;
    printf("Result: %d\n", result);
    system("Hub.exe");
}
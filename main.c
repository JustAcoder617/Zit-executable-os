#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void maintence_mode(char error[]);
void check_hub(void);
void password_check(FILE *file);
void load(void);
void apps_menu(void);
void operaction_selection(int n1, int n2);
void do_opr(int opr, int n1, int n2);
void add(int a, int b);
void sub(int a, int b);
void divi(int a, int b);
void mult(int a, int b);
void pot(int a, int b);

int chances = 3;

void password_check(FILE *file) {
    char password[100];
    char stored_password[100];

    fgets(stored_password, sizeof(stored_password), file);
    stored_password[strcspn(stored_password, "\n")] = 0;

    while (chances > 0) {
        printf("Please type your password: ");
        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = 0;

        if (strcmp(password, stored_password) == 0) {
            printf("Access granted!\n");
            check_hub();
            return;
        } else {
            chances--;
            printf("Incorrect password. %d more tries.\n", chances);
        }
    }

    printf("0 chances remaining.\n");
    Sleep(6000);
    printf("Quitting the system...\n");
    Sleep(3000);
    exit(0);
}

void load() {
    FILE *file = fopen("password.txt", "r");
    if (file == NULL) {
        printf("Error: password file not found. Entering maintenance mode...\n");
        char error[]="404p";
        maintence_mode(error);
    }
    password_check(file);
    fclose(file);
}

int main(void) {
    puts("Hello! Welcome to Ziper OS.exe!");
    puts("Documentation: www.github.com/JustAcoder617/Zit-executable-os");
    puts("Preparing the system...");
    load();
}

void check_hub() {
    FILE *file = fopen("hub.exe", "r");
    if (file == NULL) {
        printf("Error: hub.exe not found. Exiting...\n");
        exit(1);
    }
    fclose(file);
    printf("Logged sucefully.\n");
    apps_menu();
}

void apps_menu(void) {
    printf("Welcome to the apps menu!\n");
    Sleep(2000);
    printf("Wanna use: 1. notepad 2. calculator 3. cmd\n");
    int choice;
    scanf("%d", &choice);
    switch(choice){
        case 1:
            system("apps/notepad.exe");
            break;
        case 2: {
            int n1, n2;
            printf("Please type the first number: ");
            scanf("%d", &n1);
            printf("Now type the second number to do the operation with %d: ", n1);
            scanf("%d", &n2);
            operaction_selection(n1, n2);
            break;
        }
        case 3:
            system("apps/cmd.exe");
            break;
        default:
            printf("Invalid choice.\n");
            apps_menu();
            break;
    }
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
    system("hub.exe");
}

void sub(int a, int b) {
    printf("Result: %d\n", a - b);
    system("hub.exe");
}

void divi(int a, int b) {
    if (b != 0){
        printf("Result: %d\n", a / b);
        system("hub.exe");
    } else {
        printf("Cannot divide by zero.\n");
        apps_menu();
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
    system("hub.exe");
}

void maintence_mode(char error[]) {
    printf("Entering maintenance mode due to error: %s\n", error);
    printf("Please contact support or refer to the documentation for assistance.\n");
    if (strcmp(error, "404p") == 0) {
        printf("Suggested action: Create a 'password.txt' file with your desired password.\n");
        puts("Creatending a another password for you...");
        FILE *file = fopen("password.txt", "w");
        if (file == NULL) {
            printf("Error creating password file. Exiting...\n");
            Sleep(3000);
            exit(1);
        } else {
            puts("Please type your new password: ");
            char password[100];
            fgets(password, sizeof(password), stdin);
            fprintf(file, "%s", password);
            printf("Password file created successfully. Please restart the application.\n");
            Sleep(3000);
            fclose(file);
            exit(0);
        }
        fclose(file);
    }
    exit(1);
}
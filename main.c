#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
// "Functions assinatures"
void password_check(FILE *file);
void load(void);

int chances = 3;

void password_check(FILE *file) {
    char password[100];
    char stored_password[100];

    fgets(stored_password, sizeof(stored_password), file);
    stored_password[strcspn(stored_password, "\n")] = 0; // remove \n

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
        fclose(file);
        exit(1);
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
    system("hub.exe");
}
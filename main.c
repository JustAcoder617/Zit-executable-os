#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h> 

int chances = 3;

void maintenance_mode(char error[]);
void password_check(FILE *file);

void password_check(FILE *file) {
    clock_t start_time, end_time;
    double time_spent; 
    
    char password[100];
    char stored_password[100];

    fgets(stored_password, sizeof(stored_password), file);
    stored_password[strcspn(stored_password, "\n")] = 0;

    start_time = clock(); 

    while (chances > 0) {
        printf("Please type your password: ");
        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = 0;

        if (strcmp(password, stored_password) == 0) {
            end_time = clock(); 
            time_spent = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

            printf("Access granted!\n");
            printf("Time taken to log in: %.2f seconds\n", time_spent);
            printf("Starting hub...\n");
            system("hub.exe");
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
        maintenance_mode(error);
    }
    password_check(file);
    fclose(file);
}

void maintenance_mode(char error[]) {
    printf("Entering maintenance mode due to error: %s\n", error);
    printf("Please contact support or refer to the documentation for assistance.\n");
    if (strcmp(error, "404p") == 0) {
        printf("Suggested action: Create a 'password.txt' file with your desired password.\n");
        puts("Creating a new password for you...");
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
    }
    exit(1);
}

int main(void) {
    puts("Hello! Welcome to Ziper OS.exe!");
    puts("Documentation: www.github.com/JustAcoder617/Zit-executable-os");
    puts("Preparing the system...");
    load();
    return 0;
}
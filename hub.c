#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void calc_execute(void);
void notepad_execute(const char *path);

void apps_menu(void) {
    printf("Welcome to the apps menu!\n");
    Sleep(2000);
    printf("Wanna use: 1. notepad 2. calculator 3. cmd\n");
    int choice;
    scanf("%d", &choice);
    switch(choice){
        case 1:
            notepad_execute(NULL);
            break;
        case 2:
            calc_execute();
            break;
        case 3:
            system("cmd.exe");
            break;
        default:
            printf("Invalid choice.\n");
            apps_menu();
            break;
    }
}

int main(void) {
    apps_menu();
    return 0;
}
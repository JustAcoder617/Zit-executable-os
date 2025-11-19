#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
void apps_menu( void );
void apps_menu(void) {
    printf("Welcome to the apps menu!\n");
    Sleep(2000);
    printf("Wanna use: 1. notepad 2. calculator 3. cmd\n");
    int choice;
    if (scanf("%d", &choice) != 1) {
        // clear invalid input
        int c;
        while ((c = getchar()) != EOF && c != '\n');
        apps_menu();
    }
    switch(choice){
        case 1:
            system("apps\\note\\notepad.exe");
            break;
        case 2:
            system("apps\\calc\\calc.exe");
            break;
        case 3:
            system("apps\\cmd\\cmd.exe");
            break;
        default:
            printf("Invalid choice.\n");
            apps_menu();
            break;
    }
}
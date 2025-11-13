#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
void apps_menu(void);
int main(void){
    printf("Logged sucefully.\n");
    apps_menu();
}
void apps_menu(void){
    printf("Welcome to the apps menu!\n");
    Sleep(2000);
    printf("Wanna use: 1. notepad 2. calculator 3. cmd\n");
    int choice;
    scanf("%d", &choice);
    switch(choice){
        case 1:
            system("apps/notepad.exe");
            break;
        case 2:
            system("apps/calc.exe");
            break;
        case 3:
            system("apps/cmd.exe");
            break;
        default:
            printf("Invalid choice.\n");
            apps_menu();
            break;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void cmd(void);
int main(void){
    puts("Zipershell command line, all rights reserved.");
    cmd();
    return 0;
}
void cmd(void){
    char input[1024];
    while (1) {
        printf("--- ");
        puts("Type help for help with commands.");
        if (!fgets(input, sizeof(input), stdin)) break;
        input[strcspn(input, "\n")] = 0;
        if (strcmp(input, "help")){
            puts("  clear- clear the terminal\n");
            puts("  help- Shoe this message\n");
            puts("  include- Include an file on this Os\n");
            puts("  exit- quit the terminal\n");
            puts("  More future commands will be added.");
        }
        if (strcmp(input, "exit") == 0) {
            printf("Exiting command line.\n");
            break;
        }

        if (strlen(input) == 0) {
            continue;
        }


        int ret = system(input);
        if (ret == -1) {
            printf("Error executing command: %s\n", input);
        } else {
            printf("Command exited with status: %d\n", ret);
        }
    }
}
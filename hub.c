#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

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

void notepad_launch(const char *path) {
    const char *filepath = NULL;
    char input[1024];
    if (path == NULL) {
        printf("File name (will be created if missing): ");
        if (!fgets(input, sizeof(input), stdin)) return;
        input[strcspn(input, "\n")] = 0;
        if (strlen(input) == 0) {
            printf("No file provided. Exiting.\n");
            return;
        }
        filepath = strdup(input);
    } else {
        filepath = path;
    }
    if (!load_file(filepath)) {
        printf("File '%s' not found - creating new.\n", filepath);
    } else {
        printf("File '%s' loaded with %zu lines.\n", filepath, line_count);
        print_contents();
    }
    puts("Type .help for commands. Start typing lines:");
    while (1) {
        printf(">> ");
        if (!fgets(input, sizeof(input), stdin)) break;
        input[strcspn(input, "\n")] = 0;
        if (strcmp(input, ".help") == 0) {
            print_help();
            continue;
        }
        if (strcmp(input, ".save") == 0) {
            if (save_file(filepath)) printf("Saved to '%s'.\n", filepath);
            else printf("Error saving '%s'.\n", filepath);
            continue;
        }
        if (strncmp(input, ".saveas ", 8) == 0) {
            const char *newpath = input + 8;
            if (save_file(newpath)) printf("Saved to '%s'.\n", newpath);
            else printf("Error saving '%s'.\n", newpath);
            continue;
        }
        if (strcmp(input, ".q") == 0) {
            if (modified) {
                printf("There are unsaved changes. Save before exit? (y/n): ");
                char ans[8];
                if (!fgets(ans, sizeof(ans), stdin)) break;
                if (ans[0] == 'y' || ans[0] == 'Y') {
                    if (save_file(filepath)){
                        printf("Saved to '%s'.\n", filepath);
                        system("hub.exe");
                    }
                    else printf("Error saving '%s'. Exiting without saving.\n", filepath);
                }
            }
            break;
        }
        size_t len = strlen(input);
        char *ln = malloc(len + 2);
        if (!ln) { puts("Out of memory"); break; }
        memcpy(ln, input, len);
        ln[len] = '\n';
        ln[len + 1] = '\0';
        char **tmp = realloc(lines, (line_count + 1) * sizeof(char*));
        if (!tmp) { free(ln); puts("Out of memory"); break; }
        lines = tmp;
        lines[line_count++] = ln;
        modified = 1;
    }
    free_lines();
    if (path == NULL) free((void*)filepath);
    puts("Exiting notepad.");
}
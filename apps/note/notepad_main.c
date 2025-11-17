#include <stdio.h>

void notepad_execute(const char *path);

int main(int argc, char **argv) {
    const char *path = NULL;
    if (argc >= 2) path = argv[1];
    notepad_execute(path);
    return 0;
}

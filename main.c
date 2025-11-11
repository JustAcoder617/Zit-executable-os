#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
    puts("Hello! welcome to the Ziper Os.exe! wanna see our documentation? go to www.github.com/JustAcoder617/Zit-executable-os.");
    puts("We are working to prepare our system!");
    load();
}
void load(){
    FILE *file = fopen("password.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "404p");
        char error='1';
        maintenance_mode(error); //404 password and redirect to maintenance mode
    }
    password_check(file);
    // Read and process the file contents here
    fclose(file);
}
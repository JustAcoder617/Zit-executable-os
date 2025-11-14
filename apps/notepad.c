#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char **lines = NULL;
static size_t line_count = 0;
static int modified = 0;

void free_lines(void) {
	if (!lines) return;
	for (size_t i = 0; i < line_count; ++i) free(lines[i]);
	free(lines);
	lines = NULL;
	line_count = 0;
}

int load_file(const char *path) {
	FILE *f = fopen(path, "r");
	if (!f) return 0;
	char buf[1024];
	while (fgets(buf, sizeof(buf), f)) {
		size_t len = strlen(buf);
		char *ln = malloc(len + 1);
		if (!ln) { fclose(f); return 0; }
		memcpy(ln, buf, len + 1);
		char **tmp = realloc(lines, (line_count + 1) * sizeof(char*));
		if (!tmp) { free(ln); fclose(f); return 0; }
		lines = tmp;
		lines[line_count++] = ln;
	}
	fclose(f);
	return 1;
}

int save_file(const char *path) {
	FILE *f = fopen(path, "w");
	if (!f) return 0;
	for (size_t i = 0; i < line_count; ++i) {
		fputs(lines[i], f);
	}
	fclose(f);
	modified = 0;
	return 1;
}

void print_help(void) {
	puts("Commands:");
	puts("  .help       - show this help");
	puts("  .save       - save to the current file");
	puts("  .saveas F   - save to another file F");
	puts("  .q          - quit (asks to save if modified)");
	puts("Type normal lines to add them to the file.");
}

void print_contents(void) {
	puts("Current file:");
	for (size_t i = 0; i < line_count; ++i) {
		printf("%4zu: %s", i + 1, lines[i]);
		if (lines[i][strlen(lines[i]) - 1] != '\n') putchar('\n');
	}
}

int main(int argc, char **argv) {
	const char *path = NULL;
	char input[1024];

	if (argc >= 2) path = argv[1];
	else {
		printf("File name (will be created if missing): ");
		if (!fgets(input, sizeof(input), stdin)) return 0;
		input[strcspn(input, "\n")] = 0;
		if (strlen(input) == 0) {
			printf("No file provided. Exiting.\n");
			return 0;
		}
		path = strdup(input);
	}

	if (!load_file(path)) {
		printf("File '%s' not found - creating new.\n", path);
	} else {
		printf("File '%s' loaded with %zu lines.\n", path, line_count);
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
			if (save_file(path)) printf("Saved to '%s'.\n", path);
			else printf("Error saving '%s'.\n", path);
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
					if (save_file(path)){
						printf("Saved to '%s'.\n", path);
						system("hub.exe");
					}
					else printf("Error saving '%s'. Exiting without saving.\n", path);
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
	if (argc < 2) free((void*)path);
	puts("Exiting notepad.");
	return 0;
}

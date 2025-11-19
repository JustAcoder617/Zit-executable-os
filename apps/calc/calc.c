#include <stdio.h>
#include <stdlib.h>

void calc_execute(void) {
	int n1, n2;
	printf("Please type the first number: ");
	if (scanf("%d", &n1) != 1) return;
	printf("Now type the second number to do the operation with %d: ", n1);
	if (scanf("%d", &n2) != 1) return;

	int choice;
	while (1) {
		printf("Now select the operation that you want to do with %d and %d:\n", n1, n2);
		puts("1. Add");
		puts("2. Subtract");
		puts("3. Divide");
		puts("4. Multiply");
		puts("5. Power");
		puts("6. Exit to hub");
		printf("Enter your choice: ");
		if (scanf("%d", &choice) != 1) {
			int c; while ((c = getchar()) != EOF && c != '\n');
			continue;
		}

		if (choice == 6) break;

		switch (choice) {
			case 1:
				printf("Result: %d\n", n1 + n2);
				break;
			case 2:
				printf("Result: %d\n", n1 - n2);
				break;
			case 3:
				if (n2 == 0) printf("Cannot divide by zero.\n");
				else printf("Result: %d\n", n1 / n2);
				break;
			case 4:
				printf("Result: %d\n", n1 * n2);
				break;
			case 5: {
				int result = 1;
				for (int i = 0; i < n2; ++i) result *= n1;
				printf("Result: %d\n", result);
				break;
			}
			default:
				printf("Invalid option.\n");
				break;
		}
}
	}
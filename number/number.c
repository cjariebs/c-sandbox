#include <stdio.h>

int main(int argc, char* argv[]) {
    int count;

    if (argc > 1)
	count = atoi(argv[1]);
    else {
	printf("Please enter a number: ");
	scanf("%d", &count);
    }

    printf("You entered %d.\n", count);

    return 0;
}

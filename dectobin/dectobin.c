#include <stdio.h>
#include <stdlib.h>

#define MAX_ARGS 32
#define INT_SIZE sizeof(int)

void dectobin(int dec, char* bits[]) {
    int i;
    int q = dec;

    for (i = 0; i < INT_SIZE; i++)
	*bits[i] = 0;

    i = 0;
    while (q > 0) {
	*bits[i] = q % 2;
	q /= 2;
	i++;
    }
    *bits[i+1] = '\0';
}

int main(int argc, char* argv[]) {
    int i;

    char nums[MAX_ARGS];
    if (argc <= 1) {
	// [?] Get numbers from input if we don't have arguments.
	printf("Enter some base 10 integers: ");
        fgets(nums, MAX_ARGS, stdin);
    } else {
	for (i = 1; i < argc; i++) {
	    nums[i] = *argv[i];
	}
    }
    
    printf("Converting nums to ints...");
    int ints[MAX_ARGS];
    int index;
    for (i = 0; i < MAX_ARGS; i++) {
	if (!isdigit(nums[i])) continue;
	ints[index] = atoi(&nums[i]);
	index++;
    }
    printf("done\n");
    char* bits[INT_SIZE];
    for (i = 0; i < MAX_ARGS; i++) {
	dectobin(ints[i], bits);
	printf("FAILING HERE?");
	printf("%d = %s\n", ints[i], bits);
    }

    return 0;
}

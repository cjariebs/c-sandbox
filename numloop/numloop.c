#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "numloop.h"

int main(int argc, char* argv[]) {
   while(!menu()) {}

   return 0;
}

int menu() {
    printf("What would you like to do?\n");
    printf("a - add\n");
    printf("m - multiply\n");
    printf("q - quit\n");

    int choice;
    choice = getchar();
    getchar();

    switch(choice) {
	case 'a':
	    add();
	    return 0;
	
	case 'm':
	    multiply();
	    return 0;

	case 'q':
	    return 1;

	default:
	    printf("\nInvalid input.\n");
	    return 0;
    }

    return 1;
}

void add() {
    printf("Enter the numbers you wish to add: ");
    
    char nums[32];
    fgets(nums, 32, stdin);

    int sum = 0;
    int i;
    int n;

    for (i = 0; i < 32; i++) {
	if (!isdigit(nums[i])) continue;
	n = atoi(&nums[i]);
	sum += n;
    }

    printf("The sum is %d.\n", sum);
}

void multiply() {
    printf("Enter the numbers you wish to multiply: ");
    
    char nums[32];
    fgets(nums, 32, stdin);
    printf("You entered: %s\n", nums);

    int product = 1;
    int i;
    int n;

    for (i = 0; i < 32; i++) {
	if (!isdigit(nums[i])) continue;
	n = atoi(&nums[i]);
	product *= n;
    }

    printf("The product is %d.\n", product);
}

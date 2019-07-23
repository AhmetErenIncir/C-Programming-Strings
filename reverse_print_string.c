#include <stdio.h>
#include "string.h"

#define SIZE_OF_STRING 100

void PrintReverse(char* string) {

	int size = strlen(string);

	char* end_ptr = string + size - 1 ;

	while(end_ptr >= string){
		printf("%c",*end_ptr);
		--end_ptr;
	}
}

int main(){
	char string[SIZE_OF_STRING] ;

	printf("Enter the string\n");
	scanf("%s",string);
	PrintReverse(string);
}

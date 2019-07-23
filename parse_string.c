#include <stdio.h>
#include <string.h>
#include "stdlib.h"

#define SIZE 100

int main(){

	char str[SIZE];
	int i=0,j,counter=0;

	printf("Enter the string\n");
	gets(str);

	while(str[i] != '\0'){
		if(str[i] != ' '){
			printf("%c",str[i]);
		}
		else if(str[i]==' '){
			counter++;
			printf("\n");
			for(j=0 ; j<counter ; j++){
				printf("\t");
			}
		}
		i++;
	}
	printf("\n");
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

int main(){

	char str[SIZE] ,i ;

	printf("Enter string\n");
	scanf("%s",str);

	printf("Original string : \n%s\n",str);
	str[0] -= 32;
	for(i=1 ; str[i] ; i++){
		if(str[i] == '.'){
			str[i+1] = str[i+1] - 32;
		}
	}

	printf("Strint after procces \n%s\n",str);

}

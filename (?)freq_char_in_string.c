#include "stdio.h"
#include <string.h>

#define SIZE 100

int frq_char(char s[] , char c){
	int i=0 ,counter=0;
	while(s[i] != '\0'){
		if(s[i] == c){
			counter++;
		}
		i++;
	}
	return counter;
}


int main(){
	char string[SIZE] , c;
	int size,fre,x;
	//Once string alirsak prgoramda atlamalar oluyor.Scanf buffer ile alakali galiba?
	printf("Enter the character to count its frequency\n");
	scanf("%c",&c);

	printf("Enter the string\n");
	//gets(string);
	scanf("%s",string);



	size = strlen(string);

	fre = frq_char(string,c);

	printf("%c 's frequency is %d\n",c,fre);

}

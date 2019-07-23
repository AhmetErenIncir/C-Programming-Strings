#include <stdio.h>

int main(){
	char s[100];
	printf("Enter string\n");
	gets(s);
	int i=0;
	while(s[i]!='\0'){
		if(s[i+1]==' '){
			printf("%c",s[i]);
		}
		else{
			printf("%c",s[i]);
			printf("*");
		}
		i++;
	}
}

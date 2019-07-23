#include <stdio.h>
#include "string.h"

#define SIZE 20

void comp_strings(char s1[] , char s2[]){
	int i=0,cmp_hold=0;
	if(strlen(s1) != strlen(s2)){
		printf("These are not same\n");
	}
	else{
		while(s1[i] != "\0" && s2[i] != '\0'){
			if(s1[i] == s2[i]){
				cmp_hold ++;
			}
			i++;
		}
		if(cmp_hold == strlen(s2)){
			printf("These are same \n");
		}
		else{
			printf("These are note same\n");
		}
	}
}


int main(){
	char s1[SIZE] , s2[SIZE] ;
	printf("Enter the first string to compare\n");
	scanf("%s",s1);
	printf("Enter the first string to compare\n");
	scanf("%s",s2);
	comp_strings(s1,s2);
}

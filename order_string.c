#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

int main(){

	char str[SIZE], min,i,j,temp;
	printf("Enter string\n");
	scanf("%s",str);

	int size = strlen(str);

	for(i=0 ; i<size ; i++){
		min = str[i];
		for(j=i+1 ; j<size ; j++){
			if(str[j]<min){
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
				min = str[i]; //**** En kritik nokta burasi. Min tekrar str[i] olmasi lazim.
			}
		}
	}
	printf("%s\n",str);
}

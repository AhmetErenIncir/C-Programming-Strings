#include <stdio.h>
#include <string.h>
//Pointerli cozumu de mevcut. Array klasorunde.
void chech_polindrom(char s1[]){
	int size = strlen(s1);
	int i,flag=0;
	for(i=0 ; i<size/2 ; i++){
		if(s1[i]==s1[size-1-i]){
			flag = 0;
		}
		else{
			flag = 1;
		}
	}
	if(flag == 0){
		printf("This string is polyndrome\n");
	}
	else{
		printf("This string is not polyndrome\n");
	}
}

int main(){

	char str[100];
	printf("Enter the string to check polyndrome\n");
	scanf("%s",str);

	chech_polindrom(str);


}

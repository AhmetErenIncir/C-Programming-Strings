#include <stdio.h>
#include <string.h>

#define SIZE 6

// void PrintString(char **s1){
// 	int i,j;
// 	for()
// }


int main(){

	char s1[SIZE][SIZE];
	int i,j;

	printf("Enter the strings\n");
	for(i=0 ; i<SIZE ;i++){
		scanf("%s",(s1+i));
	}
	for(i=0 ; i<SIZE ;i++){
		printf("%s\n",*(s1+i));
	}


	printf("--%c--\n",*(*(s1+1)+2)); //1.satirin 3.harfini basar.



}

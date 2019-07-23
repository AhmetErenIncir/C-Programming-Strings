#include<stdio.h>
#include<stdlib.h>

#define DICT_SIZE 15
#define WORD_LEN 15
#define LINE_LEN 15

//This function find the size of string.
int get_line_size(char *line) {
	char *ch_iter = line; // so as not to lose beginning of line
	int counter = 0;
	// go until you see new line or null char
	while(*ch_iter != '\n' && *ch_iter != '\0') {
		ch_iter++; // next char
		counter++; // increment counter
	}

	return counter;
}
//this function copy the dict array depend on coordinates.
int copy_on_puzzle(char puzzle[][LINE_LEN],int size, char *string,int startcol, int startrow, int endcol, int endrow) {
	int len = get_line_size(string);
    int dcol = endcol - startcol;
    int drow = endrow - startrow;

    if (dcol != 0) {
        if (dcol == len - 1)
            dcol = 1;
        else if (dcol == 1 - len)
            dcol = -1;
        else
            return -1;
    }
    if (drow != 0) {
        if (drow == len - 1)
            drow = 1;
        else if (drow == 1 - len)
            drow = -1;
        else
            return -1;
    }
    for (int col = startcol, row = startrow; *string; string++) {
        puzzle[row][col] = *string;
        row += drow;
        col += dcol;
    }
    return 0;
}

void copy_string(char *source, char *destination) {
	// get iterators over original pointers
	char *src_iter = source;
	char *dst_iter = destination;
	// until null char
	while (*src_iter != '\0') {
		// copy pointers
		*dst_iter = *src_iter;
		// advance to next char
		src_iter++;
		dst_iter++;
   }
   // terminate string
   *dst_iter = '\0';
}

void remove_newline(char *line) {
	char *ch_iter = line;
	// go until you see new line
	while(*ch_iter != '\n' && *ch_iter != 13) {
		ch_iter++; // next char
	}
	*ch_iter = '\0'; // overwrite new line
}

void print_dictionary(char *dict[]) {
	int i;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		printf("%s\n", dict[i]);
	}
}

void print_coord(int coord[DICT_SIZE][4]) {
	int i, j;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		for(j = 0 ; j < 4 ; j++) {
			printf("%d ", coord[i][j]);
		}
		printf("\n");
	}
}
//This function generate random char to fill the puzzle.
char generate_random_char(){
	char c;
	c = (rand()%(122-97))+97;
	return c;
}
//this function prints the puzzle.
void print_puzzle(char puzzle[][LINE_LEN],int size){
	int i,j;
	for(i=0 ; i<WORD_LEN ; i++){
		for(j=0 ; j<LINE_LEN ; j++){
			printf("%c ",puzzle[i][j]);
		}
		printf("\n");
	}
}
//If user enter "exitgame", game end.This function control the exit entry
int check_exit(char string[],int size_string){
	char exit[] = {"exitgame"};
	int i=0,flag=0;
	while(string[i]!='\0'){
		if(string[i]==exit[i]){
			flag++;
		}
		i++;
	}
	if(flag==get_line_size(exit))
		return -1;
	else
		return 1;
}
//Game function.
void game(char puzzle[][LINE_LEN],int size){

	int coord_x,coord_y,x,game_counter=0;
	char word[LINE_LEN];

	printf("Enter the word to find\n");
	printf("Enter 'exitgame' to exit\n");
	scanf("%s",word);


	x = check_exit(word,LINE_LEN); //Checking exit entry.
	while(x!=-1 && game_counter!=DICT_SIZE){
		int size_of_word = get_line_size(word); //Finding the size of user entered word.
		printf("Enter the coordinates\n");
		scanf("%d%d",&coord_x,&coord_y);
		int i=0;
		int flag = 0;
		//User warns if enter wrong coordinate.
		if(puzzle[coord_x][coord_y]!=word[0] && puzzle[coord_x][coord_y]!=word[size_of_word-1]){
			printf("You entered wrong coordinates.Please enter new word\n");
		}
		else{
			//Searching all directions.
			if(coord_x+size_of_word<=LINE_LEN){
				for(i=0;i<size_of_word;i++){
					if(puzzle[coord_x+i][coord_y]==word[i]){
						flag++;
					}
				}
				if(flag==size_of_word){
					printf("%s found at entered coordinate\n",word);
					game_counter++;
				}
			}
			if(coord_y+size_of_word<=LINE_LEN){
				flag=0;
				for(i=0;i<size_of_word;i++){
					if(puzzle[coord_x][coord_y+i]==word[i]){
						flag++;
					}
				}
				if(flag==size_of_word){
					printf("%s found at entered coordinate\n",word);
					game_counter++;
				}
			}
			if(coord_x+1-size_of_word>=0){
				flag=0;
				for(i=0 ; i<size_of_word ; i++){
					if(puzzle[coord_x-size_of_word+1+i][coord_y]==word[i]){
						flag++;
					}
				}
				if(flag==size_of_word){
					printf("%s found at entered coordinate\n",word);
					game_counter++;
				}
			}
			if(coord_y+1-size_of_word>=0){
				flag=0;
				for(i=0;i<size_of_word;i++){
					if(puzzle[coord_x][coord_y-i]==word[size_of_word-1-i]){
						flag++;
					}
				}
				if(flag==size_of_word){
					printf("%s found at entered coordinate\n",word);
					game_counter++;
				}
			}
			if(coord_y+size_of_word<=WORD_LEN && coord_x+size_of_word<=LINE_LEN){
				flag=0;
				for(i=0;i<size_of_word;i++){
					if(puzzle[coord_x+i][coord_y+i]==word[i]){
						flag++;
					}
				}
				if(flag==size_of_word){
					printf("%s found at entered coordinate\n",word);
					game_counter++;
				}
			}
			if(coord_x+1-size_of_word>=0 && coord_y+size_of_word<=LINE_LEN){
				flag=0;
				for(i=0;i<size_of_word;i++){
					if(puzzle[coord_x-i][coord_y+i]==word[i]){
						flag++;
					}
				}
				if(flag==size_of_word){
					printf("%s found at entered coordinate\n",word);
					game_counter++;
				}
			}
			if(coord_x+1-size_of_word>=0 && coord_y+1-size_of_word>=0){
				flag=0;
				for(i=0;i<size_of_word;i++){
					if(puzzle[coord_x-i][coord_y-i]==word[size_of_word-1-i]){
						flag++;
					}
				}
				if(flag==size_of_word){
					printf("%s found at entered coordinate\n",word);
					game_counter++;
				}
			}
			if(coord_x-1+size_of_word<=WORD_LEN && coord_y+1-size_of_word>=0){
				flag=0;
				for(i=0;i<size_of_word;i++){
					if(puzzle[coord_x+i][coord_y-i]==word[i]){
						flag++;
					}
				}
				if(flag==size_of_word){
					printf("%s found at entered coordinate\n",word);
					game_counter++;
				}
			}

			printf("Enter the word to find\n");
			printf("Enter 'exitgame' to exit\n");
		}
		scanf("%s",word);
		x = check_exit(word,LINE_LEN);

	}
}



int main(){
	char *dict[DICT_SIZE];
    int coord[DICT_SIZE][4];
    char line[LINE_LEN];
	FILE *fp = fopen("word_hunter.dat", "r");


	int line_counter = 0;
	int dict_counter = 0;
	while(fgets(line, LINE_LEN, fp) != NULL) {
		if(line_counter%5 == 0) {
			dict[dict_counter] = (char*) malloc(sizeof(char) * get_line_size(line));
			remove_newline(line);
			copy_string(line, dict[dict_counter]);
		} else if (line_counter%5 == 1){
			coord[dict_counter][0] = atoi(line);
		} else if (line_counter%5 == 2){
			coord[dict_counter][1] = atoi(line);
		} else if (line_counter%5 == 3){
			coord[dict_counter][2] = atoi(line);
		} else if (line_counter%5 == 4){
			coord[dict_counter][3] = atoi(line);
			dict_counter++;
		}
		line_counter++;
	}

	fclose(fp);

	//print_dictionary(dict);
	//print_coord(coord);


	int i,j;
	char puzzle[WORD_LEN][LINE_LEN];
	char word[LINE_LEN];


	for(i=0 ; i<WORD_LEN ; i++){
		for(j=0 ; j<LINE_LEN ; j++){
			puzzle[i][j] = generate_random_char();
		}
	}

	//print_puzzle(puzzle,WORD_LEN);


	for(i=0 ; i<DICT_SIZE ; i++){
		copy_on_puzzle(puzzle,WORD_LEN,dict[i],coord[i][1],coord[i][0],coord[i][3],coord[i][2]);
	}

	print_puzzle(puzzle,WORD_LEN);

	game(puzzle,LINE_LEN);




	return 0;
}

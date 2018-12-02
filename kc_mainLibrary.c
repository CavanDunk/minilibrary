
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #define LINESIZE 128

int main()
{
returns();
return 0;
}


int returns()
{
	printf("Enter Book ID\n");
	char book;
	char *bookdetail[6];
	scanf("%s", &book);

	FILE *fp;
	fp = fopen("MyLibrary.txt", "r+");


//	char c;
//	char *line[6];
	int i = 0;
	char buffer[255];
	int ret;
	char f;
	char *bookdetails[6];	
	char s[255];
	int tokenCount = 0;
	while(fgets(buffer, 255, (FILE *) fp))
	{
		for(i=0; i< strlen(buffer); i++) {
			if(buffer[0] == book){
				printf("exists");
				strcpy(s, buffer);
				char* token = strtok(s, ",");
				while(token) {
					bookdetails[tokenCount] = token;
					token = strtok(NULL, ",");
					tokenCount++;
				}
			}
			
        }
        for(i=0; i < 6; i++) {
            printf("The value of token %d is %s\n.", i, bookdetails[i]);
        }
    }

	
	fclose(fp);
	printf("Book returned successfully\n");	
	printf("Enter t to try again. Enter b to go back to main menu\n");
	return 0;
}

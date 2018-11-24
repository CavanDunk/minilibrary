#include<stdio.h>
#include<string.h>
HEAD

#define username_size 8

void menu();
int countlines();
void bookAdd();
// a7ecafd7a85db7906a7b339f7be6a727da893cfe

int main()
{
	FILE *fptr;
	fptr = fopen("/Users/Documents/GitHub/minilibrary/UserInfo.txt","r");

	menu();
}

void logIn() {

}

void addBook()
{
	char title[30];
	char author[20];
	char bookAdd[50];
	int id = 0;

	FILE *fp;

	fp = fopen(Mylibrary.txt,"a");

	printf("Enter Book Title: ");
	scanf("%s", title);

	printf("\nEnter Author's Name: ");
	scanf("%s,name);

	id = countlines();
	bookAdd("%s,%s,library,null,null",title,name);

	fprintf(fp,"%id,%s,bookAdd);

	fclose(fp);

}

int countlines()
{
	FILE *fp2;
	int line = 0;
	char c;
	fp2 = fopen("MyLibrary. txt,"r");
	for(c = getc(fp2); c != EOF; c=getc(fp2))
	{
		if( c=='\n')
		{
			line = line + 1;
		}
	}
return line;
fclose(fp2);
}


void menu()
{
	printf("Enter \"q\" for book querry by author sorted by book title.\n");
	printf("Enter \"s\" for the status of a specific book.\n");
	printf("Enter \"u\" to list the books you have checked out");
	printf("Enter \"x\" to Sign Out.\n");
}

void adminMenu()
{
	printf("Enter \"a\" to add a book to the library.\n");
	printf("Enter \"d\" to delete a book from the library.\n");
	printf("Enter \"o\" to check out a book\n");
	printf("Enter \"r\" to return a book.\n");
	printf("Enter \"x\" Sign Out.\n");
}

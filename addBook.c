#include<stdio.h>
#include<string.h>
void addBook();
int countlines();
void printText();
void deleteBook();
int bookId=1;

int main()
{
	addBook();
//	deleteBook();
}
void deleteBook()
{
	int rando=0;
	int num,feel;
	FILE *fp,*fp2;
	char yr;
	char try[2];
	char file[200],check[200]="copy.txt";
	char name[50],title[50];
	printText();
	fp = fopen("Mylibrary.txt","r");
	printf("Give the ID of the book you wish to delete\n");
	scanf("%d",&num);
	fp2 = fopen("copy.txt","w");
	while(!feof(fp))
	{
		
		strcpy(file, "\0");
		fgets(file, 50, fp);
		sscanf(file,"%d,%[^,],[^,],",&rando,title,name);
		if(rando != num)
		{
			fprintf(fp2,"%s",file);
		}
	}
	
	fclose(fp);
	fclose(fp2);
	remove("Mylibrary.txt");
	rename("copy.txt","Mylibrary.txt");
	while(feel != 0)
	{
		printf("Press t to try again or b to go back to the main menu");
		scanf(%c,try);
		if(strcasecmp(try,"t")== 0)
		{
			deletebook();
		}
		else if(strcasecmp(try,"b") == 0)
		{
			adminMenu();
		}
	}
			
}
void addBook()
{
	char title[100];
	char author[150];
	//id=0;	
	char try[2];
	FILE *fp;
	
	fp = fopen("Mylibrary.txt","a");	

	printf("Enter Book Title: ");
	scanf("%[^'\n]s", title);
	printf(" ");
	printf("Enter Author's Name: ");
	scanf(" %[^'\n]s",author);

	bookId=countlines();
	
	
	fprintf(fp,"%d,%s,%s,library,null,null\n",bookId,title,author);
	fclose(fp);
	printf("Book %s was added succesfully!\n",title);
	while(feel != 0)
	{
		printf("Press t to try again or b to go back to the main menu");
		scanf(%c,try);
		if(strcasecmp(try,"t")== 0)
		{
			addBook();
		}
		else if(strcasecmp(try,"b") == 0)
		{
			adminMenu();
		}
	}


}
int countlines()
{
	FILE *fp2;
	int line = 0;
	char c;
	fp2 = fopen("Mylibrary.txt","r");
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
void printText()
{
	FILE *fp;
	char c;
	fp = fopen("Mylibrary.txt","r");
	c = fgetc(fp);
	while(c != EOF)
	{
		printf("%c",c);
		c = fgetc(fp);
	}
	fclose(fp);
}
	

#include<stdio.h>
#include<string.h>
void searchBook();
void searchAuthor();

int main()
{
//	searchBook();
	searchAuthor();
}
void searchAuthor()
{
	char try[2];
	char name[50],search[50],title[50],line[50];
	char c;
	int count=0;
	int id;
	FILE *fp,*fp2;
	printf("What author are you looking for?: ");
	scanf("%[^'\n]s",search);
	fp = fopen("Mylibrary.txt","r");
	fp2 = fopen("sort.txt","w");
	while(!feof(fp))
	{
		fgets(line,100,fp);
		sscanf(line,"%d,%[^,],%[^,],",&id,title,name);
		if(strcasecmp(search,name)==0)
		{
			count++;
			fprintf(fp2,"%s\n",line);
		
		}
	}
	fclose(fp2);
	fp2 = fopen("sort.txt","r");
	c = fgetc(fp2);
	while(c != EOF)
	{
		printf("%c",c);
		c = fgetc(fp2);
	}
	fclose(fp);
	fclose(fp2);
	if(count==0)
	{
		printf("No Books By This Author!\n");
	}
	while(feel != 0)
	{
		printf("Press t to try again or b to go back to the main menu");
		scanf(%c,try);
		if(strcasecmp(try,"t")== 0)
		{
			searchAuthor();
		}
		else if(strcasecmp(try,"b") == 0)
		{
			menu();
		}
	}

	
}
void searchBook()
{
	char name[50],search[50],title[50],line[50],status[50],date[50];
	char c;
	char try[2];
	int count=0;
	int id;
	FILE *fp,*fp2;
	printf("The name of the book you are looking for is?: ");
	scanf("%s[^'\n]",search);
	fp = fopen("Mylibrary.txt","r");
	fp2 = fopen("book.txt","w");
	while(!feof(fp))
	{
		fgets(line,100,fp);
		sscanf(line,"%d,%[^,],%[^,],%[^,],[^,]",&id,title,name,status,date);
		if(strcasecmp(search,title)==0)
		{
				count++;
				if(strcasecmp(status,"library")==0)
				{
					fprintf(fp2,"%s in library\n",title);
				}
				else
				{
					fprintf(fp2,"%s Available after %s\n",title,date);
				}
		}
	}
	fclose(fp2);
	fp2 = fopen("book.txt","r");
	c = fgetc(fp2);
	while(c != EOF)
	{
		printf("%c",c);
		c = fgetc(fp2);
	}
	fclose(fp);
	fclose(fp2);
	if(count==0)
	{
		printf("No Book By This Name\n");
	}
	while(feel != 0)
	{
		printf("Press t to try again or b to go back to the main menu");
		scanf(%c,try);
		if(strcasecmp(try,"t")== 0)
		{
			searchBook();
		}
		else if(strcasecmp(try,"b") == 0)
		{
			menu();
		}
	}

	
}


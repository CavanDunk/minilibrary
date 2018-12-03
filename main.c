/*  Group Members: James Nguyen, Cavan Dunkley, Kimberly Cyzy
*   Bonus Project Topic 4 : Mini Library
*
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

// Prototypes
int adminMain(); // Kimberly
int userMain(); // Kimberly
int aMain();  // Kimberly
int uMain();  // Kimberly
void addBook(); // Cavan
void deleteBook(); // Cavan
void checkOut(); // Cavan
int returnBook(); // Kimberly
void searchAuthor(); //Cavan
void searchBook();  // Cavan
int checkedOut(); // James
int login();  // James
int pass(); // James
void quit(); // James
int lineCount(); // James
int countLines(); // James
void printText(); // Cavan
int checkId(int n);
int checkIdExists(int n);

// Global variables
char choice;
int bookId = 1;
char currentUser[100]; // Stores the username of whoever is currently logged in


int main() {
  login();
  return 0;
}

int adminMain() {

  scanf("%c",&choice);
  switch(choice) {
    case 'a':
      printf("\n");
      addBook();
    case 'd':
      printf("\n");
      deleteBook();
    case 'o':
      printf("\n");
      checkOut();
    case 'r':
      printf("\n");
      returnBook();
    case 'x':
      quit();
    default:
      printf("\n");
      printf("Welcome to the ADMIN MENU.\n");
      aMain();
      printf("What would you like to do? ");
      adminMain();
  }
  return 0;
}

int userMain() {
  scanf("%c",&choice);
  switch(choice) {
    case 'q':
      printf("\n");
      searchAuthor();
    case 's':
      printf("\n");
      searchBook();
    case 'u':
      printf("\n");
      checkedOut();
    case 'x':
      quit();
    default:
      printf("\n");
      printf("Welcome to the USER MENU.\n");
      uMain();
      printf("What would you like to do? ");
      userMain();
  }
  return 0;
}

int aMain() {
  printf("Enter \"a\" to add a book to the library.\n");
	printf("Enter \"d\" to delete a book from the library.\n");
	printf("Enter \"o\" to check out a book.\n");
	printf("Enter \"r\" to return a book.\n");
	printf("Enter \"x\" Sign Out.\n");
  return 0;
}

int uMain() {
  printf("Enter \"q\" for book querry by author sorted by book title.\n");
  printf("Enter \"s\" for the status of a specific book.\n");
  printf("Enter \"u\" to list the books you have checked out.\n");
  printf("Enter \"x\" to Sign Out.\n");
  return 0;
}

// Admin Main Options
void addBook() {
  char title[100];
	char author[150];
	int feel = 1;
	char try[2];
	FILE *fp;

  fp = fopen("Mylibrary.txt","a");

  printf("Enter BookID: ");
  scanf(" %d",&bookId);
  checkId(bookId);
	printf("Enter Book Title: ");
	scanf(" %[^'\n]s", title);
	printf("Enter Author's Name: ");
	scanf(" %[^'\n]s",author);

	fprintf(fp,"%d,%s,%s,library,null,null\n",bookId,title,author);
	fclose(fp);
	printf("Book %s was added succesfully!\n",title);
	while(feel != 0)
	{
		printf("Press 'T' to try again. Press 'B' to go back to the main menu.\n");
		scanf(" %s",&try);
		if(strcasecmp(try,"t")== 0)
		{
      			printf("\n");
			addBook();
		}
		else if(strcasecmp(try,"b") == 0)
		{
			adminMain();
		}
		else
		{
			printf("Command not found/n");
		}
	}

}

void deleteBook() {
  	int rando=0;
	int num,feel=1;
	FILE *fp,*fp2;
	char yr;
	char try[2];
	char file[200],check[200]="copy.txt";
	char name[50],title[50];
	printText();
	fp = fopen("Mylibrary.txt","r");
	printf("Give the ID of the book you wish to delete\n");
	scanf(" %d",&num);
	fp2 = fopen("copy.txt","w");
	while(!feof(fp))
	{

		strcpy(file, "\0");
		fgets(file, 50, fp);
		sscanf(file,"%d,%[^,],[^,],",&rando,title,name);
		if(rando != num)
		{
			fprintf(fp2," %s",file);
		}
	}

	fclose(fp);
	fclose(fp2);
	remove("Mylibrary.txt");
	rename("copy.txt","Mylibrary.txt");
	while(feel != 0)
	{
		printf("Press 'T' to try again. Press 'B' to got back to main menu.\n");
		scanf(" %s",&try);
		if(strcasecmp(try,"t") == 0)
		{
     		 	printf("\n");
			deleteBook();
		}
		else if(strcasecmp(try,"b") == 0)
		{
			adminMain();
		}
		else
		{
			printf("Command does not exist\n");
		}
	}
}

void checkOut() {
	FILE *fp,*fp2,*fp3;
	char user[100],title[100],name[100],status[100],date[100],due[100];
	char fil[200],line[100];
	char first[100],last[100],uname[100];
	char try[40];
	int id,num,bookCheck=0,myguy;
	int exist = 0;
	int feel = 1;
	int year,month,day;
	time_t now;
	time(&now);
	struct tm *local = localtime(&now);

	year = local->tm_year+1900;
	month = local->tm_mon+1;
	day=local->tm_mday;
	fp = fopen("UserInfo.txt","r");
	fp2 = fopen("Mylibrary.txt","r");
	fp3 = fopen("check.txt","w");
	printf("Enter the User\n");
	scanf("%s",&user);
	while(!feof(fp))
	{
		fgets(line,100,fp);
		sscanf(line,"%d,%[^,],%[^,],%[^,]",&id,&first,&last,&uname);
		if(strcasecmp(user,uname) == 0)
		{
			printf("user exist\n");
			exist = 1;
		}
		
	}
	if(exist==0)
	{
		printf("User does not exist\n");
		bookCheck = 5;
	}
	else
	{
		while(!feof(fp2))
		{
			fgets(line,100,fp2);
			sscanf(line,"%d,%[^,],%[^,],%[^,]",&id,&title,&name,&status);
			if(strcasecmp(user,status)==0)
			{
				bookCheck++;
			}
		}
	}
	if(bookCheck < 3)
	{
		printf("Give the Id of the book you wish to check out\n");
		scanf("%d",&myguy);
		rewind(fp2);
		while(!feof(fp2))
		{
			fgets(fil,256, fp2);
			sscanf(fil," %d,%[^,],[^,],[^,],",&num,&title,&name,&status);
			if(num!=myguy)
			{
				fprintf(fp3," %s",fil);
				fflush(fp3);
			}	
			else
			{
				fprintf(fp3,"%d,%s,%s,%s,%d-%d-%d,%d-%d-%d\n",num,&title,&name,&user,year,month,day,year,month,day+10);
				fflush(fp3);
			}
		}
		printf("checked out!\n");
		fclose(fp3);
		fclose(fp2);
		fclose(fp);
		remove("Mylibrary.txt");
		rename("check.txt","Mylibrary.txt");
	}
	else
	{
		fclose(fp3);
		fclose(fp2);
		fclose(fp);
	}
//	remove("Mylibrary.txt");
//	rename("check.txt","Mylibrary.txt");
	while(feel != 0)
	{
		printf("Press t to try again or Press b to got back to main menu\n");
		scanf(" %s",try);
		if(strcasecmp(try,"t") == 0)
		{
			checkOut();
		}
		else if(strcasecmp(try,"b") == 0)
		{
			adminMain();
		}
		else
		{
			printf("Command does not exist\n");
		}
	}


 }



int returnBook() {

  return 0;
}

// User Main Options
void searchAuthor() {
  char try[2];
	char name[50],search[50],title[50],line[50];
	char c;
	int count=0;
	int id;
	int feel = 1;
	FILE *fp,*fp2;
	printf("What author are you looking for?: ");
	scanf(" %[^'\n]s",search);
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

  // Asks if user wants to try again or go back to menu
	while(feel != 0)
	{
		printf("Press 'T' to try again. Press 'B' to go back to the main menu.");
		scanf(" %s",&try);
		if(strcasecmp(try,"t")== 0)
		{
     	 		printf("\n");
			searchAuthor();
		}
		else if(strcasecmp(try,"b") == 0)
		{
			userMain();
		}
		else
		{
			printf("Command does not exist\n");
		}
	}
}

void searchBook() {
  char name[50],search[50],title[50],line[50],status[50],date[50],due[50];
	char c;
	char try[2];
	int count=0,feel=1;
	int id;
	FILE *fp,*fp2;
	printf("The name of the book you are looking for is?: ");
	scanf("%s[^'\n]",search);
	fp = fopen("Mylibrary.txt","r");
	fp2 = fopen("book.txt","w");
	while(!feof(fp))
	{
		fgets(line,100,fp);
		sscanf(line,"%d,%[^,],%[^,],%[^,],%[^,],%[^\n]",&id,title,name,status,date,due);
		if(strcasecmp(search,title)==0)
		{
				count++;
				if(strcasecmp(status,"library")==0)
				{
					fprintf(fp2,"%s in library\n",title);
				}
				else
				{
					fprintf(fp2,"%s available after %s.\n",title,due);
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

  // Asks if user wants to try again or go back to menu
	while(feel != 0)
	{
		printf("Press 'T' to try again. Press 'B' to go back to the main menu.");
		scanf(" %s",&try);
		if(strcasecmp(try,"t")== 0)
		{
      			printf("\n");
			searchBook();
		}
		else if(strcasecmp(try,"b") == 0)
		{
			userMain();
		}
    else {
      printf("Command does not exist.\n");
    }
	}
}

// Function listing the books checked out by currentUser and whether or not book is overdue
int checkedOut() {

  // Book Info Variables
  int id, year, month, day;
  char title[100], author[100], acc[100], co[100], due[100];

  char buff[100]; // Used to store due date to compare it to the current date
  char *cmpdate[100]; // Stores the split due date string into year,month,day

  // Use time.h in standard C library to retrieve the local time
  time_t now;
  time(&now);
  struct tm *local = localtime(&now);

  year = local->tm_year+1900;
  month = local->tm_mon+1;
  day = local->tm_mday;

  printf("Today is %d-%d-%d.\n",year,month,day);
  printf("====CHECKED OUT=====\n");

  FILE *fp;
  fp = fopen("Mylibrary.txt","r");

  // Copies each line of Mylibrary.txt into corresponding Book Info Variables
  while (fscanf(fp,"%d,%100[^,],%100[^,],%100[^,],%100[^,],%100[^\n]",&id,title,author,acc,co,due)==6) {
    // If the currentUser matches the account field in Mylibrary.txt, the following code will execute
    if(strcasecmp(currentUser,acc)==0) {

      // Prints the line that relates to the current user
      printf("%d,%s,%s,%s,%s,%s ",id,title,author,acc,co,due);

      /* Copies and splits up the duedate string field
      by using "-" as the delimiter and stores the split string into cmpdate */
      strcpy(buff,due);
      char *p = strtok(buff,"-");
      int i = 0;
      while (p!=NULL) {
        cmpdate[i++] = p;
        p = strtok(NULL,"-");
      }

      /* Compares the current date to due date and prints OVERDUE
      if due date is greater than current date */
      if(year > atoi(cmpdate[0])) {
        printf("OVERDUE");
      }
      if(year = atoi(cmpdate[0])) {
        if(month > atoi(cmpdate[1])) {
          printf("OVERDUE");
        }
        if(month = atoi(cmpdate[1])) {
          if(day > atoi(cmpdate[2])) {
            printf("OVERDUE");
          }
        }
      }
      printf("\n");
    }
  }
  fclose(fp);

  // Asks if user wants to try again or go back to menu
  char try[2];
  int feel = 1;
  while(feel != 0){
		printf("Press 'T' to try again. Press 'B' to got back to main menu. ");
		scanf(" %s",&try);
		if(strcasecmp(try,"t") == 0){
      			printf("\n");
      			checkedOut();
		} else if(strcasecmp(try,"b") == 0) {
			userMain();
		} else {
			printf("Command does not exist\n");
		}
	}

  return 0;
}

void quit() {
  exit(0);
}

// Function for logging in to Library System. Checks if username exists.
int login() {
  // User Info Variables
  int id;
  char first[100], last[100], acc[100], p[100];
  char cat;

  // User Input
  char user[100];
  char welcome[100];

  // Username Prompt
  printf("USERNAME: ");
  scanf("%s",user);

  FILE *fp;
  fp = fopen("UserInfo.txt","r");

  // Copies each line from UserInfo.txt into corresponding User Info Variables
  int success = 1;
  while(fscanf(fp,"%d,%10[^,],%10[^,],%10[^,],%10[^,],%c",&id,first,last,acc,p,&cat)==6) {
    if (strcasecmp(user,acc)==0) {
      success = 0;
    }
  }

  // If success = 0, then user match was successful and will now prompt for password.
  if (success == 0) {
    pass();
  }

  // If user did not match, success will remain false and prompt user to re-enter info.
  if (success == 1) {
    printf("User does not exist.\n");
    login();
  }

  fclose(fp);
  return 0;
}

// Function checks if password matches the saved password for currentUser
int pass() {
  // User Info Variables
  int id;
  char first[100], last[100], acc[100], p[100];
  char cat;

  // Password Prompt
  char pw[100];
  printf("PASSWORD: ");
  scanf("%s",pw);

  FILE *fp;
  fp = fopen("UserInfo.txt","r");

  // Copies each line from UserInfo.txt into corresponding User Info Variable
  int success = 1;
  while(fscanf(fp,"%d,%10[^,],%10[^,],%10[^,],%10[^,],%c",&id,first,last,acc,p,&cat)==6) {
    if (strcmp(pw,p)==0) {
      printf("Welcome %s.\n",acc);
      strcpy(currentUser,acc);
      // If user is Borrrower, program will redirect to the User's menu.
      // Otherwise, program will direct to Admin's menu.
      if (cat == 'B') {
        userMain();
      } else {
        adminMain();
      }
      success = 0;
    }
  }

  // If password did not match, success remains 1 and will prompt user to re-enter info
  if (success == 1) {
    printf("Password is incorrect.\n");
    login();
  }

  fclose(fp);
  return 0;
}

// This function was used to count the number of lines in UserInfo.txt
int lineCount() {
  FILE *fp;
  int count = 0;
  char filename[1000];
  char c;

  fp = fopen("UserInfo.txt", "r");

  if (fp == NULL) {
    printf("Could not open file.");
    return 0;
  }

  for (c = getc(fp); c != EOF; c = getc(fp)) {
      if (c == '\n') {
        count = count + 1;
      }
  }
  fclose(fp);
  return count;
}

// This function was used to count the number of lines in Mylibrary.txt
int countLines() {
  FILE *fp2;
  int line = 0;
  char c;
  fp2 = fopen("Mylibrary.txt","r");
  for (c = getc(fp2); c != EOF; c = getc(fp2)) {
    if (c == '\n') {
      line = line + 1;
    }
  }
  return line;
  fclose(fp2);
}

// This function is used to print Mylibrary.txt
void printText() {
  FILE *fp;
  char c;
  fp = fopen("Mylibrary.txt","r");
  c = fgetc(fp);
  while (c != EOF) {
    printf("%c",c);
    c = fgetc(fp);
  }
  fclose(fp);
}

int checkId(int n) {
  char buf[128];
  int id;
  int ID[countLines()];
  int i = 0;

  FILE *fp;
  fp = fopen("Mylibrary.txt","r");

  while(fscanf(fp,"%d",&id)==1) {
    ID[i] = id;
    i++;
  }
  fclose(fp);

  int j = 0;
  while(j < (countLines())) {
    if(n==ID[j]) {
      printf("ID already exists.\n");
      addBook();
    }
    j++;
  }

  return 0;
}

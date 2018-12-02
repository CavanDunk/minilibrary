#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Prototypes
int adminMain();
int userMain();
int aMain();
int uMain();
int addBook();
int deleteBook();
int checkOut();
int returnBook();
int query();
int bookStatus();
int checkedOut();
int login();
int pass();
void quit();
int lineCount();
int countLines();
int postAddBook();


// Global variables
char choice;
int bookId = 1;

struct USER {
  int id;
  char first[100];
  char last[100];
  char acc[100];
  char pass[100];
  char cat;
};

struct USER user;

int main() {
  login();
  return 0;
}

int adminMain() {

  scanf("%c",&choice);
  switch(choice) {
    case 'a':
      addBook();
    case 'd':
      deleteBook();
    case 'o':
      checkOut();
    case 'r':
      returnBook();
    case 'x':
      quit();
    default:
      printf("Welcome to the ADMIN MENU.\n");
      aMain();
      printf("What would you like to do? ");
      adminMain();
  }
  return 0;
}

int userMain() {
  switch(choice) {
    case 'q':
      query();
    case 's':
      bookStatus();
    case 'u':
      checkedOut();
    case 'x':
      quit();
    default:
      printf("Invalid input\n");
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

int uMenu() {
  printf("Enter \"q\" for book querry by author sorted by book title.\n");
  printf("Enter \"s\" for the status of a specific book.\n");
  printf("Enter \"u\" to list the books you have checked out.\n");
  printf("Enter \"x\" to Sign Out.\n");
  return 0;
}

// Admin Main Options
int addBook() {
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
  return 0;
}

int deleteBook() {
  return 0;
}

int checkOut() {
  return 0;
}

int returnBook() {
  return 0;
}

// User Main Options
int query() {
  return 0;
}

int bookStatus() {
  return 0;
}

int checkedOut() {
  return 0;
}

void quit() {
  login();
}

// Prompt for username
int login() {


  // User Info
  int id;
  char first[100];
  char last[100];
  char acc[100];
  char p[100];
  char cat;

  // User Input
  char user[100];
  char welcome[100];

  printf("USERNAME: ");
  scanf("%s",user);

  FILE *fp;
  fp = fopen("/Users/jnguyen/Documents/GitHub/minilibrary/UserInfo.txt","r");

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

// Prompt for user's password
int pass() {

  // User Info
  int id;
  char first[100];
  char last[100];
  char acc[100];
  char p[100];
  char cat;

  char pw[100];
  printf("PASSWORD: ");
  scanf("%s",pw);

  FILE *fp;
  fp = fopen("/Users/jnguyen/Documents/GitHub/minilibrary/UserInfo.txt","r");

  int success = 1;
  while(fscanf(fp,"%d,%10[^,],%10[^,],%10[^,],%10[^,],%c",&id,first,last,acc,p,&cat)==6) {
    if (strcmp(pw,p)==0) {
      printf("Welcome %s.\n",acc);
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
  return 0;
}

int lineCount() {
  FILE *fp;
  int count = 0;
  char filename[1000];
  char c;

  fp = fopen("/Users/jnguyen/Documents/GitHub/minilibrary/UserInfo.txt", "r");

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

int countLines() {
  FILE *fp2;
  int line = 0;
  char c;
  fp2 = fopen("/Users/jnguyen/Documents/GitHub/minilibrary/Mylibrary.txt","r");
  for (c = getc(fp2); c != EOF; c = getc(fp2)) {
    if (c == '\n') {
      line = line + 1;
    }
  }
  return line;
  fclose(fp2);
}

void printText() {
  FILE *fp;
  char c;
  fp = fopen("/Users/jnguyen/Documents/GitHub/minilibrary/Mylibrary.txt","r");
  c = fgetc(fp);
  while (c != EOF) {
    printf("%c",c);
    c = fgetc(fp);
  }
  fclose(fp);
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define USERSIZE 20
// Prototypes
int adminMain();
int userMain();
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

// Global variables
char choice;
int l = lineCount(); // # of lines in UserInfo.txt

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
      printf("Invalid input\n");
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

// Admin Main Options
int addBook() {
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
  exit(0);
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

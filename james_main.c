#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// prototypes
int add_user();
int getdata_user(int choice);
int checkUserId(int n);
int lineCount();

// list of global variables
char choice;
FILE *login;
char catagories_u[][15]={"Student","teacher","others"};

// main interface
int main() {
  add_user();
}

struct USER {
  int id;
  char name[20];
  char pass[20];
  char *cat;
};

struct USER user;

int add_user() {
    FILE *fp;
    int i, choice;
    printf("Enter your choice: ");
    scanf("%d",&choice);
    fp = fopen("uRecord.txt","ab+");
    if(setdata_user(choice)==1){
      user.cat=catagories_u[choice-1];
      fseek(fp,0,SEEK_END);
      fprintf(fp,"%d,%s,%s,%s\n",user.id,user.name,user.pass,user.cat);
      fclose(fp);
      printf("The record is sucessfully saved");
    }
    fclose(fp);
    return 1;
}

int setdata_user(int choice) {
  int userID;

  printf("Enter your info below.\n");

  // Displays the selected user category
  printf("Category: ");
  printf("%s\n",catagories_u[choice-1]);

  // Enter User ID and store in id variable in struct user
  printf("User ID: ");
  scanf("%d",&userID);

  // Checks for an existing user ID
  checkUserId(userID);
  user.id=userID;

  // Enter username and stores it in name[] in struct user
  printf("User Name: ");
  scanf("%s",user.name);

  //Enter password and stores it in pass[] in struct user
  printf("Password: ");
  scanf("%s",user.pass);

  return 1;
}

int checkUserId(int n) {
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

  for (int j = 0; j < lineCount(); j++) {
    if(n == ID[j]) {
      printf("ID already exists.\n");
      addBook();
    }
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

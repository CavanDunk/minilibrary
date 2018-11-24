#include <stdio.h>
#include <string.h>

// prototypes
int add_user();
int getdata_user(int choice);

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
    fp = fopen("uRecord.dat","ab+");
    if(getdata_user(choice)==1){
      user.cat=catagories_u[choice-1];
      fseek(fp,0,SEEK_END);
      fwrite(&user,sizeof(user),1,fp);
      fclose(fp);
      printf("The record is sucessfully saved");
    }
    fclose(fp);
    return 1;
}

int getdata_user(int choice) {
  int x1 = 30;
  int userID;
  printf("Enter info below\n");
  printf("category: "); printf("%s",catagories_u[choice-1]);
  printf("\nuser ID: "); scanf("%d",&userID);

  if(user.id==userID) {
    printf("id already exist");
  }

  user.id=userID;
  printf("\nusername: "); scanf("%s",user.name);
  printf("\npassword: "); scanf("%s",user.pass);
  return 1;
}

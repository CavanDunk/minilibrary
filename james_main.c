#include <stdio.h>
#include <string.h>

//Prototypes
int adminMain(void);
int add_user(void);
int u_pass();
int user_pass();
int getdata(int choice);

// Global variables
char choice;
FILE *login;
char findBook;
char password[10];
int x = 15;

// Main Interface
int main () {
  printf("Login Area\n");
  printf("1. Admin\n");
  printf("2. User\n");
  printf("3. Exit\n");
  printf("Enter your choice: ");
  choice = getchar();
  switch(choice) {
    case '1':
      add_user();
      break;

    case '2':
      u_pass();
      break;

    case '3':
      //finish();
      break;

    default:
      printf("wrong input! --- try again.");
      main();
  };

  return 0;
}

int adminMain(void) {
  printf("Admin Menu\n");
  printf("To be completed later...");
  return 1;
}

struct USER {
  int id;
  char name[20];
  char pass[20];
  char *cat;
};

struct USER user;

int add_user(void) {
  FILE *fp;
  int i, choice;
  fp = fopen("uRecord.dat","ab+");
  if(1==1) {
    fseek(fp,0,SEEK_END);
    fwrite(&user,sizeof(user),1,fp);
    fclose(fp);
    printf("done");
  }
  return 1;
}

int u_pass() {
  printf("To enter the user area, a Library ID is required.\n");
  printf("Do you have a Library ID(Y/n): ");
  if(getchar()=='n') {
    printf("please contact a Library admin for your Library ID.");

    main();
  } else {
    user_pass();
  }
  return 1;
}

int user_pass() {
  FILE *ft, *fp;
  int d,findUser = 0;
  while(1) {
    printf("USER login\n");
    printf("please enter user id: ");
    scanf("%d",&d);
    fp = fopen("uRecord.dat","rb+");
    while(fread(&user,sizeof(user),1,fp)==1) {
      if(user.id==d){
        printf("user record is available.\n");
        printf("user name is %s","bob");

        char p[20];
        printf("enter password: ");
        scanf("%s",p);
        if(strcmp(user.pass,(p))==0) {
          printf("thank you");

          //userMain();
        } else {
          printf("wrong pass");

          main();
        }
      }
    }
    if(findUser == 0) {
      printf("no user found");

      main();
    }
  }
}

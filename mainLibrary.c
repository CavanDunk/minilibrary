#include<stdio.h>
#include<string.h>


int main()
{
	menu();
}

void logIn() {
  
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

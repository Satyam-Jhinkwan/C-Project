#include <stdio.h>
#include <string.h>

typedef struct BookShelf
{
    int ID;
    char title[50];
    char author[50];
}BookShelf;


void addBook( BookShelf *books){
    printf("\nEnter Book ID : ");
    scanf("%d",&books->ID);
    getchar();

    printf("Enter Book Title : ");
    fgets(books->title, sizeof(books->title), stdin);
    books->title[strcspn(books->title, "\n")] = 0; 

    printf("Enter Book Author's Name : ");
    fgets(books->author, sizeof(books->author), stdin);
    books->author[strcspn(books->author, "\n")] = 0; 
        
    printf("\nBook Added Successfully :)");
}

void borrowBook (BookShelf *books , int n){
    int bid , found = 0 , stdID;
    printf("\nEnter Student ID : ");
    scanf("%d",&stdID);
    printf("Enter Book ID : ");
    scanf("%d",&bid);
     for (int i = 0; i < n; i++) {
        if (books[i].ID == bid) { 
            printf("Book is available.\n");
            printf("Book Title: %s\n", books[i].title);
            printf("Book Author: %s\n", books[i].author);
            found = 1;
            break;
        }
    }
    if(found == 0 ){
        printf("There was no Book With That Book ID\n");
    }else{
        printf("Book Is Issued To You\n");
    }
}


int main(){
    int choice , n = 0;
    BookShelf books[100];
    printf("\n************* WELCOME TO E-LIBRARY *************");
    printf("\n\nEnter   1 To Add A Book");
    printf("\n\t2 To Borrow A Book");
    printf("\n\t3 To Return A Book");
    printf("\n\t4 To Generate Reports : ");
    scanf("%d",&choice);
    getchar();
    if(choice == 1){
        addBook(&books[n]);
        n++;  
    }
    else if(choice == 2){
        borrowBook(books , n);
    }
    else if(choice == 3){}
    else if(choice == 4){}
    else{
        printf("\nInvalid Input");
    }
    return 0;
}
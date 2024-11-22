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

void borrowBook (BookShelf *books , BookShelf *student ,int n , int *m){
    int bid , found = 0 , stdID;
    printf("\nEnter Student ID : ");
    scanf("%d",&stdID);
    printf("Enter Book ID : ");
    scanf("%d",&bid);
     for (int i = 0; i < n; i++) {
        if (books[i].ID == bid) { 
            printf("\nBook is available.\n");
            printf("Book Title: %s\n", books[i].title);
            printf("Book Author: %s\n", books[i].author);
            student[*m] = books[i];
            found = 1;
            break;
        }
    }
    if(found == 0 ){
        printf("\nThere was no Book With That Book ID");
    }else{
        printf("\nBook Borrowed Successfully by Student %d",stdID);
        (*m)++;
    }
}

void returnBook(BookShelf *books, BookShelf *student, int *m){
    int bid, stdID, late = 0,found = 0;
    printf("\nEnter Student ID : ");
    scanf("%d", &stdID);
    printf("Enter Book ID : ");
    scanf("%d", &bid);
    printf("Enter Number Of Days Late : ");
    scanf("%d", &late);
    for(int i = 0; i < *m; i++) {
        if(student[i].ID == bid) {
            student[i].ID = 0;
            strcpy(student[i].title, "");
            strcpy(student[i].author, "");
            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("\nNo such book was borrowed by this student.\n");
    } else {
        if(late > 0) {
            printf("Fine of Rs. %d Applied", late * 10);
        }
        printf("\nBook Returned Successfully By Student %d", stdID);
        (*m)--;
    }
}


void result(BookShelf *books ,BookShelf *student , int n , int m){
    printf("\nList of all available books in the library :-\n");
    for(int i=0; i<n ; i++){
        printf("\nBook %d ID : %d",i+1,books[i].ID);
        printf("\nBook %d Title : %s",i+1,books[i].title);
        printf("\nBook %d Author : %s",i+1,books[i].author);
    }

    printf("\n\nList of books Borrowd by the student :-\n");
    for(int i=0; i<m ; i++){
        printf("\nBook %d ID : %d",i+1,student[i].ID);
        printf("\nBook %d Title : %s",i+1,student[i].title);
        printf("\nBook %d Author : %s",i+1,student[i].author);
    }

}

int main(){
    int choice , n = 2 , quit=1 , m=0;
    BookShelf books[100]={
    {101, "It Ends With Us", "Colleen Hoover"},
    {102, "Berserk", "Kentaro Miura"},
    {103, "Vinland Saga", "Makato Yukimura"},
    };

    BookShelf student[100];
    printf("\n************* WELCOME TO E-LIBRARY *************");
    
    while (quit != 0){
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
            borrowBook(books ,student, n , &m);
        }
        else if(choice == 3){
            returnBook(books,student,&m);
        }
        else if(choice == 4){
            result(books , student , n , m);
        }
        else{
            printf("\nInvalid Input");
        }
        
        printf("\n\nEnter 0 to quit or input anything to continue : ");
        scanf("%d",&quit);
        printf("\n\n********************");
    }
    return 0;
}
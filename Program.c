#include <stdio.h>
#include <string.h>

typedef struct BookShelf
{
    int ID;
    char title[50];
    char author[50];
    int borrowedByStudentID;
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
        
    books->borrowedByStudentID = 0;
    printf("\nBook Added Successfully :)");
}

void borrowBook(BookShelf *books, BookShelf *student, int n, int *m) {
    int bid, found = 0, stdID;
    printf("\nEnter Student ID : ");
    scanf("%d", &stdID);
    printf("Enter Book ID : ");
    scanf("%d", &bid);

    for (int i = 0; i < n; i++) {
        if (books[i].ID == bid) { 
            if (books[i].borrowedByStudentID != 0) {
                printf("\nThis book is already borrowed by Student %d\n", books[i].borrowedByStudentID);
                return;
            }
            printf("\nBook is available.\n");
            printf("Book Title: %s\n", books[i].title);
            printf("Book Author: %s\n", books[i].author);
            books[i].borrowedByStudentID = stdID;
            student[*m] = books[i];
            (*m)++;
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nThere was no Book With That Book ID\n");
    } else {
        printf("\nBook Borrowed Successfully by Student %d\n", stdID);
        (*m)++;
    }
}

void returnBook(BookShelf *books, BookShelf *student, int n, int *m) {
    int bid, stdID, late = 0, found = 0;
    printf("\nEnter Student ID : ");
    scanf("%d", &stdID);
    printf("Enter Book ID : ");
    scanf("%d", &bid);
    printf("Enter Number Of Days Late : ");
    scanf("%d", &late);

    for (int i = 0; i < n; i++) {
        if (books[i].ID == bid && books[i].borrowedByStudentID == stdID) {
            books[i].borrowedByStudentID = 0; 
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nNo such book was borrowed by this student.\n");
        return;
    }

    for (int i = 0; i < *m; i++) {
        if (student[i].ID == bid && student[i].borrowedByStudentID == stdID) {
            for (int j = i; j < *m - 1; j++) {
                student[j] = student[j + 1];
            }
            (*m)--;
            break;
        }
    }

    if (late > 0) {
        printf("Fine of Rs. %d Applied\n", late * 10);
    }
    printf("\nBook Returned Successfully By Student %d\n", stdID);
}

void result(BookShelf *books, BookShelf *student, int n, int m) {
    printf("\nList of all available books in the library :-\n");
    for (int i = 0; i < n; i++) {
        if (books[i].borrowedByStudentID == 0) {
            printf("\n***** BOOK %d *****", i + 1);
            printf("\nBook ID : %d", books[i].ID);
            printf("\nBook Title : %s", books[i].title);
            printf("\nBook Author : %s\n", books[i].author);
        }
    }

    printf("\n\nList of books Borrowed by the students :-\n");
    for (int i = 0; i < m; i++) {
        printf("\n***** BOOK %d *****", i + 1);
        printf("\nBook ID : %d", student[i].ID);
        printf("\nBook Title : %s", student[i].title);
        printf("\nBook Author : %s", student[i].author);
        printf("\nBorrowed By Student %d\n", student[i].borrowedByStudentID);
    }
}

int main(){
    int choice , n = 3 , quit=1 , m=0;
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
            returnBook(books,student,n,&m);
        }
        else if(choice == 4){
            result(books , student , n , m);
        }
        else{
            printf("\nInvalid Input");
        }
        
        printf("\n\nEnter 0 to quit or any number to continue : ");
        scanf("%d",&quit);
    }
    printf("\n\n**********************************************");
    return 0;
}
#ifndef 	LIBRARY_H
#define 	LIBRARY_H
typedef struct
{
    char Book_Title[100] ;
    char AuthorName[100] ;
    int Publication_Year ;
    int Copies_Number ;
    float Price ;
    char Status[50] ;
}Book;
void Add_Book           (void) ;
void PrintBookDetails   (void) ;
void Borrow_Book        (void) ;
void DeleteBook         (void) ;
void BuyBook            (void) ;
void Design             (void) ;

#endif

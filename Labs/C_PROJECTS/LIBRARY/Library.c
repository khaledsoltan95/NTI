#include <stdio.h>
#include "Library.h"

Book Library[100] ;
static char Counter = 0 ;

void Add_Book           (void)
{
    char Flag = 7  ;
    char Count = 0 ;
    char i=0 , j ;
    if (Counter < 100 )
    {
        char Temp[100];
        printf("Enter Book Title : \n") ;
        scanf ("%s",Temp) ;
        while (Temp[i] != NULL)
        {
            Count ++ ;
            i++ ;
        }
        for ( i = 0 ; (i<Counter) ; i++)
        {
            Flag = 0 ;
            for ( j = 0 ; (j<Count-1)  ; j++)
            {
                if ((Library[i]).Book_Title[j] != Temp[j])
                {
                    Flag = 1 ;
                    break ;
                }
            }
            if ( Flag == 0  )
            {
                break ;
            }
        }
        Counter ++ ;
        Count = Counter ;
        if ( (Flag != 0)  )
        {
            i = 0  ;
            while (Temp[i] != NULL )
            {
               Library[Counter-1].Book_Title[i] = Temp[i] ;
                i++ ;
            }
            printf("Enter Author Name : \n") ;
            scanf ("%s",Library[Counter-1].AuthorName) ;
            printf("Enter Publication Year : \n") ;
            scanf ("%d",&Library[Counter-1].Publication_Year) ;
            printf("Enter Copies Number : \n") ;
            scanf ("%d",&Library[Counter-1].Copies_Number) ;
            printf("Enter Price : \n") ;
            scanf ("%f",&Library[Counter-1].Price) ;
            printf("Enter Status : \n") ;
            scanf ("%s",Library[Counter-1].Status) ;
        }
        else
        {
            Library[Counter-1].Copies_Number ++ ;
        }
        printf("************Book adding done*************\n") ;
    }
    else
    {
        printf("No More Books");
    }
}
void PrintBookDetails   (void)
{
    char Flag = 7  ;
    char Search[100];
    char i=0 ,j;
    char Count = 0 ;
    printf("Enter Book Title \n") ;
    scanf("%s",Search) ;
    while (Search[i] != NULL)
    {
        Count ++ ;
        i++ ;
    }
    for ( i = 0 ; (i<Counter) ; i++)
    {
        Flag = 0 ;
        for ( j = 0 ; (j<Count)  ; j++)
        {
            if ((Library[i]).Book_Title[j] != Search[j])
            {
                Flag = 1 ;
                break ;
            }
        }
        if ( Flag == 0  )
        {
            break ;
        }
    }
    Count = Counter ;
     if ( (Flag == 0)  )
        {
            printf("Author Name : %s \n",Library[i].AuthorName) ;
            printf("Publication Year : %d \n",Library[i].Publication_Year) ;
            printf("Copies Number : %d \n",Library[i].Copies_Number) ;
            printf("Price : %f \n",Library[i].Price) ;
            printf("Status : %s \n",Library[i].Status) ;
            printf("************Operation Required Done*************\n") ;
        }
    else
        {
            printf("************Not Founded*************\n") ;
        }
}
void Borrow_Book        (void)
{
    char Flag = 7  ;
    char Search[100];
    char i=0 ,j;
    char Count = 0 ;
    printf("Enter Book Title \n") ;
    scanf("%s",Search) ;
    while (Search[i] != NULL)
    {
        Count ++ ;
        i++ ;
    }
    for ( i = 0 ; (i<Counter) ; i++)
    {
        Flag = 0 ;
        for ( j = 0 ; (j<Count)  ; j++)
        {
            if ((Library[i]).Book_Title[j] != Search[j])
            {
                Flag = 1 ;
                break ;
            }
        }
        if ( Flag == 0  )
        {
            break ;
        }
    }
     if ( (Flag == 0)  )
        {
            Library[i].Copies_Number -- ;
            printf("************Operation Required Done*************\n") ;

        }
    else
        {
            printf("************Not Founded*************\n") ;
        }
}
void DeleteBook         (void)
{
    char Flag = 7  ;
    char Search[100];
    char i=0 ,j;
    char Count = 0 ;
    printf("Enter Book Title \n") ;
    scanf("%s",Search) ;
    while (Search[i] != NULL)
    {
        Count ++ ;
        i++ ;
    }
    for ( i = 0 ; (i<Counter) ; i++)
    {
        Flag = 0 ;
        for ( j = 0 ; (j<Count)  ; j++)
        {
            if ((Library[i]).Book_Title[j] != Search[j])
            {
                Flag = 1 ;
                break ;
            }
        }
        if ( Flag == 0  )
        {
            break ;
        }
    }
     if ( Flag == 0 )
        {
            //Counter -= Library[i].Copies_Number ;
            Count = Library[i].Copies_Number ;
            Count = Counter ;
            for (j=i ; j<Counter-1 ; j++ )
            {
                Library[j]= Library[j+1] ;
            }
            Library[j].Book_Title[0] = 0 ;
            Library[j].AuthorName[0] = 0 ;
            Library[j].Publication_Year = 0 ;
            Library[j].Copies_Number = 0  ;
            Library[j].Price = 0 ;
            Library[j].Status[0] = 0 ;
             printf("************Deletion Required Done*************\n") ;
        }
    else
        {
            printf("************Not Founded*************\n") ;
        }
}
void BuyBook            (void)
{
    char Flag = 7  ;
    char Search[100];
    char i=0 ,j , BookCopies = 0 ;
    char Count = 0 ;
    printf("Enter Book Title \n") ;
    scanf("%s",Search) ;
    while (Search[i] != NULL)
    {
        Count ++ ;
        i++ ;
    }
    for ( i = 0 ; (i<Counter) ; i++)
    {
        Flag = 0 ;
        for ( j = 0 ; (j<Count)  ; j++)
        {
            if ((Library[i]).Book_Title[j] != Search[j])
            {
                Flag = 1 ;
                break ;
            }
        }
        if ( Flag == 0  )
        {
            break ;
        }
    }
     if ( (Flag == 0)  )
        {
            printf("Enter Number of Copies \n") ;
            scanf("%d",&BookCopies) ;
            while ( ( Library[i].Copies_Number + BookCopies ) > 100 )
            {
                printf("************No Enough Space*************\n") ;
                printf("Enter Number of Copies \n") ;
                printf("************To exit enter 0 ************ \n") ;
                scanf("%d",&BookCopies) ;
            }
            Library[i].Copies_Number += BookCopies ;
            printf("************Operation Required Done*************\n") ;

        }
    else
        {
            printf("************Not Founded*************\n") ;
        }

}
void Design             (void)
{
    char Option = 0 ;
    system ("cls") ;
    printf("************************************************************\n") ;
    printf("\t\tWELCOME TO MY LIBRARY \n") ;
    printf("************************************************************\n") ;
    printf("\t\tPlease select one of these options \n") ;
    printf("\t\t********************************** \n") ;
    printf("1-Add Book\n");
    printf("2-Print Book Details\n");
    printf("3-Borrow Book \n");
    printf("4-Delete Book\n");
    printf("5-Buy Book \n");
    printf("\t\t7-Exit \n");
    printf("************************************************************\n") ;
    scanf("%d",&Option) ;
    switch (Option)
    {
        case 7  :    system ("cls") ;   printf("\t\tBYE BYE ") ;                        break ;
        case 1  :    system ("cls") ;   Add_Book() ;        system ("cls") ; Design() ; break ;
        case 2  :    system ("cls") ;   PrintBookDetails() ;printf("\nEnter any number to switch to Home Page\n");scanf("%d",&Option);system ("cls") ; Design() ; break ;
        case 3  :    system ("cls") ;   Borrow_Book();      system ("cls") ; Design() ; break ;
        case 4  :    system ("cls") ;   DeleteBook();       system ("cls") ; Design() ; break ;
        case 5  :    system ("cls") ;   BuyBook() ;         system ("cls") ; Design() ; break ;
        default :    system ("cls") ;   Design() ;                                      break ;
    }

}

#include <stdio.h>
#include <stdlib.h>

                                /* THIS APPLICATION TO GENERATE HASH */

void HashFunc (void) ;
int main()
{
    HashFunc() ;                                  // HASH GENERATION
    while (1)
    {

    }
}
 void HashFunc (void)
 {
    unsigned int Counter = 0 ;
    unsigned char arr[256] ;
    unsigned short int Sum[16] ;

    for (unsigned int i = 0 ; i<256 ; i++)
    {
        arr[i] = i ;
    }
    for (unsigned int j = 0 ; j<256 ; j++)
    {
         printf("%d\t" , arr[j] ) ;
    }
    for (unsigned int k = 0 ; k < 256 ; k++)
    {
         if ((k%16) == 0 )
         {
             Counter ++ ;
         }
         else
         {
             Sum[Counter] += arr[k] ;
         }
     }
     printf("\n                                     the Result are : \n") ;
     for (unsigned int m = 0 ; m < 16 ; m++)
     {
         printf("%d\t",Sum[m]) ;
     }
     arr[10] = 201 ;
     arr[20] = 150 ;
     arr[30] = 100 ;
     arr[40] = 50 ;
     arr[50] = 0 ;
    Counter = 0 ;
    for (unsigned int k = 0 ; k < 256 ; k++)
     {
         if ((k%16) == 0 )
         {
             Counter ++ ;
         }
         else
         {
             Sum[Counter] += arr[k] ;
         }
     }
    printf("\n                                      After change Date the Result are : \n") ;
     for (unsigned int m = 0 ; m < 16 ; m++)
     {
         printf("%d\t",Sum[m]) ;
     }
 }




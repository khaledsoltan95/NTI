#include <stdio.h>
#include <stdlib.h>

                                /* THIS APPLICATION TO ENCRYPT & DECRYPT MESSAGE */
#define         SIZE        1000
void CyberFunc (unsigned char* Message , unsigned int Key) ;
void HashFunc (void) ;
int main()
{

    unsigned char Real[SIZE] = {0} ;
    int Key ;
    printf("Enter Real Message\n ") ;
    gets(Real) ;
    printf("Enter Key\n ") ;
    scanf("%d",&Key) ;
    while (1)
    {
         CyberFunc(Real,Key) ;
    }
}

void CyberFunc (unsigned char* Message , unsigned int Key)
{
    if (Message != NULL)
    {
         int Option ;
    int i = 0 , Counter = 0  , j;
    for ( j = 0 ; Message[j] != '\0' ; j++)
    {
        Counter ++ ;
    }
    Message[j] = 0 ;
    printf("Enter 1 : Encrypt\n      2 : to Decrypt\n ") ;
    scanf("%d" , &Option) ;
    if (Key > 26)
    {
        Key %= 26 ;
    }
    if (Option==1u)
    {
        for (i=0 ; i<Counter ; i++)
        {
            if (Message[i] == ' '  )
            {

            }
            else
            {

                if ((Message[i] >= 'A') && (Message[i] <= 'Z'))
                {
                    Message[i] += Key ;
                    if ( Message[i] > 'Z')
                    {
                        Message[i] = (Message[i] - 'Z') + 'A' - 1u ;
                    }
                }
                else if ((Message[i] >= 'a') && (Message[i] <= 'z'))
                {
                    Message[i] += Key ;
                    if ( Message[i] > 'z')
                    {
                        Message[i] = (Message[i] - 'z') + 'a' - 1u ;
                    }
                }
            }
        }
        printf("%s\n" , Message) ;
    }
    else if (Option==2u)
    {
            for (i=0 ; i<Counter ; i++)
            {
                if (Message[i] == ' '  )
                {

                }
                else
                {
                    if ((Message[i] >= 'a') && (Message[i] <= 'z'))
                    {
                        Message[i] -= Key ;
                        if ( Message[i] <'a')
                        {
                            Message[i] = 'z' - ( 'a' -  Message[i]  ) + 1u    ;
                        }
                    }
                    else if ((Message[i] >= 'A') && (Message[i] <= 'Z'))
                    {
                        Message[i] -= Key ;
                        if ( Message[i] < 'A')
                        {
                            Message[i] = 'Z' - ( 'A' -  Message[i] ) +  1u   ;
                        }
                    }
                }
            }
        printf("%s\n" , Message) ;
    }
    else
    {
        printf("Not Valid Option \n") ;
    }
    }
    else
    {
        printf("NULL_ARRAY\N") ;
    }



}

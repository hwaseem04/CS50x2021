#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Getting credit card number
    long number = get_long("Enter card Number : ");
    
    //Declaring Necessary variables
    long num = number;
    int i = 0, sum1 = 0, sum2 = 0, d = 0;
    
    //Calculating Checksum
    while (number > 0)
    {
        d = number % 10; 
        
        number = number / 10;
        
        i++;
        //Multiplying every other digit by 2,starting from 
        //second-to-last digit and adding those products' digits
        if (i % 2 == 0)
        {
            if (d * 2 > 9)
            {
                int d1 = (d * 2) % 10 ;
                int d2 = (d * 2) / 10 ;
                sum1 += d1 + d2 ;
            }
            else
            {
                sum1 += d * 2;
            }
        }
        //adding remaining digits ,that are'nt multiplied by 2
        else
        {
            sum2 += d;
        }
    }
    long checksum = sum1 + sum2;
    
    //Checking the type of card
    for (int m = 0; m < i - 2; m++)
    {
        num = num / 10;
    }
    if (checksum % 10 == 0)
    {
        if ((i == 15) && (num == 34 || num == 37))
        {
            printf("AMEX\n");
        }
        else if ((i == 13 || i == 16) && ((num / 10) == 4))
        {
            printf("VISA\n");
        }
        else if ((i == 16) && (num == 51 || num == 52 || num == 53 || num == 54 || num == 55))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
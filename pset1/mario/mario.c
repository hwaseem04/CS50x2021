#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        //Get input for height
        height = get_int("Enter height : ");
    }
    while (height < 1 || height > 8);
    
    for (int i = 0; i < height; i++)
    {
        //displaying spaces for first pyramid
        for (int j = i; j < height - 1; j++)
        {
            printf(" ");
        }
        
        //displaying hashes for first pyramid
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        
        //Leaving spaces equal to width of two hashes
        printf("  ");
        
        //Displaying Hashes for second pyramid
        for (int l = 0; l < i + 1; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}
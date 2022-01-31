#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt for start size
    int start;
    do
    {
        start = get_int("Enter start size : ");
    }
    while (start < 9);
    
    //Prompt for end size
    int end;
    do
    {
        end = get_int("Enter end size : ");
    }
    while (end < start);

    //Calculate number of years until we reach threshold
    int i = 0;
    while (true)
    {
        if (start < end)
        {
            start = start + (start / 3) - (start / 4);
            i++;
        }
        else if (start >= end)
        {
            break;
        }
    }
    

    //Print number of years
    printf("Years: %i\n", i);
}


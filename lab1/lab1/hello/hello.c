#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //getting input
    string answer = get_string("Enter name : ");
    printf("Hello, %s\n", answer);
}
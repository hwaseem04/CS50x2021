#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Declaring Prototype of required helper functions
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //Getting input string from user
    string s = get_string("Text: ");
    
    //Getting values of number of words,letters,sentences
    int a = count_letters(s);
    int b = count_words(s);
    int c = count_sentences(s);
    
    //Calculating value of L and S
    float L = ((float)a / b) * 100;
    float S = ((float)c / b) * 100;
    
    //Calculating Coleman-Liau index value
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    
    //Displaying index value on respective conditions
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    
    else
    {
        printf("Grade %i\n", index);
    }
    
    
}

//Function for calculating number of sentences
int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }
    return count;
}

//Function for calculating number of words
int count_words(string text)
{
    int count = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count;
}

//Function for calculating number of letters
int count_letters(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}
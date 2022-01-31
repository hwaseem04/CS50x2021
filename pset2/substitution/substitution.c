#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>



int main(int argc, string argv[])
{
    
    
    // if total string in command line is more than 2
    if (argc != 2)
    {
        printf("Enter Valid Key Argument!\n");
        return 1;
    }
    
    else
    {
        int length = strlen(argv[1]);
        bool duplicate ;
        bool notalpha ;
        
        //
        for (int i = 0, n = length; i < n; i++)
        {
            char temp = argv[1][i];
            for (int j = i + 1, m = length; j < m; j++)
            {
                if (tolower(temp) == tolower(argv[1][j]))
                {
                    duplicate = true;
                    break;
                }
            }
            //Checking whether all characters in key are alphabets
            if (isalpha(temp) == false)
            {
                notalpha = true;
            }
            //Checking whether all characters in key are unique
            if (duplicate)
            {
                break;
            }
        }
        // Displaying output, when the length of key is not 26, or when it have duplicate values or when it contains non alphabetical characters
        if (length != 26 || notalpha  || duplicate)
        {
            printf("Invalid Key; Type key with only 26 Alphabets ,with no repeatation!\n");
            return 1;
        }
        //If the key is valid
        else
        {
            string original = get_string("plaintext: ");
            string key = argv[1];
            int length1 = strlen(original);

            char cipher[length1 + 1];
            
            //Appending values to new array - Cipher
            for (int i = 0, n = strlen(original); i < n; i++)
            {
                if (islower(original[i]))
                {
                    cipher[i] = tolower(key[original[i] - 97]);
                }
                else if (isupper(original[i]))
                {
                    cipher[i] = toupper(key[original[i] - 65]);
                }
                else
                {
                    cipher[i] = original[i];
                }
            }
            //Speccifying end of char array
            cipher[length1] = '\0';
            printf("ciphertext: ");
            
            //Displaying elements of char array one by one
            for (int i = 0; cipher[i] != '\0'; i++)
            {
                printf("%c", cipher[i]);
            }
            printf("\n");
            return 0;

        }
    }
}


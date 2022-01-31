#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    typedef uint8_t BYTE;
    
    //Checking for correct number of arguments
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    //Opening the input file 
    FILE *input = fopen(argv[1], "r");

    //Checking whether the file is opened
    if (input == NULL)
    {
        printf("Cannot open Forensic image\n");
        return 1;
    }
    //Declaring array of bytes
    BYTE buffer[512];
    
    //Initializing counter for keeping check on number of output image
    int i = 0;
    
    //Declaring array of characters for image file name
    char filename[8];
    
    FILE *output = NULL;
    
    while (fread(buffer, sizeof(BYTE), 512, input))
    {
        
        //When the signature of Jpeg is found
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
        {   
            
            if (output != NULL)
            {
                fclose(output);
            }
            sprintf(filename, "%03i.jpg", i);
            output = fopen(filename, "w");
            i++;
        }
        //Other blocks of the particular Jpeg file is added
        if (output != NULL)
        {
            fwrite(buffer, 512, 1, output);
        }
    }
    //Closing the input file
    fclose(input);
    
    //Closing the final image file
    fclose(output);
    return 0;
}
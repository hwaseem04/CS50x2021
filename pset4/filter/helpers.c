#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE average;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / (float)3);
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = average;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE temp1, temp2, temp3;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (int)(width / 2); j++)
        {
            temp1 = image[i][j].rgbtBlue;
            temp2 = image[i][j].rgbtGreen;
            temp3 = image[i][j].rgbtRed;
            image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
            image[i][width - 1 - j].rgbtBlue = temp1;
            image[i][width - 1 - j].rgbtGreen = temp2;
            image[i][width - 1 - j].rgbtRed = temp3;
        }

    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE newImage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            newImage[i][j] = image[i][j];
        }
    }

    for (int i = 0, red, green, blue, counter; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red = green = blue = counter = 0;
            // add the center pixel
            if (i >= 0 && j >= 0)
            {
                red += newImage[i][j].rgbtRed;
                green += newImage[i][j].rgbtGreen;
                blue += newImage[i][j].rgbtBlue;
                counter++;
            }
            // add Left pixel
            if (j - 1 >= 0)
            {
                red += newImage[i][j - 1].rgbtRed;
                green += newImage[i][j - 1].rgbtGreen;
                blue += newImage[i][j - 1].rgbtBlue;
                counter++;
            }
            // add right pixel
            if (j + 1 < width)
            {
                red += newImage[i][j + 1].rgbtRed;
                green += newImage[i][j + 1].rgbtGreen;
                blue += newImage[i][j + 1].rgbtBlue;
                counter++;
            }
            // add upper pixel
            if (i - 1 >= 0)
            {
                red += newImage[i - 1][j].rgbtRed;
                green += newImage[i - 1][j].rgbtGreen;
                blue += newImage[i - 1][j].rgbtBlue;
                counter++;
            }
            // add left upper pixel
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                red += newImage[i - 1][j - 1].rgbtRed;
                green += newImage[i - 1][j - 1].rgbtGreen;
                blue += newImage[i - 1][j - 1].rgbtBlue;
                counter++;
            }
            // add right upper pixel
            if (i - 1 >= 0 && j + 1 < width)
            {
                red += newImage[i - 1][j + 1].rgbtRed;
                green += newImage[i - 1][j + 1].rgbtGreen;
                blue += newImage[i - 1][j + 1].rgbtBlue;
                counter++;
            }
            // add lower pixel
            if (i + 1 < height)
            {
                red += newImage[i + 1][j].rgbtRed;
                green += newImage[i + 1][j].rgbtGreen;
                blue += newImage[i + 1][j].rgbtBlue;
                counter++;
            }
            // add lower left pixel
            if (i + 1 < height && j - 1 >= 0)
            {
                red += newImage[i + 1][j - 1].rgbtRed;
                green += newImage[i + 1][j - 1].rgbtGreen;
                blue += newImage[i + 1][j - 1].rgbtBlue;
                counter++;
            }
            // add lower right pixel
            if (i + 1 < height && j + 1 < width)
            {
                red += newImage[i + 1][j + 1].rgbtRed;
                green += newImage[i + 1][j + 1].rgbtGreen;
                blue += newImage[i + 1][j + 1].rgbtBlue;
                counter++;
            }

            image[i][j].rgbtRed = round(red / (float) counter) ;
            image[i][j].rgbtGreen = round(green / (float) counter) ;
            image[i][j].rgbtBlue = round(blue / (float) counter) ;
        }
    }

    return;
}
// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE newImage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            newImage[i][j] = image[i][j];
        }
    }
    
    for (int i = 0, Gxred, Gxgreen, Gxblue, Gyred, Gygreen, Gyblue, redROOT, greenROOT, blueROOT ; i < height ; i++)
    {   
        for (int j = 0; j < width; j++)
        {   
            Gxred = Gxgreen = Gxblue = Gyred = Gygreen = Gyblue = 0;

            //  Left pixel
            if (j - 1 >= 0)
            {
                Gxred += (newImage[i][j - 1].rgbtRed * -2);
                Gxgreen += (newImage[i][j - 1].rgbtGreen * -2);
                Gxblue += (newImage[i][j - 1].rgbtBlue * -2);
            }
            //  right pixel
            if (j + 1 < width)
            {
                Gxred += (newImage[i][j + 1].rgbtRed * 2);
                Gxgreen += (newImage[i][j + 1].rgbtGreen * 2);
                Gxblue += (newImage[i][j + 1].rgbtBlue * 2);
            }
            //  upper pixel
            if (i - 1 >= 0)
            {
                Gyred += (newImage[i - 1][j].rgbtRed * -2);
                Gygreen += (newImage[i - 1][j].rgbtGreen * -2);
                Gyblue += (newImage[i - 1][j].rgbtBlue * -2);
            }
            // left upper pixel
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                //Gx calculation
                Gxred  += (newImage[i - 1][j - 1].rgbtRed * -1);
                Gxgreen += (newImage[i - 1][j - 1].rgbtGreen * -1);
                Gxblue += (newImage[i - 1][j - 1].rgbtBlue * -1);
                //Gy calculation
                Gyred += (newImage[i - 1][j - 1].rgbtRed * -1);
                Gygreen += (newImage[i - 1][j - 1].rgbtGreen * -1);
                Gyblue += (newImage[i - 1][j - 1].rgbtBlue * -1);
            }
            //  right upper pixel
            if (i - 1 >= 0 && j + 1 < width)
            {
                //Gx calculation
                Gxred  += (newImage[i - 1][j + 1].rgbtRed * 1);
                Gxgreen += (newImage[i - 1][j + 1].rgbtGreen * 1);
                Gxblue += (newImage[i - 1][j + 1].rgbtBlue * 1);
                //Gy calculation
                Gyred += (newImage[i - 1][j + 1].rgbtRed * -1);
                Gygreen += (newImage[i - 1][j + 1].rgbtGreen * -1);
                Gyblue += (newImage[i - 1][j + 1].rgbtBlue * -1);
            }
            //  lower pixel
            if (i + 1 < height)
            {
                Gyred += (newImage[i + 1][j].rgbtRed * 2);
                Gygreen += (newImage[i + 1][j].rgbtGreen * 2);
                Gyblue += (newImage[i + 1][j].rgbtBlue * 2);
            }
            //  lower left pixel
            if (i + 1 < height && j - 1 >= 0)
            {
                //Gx calculation
                Gxred  += (newImage[i + 1][j - 1].rgbtRed * -1);
                Gxgreen += (newImage[i + 1][j - 1].rgbtGreen * -1);
                Gxblue += (newImage[i + 1][j - 1].rgbtBlue * -1);
                //Gy calculation
                Gyred += (newImage[i + 1][j - 1].rgbtRed * 1);
                Gygreen += (newImage[i + 1][j - 1].rgbtGreen * 1);
                Gyblue += (newImage[i + 1][j - 1].rgbtBlue * 1);
            }
            //  lower right pixel
            if (i + 1 < height && j + 1 < width)
            {
                //Gx calculation
                Gxred  += (newImage[i + 1][j + 1].rgbtRed * 1);
                Gxgreen += (newImage[i + 1][j + 1].rgbtGreen * 1);
                Gxblue += (newImage[i + 1][j + 1].rgbtBlue * 1);
                //Gy calculation
                Gyred += (newImage[i + 1][j + 1].rgbtRed * 1);
                Gygreen += (newImage[i + 1][j + 1].rgbtGreen * 1);
                Gyblue += (newImage[i + 1][j + 1].rgbtBlue * 1);
            }
            // Updating red channel of the pixel
            redROOT = round(sqrt(pow(Gxred, 2) + pow(Gyred, 2))) ;
            if (redROOT > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = redROOT;
            }
            // Updating green channel of the pixel
            greenROOT = round(sqrt(pow(Gxgreen, 2) + pow(Gygreen, 2))) ;
            if (greenROOT > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = greenROOT;
            }
            //Updating blue channel of the pixel
            blueROOT = round(sqrt(pow(Gxblue, 2) + pow(Gyblue, 2))) ;
            if (blueROOT > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = blueROOT;
            }
        }
    }
    return;
}

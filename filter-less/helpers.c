#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            double t = 0;
            t += image[i][j].rgbtBlue;
            t += image[i][j].rgbtRed;
            t += image[i][j].rgbtGreen;
            t = t/3;
            image[i][j].rgbtBlue = (int) round(t);
            image[i][j].rgbtRed = (int) round(t);
            image[i][j].rgbtGreen = (int) round(t);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int m = image[i][j].rgbtRed;
            int n = image[i][j].rgbtGreen;
            int p = image[i][j].rgbtBlue;
            int Red = (int) round(.393 * m + .769 * n + .189 * p);
            if(Red >255)
            {
                Red = 255;
            }
            int Green = (int) round(.349 * m + .686 * n + .168 * p);
            if(Green > 255)
            {
                Green = 255;
            }
            int Blue = (int) round(.272 * m + .534 * n + .131 * p);
            if(Blue > 255)
            {
                Blue = 255;
            }
            image[i][j].rgbtRed = Red;
            image[i][j].rgbtGreen = Green;
            image[i][j].rgbtBlue = Blue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int array[width][3];
    for(int i = 0; i < height ; i++)
    {
        for(int m = 0; m < width; m++)
        {
            array[m][0] = image[i][m].rgbtRed;
            array[m][1] = image[i][m].rgbtGreen;
            array[m][2] = image[i][m].rgbtBlue;
        }
        for(int m = 0; m < width; m++)
        {
            image[i][m].rgbtRed = array[width - 1 - m][0];
            image[i][m].rgbtGreen = array[width - 1 - m][1];
            image[i][m].rgbtBlue = array[width - 1 - m][2];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int totalRed, totalGreen, totalBlue;
            totalRed = totalBlue = totalGreen = 0;
            float counter = 0.00;
            for (int x = -1; x <2; x++)
            {
                for(int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    if(currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }
                    totalRed += image[currentX][currentY].rgbtRed;
                    totalGreen += image[currentX][currentY].rgbtGreen;
                    totalBlue += image[currentX][currentY].rgbtBlue;

                    counter++;
                }
            }
            temp[i][j].rgbtRed = round(totalRed / counter);
            temp[i][j].rgbtBlue = round(totalBlue / counter);
            temp[i][j].rgbtGreen = round(totalGreen / counter);
        }
    }
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}

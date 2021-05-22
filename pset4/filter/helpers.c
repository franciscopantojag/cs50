#include "helpers.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = (int) round((float)(image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / (float)3);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = (int) round(.393 * (float)image[i][j].rgbtRed + .769 * (float)image[i][j].rgbtGreen + .189 *
                                    (float)image[i][j].rgbtBlue);
            int sepiaGreen = (int) round(.349 * (float)image[i][j].rgbtRed + .686 * (float)image[i][j].rgbtGreen + .168 *
                                    (float)image[i][j].rgbtBlue);
            int sepiaBlue = (int) round(.272 * (float)image[i][j].rgbtRed + .534 * (float)image[i][j].rgbtGreen + .131 *
                                    (float)image[i][j].rgbtBlue);
            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;

            }
            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;

            }
            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;

            }
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE original[height][width];
    memset(original, 0, sizeof(original));
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            original[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = original[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = original[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = original[i][width - j - 1].rgbtBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE original[height][width];
    memset(original, 0, sizeof(original));
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            original[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int counter = 1;
            int totalRed = original[i][j].rgbtRed;
            int totalGreen = original[i][j].rgbtGreen;
            int totalBlue = original[i][j].rgbtBlue;
            if (i + 1 < height)
            {
                counter++;
                totalRed += original[i + 1][j].rgbtRed;
                totalGreen += original[i + 1][j].rgbtGreen;
                totalBlue += original[i + 1][j].rgbtBlue;
            }
            if (i - 1 >= 0)
            {
                counter++;
                totalRed += original[i - 1][j].rgbtRed;
                totalGreen += original[i - 1][j].rgbtGreen;
                totalBlue += original[i - 1][j].rgbtBlue;
            }
            if (j + 1 < width)
            {
                counter++;
                totalRed += original[i][j + 1].rgbtRed;
                totalGreen += original[i][j + 1].rgbtGreen;
                totalBlue += original[i][j + 1].rgbtBlue;
            }
            if (j - 1 >= 0)
            {
                counter++;
                totalRed += original[i][j - 1].rgbtRed;
                totalGreen += original[i][j - 1].rgbtGreen;
                totalBlue += original[i][j - 1].rgbtBlue;
            }
            if (i + 1 < height && j + 1 < width)
            {
                counter++;
                totalRed += original[i + 1][j + 1].rgbtRed;
                totalGreen += original[i + 1][j + 1].rgbtGreen;
                totalBlue += original[i + 1][j + 1].rgbtBlue;
            }
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                counter++;
                totalRed += original[i - 1][j - 1].rgbtRed;
                totalGreen += original[i - 1][j - 1].rgbtGreen;
                totalBlue += original[i - 1][j - 1].rgbtBlue;
            }
            if (i + 1 < height && j - 1 >= 0)
            {
                counter++;
                totalRed += original[i + 1][j - 1].rgbtRed;
                totalGreen += original[i + 1][j - 1].rgbtGreen;
                totalBlue += original[i + 1][j - 1].rgbtBlue;
            }
            if (i - 1 >= 0 && j + 1 < width)
            {
                counter++;
                totalRed += original[i - 1][j + 1].rgbtRed;
                totalGreen += original[i - 1][j + 1].rgbtGreen;
                totalBlue += original[i - 1][j + 1].rgbtBlue;
            }
            image[i][j].rgbtRed = (int) round((float)totalRed / (float)counter);
            image[i][j].rgbtGreen = (int) round((float)totalGreen / (float)counter);
            image[i][j].rgbtBlue = (int) round((float)totalBlue / (float)counter);

        }
    }
    return;
}

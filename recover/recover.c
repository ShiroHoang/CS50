#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;



int main(int argc, char *argv[])
{
    if( argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");

    if(input == NULL)
    {
        return 1;
    }

    char filename[8];
    FILE *image;
    BYTE buffer[512];
    int counter = 0;

    while (fread(buffer, 1, 512, input) == 512)
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ( buffer[3] & 0xf0) == 0xe0)
        {
            if(counter !=0)
            {
                fclose(image);
            }
            sprintf(filename, "%03i.jpg" , counter++);
            image = fopen(filename, "w");
            fwrite(buffer, 1, 512, image);
        }
        else if(counter > 0)
        {
            fwrite(buffer, 1, 512, image);
        }
    }
    fclose(input);
    fclose(image);
}
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if(argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }
    // check input
    int n = strlen(argv[1]);
    if(argv[1][n-1] != 'v' || argv[1][n-2] != 'a' || argv[1][n-3] != 'w')
    {
        printf("Input is not a WAV file.\n");
        return 1;
    }
    // check output
    int m = strlen(argv[2]);
    if(argv[2][m-1] != 'v' || argv[2][m-2] != 'a' || argv[2][m-3] != 'w')
    {
        printf("Output is not a WAV file.\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *input = fopen(argv[1], "r");
    if(input == NULL)
    {
        printf("Input file not found!\n");
        return 1;
    }

    // Read header
    // TODO #3
    WAVHEADER header;
    fread(&header, sizeof(WAVHEADER), 1, input);

    // Use check_format to ensure WAV format
    // TODO #4
    if(check_format(header) == 1)
    {
        return 1;
    }

    // Open output file for writing
    // TODO #5
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        fclose(input);
        printf("Could not create %s.\n", argv[2]);
    }

    // Write header to file
    // TODO #6
    fwrite(&header, sizeof(WAVHEADER), 1, output);

    // Use get_block_size to calculate size of block
    // TODO #7
    int size = get_block_size(header);

    // Write reversed audio to file
    // TODO #8
    if(fseek(input, size, SEEK_END))
    {
        return 1;
    }

    BYTE buffer[size];
    while(ftell(input) - size > sizeof(header))
    {
        if(fseek(input, - 2 * size, SEEK_CUR))
        {
            return 1;
        }
        fread(buffer, size, 1, input);
        fwrite(buffer, size, 1, output);
    }
    fclose(input);
    fclose(output);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if(header.format[0] != 'W' || header.format[1] != 'A' || header.format[2] != 'V' || header.format[3] != 'E')
    {
        return 1;
    }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    int n = header.bitsPerSample / 8;

    return header.numChannels * n;
}

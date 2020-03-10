#include<stdio.h>
#include<string.h>
#include<math.h>
#include"myheader.h"

void WriteImage(const char *fileName, unsigned char *pixels)
{
        FILE *outputFile = fopen(fileName, "wb");
        //*****HEADER************//
        const char *BM = "BM";
        fwrite(&BM[0], 1, 1, outputFile);
        fwrite(&BM[1], 1, 1, outputFile);
        int paddedRowSize = (int)(4 * ceil((float)bih.width/4.0f))*bih.bitcount/8;
        unsigned int fileSize = paddedRowSize*bih.height + HEADER_SIZE + INFO_HEADER_SIZE;
        fwrite(&fileSize, 4, 1, outputFile);
        unsigned int reserved = 0x0000;
        fwrite(&reserved, 4, 1, outputFile);
        unsigned int dataOffset = HEADER_SIZE+INFO_HEADER_SIZE;
        fwrite(&dataOffset, 4, 1, outputFile);

        //*******INFO*HEADER******//
        unsigned int infoHeaderSize = INFO_HEADER_SIZE;
        fwrite(&infoHeaderSize, 4, 1, outputFile);
        fwrite(&bih.width, 4, 1, outputFile);
        fwrite(&bih.height, 4, 1, outputFile);
        short planes = 1; //always 1
        fwrite(&planes, 2, 1, outputFile);
        fwrite(&bih.bitcount, 2, 1, outputFile);
        //write compression
        unsigned int compression = NO_COMPRESION;
        fwrite(&compression, 4, 1, outputFile);

        unsigned int imageSize = bih.width*bih.height*bih.bytecount;
        fwrite(&imageSize, 4, 1, outputFile);
        unsigned int resolutionX = 11811; //300 dpi
        unsigned int resolutionY = 11811; //300 dpi
        fwrite(&resolutionX, 4, 1, outputFile);
        fwrite(&resolutionY, 4, 1, outputFile);
        unsigned int colorsUsed = MAX_NUMBER_OF_COLORS;
        fwrite(&colorsUsed, 4, 1, outputFile);
        unsigned int importantColors = ALL_COLORS_REQUIRED;
        fwrite(&importantColors, 4, 1, outputFile);
        int i = 0;
        int unpaddedRowSize = bih.width*bih.bytecount;
        printf("\n%d %d",bih.height,unpaddedRowSize);
        for ( i = 0; i < bih.height*unpaddedRowSize; i++)
        {
                pixels[i+1]=(pixels[i+1]+pixels[i])/2;

        }
        unsigned char pixeldata[bih.height][unpaddedRowSize/bih.bytecount][bih.bytecount];
        for ( i = 0; i < bih.height; i++)
        {
                int pixelOffset = ((bih.height - i) - 1)*unpaddedRowSize;
                fwrite(&pixels[pixelOffset], 1, paddedRowSize, outputFile);

        }
}

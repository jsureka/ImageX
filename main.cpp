
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define DATA_OFFSET_OFFSET 0x000A
#define WIDTH_OFFSET 0x0012
#define HEIGHT_OFFSET 0x0016
#define BITS_PER_PIXEL_OFFSET 0x001C
#define HEADER_SIZE 14
#define INFO_HEADER_SIZE 40
#define NO_COMPRESION 0
#define MAX_NUMBER_OF_COLORS 0
#define ALL_COLORS_REQUIRED 0

  unsigned char *pixels;
void ReadImage(FILE* );

void WriteImage(const char*);
typedef struct {
	   unsigned int width;
	   unsigned int height;
	   unsigned int planes;
	   unsigned short bitcount;
	   unsigned int size;
	   unsigned int dataOffset;
	   unsigned int bytecount;
	} BITMAPINFOHEADER;

   static  BITMAPINFOHEADER bih;


static FILE *image;
BITMAPINFOHEADER getImageData(FILE *);

	char ipath[1000];

void readbmp(FILE*);



BITMAPINFOHEADER getImageData(FILE *image)
	{
	    FILE *x;
	    x=image;
	    BITMAPINFOHEADER h;
	    fseek(x,2,SEEK_SET);
	    fread(&h.size,4,1,x);
	    printf("Size=%d\n",h.size);
	    fseek(x,18,SEEK_SET);
	    fread(&h.width,4,1,x);
	    fseek(x,22,SEEK_SET);
	    fread(&h.height,4,1,x);
	    printf("Width=%d\tHeight=%d\n",h.width,h.height);
    fseek(x,26,SEEK_SET);
	    fread(&h.planes,2,1,x);
	    printf("Number of planes:%d\n",h.planes);
	    fseek(x,28,SEEK_SET);
	    fread(&h.bitcount,2,1,x);
	    printf("Bit Count:%d\n",h.bitcount);
	    h.bytecount=h.bitcount/8;
	    return h;
	}

void ReadImage(FILE *imageFile)
{
        bih=getImageData(imageFile);
        unsigned int dataOffset;
        fseek(imageFile, DATA_OFFSET_OFFSET, SEEK_SET);
        fread(&dataOffset, 4, 1, imageFile);
        printf("\n%d\n",dataOffset);

        int paddedRowSize = (int)(4 * ceil((float)(bih.width) / 4.0f))*(bih.bytecount);
        int unpaddedRowSize = (bih.width)*(bih.bytecount);
        int totalSize = unpaddedRowSize*(bih.height);
        pixels = (unsigned char*)malloc(totalSize);
        int i = 0;
        unsigned char *currentRowPointer = pixels+((bih.height-1)*unpaddedRowSize);
        for (i = 0; i < bih.height; i++)
        {
                fseek(imageFile, dataOffset+(i*paddedRowSize), SEEK_SET);
            fread(currentRowPointer, 1, unpaddedRowSize, imageFile);
            currentRowPointer -= unpaddedRowSize;
        }

        fclose(imageFile);
}

void WriteImage(const char *fileName)
{
        FILE *outputFile = fopen(fileName, "wb");
        //*****HEADER************//
        const char *BM = "BM";
        fwrite(&BM[0], 1, 1, outputFile);
        fwrite(&BM[1], 1, 1, outputFile);
        int paddedRowSize = (int)(4 * ceil((float)bih.width/4.0f))*bih.bytecount;
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
//        for ( i = 0; i < bih.height*unpaddedRowSize; i++)
//        {
//                pixels[i+1]=(pixels[i+1]+pixels[i]);
//
//        }
        unsigned char pixeldata[bih.height][unpaddedRowSize/bih.bytecount][bih.bytecount];
        for ( i = 0; i < bih.height; i++)
        {
                int pixelOffset = ((bih.height - i) - 1)*unpaddedRowSize;
                fwrite(&pixels[pixelOffset], 1, paddedRowSize, outputFile);

        }
        fclose(outputFile);
}

int main()
{
    while(image==NULL)
	{

		printf("Enter Path : ");
		scanf("%s",ipath);
		image=fopen(ipath,"rb+");
		if(image==NULL)
		printf("Error! Enter path again\n\n");
	}


	image=fopen(ipath,"rb+");
    ReadImage(image);

    WriteImage("image1.bmp");

}


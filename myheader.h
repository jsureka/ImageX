    unsigned char *pixels;
typedef struct {
	   unsigned int width;
	   unsigned int height;
	   unsigned int planes;
	   unsigned short bitcount;
	   unsigned int size;
	   unsigned int dataOffset;
	   unsigned int bytecount;
	} BITMAPINFOHEADER;


   static BITMAPINFOHEADER bih;
 static unsigned char pixelData[1000][1000][3];
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

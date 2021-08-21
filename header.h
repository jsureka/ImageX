#include<bits/stdc++.h>
using namespace std;
#include<graphics.h>
#include<conio.h>
#pragma pack(push, 1)
    typedef struct
    {
      char bitmapSignatureBytes[2];
      uint32_t sizeOfBitmapImageBytes;
      uint16_t reserved1;
      uint16_t reserved2;
      uint32_t pixelOffset[1][1];

}bmpFileHeader;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct
{
  uint32_t  dib_header_size;  // DIB Header size in bytes (40 bytes)
  int32_t   width;         // Width of the image
  int32_t   height;        // Height of image
  uint16_t  num_planes;       // Number of color planes
  uint16_t  bits_per_pixel;   // Bits per pixel
  uint32_t  compression;      // Compression type
  uint32_t  image_size_bytes; // Image size in bytes
  int32_t   x_resolution_ppm; // Pixels per meter
  int32_t   y_resolution_ppm; // Pixels per meter
  uint32_t  num_colors;       // Number of colors
  uint32_t  important_colors; // Important colors

}bmpInfoHeader;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct
{
  uint8_t blue;
  uint8_t green;
  uint8_t red;

}pixel;
#pragma pack(pop)

    int options();
    int randNum(void);
    void edgeDetection();
    void viewOptions();
void viewInput(bmpFileHeader myBmpFileHeader, bmpInfoHeader myBmpInfoHeader,
                FILE *newBmpImage,FILE *bmpImage, int width, int height, int padding, pixel image_modified[1000][1000],char*);
void readImage(char ipath[100]);
void greyscale(pixel temp[1000][1000], pixel outemp[1000][1000],int height, int width);
void edgeDetection(pixel image[1000][1000],pixel image_modified[1000][1000],pixel image_temp[1000][1000],int height,int width);
void smoothing(pixel temp[1000][1000], pixel outemp[1000][1000],int height,int width);
void brightening(pixel image[1000][1000],pixel image_modified[1000][1000],int height,int width);
void image_blur(pixel temp[1000][1000], pixel outemp[1000][1000],int height,int width);
void noise(pixel temp[1000][1000], pixel outemp[1000][1000],int height, int width);
void halftoning(pixel image[1000][1000],pixel image_modified[1000][1000],pixel image_temp[1000][1000],int height,int width);
void sharpen(pixel temp[1000][1000], pixel outemp[1000][1000],int height, int width);
void viewOptions(bmpFileHeader myBmpFileHeader, bmpInfoHeader myBmpInfoHeader,
                FILE *newBmpImage,FILE *bmpImage,int padding,pixel image[1000][1000],pixel image_modified[1000][1000],pixel image_temp[1000][1000],int height,int width);
void showMainMenu(bmpFileHeader myBmpFileHeader, bmpInfoHeader myBmpInfoHeader,
                FILE *newBmpImage,FILE *bmpImage,int padding,pixel image[1000][1000],pixel image_modified[1000][1000],pixel image_temp[1000][1000],int height,int width);
void writeImage(bmpFileHeader myBmpFileHeader, bmpInfoHeader myBmpInfoHeader,
                FILE *newBmpImage,FILE *bmpImage, int width, int height, int padding, pixel image_modified[1000][1000]
);
void saveImage(bmpFileHeader myBmpFileHeader, bmpInfoHeader myBmpInfoHeader,
                FILE *newBmpImage,FILE *bmpImage, int width, int height, int padding, pixel image_modified[1000][1000], char name[50]
);

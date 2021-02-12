#include<bits/stdc++.h>
using namespace std;

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
 pixel image[1000][1000];
    pixel image_modified[1000][1000];
int randNum(void);
int main(void){

  bmpFileHeader myBmpFileHeader;
  bmpInfoHeader myBmpInfoHeader;
    cout<<"Write the file name here : ";
    char path[1000];
    scanf("%s",path);

  FILE *bmpImage = fopen(path, "rb");
  FILE *newBmpImage = fopen("image1.bmp", "wb");

  if (bmpImage == NULL)
  {
    printf("Error occured when opening file\n");
  }



    fread(&myBmpFileHeader, sizeof(myBmpFileHeader), 1, bmpImage);
    fread(&myBmpInfoHeader, sizeof(myBmpInfoHeader), 1, bmpImage);

    if (myBmpFileHeader.bitmapSignatureBytes[0]==0x42 && myBmpFileHeader.bitmapSignatureBytes[1]==0x4D && myBmpInfoHeader.dib_header_size == 40 && myBmpInfoHeader.bits_per_pixel == 24 && myBmpInfoHeader.compression ==0 )
    {
      printf(" File is BMP\n");
    }else{
      printf("Error\n");
    }
    int width = myBmpInfoHeader.width;
    //printf("Width %i\n", width );
    int height = abs(myBmpInfoHeader.height);
    int padding = (4 - (width * sizeof(pixel)) % 4) % 4;

    for (int i = 0; i < height; ++i)
    {
      fread(image[i], sizeof(pixel), width, bmpImage);
      fseek(bmpImage, padding, SEEK_CUR);

    }
    cout<<"USER MENU\n\n"<<endl;
    cout<<"1. Edge Detect"<<endl;
    cout<<"2. Greyscale"<<endl;
    cout<<"3. Brighten"<<endl;
  int choose;
  cin>>choose;
  if(choose==1)
  {
        int gx[3][3];
    int gy[3][3];

    gx[0][0] = -1;
    gx[0][1] = 0;
    gx[0][2] = 1;

    gx[1][0] = -2;
    gx[1][1] = 0;
    gx[1][2] = 2;

    gx[2][0] = -1;
    gx[2][1] = 0;
    gx[2][2] = 1;


    gy[0][0] = -1;
    gy[0][1] = -2;
    gy[0][2] = -1;

    gy[1][0] = 0;
    gy[1][1] = 0;
    gy[1][2] = 0;

    gy[2][0] = 1;
    gy[2][1] = 2;
    gy[2][2] = 1;

    int gxValBlue;
    int gyValBlue;

    int gxValGreen;
    int gyValGreen;

    int gxValRed;
    int gyValRed;

    int squaredBlue;
    int squaredGreen;
    int squaredRed;





       for (int lin = 0; lin < height; ++lin)
    {

      for (int col = 0; col < width; ++col)
      {


        if (lin !=0 && lin != height && col != 0 && col != width)// tem todos os vizinhos
        {




          gxValBlue = (image[lin-1][col-1].blue * gx[0][0] + image[lin-1][col].blue * gx[0][1] + image[lin-1][col+1].blue * gx[0][2] + image[lin][col-1].blue * gx[1][0] + image[lin][col].blue * gx[1][1] + image[lin][col+1].blue * gx[1][2] + image[lin-1][col-1].blue * gx[2][0] + image[lin+1][col].blue * gx[2][1] + image[lin+1][col+1].blue * gx[2][2]);
          gyValBlue = (image[lin-1][col-1].blue * gy[0][0] + image[lin-1][col].blue * gy[0][1] + image[lin-1][col+1].blue * gy[0][2] + image[lin][col-1].blue * gy[1][0] + image[lin][col].blue * gy[1][1] + image[lin][col+1].blue * gy[1][2] + image[lin-1][col-1].blue * gy[2][0] + image[lin+1][col].blue * gy[2][1] + image[lin+1][col+1].blue * gy[2][2]);

          squaredBlue = (int)sqrt(gxValBlue*gxValBlue + gyValBlue*gyValBlue);

          gxValGreen = (image[lin-1][col-1].green * gx[0][0] + image[lin-1][col].green * gx[0][1] + image[lin-1][col+1].green * gx[0][2] + image[lin][col-1].green * gx[1][0] + image[lin][col].green * gx[1][1] + image[lin][col+1].green * gx[1][2] + image[lin-1][col-1].green * gx[2][0] + image[lin+1][col].green * gx[2][1] + image[lin+1][col+1].green * gx[2][2]);
          gyValGreen = (image[lin-1][col-1].green * gy[0][0] + image[lin-1][col].green * gy[0][1] + image[lin-1][col+1].green * gy[0][2] + image[lin][col-1].green * gy[1][0] + image[lin][col].green * gy[1][1] + image[lin][col+1].green * gy[1][2] + image[lin-1][col-1].green * gy[2][0] + image[lin+1][col].green * gy[2][1] + image[lin+1][col+1].green * gy[2][2]);

          squaredGreen = (int)sqrt(gxValGreen*gxValGreen + gyValGreen*gyValGreen);

          gxValRed = (image[lin-1][col-1].red * gx[0][0] + image[lin-1][col].red * gx[0][1] + image[lin-1][col+1].red * gx[0][2] + image[lin][col-1].red * gx[1][0] + image[lin][col].red * gx[1][1] + image[lin][col+1].red * gx[1][2] + image[lin-1][col-1].red * gx[2][0] + image[lin+1][col].red * gx[2][1] + image[lin+1][col+1].red * gx[2][2]);
          gyValRed = (image[lin-1][col-1].red * gy[0][0] + image[lin-1][col].red * gy[0][1] + image[lin-1][col+1].red * gy[0][2] + image[lin][col-1].red * gy[1][0] + image[lin][col].red * gy[1][1] + image[lin][col+1].red * gy[1][2] + image[lin-1][col-1].red * gy[2][0] + image[lin+1][col].red * gy[2][1] + image[lin+1][col+1].red * gy[2][2]);

          squaredRed = (int)sqrt(gxValRed*gxValRed + gyValRed*gyValRed);



          if (squaredBlue > 255)
          {
            image_modified[lin][col].blue = 255;
          }else{
            image_modified[lin][col].blue = squaredBlue;
          }



          if (squaredGreen > 255)
          {
            image_modified[lin][col].green = 255;
          }else{
            image_modified[lin][col].green = squaredGreen;
          }


          if (squaredRed > 255)
          {
            image_modified[lin][col].red = 255;
          }else{
            image_modified[lin][col].red = squaredRed;
          }





        }else { // bottom


          image_modified[lin][col].blue = 0;
          image_modified[lin][col].green = 0;
          image_modified[lin][col].red = 0;


        }





    }

      }
  }
  else if( choose==2)
  {

       for (int lin = 0; lin < height; ++lin)
        {

      for (int col = 0; col < width; ++col)
      {

          image_modified[lin][col].blue=(image[lin][col].blue+image[lin][col].red+image[lin][col].green)/3;
          image_modified[lin][col].red=(image[lin][col].blue+image[lin][col].red+image[lin][col].green)/3;
          image_modified[lin][col].green=(image[lin][col].blue+image[lin][col].red+image[lin][col].green)/3;

      }

      }

  }
  else if(choose==3)
  {

  }
fwrite(&myBmpFileHeader, sizeof(myBmpFileHeader),1, newBmpImage);
fwrite(&myBmpInfoHeader, sizeof(myBmpInfoHeader), 1, newBmpImage);


for (int i = 0; i < height; ++i)
{

  for (int k = 0; k < padding; ++k)
  {
    fputc(0x00, newBmpImage);
  }
  fwrite(image_modified[i], sizeof(pixel), width, newBmpImage);
}


fclose(newBmpImage);
fclose(bmpImage);
free(image);
free(image_modified);
return 0;
}



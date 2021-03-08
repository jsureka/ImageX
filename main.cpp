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
void edgeDetection();
int options();
    pixel image[1000][1000];
    pixel image_modified[1000][1000];
    pixel image_temp[1000][1000];
int randNum(void);
bmpFileHeader myBmpFileHeader;
bmpInfoHeader myBmpInfoHeader;

  FILE *bmpImage;
  FILE *newBmpImage;
      int width;
    int height;
    void viewOptions();
void viewInput(char input[100])
{

    int heightOfScreen = GetSystemMetrics(SM_CXSCREEN);
    int widthOfScreen = GetSystemMetrics(SM_CYSCREEN);
    //printf("1");
    char nameOfImage[20];
    snprintf(nameOfImage, 20, "%s",input); // puts string into buffer
   // printf("%s\n", nameOfImage);
    //variable++;
    initwindow(800,700, nameOfImage,300,0);
    readimagefile(nameOfImage,200,200,600,600);
getchar();
getchar();
    closegraph();
}
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void greyscale(pixel temp[1000][1000], pixel outemp[1000][1000]){


       for (int lin = 0; lin < height; ++lin)
        {

      for (int col = 0; col < width; ++col)
      {

          outemp[lin][col].blue=(temp[lin][col].blue+temp[lin][col].red+temp[lin][col].green)/3;
          outemp[lin][col].red=(temp[lin][col].blue+temp[lin][col].red+temp[lin][col].green)/3;
          outemp[lin][col].green=(temp[lin][col].blue+temp[lin][col].red+temp[lin][col].green)/3;

      }

      }


}

void edgeDetection(){

         int gx[3][3];
    int gy[3][3];

    gx[0][0] = 1;
    gx[0][1] = 0;
    gx[0][2] = -1;

    gx[1][0] = 2;
    gx[1][1] = 0;
    gx[1][2] = -2;

    gx[2][0] = -1;
    gx[2][1] = 0;
    gx[2][2] = 1;


    gy[0][0] = 1;
    gy[0][1] = 2;
    gy[0][2] = 1;

    gy[1][0] = 0;
    gy[1][1] = 0;
    gy[1][2] = 0;

    gy[2][0] = -1;
    gy[2][1] = -2;
    gy[2][2] = -1;

    int gxValBlue;
    int gyValBlue;

    int gxValGreen;
    int gyValGreen;

    int gxValRed;
    int gyValRed;

    int squaredBlue;
    int squaredGreen;
    int squaredRed;

    greyscale(image,image_temp);


       for (int lin = 0; lin < height; ++lin)
    {

      for (int col = 0; col < width; ++col)
      {


        if (lin !=0 && lin != height && col != 0 && col != width)// tem todos os vizinhos
        {




          gxValBlue = (image_temp[lin-1][col-1].blue * gx[0][0] + image_temp[lin-1][col].blue * gx[0][1] + image_temp[lin-1][col+1].blue * gx[0][2] + image_temp[lin][col-1].blue * gx[1][0] + image_temp[lin][col].blue * gx[1][1] + image_temp[lin][col+1].blue * gx[1][2] + image_temp[lin-1][col-1].blue * gx[2][0] + image_temp[lin+1][col].blue * gx[2][1] + image_temp[lin+1][col+1].blue * gx[2][2]);
          gyValBlue = (image_temp[lin-1][col-1].blue * gy[0][0] + image_temp[lin-1][col].blue * gy[0][1] + image_temp[lin-1][col+1].blue * gy[0][2] + image_temp[lin][col-1].blue * gy[1][0] + image_temp[lin][col].blue * gy[1][1] + image_temp[lin][col+1].blue * gy[1][2] + image_temp[lin-1][col-1].blue * gy[2][0] + image_temp[lin+1][col].blue * gy[2][1] + image_temp[lin+1][col+1].blue * gy[2][2]);

          squaredBlue = (int)sqrt(gxValBlue*gxValBlue + gyValBlue*gyValBlue);

          gxValGreen = (image_temp[lin-1][col-1].green * gx[0][0] + image_temp[lin-1][col].green * gx[0][1] + image_temp[lin-1][col+1].green * gx[0][2] + image_temp[lin][col-1].green * gx[1][0] + image_temp[lin][col].green * gx[1][1] + image_temp[lin][col+1].green * gx[1][2] + image_temp[lin-1][col-1].green * gx[2][0] + image_temp[lin+1][col].green * gx[2][1] + image_temp[lin+1][col+1].green * gx[2][2]);
          gyValGreen = (image_temp[lin-1][col-1].green * gy[0][0] + image_temp[lin-1][col].green * gy[0][1] + image_temp[lin-1][col+1].green * gy[0][2] + image_temp[lin][col-1].green * gy[1][0] + image_temp[lin][col].green * gy[1][1] + image_temp[lin][col+1].green * gy[1][2] + image_temp[lin-1][col-1].green * gy[2][0] + image_temp[lin+1][col].green * gy[2][1] + image_temp[lin+1][col+1].green * gy[2][2]);

          squaredGreen = (int)sqrt(gxValGreen*gxValGreen + gyValGreen*gyValGreen);

          gxValRed = (image_temp[lin-1][col-1].red * gx[0][0] + image_temp[lin-1][col].red * gx[0][1] + image_temp[lin-1][col+1].red * gx[0][2] + image_temp[lin][col-1].red * gx[1][0] + image_temp[lin][col].red * gx[1][1] + image_temp[lin][col+1].red * gx[1][2] + image_temp[lin-1][col-1].red * gx[2][0] + image_temp[lin+1][col].red * gx[2][1] + image_temp[lin+1][col+1].red * gx[2][2]);
          gyValRed = (image_temp[lin-1][col-1].red * gy[0][0] + image_temp[lin-1][col].red * gy[0][1] + image_temp[lin-1][col+1].red * gy[0][2] + image_temp[lin][col-1].red * gy[1][0] + image_temp[lin][col].red * gy[1][1] + image_temp[lin][col+1].red * gy[1][2] + image_temp[lin-1][col-1].red * gy[2][0] + image_temp[lin+1][col].red * gy[2][1] + image_temp[lin+1][col+1].red * gy[2][2]);

          squaredRed = (int)sqrt(gxValRed*gxValRed + gyValRed*gyValRed);



          if (squaredBlue > 100)
          {
            image_modified[lin][col].blue = 255;
          }else{
            image_modified[lin][col].blue = 0;
          }



          if (squaredGreen > 100)
          {
            image_modified[lin][col].green = 255;
          }else{
            image_modified[lin][col].green = 0;
          }


          if (squaredRed > 100)
          {
            image_modified[lin][col].red = 255;
          }else{
            image_modified[lin][col].red = 0;
          }





        }else { // bottom


          image_modified[lin][col].blue = 0;
          image_modified[lin][col].green = 0;
          image_modified[lin][col].red = 0;


        }





    }

      }

}

void smoothing(pixel temp[1000][1000], pixel outemp[1000][1000]){
        int matrix[9];
       for (int lin = 0; lin < height; ++lin)
        {

        for (int col = 0; col < width; ++col)
            {
            matrix[0] = temp[lin-1][col-1].blue;
            matrix[1] = temp[lin-1][col].blue;
            matrix[2] = temp[lin-1][col+1].blue;
            matrix[3] = temp[lin][col-1].blue;
            matrix[4] = temp[lin][col].blue;
            matrix[5] = temp[lin][col+1].blue;
            matrix[6] = temp[lin+1][col-1].blue;
            matrix[7] = temp[lin+1][col].blue;
            matrix[8] = temp[lin+1][col+1].blue;

            //sort matrix image
            insertionSort(matrix,9);
            //put the median to the new image
            outemp[lin][col].blue=matrix[4];
            }
        }
         for (int lin = 0; lin < height; ++lin)
        {

        for (int col = 0; col < width; ++col)
            {
            matrix[0] = temp[lin-1][col-1].green;
            matrix[1] = temp[lin-1][col].green;
            matrix[2] = temp[lin-1][col+1].green;
            matrix[3] = temp[lin][col-1].green;
            matrix[4] = temp[lin][col].green;
            matrix[5] = temp[lin][col+1].green;
            matrix[6] = temp[lin+1][col-1].green;
            matrix[7] = temp[lin+1][col].green;
            matrix[8] = temp[lin+1][col+1].green;

            //sort matrix image
            sort(matrix,matrix+9);
            //put the median to the new image
            outemp[lin][col].green=matrix[4];
            }
        }
           for (int lin = 0; lin < height; ++lin)
        {

        for (int col = 0; col < width; ++col)
            {
            matrix[0] = temp[lin-1][col-1].red;
            matrix[1] = temp[lin-1][col].red;
            matrix[2] = temp[lin-1][col+1].red;
            matrix[3] = temp[lin][col-1].red;
            matrix[4] = temp[lin][col].red;
            matrix[5] = temp[lin][col+1].red;
            matrix[6] = temp[lin+1][col-1].red;
            matrix[7] = temp[lin+1][col].red;
            matrix[8] = temp[lin+1][col+1].red;

            //sort matrix image
            insertionSort(matrix,9);
            //put the median to the new image
            outemp[lin][col].red=matrix[4];
            }
        }


}

void brightening(){
    cout<<"Input the brightness level between 1-20 : ";
    uint8_t level;
    cin>> level;
    for (int lin = 0; lin < height; ++lin)
        {

        for (int col = 0; col < width; ++col)
        {
            image_modified[lin][col].blue=image[lin][col].blue+level;
            image_modified[lin][col].green=image[lin][col].green+level;
            image_modified[lin][col].red=image[lin][col].red+level;
            if(image_modified[lin][col].blue > 255)
            image_modified[lin][col].blue = 255;

            if(image_modified[lin][col].green > 255)
            image_modified[lin][col].green = 255;

            if(image_modified[lin][col].red > 255)
            image_modified[lin][col].red = 255;


        }
    }

}

void image_blur(pixel temp[1000][1000], pixel outemp[1000][1000]){
    int matrix[9];
     for (int lin = 0; lin < height; ++lin)
        {

        for (int col = 0; col < width; ++col)
            {
                if( lin<1||col<1||lin+1==width||col+1==col)
                    continue;
                int sum = 0;
                 matrix[0] = temp[lin-1][col-1].green;
                matrix[1] = temp[lin-1][col].green;
                matrix[2] = temp[lin-1][col+1].green;
                matrix[3] = temp[lin][col-1].green;
                matrix[4] = temp[lin][col].green;
                matrix[5] = temp[lin][col+1].green;
                matrix[6] = temp[lin+1][col-1].green;
                matrix[7] = temp[lin+1][col].green;
                matrix[8] = temp[lin+1][col+1].green;
                sum = accumulate(matrix,matrix+9,sum);
                int avg=sum/9;
                outemp[lin][col].green=avg;
            }

        }
        for (int lin = 0; lin < height; ++lin)
        {

        for (int col = 0; col < width; ++col)
            {
                if( lin<1||col<1||lin+1==width||col+1==col)
                    continue;
                int sum = 0;
                 matrix[0] = temp[lin-1][col-1].red;
                matrix[1] = temp[lin-1][col].red;
                matrix[2] = temp[lin-1][col+1].red;
                matrix[3] = temp[lin][col-1].red;
                matrix[4] = temp[lin][col].red;
                matrix[5] = temp[lin][col+1].red;
                matrix[6] = temp[lin+1][col-1].red;
                matrix[7] = temp[lin+1][col].red;
                matrix[8] = temp[lin+1][col+1].red;
                sum = accumulate(matrix,matrix+9,sum);
                int avg=sum/9;
                outemp[lin][col].red=avg;
            }

        }
        for (int lin = 0; lin < height; ++lin)
        {

        for (int col = 0; col < width; ++col)
            {
                if( lin<1||col<1||lin+1==width||col+1==col)
                    continue;
                int sum = 0;
                 matrix[0] = temp[lin-1][col-1].blue;
                matrix[1] = temp[lin-1][col].blue;
                matrix[2] = temp[lin-1][col+1].blue;
                matrix[3] = temp[lin][col-1].blue;
                matrix[4] = temp[lin][col].blue;
                matrix[5] = temp[lin][col+1].blue;
                matrix[6] = temp[lin+1][col-1].blue;
                matrix[7] = temp[lin+1][col].blue;
                matrix[8] = temp[lin+1][col+1].blue;
                sum = accumulate(matrix,matrix+9,sum);
                int avg=sum/9;
                outemp[lin][col].blue=avg;
            }

        }

}
void noise(pixel temp[1000][1000], pixel outemp[1000][1000]){
      for (int lin = 0; lin < height; ++lin)
        {

        for (int col = 0; col < width; ++col)
            {
                outemp[lin][col].blue = rand()%150 + temp[lin][col].blue;
                outemp[lin][col].green = rand()%150 +temp[lin][col].green;
                outemp[lin][col].red = rand()%150 +temp[lin][col].red;
                 if(outemp[lin][col].blue > 255)
                outemp[lin][col].blue = 255;

                if(outemp[lin][col].green > 255)
                outemp[lin][col].green = 255;

                if(outemp[lin][col].red > 255)
                outemp[lin][col].red = 255;

            }

        }

}
float ep[1000][1000] = {0.0}, eg[1000][1000] = {0.0};
void halftoning(pixel temp[1000][1000], pixel outemp[1000][1000]){
    greyscale(image,image_temp);
    int threshold;
    cout<<"Enter Halftoning Threshold ( Standard - 128 ): ";
        cin>>threshold;

    float c[2][3],sum_p,t;
    int i, j, m, n, xx, yy;
    c[0][0] = 0.0;
    c[0][1] = 0.2;
    c[0][2] = 0.0;
    c[1][0] = 0.6;
    c[1][1] = 0.1;
    c[1][2] = 0.1;
        for(m=0; m<height; m++){
            for(n=0; n<width; n++){
                sum_p = 0.0;
                for(i=0; i<2; i++){
                    for(j=0; j<3; j++){
                        xx = m-i+1;
                        yy = n-j+1;
                        if(xx < 0) xx = 0;
                        if(xx >= height) xx = height-1;
                        if(yy < 0) yy = 0;
                        if(yy >= width) yy = width-1;
                        sum_p = sum_p + c[i][j] * eg[xx][yy];
                        } /* ends loop over j */
                        } /* ends loop over i */
                        ep[m][n] = sum_p;
                        t = image_temp[m][n].blue + ep[m][n];
                        if(t > threshold){
                        eg[m][n] = t - threshold*2;
                        image_modified[m][n].blue = image_temp[m][n].blue;
                         image_modified[m][n].red = image_temp[m][n].blue;
                          image_modified[m][n].green = image_temp[m][n].blue;
                        }
                        else{ /* t <= threshold */
                        eg[m][n] = t;
                        image_modified[m][n].blue = 0;
                        image_modified[m][n].red = 0;
                        image_modified[m][n].green = 0;

                        } /* ends else t <= threshold */
                    } /* ends loop over n columns */
                }


}

void sharpen(pixel temp[1000][1000], pixel outemp[1000][1000])
{
    int msk[3][3]={{0,-1,0},
                {-1,5,1},
                {0,-1,0}};
     for (int lin = 0; lin < height; ++lin)
        {

        for (int col = 0; col < width; ++col)
            {
                if( lin<1||col<1||lin+1==width||col+1==col)
                {
                    outemp[lin][col].blue = temp[lin][col].blue;
                    outemp[lin][col].blue = temp[lin][col].green;
                    outemp[lin][col].blue = temp[lin][col].red;
                     continue;

                }

                  for (int YK = -1; YK < 2; YK++) {
                    for (int XK = -1; XK < 2; XK++) {

                    outemp[lin][col].red = temp[lin][col].red + msk[YK+1][XK+1] * temp[lin][col].red;
                    outemp[lin][col].green = temp[lin][col].green + msk[YK+1][XK+1] * temp[lin][col].green;
                    outemp[lin][col].blue = temp[lin][col].blue + msk[YK+1][XK+1] * temp[lin][col].blue;

                    }
                }
            }
        }

}
 char out[100]="image1.bmp";
 int padding = (4 - (width * sizeof(pixel)) % 4) % 4;

int options()
{
     newBmpImage = fopen("image1.bmp", "wb");
    int choose;
  cin>>choose;
      if(choose==1)
  {
    edgeDetection();

  }
  else if( choose==2)
  {
        greyscale(image,image_modified);
  }
  else if(choose==3)
  {
    smoothing(image,image_temp);
    cout<<"Enter the smoothing threshold ( 2 - 10 ) : ";
      int th;
      cin>>th;
     for(int i=0;i<th;i++)
      smoothing(image_temp,image_temp);
     smoothing(image_temp,image_modified);

  }
  else if( choose == 4)
  {
      brightening();
  }
  else if (choose == 5)
  {
      image_blur(image,image_temp);
      cout<<"Enter the blur threshold ( 2 - 10 ) : ";
      int th;
      cin>>th;
      for(int i=0;i<th;i++)
      image_blur(image_temp,image_temp);
      image_blur(image_temp,image_modified);

  }
  else if (choose == 6)
  {
      noise(image,image_modified);
      //noise(image_temp,image_modified);
  }
  else if (choose == 7)
  {
      halftoning(image,image_modified);
  }
  else if(choose==8)
  {
       sharpen(image,image_modified);
     cout<<"Enter the sharpen threshold ( 2 - 10 ) : ";
      int th;
      cin>>th;
      for(int i=0;i<th;i++)
      //sharpen(image_temp,image_temp);
      sharpen(image_modified,image_modified);
  }
  else if(choose == 9)
  {
      cout<<"Thank You For Using ImageX"<<endl;
    return 0;
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
    free(image_modified);
     viewInput(out);
     options();
}
int main(void){
    char ipath[100];

    printf("Enter Path : ");
    scanf("%s",ipath);
    bmpImage = fopen(ipath, "rb");

    viewInput(ipath);
  if (bmpImage == NULL)
  {
    printf("Error occured when opening file\n");
  }



    fread(&myBmpFileHeader, sizeof(myBmpFileHeader), 1, bmpImage);
    fread(&myBmpInfoHeader, sizeof(myBmpInfoHeader), 1, bmpImage);

    if (myBmpFileHeader.bitmapSignatureBytes[0]==0x42 && myBmpFileHeader.bitmapSignatureBytes[1]==0x4D && myBmpInfoHeader.dib_header_size == 40 && myBmpInfoHeader.bits_per_pixel == 24 && myBmpInfoHeader.compression ==0 )
    {
      printf("\nFile Format is BMP\n");
    }else{
      printf("Error\n");
    }
       width = myBmpInfoHeader.width;
    height = abs(myBmpInfoHeader.height);


    for (int i = 0; i < height; ++i)
    {
      fread(image[i], sizeof(pixel), width, bmpImage);
      fseek(bmpImage, padding, SEEK_CUR);

    }
    cout<<"USER MENU\n\n"<<endl;
    cout<<"1. Edge Detect"<<endl;
    cout<<"2. Greyscale"<<endl;
    cout<<"3. Smoothing"<<endl;
    cout<<"4. Brightening"<<endl;
    cout<<"5. Image Blur"<<endl;
    cout<<"6. Noise Generator"<<endl;
    cout<<"7. Image Halftoning"<<endl;
    cout<<"8. Sharpening" <<endl;

  options();
 free(image);
return 0;
}


#include"header.h";
pixel image[1000][1000];
pixel image_modified[1000][1000];
pixel image_temp[1000][1000];

bmpFileHeader myBmpFileHeader;
bmpInfoHeader myBmpInfoHeader;

FILE *bmpImage;
FILE *newBmpImage;
int width;
int height;

char out[100]="image1.bmp";
int padding = (4 - (width * sizeof(pixel)) % 4) % 4;

//int options()
//{
//    viewOptions(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage, padding, image,image_modified,image_temp,height,width);
//    options();
//}
//
//void readImage(char ipath[100]){
//
//    bmpImage = fopen(ipath, "rb");
//    viewInput(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage,  width,height,padding,image_modified,ipath);
//    if (bmpImage == NULL)
//    {
//        printf("Error occured when opening file\n");
//    }
//    fread(&myBmpFileHeader, sizeof(myBmpFileHeader), 1, bmpImage);
//    fread(&myBmpInfoHeader, sizeof(myBmpInfoHeader), 1, bmpImage);
//
//    if (myBmpFileHeader.bitmapSignatureBytes[0]==0x42 && myBmpFileHeader.bitmapSignatureBytes[1]==0x4D && myBmpInfoHeader.dib_header_size == 40 && myBmpInfoHeader.bits_per_pixel == 24 && myBmpInfoHeader.compression ==0 )
//    {
//        printf("\nFile Format is BMP\n");
//    }
//    else
//    {
//        printf("Error\n");
//
//    }
//    width = myBmpInfoHeader.width;
//    height = abs(myBmpInfoHeader.height);
//
//
//    for (int i = 0; i < height; ++i)
//    {
//        fread(image[i], sizeof(pixel), width, bmpImage);
//        fseek(bmpImage, padding, SEEK_CUR);
//
//    }
//    options();
//
//}
int main(void)
{
//    char ipath[100];
//    printf("Enter Path : ");
//    scanf("%s",ipath);

//    options();
    viewOptions(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage, padding, image,image_modified,image_temp,height,width);
    free(image);
    return 0;
}


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

int options()
{
      cout<<"USER MENU\n\n"<<endl;
    cout<<"1. Edge Detect"<<endl;
    cout<<"2. Greyscale"<<endl;
    cout<<"3. Smoothing"<<endl;
    cout<<"4. Brightening"<<endl;
    cout<<"5. Image Blur"<<endl;
    cout<<"6. Noise Generator"<<endl;
    cout<<"7. Image Halftoning"<<endl;
    cout<<"8. Sharpening" <<endl;

    newBmpImage = fopen("image1.bmp", "wb");
    int choose;
    cin>>choose;
    if(choose==1)
    {
        edgeDetection(image,image_modified,image_temp,height,width);

    }
    else if( choose==2)
    {
        greyscale(image,image_modified,height,width);
    }
    else if(choose==3)
    {
        smoothing(image,image_temp,height,width);
        cout<<"Enter the smoothing threshold ( 2 - 10 ) : ";
        int th;
        cin>>th;
        for(int i=0; i<th; i++)
            smoothing(image_temp,image_temp,height,width);
        smoothing(image_temp,image_modified,height,width);

    }
    else if( choose == 4)
    {
        brightening(image_temp,image_modified,height,width);
    }
    else if (choose == 5)
    {
        image_blur(image,image_temp,height,width);
        cout<<"Enter the blur threshold ( 2 - 10 ) : ";
        int th;
        cin>>th;
        for(int i=0; i<th; i++)
            image_blur(image_temp,image_temp,height,width);
        image_blur(image_temp,image_modified,height,width);

    }
    else if (choose == 6)
    {
        noise(image,image_modified,height,width);
        //noise(image_temp,image_modified);
    }
    else if (choose == 7)
    {
        halftoning(image,image_modified,image_temp,height,width);
    }
    else if(choose==8)
    {
        sharpen(image,image_temp,height,width);
        cout<<"Enter the sharpen threshold ( 2 - 10 ) : ";
        int th;
        cin>>th;
        for(int i=0; i<th; i++)
            //sharpen(image_temp,image_temp);
            sharpen(image_temp,image_modified,height,width);
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
int main(void)
{
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
    }
    else
    {
        printf("Error\n");
    }
    width = myBmpInfoHeader.width;
    height = abs(myBmpInfoHeader.height);


    for (int i = 0; i < height; ++i)
    {
        fread(image[i], sizeof(pixel), width, bmpImage);
        fseek(bmpImage, padding, SEEK_CUR);

    }
    options();
    free(image);
    return 0;
}


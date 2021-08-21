#include"header.h"

void saveImage(bmpFileHeader myBmpFileHeader, bmpInfoHeader myBmpInfoHeader,
                FILE *newBmpImage,FILE *bmpImage, int width, int height, int padding, pixel image_modified[1000][1000], char name[50]
){
    FILE *saveBmpImage;
    saveBmpImage = fopen(name,"wb");
    fwrite(&myBmpFileHeader, sizeof(myBmpFileHeader),1, saveBmpImage);
    fwrite(&myBmpInfoHeader, sizeof(myBmpInfoHeader), 1, saveBmpImage);

    for (int i = 0; i < height; ++i)
    {

        for (int k = 0; k < padding; ++k)
        {
            fputc(0x00, saveBmpImage);
        }
        fwrite(image_modified[i], sizeof(pixel), width, saveBmpImage);
    }
    fclose(saveBmpImage);

}


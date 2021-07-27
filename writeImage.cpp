#include"header.h"

void writeImage(bmpFileHeader myBmpFileHeader, bmpInfoHeader myBmpInfoHeader,
                FILE *newBmpImage,FILE *bmpImage, int width, int height, int padding, pixel image_modified[1000][1000]
){
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
    //fclose(bmpImage);
    free(image_modified);
}

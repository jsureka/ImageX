#include"header.h";

void brightening(pixel image[1000][1000],pixel image_modified[1000][1000],int height,int width)
{
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


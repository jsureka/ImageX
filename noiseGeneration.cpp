#include"header.h";

void noise(pixel temp[1000][1000], pixel outemp[1000][1000],int height, int width)
{
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

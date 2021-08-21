#include"header.h";

void brightening(pixel image[1000][1000],pixel image_modified[1000][1000],int height,int width)
{
    cout<<"Input the brightness level between 1-20 : ";
    int level;
    cin>> level;
    for (int lin = 0; lin < height; ++lin)
    {


        for (int col = 0; col < width; ++col)
        {

                    int b = image[lin][col].blue;
                    b =b+min(level,(255-b));

                   int r =  image[lin][col].red;
                   r = r+min(level,(255-r));

                  int g = image[lin][col].green;
                  g = g+min(level,(255-g));

                  image_modified[lin][col].blue=max(b,0);
                  image_modified[lin][col].red=max(r,0);
                  image_modified[lin][col].green=max(g,0);
        }

    }

}


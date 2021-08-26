#include"header.h";


void sharpen(pixel temp[1000][1000], pixel outemp[1000][1000],int height, int width)
{
    int msk[3][3]= {{0,-1,0},
        {-1,5,-1},
        {0,-1,0}
    };
    for (int lin = 0; lin < height; ++lin)
    {

        for (int col = 0; col < width; ++col)
        {
            if( lin<1||col<1||lin+1==width||col+1==height)
            {
                outemp[lin][col].blue = temp[lin][col].blue;
                outemp[lin][col].green = temp[lin][col].green;
                outemp[lin][col].red = temp[lin][col].red;
                continue;

            }

            for (int YK = -1; YK < 2; YK++)
            {
                for (int XK = -1; XK < 2; XK++)
                {

                    outemp[lin][col].red = temp[lin][col].red + msk[YK+1][XK+1] * temp[lin][col].red;
                    outemp[lin][col].green = temp[lin][col].green + msk[YK+1][XK+1] * temp[lin][col].green;
                    outemp[lin][col].blue = temp[lin][col].blue + msk[YK+1][XK+1] * temp[lin][col].blue;

                }
            }
        }
    }

}

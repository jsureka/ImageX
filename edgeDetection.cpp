#include"header.h";
void edgeDetection(pixel image[1000][1000],pixel image_modified[1000][1000],pixel image_temp[1000][1000],int height,int width)
{

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

    greyscale(image,image_temp,height,width);


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
                }
                else
                {
                    image_modified[lin][col].blue = 0;
                }



                if (squaredGreen > 100)
                {
                    image_modified[lin][col].green = 255;
                }
                else
                {
                    image_modified[lin][col].green = 0;
                }


                if (squaredRed > 100)
                {
                    image_modified[lin][col].red = 255;
                }
                else
                {
                    image_modified[lin][col].red = 0;
                }

            }
            else    // bottom
            {


                image_modified[lin][col].blue = 0;
                image_modified[lin][col].green = 0;
                image_modified[lin][col].red = 0;


            }

        }

    }

}

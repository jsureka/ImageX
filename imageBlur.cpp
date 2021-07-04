#include"header.h";

void image_blur(pixel temp[1000][1000], pixel outemp[1000][1000],int height,int width)
{
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

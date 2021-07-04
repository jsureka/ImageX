#include"header.h";

void greyscale(pixel temp[1000][1000], pixel outemp[1000][1000],int height, int width){


       for (int lin = 0; lin < height; ++lin)
        {

      for (int col = 0; col < width; ++col)
      {

          outemp[lin][col].blue=(temp[lin][col].blue+temp[lin][col].red+temp[lin][col].green)/3;
          outemp[lin][col].red=(temp[lin][col].blue+temp[lin][col].red+temp[lin][col].green)/3;
          outemp[lin][col].green=(temp[lin][col].blue+temp[lin][col].red+temp[lin][col].green)/3;

      }

      }


}


#include"header.h";

float ep[1000][1000] = {0.0}, eg[1000][1000] = {0.0};
void halftoning(pixel image[1000][1000],pixel image_modified[1000][1000],pixel image_temp[1000][1000],int height,int width)
{
    greyscale(image,image_temp,height,width);
    int threshold;
    cout<<"Enter Halftoning Threshold ( Standard - 128 ): ";
    cin>>threshold;

    float c[2][3],sum_p,t;
    int i, j, m, n, xx, yy;
    c[0][0] = 0.0;
    c[0][1] = 0.2;
    c[0][2] = 0.0;
    c[1][0] = 0.6;
    c[1][1] = 0.1;
    c[1][2] = 0.1;
    for(m=0; m<height; m++)
    {
        for(n=0; n<width; n++)
        {
            sum_p = 0.0;
            for(i=0; i<2; i++)
            {
                for(j=0; j<3; j++)
                {
                    xx = m-i+1;
                    yy = n-j+1;
                    if(xx < 0) xx = 0;
                    if(xx >= height) xx = height-1;
                    if(yy < 0) yy = 0;
                    if(yy >= width) yy = width-1;
                    sum_p = sum_p + c[i][j] * eg[xx][yy];
                } /* ends loop over j */
            } /* ends loop over i */
            ep[m][n] = sum_p;
            t = image_temp[m][n].blue + ep[m][n];
            if(t > threshold)
            {
                eg[m][n] = t - threshold*2;
                image_modified[m][n].blue = image_temp[m][n].blue;
                image_modified[m][n].red = image_temp[m][n].blue;
                image_modified[m][n].green = image_temp[m][n].blue;
            }
            else  /* t <= threshold */
            {
                eg[m][n] = t;
                image_modified[m][n].blue = 0;
                image_modified[m][n].red = 0;
                image_modified[m][n].green = 0;

            } /* ends else t <= threshold */
        } /* ends loop over n columns */
    }


}


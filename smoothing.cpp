#include"header.h";
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}



void smoothing(pixel temp[1000][1000], pixel outemp[1000][1000],int height,int width)
{
    int matrix[9];
    for (int lin = 0; lin < height; ++lin)
    {

        for (int col = 0; col < width; ++col)
        {
            matrix[0] = temp[lin-1][col-1].blue;
            matrix[1] = temp[lin-1][col].blue;
            matrix[2] = temp[lin-1][col+1].blue;
            matrix[3] = temp[lin][col-1].blue;
            matrix[4] = temp[lin][col].blue;
            matrix[5] = temp[lin][col+1].blue;
            matrix[6] = temp[lin+1][col-1].blue;
            matrix[7] = temp[lin+1][col].blue;
            matrix[8] = temp[lin+1][col+1].blue;

            //sort matrix image
            insertionSort(matrix,9);
            //put the median to the new image
            outemp[lin][col].blue=matrix[4];
        }
    }
    for (int lin = 0; lin < height; ++lin)
    {

        for (int col = 0; col < width; ++col)
        {
            matrix[0] = temp[lin-1][col-1].green;
            matrix[1] = temp[lin-1][col].green;
            matrix[2] = temp[lin-1][col+1].green;
            matrix[3] = temp[lin][col-1].green;
            matrix[4] = temp[lin][col].green;
            matrix[5] = temp[lin][col+1].green;
            matrix[6] = temp[lin+1][col-1].green;
            matrix[7] = temp[lin+1][col].green;
            matrix[8] = temp[lin+1][col+1].green;

            //sort matrix image
            sort(matrix,matrix+9);
            //put the median to the new image
            outemp[lin][col].green=matrix[4];
        }
    }
    for (int lin = 0; lin < height; ++lin)
    {

        for (int col = 0; col < width; ++col)
        {
            matrix[0] = temp[lin-1][col-1].red;
            matrix[1] = temp[lin-1][col].red;
            matrix[2] = temp[lin-1][col+1].red;
            matrix[3] = temp[lin][col-1].red;
            matrix[4] = temp[lin][col].red;
            matrix[5] = temp[lin][col+1].red;
            matrix[6] = temp[lin+1][col-1].red;
            matrix[7] = temp[lin+1][col].red;
            matrix[8] = temp[lin+1][col+1].red;

            //sort matrix image
            insertionSort(matrix,9);
            //put the median to the new image
            outemp[lin][col].red=matrix[4];
        }
    }


}

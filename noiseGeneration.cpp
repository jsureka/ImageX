#include"header.h";
vector<int> vect;
void prec(int height, int width){

    for(int i=0;i<height*width;i++)
    {
         srand(i);
         vect.push_back(rand()%107 + 10);

    }

    random_shuffle(vect.begin(),vect.end());

}
void noise(pixel temp[1000][1000], pixel outemp[1000][1000],int height, int width)
{
    prec(height,width);

    vector<int>::iterator x = vect.begin();
    for (int lin = 0; lin < height; ++lin)
    {

        for (int col = 0; col < width; ++col)
        {

            outemp[lin][col].blue = min(255,*x+temp[lin][col].blue);
            outemp[lin][col].green = min(255,*x+temp[lin][col].green);
            outemp[lin][col].red = min(255,*x +temp[lin][col].red);
            //cout<<*x<<endl;
            x++;
            if(x == vect.end())
                x = vect.begin();
        }


    }



}

#include"header.h";

void viewInput(char input[100])
{

    int heightOfScreen = GetSystemMetrics(SM_CXSCREEN);
    int widthOfScreen = GetSystemMetrics(SM_CYSCREEN);
    //printf("1");
    char nameOfImage[20];
    snprintf(nameOfImage, 20, "%s",input); // puts string into buffer
   // printf("%s\n", nameOfImage);
    //variable++;
    initwindow(800,700, nameOfImage,300,0);
    readimagefile(nameOfImage,200,200,600,600);
getchar();
getchar();
    closegraph();
}

#include"header.h";
bool isFirst=false;
void viewInput(bmpFileHeader myBmpFileHeader, bmpInfoHeader myBmpInfoHeader,
                FILE *newBmpImage,FILE *bmpImage, int width, int height, int padding, pixel image_modified[1000][1000],char input[100])
{

    int heightOfScreen = GetSystemMetrics(SM_CXSCREEN);
    int widthOfScreen = GetSystemMetrics(SM_CYSCREEN);
    //printf("1");
    char nameOfImage[20];
    snprintf(nameOfImage, 20, "%s",input); // puts string into buffer
   // printf("%s\n", nameOfImage);
    //variable++;
    initwindow(800,700, nameOfImage,0,0);
    readimagefile(nameOfImage,200,200,600,600);
    if(isFirst == false)
   {
       isFirst = true;
       delay(2000);
        closegraph();
   }
    else
    {
        settextstyle(BOLD_FONT,HORIZ_DIR,5);

    setcolor(10);
    settextstyle(BOLD_FONT,HORIZ_DIR,3);
    rectangle(200,620,400,680);
    outtextxy(230,640,"SAVE IMAGE");
    setcolor(12);
    rectangle(410,620,600,680);
    outtextxy(450,640,"CANCEL");
    int count=0;
    POINT position;
    bool flag=false;
    std::cout<< "options"<<std::endl;
    while(1)
    {
        //if(!flag) cout<< "in"<<endl;
        flag=true;
        if(GetKeyState(VK_LBUTTON)&0x8000)
        {
            GetCursorPos(&position);
           // printf("\n now point is %d %d",position.x,position.y);
            count++;
        }
        if(count==2) break;
    }
    int x,y;
    x = position.x;
    y = position.y;
    if(x>=200 && x<=400 && y>=620 && y<=680) //save
    {
         closegraph();
        delay(500);
                char name[50];
                cout<<"\nWrite the File name here : ";
                scanf("%s",name);
                saveImage(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage,  width,height,padding,image_modified,name);
                int height=300,width=700;
                initwindow(width,height,"Saved Image!",200,200);
                settextstyle(8,HORIZ_DIR,3);
                outtextxy(100,100,"Image Saved Successfully!");
                delay(2000);
                closegraph();
    }

    if(x>=410 && x<=600 && y>=620 && y<=680) //cancel
    {
        closegraph();
    }
    }
}

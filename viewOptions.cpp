#include"header.h";
bool ifRead = false;
 bool ifOut = false;

void viewOptions(bmpFileHeader myBmpFileHeader, bmpInfoHeader myBmpInfoHeader,
                FILE *newBmpImage,FILE *bmpImage,int padding,pixel image[1000][1000],pixel image_modified[1000][1000],pixel image_temp[1000][1000],int height,int width)
{
    int heightOfScreen = GetSystemMetrics(SM_CXSCREEN);
    int widthOfScreen = GetSystemMetrics(SM_CYSCREEN);
    int gd = DETECT;
    int gm;
    initwindow(heightOfScreen,widthOfScreen,"Options",-3,-3);
    settextstyle(BOLD_FONT,HORIZ_DIR,5);
    // SetBkColor(GREEN);

    setcolor(14);
    //rectangle(500,100,900,200);
    outtextxy(250,130,"Welcome to Image Processing System!");
    setcolor(3);
    settextstyle(BOLD_FONT,HORIZ_DIR,3);

    rectangle(80,400,300,450);
    outtextxy(150,415,"TOOLS");

    rectangle(400,400,600,450);
    outtextxy(430,420,"INPUT IMAGE");

    rectangle(700,400,900,450);
    outtextxy(720,415,"OUTPUT IMAGE");

    rectangle(1000,400,1200,450);
    outtextxy(1050,415,"ABOUT US");

    rectangle(1000,550,1200,600);
    setcolor(RED);
    outtextxy(1080,570,"EXIT");
    int count=0;
    //getch();
    delay(500);
    POINT position;
    bool flag=false;
    std::cout<< "options"<<std::endl;
    while(1)
    {
        if(!flag) cout<< "in"<<endl;
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
    if(x>=100 && x<=300 && y>=400 && y<=470) //tools
    {

        if(ifRead == false)
        {
            int height=300,width=700;
            initwindow(width,height,"Input Image Missing!",200,200);
            settextstyle(8,HORIZ_DIR,3);
            outtextxy(100,100,"PlEASE ENTER AN INPUT IMAGE...");
            delay(2000);
            closegraph();
    viewOptions(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage, padding, image,image_modified,image_temp,height,width);
        }
        closegraph();
        delay(500);
        ifOut = true;
        showMainMenu(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage, padding, image,image_modified,image_temp,height,width);

    }

    if(x>=400 && x<=600 && y>=400 && y<=470) //input image
    {
        closegraph();
        delay(500);
        ifRead = true;
        char ipath[100];
        cout<<"Enter the path of the image here : ";
        scanf("%s",ipath);
        readImage(ipath);
    }

    if(x>=700 && x<=900 && y>=400 && y<=470) //output image
    {
        if(ifOut == false)
        {
            int height=300,width=700;
            initwindow(width,height,"Output Image Missing!",200,200);
            settextstyle(8,HORIZ_DIR,3);
            outtextxy(100,100,"PlEASE EDIT AN IMAGE FIRST!");
            delay(2000);
            closegraph();
        }
        else
        {
            char s[100] = "image1.bmp";
            viewInput(s);
        }
        closegraph();
        viewOptions(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage, padding, image,image_modified,image_temp,height,width);


    }

    if(x>=1000 && x<=1200 && y>=400 && y<=470)//about us
    {
         closegraph();
        delay(500);
    }

    if(x>=1000 && x<=1200 && y>=550 && y<=650)//exit
    {
        //closegraph();
        int height=300,width=700;
        initwindow(width,height,"Exiting",200,200);
        settextstyle(8,HORIZ_DIR,3);
        outtextxy(100,100,"THANK YOU FOR USING THE SYSTEM...");
        delay(2000);
        closegraph();
        fclose(bmpImage);
        free(image);
        free(image_temp);
        free(image_modified);
        exit(1);
    }
    _getch();
    closegraph();
}

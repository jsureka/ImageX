#include"header.h";

void showMainMenu(bmpFileHeader myBmpFileHeader, bmpInfoHeader myBmpInfoHeader,
                FILE *newBmpImage,FILE *bmpImage,int padding,pixel image[1000][1000],pixel image_modified[1000][1000],pixel image_temp[1000][1000],int height,int width){

    int heightOfScreen = GetSystemMetrics(SM_CXSCREEN);
    int widthOfScreen = GetSystemMetrics(SM_CYSCREEN);
    int gd = DETECT;
    int gm;
    initwindow(heightOfScreen,widthOfScreen,"Options",-3,-3);
    settextstyle(BOLD_FONT,HORIZ_DIR,7);

    setcolor(14);
    outtextxy(550,130,"Main Menu");
    setcolor(3);
    settextstyle(BOLD_FONT,HORIZ_DIR,3);

    rectangle(80,400,300,450);
    outtextxy(120,415,"Edge Detect");

    rectangle(400,400,600,450);
    outtextxy(430,415,"Grey Scale");

    rectangle(700,400,900,450);
    outtextxy(760,415,"Smoothen");

    rectangle(1000,400,1200,450);
    outtextxy(1050,415,"Brighten");

     rectangle(80,480,300,530);
    outtextxy(140,500,"Blur");

    rectangle(400,480,600,530);
    outtextxy(440,500,"Noise");

    rectangle(700,480,900,530);
    outtextxy(740,500,"Halftone");

    rectangle(1000,480,1200,530);
    outtextxy(1050,500,"Sharpen");

    rectangle(1000,550,1200,600);
    setcolor(RED);
    outtextxy(1060,570,"Return");


    int count=0;
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
        if(count==5) break;
    }
    int x,y;
    x = position.x;
    y = position.y;
    if(x>=100 && x<=300 && y>=400 && y<=470)//edge detect
    {

        closegraph();
        delay(500);
        newBmpImage = fopen("image1.bmp", "wb");
        edgeDetection(image,image_modified,image_temp,height,width);
        char s[100] = "image1.bmp";
        writeImage(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage,  width,height,padding,image_modified);
                viewInput(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage,  width,height,padding,image_modified,s);
        showMainMenu(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage, padding,image,image_modified,image_temp,height,width);
    }

    if(x>=400 && x<=600 && y>=400 && y<=470)//grey scale
    {
        closegraph();
        delay(500);
        newBmpImage = fopen("image1.bmp", "wb");
        greyscale(image,image_modified,height,width);
         char s[100] = "image1.bmp";
        writeImage(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage,  width,height,padding,image_modified);
                viewInput(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage,  width,height,padding,image_modified,s);
        showMainMenu(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage, padding,image,image_modified,image_temp,height,width);

    }

    if(x>=700 && x<=900 && y>=400 && y<=470)//smooth
    {
        closegraph();
        newBmpImage = fopen("image1.bmp", "wb");
        smoothing(image,image_temp,height,width);
        cout<<"Enter the smoothing threshold ( 2 - 10 ) : ";
        int th;
        cin>>th;
        for(int i=0; i<th; i++)
            smoothing(image_temp,image_temp,height,width);
        smoothing(image_temp,image_modified,height,width);
         char s[100] = "image1.bmp";
        writeImage(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage,  width,height,padding,image_modified);
                viewInput(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage,  width,height,padding,image_modified,s);
        showMainMenu(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage, padding,image,image_modified,image_temp,height,width);

    }

    if(x>=1000 && x<=1200 && y>=400 && y<=470)//brighten
    {
         closegraph();
        delay(500);
        newBmpImage = fopen("image1.bmp", "wb");
        brightening(image,image_modified,height,width);
         char s[100] = "image1.bmp";
        writeImage(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage,  width,height,padding,image_modified);
        viewInput(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage,  width,height,padding,image_modified,s);
        showMainMenu(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage, padding,image,image_modified,image_temp,height,width);

    }
     if(x>=100 && x<=300 && y>=480 && y<=550)//blur
    {
        closegraph();
        delay(500);
        newBmpImage = fopen("image1.bmp", "wb");
         image_blur(image,image_temp,height,width);
        cout<<"Enter the blur threshold ( 2 - 10 ) : ";
        int th;
        cin>>th;
        for(int i=0; i<th; i++)
            image_blur(image_temp,image_temp,height,width);
        image_blur(image_temp,image_modified,height,width);
         char s[100] = "image1.bmp";
        writeImage(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage,  width,height,padding,image_modified);
                viewInput(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage,  width,height,padding,image_modified,s);
        showMainMenu(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage, padding,image,image_modified,image_temp,height,width);

    }

    if(x>=400 && x<=600 && y>=480 && y<=550)//noise
    {
        closegraph();
        delay(500);
                newBmpImage = fopen("image1.bmp", "wb");

        noise(image,image_modified,height,width);
         char s[100] = "image1.bmp";
        writeImage(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage,  width,height,padding,image_modified);
                viewInput(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage,  width,height,padding,image_modified,s);
        showMainMenu(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage, padding,image,image_modified,image_temp,height,width);
    }

    if(x>=700 && x<=900 && y>=480 && y<=550)//halftoning
    {
        closegraph();
        delay(500);
                newBmpImage = fopen("image1.bmp", "wb");
        halftoning(image,image_modified,image_temp,height,width);
         char s[100] = "image1.bmp";
        writeImage(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage,  width,height,padding,image_modified);
                viewInput(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage,  width,height,padding,image_modified,s);
        showMainMenu(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage, padding,image,image_modified,image_temp,height,width);

    }

    if(x>=1000 && x<=1200 && y>=480 && y<=550)//sharpening
    {
         closegraph();
        delay(500);
                newBmpImage = fopen("image1.bmp", "wb");
        sharpen(image,image_temp,height,width);
        cout<<"Enter the sharpen threshold ( 2 - 10 ) : ";
        int th;
        cin>>th;
        for(int i=0; i<th; i++)
            //sharpen(image_temp,image_temp);
            sharpen(image_temp,image_modified,height,width);
             char s[100] = "image1.bmp";
        writeImage(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage,  width,height,padding,image_modified);
                viewInput(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage,  width,height,padding,image_modified,s);
        showMainMenu(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage, padding,image,image_modified,image_temp,height,width);
    }


    if(x>=1000 && x<=1200 && y>=550 && y<=650)//return
    {
        viewOptions(myBmpFileHeader,myBmpInfoHeader, newBmpImage,bmpImage, padding,image,image_modified,image_temp,height,width);
      }
    _getch();
    closegraph();

}


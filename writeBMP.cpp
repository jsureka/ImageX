#include<stdio.h>
#include<string.h>
#include"myheader2.h"

void writeBmp(FILE *fpInput){
//    FILE *fpInput;
    FILE *fpOutput;
    fpOutput=fopen("Output.bmp","wb+");
  //  fpInput=fopen(image,"rb+");
    fwrite(fpInput,54,1,fpOutput);
    for(int i=0;i<bih.height;i++){
        for(int j=0;j<bih.width;j++){
            fwrite(pixelData[i][j],1,1,fpOutput);
        }
    }
    fclose(fpOutput);
    fclose(fpInput);
}

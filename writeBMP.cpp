#include<stdio.h>
#include<string.h>
#include"myheader2.h"

void writeBmp(FILE *fpInput){
//    FILE *fpInput;
    FILE *fpOutput;
    fpOutput=fopen("Output.bmp","wb+");
  //  fpInput=fopen(image,"rb+");
    fread(fpInput,54,1,fpOutput);
    for(int i=0;i<369;i++){
        for(int j=0;j<598;j++){
            fwrite(pixelData[j][i],1,1,fpOutput);
        }
    }
    fclose(fpOutput);
    fclose(fpInput);
}

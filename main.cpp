#include"myheader2.h"
#include <stdio.h>
#include <string.h>
void writeBmp(FILE*);
 FILE *image;
	char ipath[1000];

void readbmp(FILE*);
int main()
{
    while(image==NULL)
	{

		printf("Enter Path : ");
		scanf("%s",ipath);
		image=fopen(ipath,"rb+");
		printf("Error! Enter path again\n\n");
	}


	image=fopen(ipath,"rb+");
    readbmp(image);
    writeBmp(image);

}


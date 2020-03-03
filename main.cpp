
#include <stdio.h>
#include <string.h>

 FILE *image;
	char ipath[1000];

void readbmp(FILE*);
int main()
{
    while(image==NULL)
	{
		printf("Error! Enter path again:");
		scanf("%s",ipath);
		image=fopen(ipath,"rb+");
	}


	image=fopen(ipath,"rb+");
    readbmp(image);
}

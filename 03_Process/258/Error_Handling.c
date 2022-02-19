#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
int main(int argc,char *argv[])
{
	FILE *fp;
	char *buf;

	printf("%d\n", argc);
	printf("%s\n", argv[0]);
	// printf("%s\n", argv[1]);

	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("strerror:%s\n",strerror(errno));
		exit(0);
	}

	perror("perror");
	errno=13;
	printf("strerror:%s\n",strerror(errno));
	fclose(fp);
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"


#define HELP "backlight n\nn - proc"


int main(int argc, char** argv)
{
	if(argc == 2)
	{
		FILE *fd_m, *fd_t; 

		if((fd_m = fopen(max_file, "r")) == NULL)
		{
			printf("Error open %s\n", max_file);
			return 1;
		}

		if((fd_t = fopen(target_file, "w")) == NULL)
		{
			printf("Error open %s\n", target_file);
			return 2;
		}

		char buf[10];
		fscanf(fd_m, "%s", buf);

		float max_b = (float)atoi(buf);
		float new_b = (float)atoi(argv[1]);
		int x = (int)(max_b*new_b/100.0);

		printf("%d --> %s\n", x, target_file);
		fprintf(fd_t, "%d", x);


		if(fd_m != NULL)
			fclose(fd_m);
		if(fd_t != NULL)
			fclose(fd_t);
	}
	else
	{
		printf("%s\n", HELP);
	}

	
	return 0;
}

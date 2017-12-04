#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>


int main(int argc,char **argv){
	FILE *fp = NULL;
	size_t line_len = 1024;
	char *lineptr =(char *)malloc(1024);			
	if(!lineptr){
		perror("malloc()");
		exit(1);
	}
	fp = fopen("test.txt", "r");
	if(!fp){
		perror("fopen()");
		exit(1);
	}
	while(-1 != getline(&lineptr, &line_len, fp)){
		printf("%s", lineptr);
	}
	
	free(lineptr);
	
	return 0;
}



#include <stdio.h>


int main(int argc,char **argv){
	char buf[128];

	while(NULL != fgets(buf,128, stdin)){
		puts(buf);
	}
	return 0;
}

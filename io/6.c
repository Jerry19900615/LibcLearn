#include <stdio.h>

int main(int argc,char **argv){
	char *s;
	char buf[10];
	while(NULL != (s = fgets(buf, 10, stdin))){
		printf("%s\n", buf);
	}
	return 0;
}

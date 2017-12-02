
#include <stdio.h>
#include "work.h"


int main(int argc,char **argv){
	int c;
	while(EOF != (c =fgetc(stdin))){
		putchar(c);
	}
	return 0;
}

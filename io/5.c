#include <stdio.h>


int y_or_n_p(const char *question){
	int c;
	int y = 2; 
	do {
		puts(question);
		while((c = getc(stdin)) == '\n');
		switch(c){
			case 'y':
			case 'Y':
				y = 1;
				break;
			case 'n':
			case 'N':
				y = 0;
				break;
			default:
				fprintf(stderr, "unkonwn select %c", c);
				break;
		}
	}
	while(y == 2);

	return y;
}


int main(int argc,char **argv){
	int s;
	do{	
		s = y_or_n_p("Quit ?(y/N):");
	}
	while(!s);

	return 0;
}

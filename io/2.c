#include <stdio.h>
#include <wchar.h>
#include <locale.h>



void read_file(){
	int c;
	FILE *fp = fopen("test.txt", "r");
	if(!fp){
		perror("fopen()");
		return;
	}
	while(EOF != (c = fgetc(fp))){
		fputc(c, stdout);
	}
	
	fclose(fp);
}


void read_file_w(){
	wint_t c;
	FILE *fp = fopen("test.txt", "r");
	if(!fp){
		perror("fopen()");
		return ;
	}
	while(WEOF != (c = fgetwc(fp))){
		fputwc(c, stdout);
	}
	fclose(fp);
}




int main(int argc,char **argv){
	setlocale(LC_ALL,"");
	fwide(stdout, 1);
	if(fwide(stdout, 0) < 0){
		read_file();
	}
	else {
		read_file_w();
	}
	return 0;
}




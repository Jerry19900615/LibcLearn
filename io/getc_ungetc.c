#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv){
    int c;
    FILE *fp = fopen("test.txt", "r");
    if(!fp){
        perror("fopen()");
        exit(1);
    }
    c = fgetc(fp);
    putc(c,stdout);
    ungetc(c, fp);
    ungetc(c, fp);

    while(EOF != (c = fgetc(fp))){
        putc(c,stdout);
    }
    return 0;
}
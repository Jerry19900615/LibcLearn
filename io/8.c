#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv){
    size_t size = 1024;
    char *buf = (char *)malloc(1024);
    FILE *fp = NULL;
    fp = fopen("test.txt", "r");
    if(!fp){
        perror("fopen()");
        exit(1);
    }
    while(-1 != getdelim(&buf, &size, '\n', fp)){
        puts(buf);
    }
    return 0;
}
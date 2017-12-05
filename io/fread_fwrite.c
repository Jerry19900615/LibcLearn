
#include <stdio.h>
#include <stdlib.h>


int main(int argc,char **argv){
    int arr[4] = {3,4,5,6};
    int i, val;
    FILE *fp = NULL;
    fp = fopen("test.bin", "wb");
    if(!fp){
        perror("fopen()");
        exit(1);
    }

    for(i = 0;i < 4;i ++){
        fwrite(&arr[i], 4, 1, fp);
    }
    fclose(fp);

    fp = fopen("test.bin", "rb");
    if(!fp){
        perror("fopen()");
        exit(1);
    }
    for(i = 0;i < 4;i ++){
        fread(&val, 4, 1, fp);
        printf("%d\n", val);
    }
    fclose(fp);
    return 0;
}
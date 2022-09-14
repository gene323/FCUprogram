//D1051520_input.c
//Date: 2022/03/24
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fp = fopen("D1051520.dat", "wb");
    char id[]= "D1051520";
    fwrite(id, sizeof(id), 1, fp);

    char buf[] = "\n";
    fwrite(buf, sizeof(buf), 1, fp);

    int num;
    scanf("%d", &num);
    fwrite(&num, sizeof(int), 1, fp);


    fclose(fp);
    return 0;
}

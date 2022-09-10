//D1051520_output.c
//Date: 2022/03/25
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long toBin(FILE *fp, int num){
    long long res = 0;
    long long ten = 1;
    while(num){
        res = (num%2)*ten + res;
        num /= 2;
        ten *= 10;
    }
    return res;
}

int main(){
    FILE *fp = fopen("D1051520.dat", "rb+");
    char buf[8+1];
    char newline[] = "\n";

    fread(buf, sizeof(buf), 1, fp);
    fread(newline, sizeof(newline), 1, fp);

    int num;
    fread(&num, sizeof(int), 1, fp);
    long long res = toBin(fp, num);

    printf("%s\n", buf);
    printf("input:%d\n", num);
    printf("BIN : %17lld\n", res);
    printf("OCT : %17o\n", num);
    printf("DEC : %17d\n", num);
    printf("HEX : %17X\n", num);

    fclose(fp);
    fp = fopen("D1051520.dat", "r+");
    fseek(fp, 0, SEEK_END);
    fprintf(fp, "\n");
    fprintf(fp, "%lld\n", res);
    fprintf(fp, "%o\n", num);
    fprintf(fp, "%d\n", num);
    fprintf(fp, "%X\n", num);
    fclose(fp);
    return 0;
}

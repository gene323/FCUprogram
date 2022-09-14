#include <stdio.h>
#include <stdlib.h>

void outputInfo(FILE *file);
void writeInfo(FILE *file);

int main(){

    FILE *file = fopen("a.txt", "r+");
    int order;

    printf("What do you wanna do\n"
    "1:Input friends menu\n2:Add friends' info\n"
    "3:quit\n");

    printf("Your input: ");
    while(scanf("%d", &order)){

        if(order == 1){ outputInfo(file); }
        else if(order == 2){ writeInfo(file); }
        else if(order == 3){ break; }

        printf("What do you wanna do\n"
        "1:Input friends menu\n2:Add friends' info\n"
        "3:quit\n");
        printf("Your input: ");
    }
    
    fclose(file);
    return 0;
}//end main

void outputInfo(FILE *file){

    char name[10];
    char phone[20];
    char birth[20];

    //reset file pointer
    fseek(file, 0, SEEK_SET);
    fscanf(file, "%s %s %s", name, phone, birth);
    while(!feof(file)){
        puts("");
        printf("%10s's phone number: %s\n", name, phone);
        printf("%10s's birthday: %s\n", name, birth);
        fscanf(file, "%s %s %s", name, phone, birth);
    }//end while
    puts("");
}//end outputInfo func 

void writeInfo(FILE *file){
    char name[20];
    char phone[20];
    char birth[20];
    
    //let pointer to the last line
    fseek(file, 0, SEEK_END);

    printf("Input your friend's name: ");
    scanf("%s", name);
    printf("Input your friend's phone number: ");
    scanf("%s", phone);
    printf("Input your friend's birthday: ");
    scanf("%s", birth);

    fprintf(file, "%s %s %s\n", name, phone, birth);
}

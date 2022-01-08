#include<stdio.h>
int main()
{

    float weight;
    float height;
    float bmi;
    float recommend_weight;//recommend the better weight
    char gender;

    printf("請輸入體重(kg)\n");//input weight
    scanf("%f", &weight);
    printf("請輸入身高(cm)\n");//input height
    scanf("%f", &height);
    printf("請輸入性別，男生為M，女生為F\n");
    getchar();
    scanf("%c", &gender);

    while(gender!='m' && gender!='M' && gender!='f' && gender!='F')//avoid the wrong input
    {
        printf("請輸入性別，男生為M，女生為F\n");
        getchar();
        scanf("%c", &gender);
    }

    height/=100;
    bmi = weight/(height*height);//count BMI

    if(gender=='m' || gender=='M')//judge which gender
        recommend_weight = ((height*100)-80)*0.7;
    else
        recommend_weight = ((height*100)-70)*0.6;

    printf("\n您的BMI為\t%.2f  \n",bmi);
    if(18.50<=bmi && bmi<24.00)
    {
        printf("健康體位\n");
        printf("您的標準體重介於\t%.1f ~ %.1f", recommend_weight - recommend_weight*0.1, recommend_weight + recommend_weight*0.1);

    }

    else if(bmi<18.50)
    {
        printf("體重過輕！\n");
        printf("您的標準體重介於\t%.1f ~ %.1f", recommend_weight - recommend_weight*0.1, recommend_weight + recommend_weight*0.1);
    }

    else if(24<=bmi && bmi<27)
    {
        printf("體重過重！\n");
        printf("您的標準體重介於\t%.1f ~ %.1f", recommend_weight - recommend_weight*0.1, recommend_weight + recommend_weight*0.1);
    }

    else if(27<=bmi && bmi<30)
    {
        printf("有點胖！\n");
        printf("您的標準體重介於\t%.1f ~ %.1f", recommend_weight - recommend_weight*0.1, recommend_weight + recommend_weight*0.1);
    }

    else if(30<bmi && bmi<=35)
    {
        printf("好胖！\n");
        printf("您的標準體重介於\t%.1f ~ %.1f", recommend_weight - recommend_weight*0.1, recommend_weight + recommend_weight*0.1);
    }

    else if(35<=bmi)
    {
        printf("超胖！別再吃了\n");
        printf("您的標準體重介於\t%.1f ~ %.1f", recommend_weight - recommend_weight*0.1, recommend_weight + recommend_weight*0.1);
    }
}

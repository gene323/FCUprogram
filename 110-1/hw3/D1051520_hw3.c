#include <stdio.h>
#include <stdlib.h>

void method(char ID[9]) //the method of he/she admit the school
{
    printf("入學管道：");

    if ('0' <= ID[3] && ID[3] <= '4')
        printf("特殊選材/繁星推薦/海外申請");

    else if ('5' <= ID[3] && ID[3] <= '8')
        printf("申請入學/四技二專徵選");

    else if ('9' == ID[3])
        printf("考試入學");

    printf("\n");
}

void go_to_school(char ID[9], int week)//Whether he/she should go to school
{
    if ((int)(ID[7]) % 2 == 1)
    {
        if(week % 2 == 1)
            printf("這週要實體上課\n");

        else
            printf("這週線上上課\n");
    }

    else
    {
        if(week % 2 == 0)
            printf("這週實體上課\n");

        else
            printf("這週線上上課\n");

    }

}

int main()
{
    char ID[9]; //student ID
    char year[3];
    int begin_year; //the year of admit the school
    int end_year;   //the year of graduate from school
    int week;

    printf("輸入您的學號(D1234567)\n");
    scanf("%8s", ID);
    printf("輸入第幾週\n");
    scanf("%d", &week);

    year[0] = ID[1];
    year[1] = ID[2];
    begin_year = atoi(year);
    end_year = atoi(year) + 4;

    if(begin_year<20)
    {
        begin_year += 100;
        end_year += 100;
    }

    //convert to A.D.
    begin_year += 1911;
    end_year += 1911;

    printf("入學年份：%d\n畢業年份：%d\n", begin_year, end_year);
    method(ID);
    go_to_school(ID, week);
}

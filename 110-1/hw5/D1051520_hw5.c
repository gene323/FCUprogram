#include <stdio.h>
#include <stdlib.h>

void ascii(void); //function prototype

void bmi_input_weight(float *);                  //function prototype
void bmi_input_height(float *);                  //function prototype
void bmi_input_gender(char *);                   //function prototype
void bmi_judge_gender(char *);                   //function prototype
void bmi_calculator(float, float, float);        //function prototype
void bmi_recommend_weight(float *, float, char); //function prototype

void divider(void);           //function prototype
void input_studentID(char *); //function prototype

void fortune_teller(char *, int *, int *);     //function prototype
void fortune_teller_input_week(int *);         //function prototype
void fortune_teller_convert_AD(int *, int *);  //function prototype
void fortune_teller_method(char *);            //function prototype
void fortune_teller_go_to_school(char *, int); //function prototype

void studentID_checksystem(char *);      //function prototype
int studentID_checksystem_odd(int);  //function prototype
int studentID_checksystem_even(int); //function prototype

int main()
{
    int order; //to choose which function start

    puts("請輸入0到4");
    puts("1:列印鴨鴨圖案");
    puts("2:計算BMI");
    puts("3:學號算命術");
    puts("4:逢甲學號真實性辨識");
    puts("0:退出程式");

    while (scanf("%d", &order))
    {

        if (order == 1)
        {
            ascii();

        } //end order == 1

        else if (order == 2)
        {
            float weight = 0;
            float height = 0;
            float recommend_weight = 0;
            char gender = '0';

            bmi_input_weight(&weight);
            bmi_input_height(&height);
            height /= 100; //convert to meter
            getchar();
            bmi_input_gender(&gender);
            bmi_judge_gender(&gender);
            bmi_recommend_weight(&recommend_weight, height, gender);
            bmi_calculator(weight, height, recommend_weight);

        } //end order == 2

        else if (order == 3)
        {
            char studentID[9];
            int week;
            int begin_year; //the year of admit the school
            int end_year;   //the year of graduate from school

            input_studentID(studentID);

            fortune_teller_input_week(&week);

            fortune_teller(studentID, &begin_year, &end_year);

            fortune_teller_convert_AD(&begin_year, &end_year);

            printf("入學年份：%d\n畢業年份：%d\n", begin_year, end_year);

            fortune_teller_method(studentID);

            fortune_teller_go_to_school(studentID, week);

        } //end order == 3

        else if (order == 4)
        {
            int order2;
            char studentID[9];
            int ID;
            int odd = 0;
            int even = 0;

            puts("請輸入1到2");
            puts("1:學號辨別");
            puts("2:真實學號單偶數量");
            scanf("%d", &order2);

            if (order2 == 1)
            {
                input_studentID(studentID);
                studentID_checksystem(studentID);
            }
            else if (order2 == 2)
            {
                for (ID = 700000; ID <= 1099999; ID++)
                {
                    int temp_ID = ID;

                    if(ID<1000000)
                    {
                        if( studentID_checksystem_odd(temp_ID) == 1)
                            odd += 1;

                        else if( studentID_checksystem_odd(temp_ID) == 2)
                            even += 1;
                    }

                    else
                    {
                        if( studentID_checksystem_even(temp_ID) == 1)
                            odd += 1;

                        else if( studentID_checksystem_even(temp_ID) == 2)
                            even += 1;
                    }


                }

                printf("odd:%d even:%d\n", odd, even);
            }
        }

        else
        {
            puts("bye~~");
            break;
        }

        divider();
        puts("請輸入0到4");
        puts("1:列印鴨鴨圖案");
        puts("2:計算BMI");
        puts("3:學號算命術");
        puts("4:逢甲學號真實性辨識");
        puts("0:退出程式");
    }

} //end main function

void ascii(void)
{
    printf("!!!!!!!!!!!!!!!!!XUUUUUUUUUUUUUU!!!!!!!!!!!!!!!!!!\n");
    printf("!!!!!!!!!!UUH@*TTTTTTTTTTTTTTTTTTTT@@HUU!!!!!!!!!!\n");
    printf("!!!!!!U@MT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!TT@HX!!!!!\n");
    printf("!!!!W*?!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!U!!!#WX!!!\n");
    printf("!!W@?!!UX!UX!!!!!!!!!!!!!!!!!!!!!!!!?M@HUT@!!!RH!!\n");
    printf("!HR?X@TXHT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!#!!!!!$M!\n");
    printf("!M!!?!!?!!!!!!!!H!!!!!!!!!!!!!!!!!!!X!!!!!!!!!!MM!\n");
    printf("!M!!!!!!!!!!!?H!HMH!!!!!!!!!!!!!!!X@S!SH!!!!!!!MM!\n");
    printf("!MX!!!!!!!!!!!!TH$W8!!!!!!!!!!!!XU$$$M?!!!!!!!!8M!\n");
    printf("!MX!!!!!!!!!!!!TH$W8!!!!!!!!!!!!XU$$$M?!!!!!!!!8M!\n");
    printf("!!M$!!!!!!!!!!$$$$$$$$M!!!!!!XW$$$$$$$$M!!!!!!$!!!\n");
    printf("!!!?@U!!!!!!!M$$$$*$$$M!!!!!!M$$$$TT#$$M!!!!W*?!!!\n");
    printf("!!!!?$H!!!!!!M$$#WWX*$!!!!!!!M$$?XWU!$$?!!!HR!!!!!\n");
    printf("!!!!!!#HU!!!!M$$H#*8$#!!!!!!!?$$H?*I$#?!!X@#!!!!!!\n");
    printf("!!!!!!!X8R!!!!?T$$*TUUH@@@@@@HUT$$*T?!!!!T$W!!!!!!\n");
    printf("!!!!!!!M$!!!!!!!!!!T@RIT@@HH@@TB**UU@@H!!!!MM!!!!!\n");
    printf("!!!!!!!?#HU!!!!!!!!!!!!?T@@@MT!!!!!!!!!!UW*#!!!!!!\n");
    printf("!!!!!!!!!!TTTM@@@@@@UUX!!!!!!!!UUH@@@@MTT!!!!!!!!!\n");
    printf("!!!!!!!!!!!!!!!!!!!!!!R$!!!!!H$?!!!!!!!!!!!!!!!!!!\n");
    printf("!!!!!!!!!!!!!!!!!!!!!!?#W!!!!$T!!!!!!!!!!!!!!!!!!!\n");
    printf("!!!!!!!!!!!!!!!!!!!!!U@@*!!!!#@@UX!!!!!!!!!!!!!!!!\n");
    printf("!!!!!!!!!!!!!!!!!!X@T8MT!!!!!T!@R@X!!!!!!!!!!!!!!!\n");
    printf("!!!!!!!!!!!!!!!!U*#XW#!!!!!!!!!?@W#WX!!!!!!!!!!!!!\n");
    printf("!!!!!!!!!!!!!!W*?XW#!!!!!!!!!!!!M$X!$X!!!!!!!!!!!!\n");
    printf("!!!!!!!!!!!!!!$!HMT!!!!!!!!!!!!!!MM!MM!!!!!!!!!!!!\n");
    printf("!!!!!!!!!!!!!!?*@M!!!!!!!!!!!!!!!M@@T!!!!!!!!!!!!!\n");
    printf("!!!!!!!!!!!!!!!!MM!!!!!!!!!!!!!!!MM!!!!!!!!!!!!!!!\n");
    printf("!!!!!!!!!!!!!!!!M8X!!!!!!!!!!!!X@#!!!!!!!!!!!!!!!!\n");
    printf("!!!!!!!!!!!!!!!!!#@X!!!!!!!!!!U@?!!!!!!!!!!!!!!!!!\n");
    printf("!!!!!!!!!!!!!!!!!!?@!HMTTT@!HT!!!!!!!!!!!!!!!!!!!!\n");
    printf("!!UW@@@TTTTM@@UUU!!M!M!!!!M!M!!!XUUU@@@HUUUX!!!!!!\n");
    printf("!M?!H@I*M!!!!!!!!TTT!MX!XW*!M@TT?!!!!!!@WU!?#WX!!!\n");
    printf("!MHMMT!!!!!!!!!!!UUH@*?!?*@HUX!!!!!!!!!!!TRMH!R!!!\n");
    printf("!MMMH!!!!!!!UU@TT!!!!!!!!!!!!?T*HU!!!!!!!!!MM!M!!!\n");
    printf("!!!!!TTTTTTT!!!!!!!!!!!!!!!!!!!!!!TTM@@@@@TTTT!!!!\n");

} //end ascii function

void bmi_input_weight(float *weight_pointer)
{
    printf("請輸入體重(kg)\n"); //input weight
    scanf("%f", &*weight_pointer);

} //end bmi_input_weight function

void bmi_input_height(float *height_pointer)
{
    printf("請輸入身高(cm)\n"); //input height
    scanf("%f", &*height_pointer);

} //end bmi_input_height function

void bmi_input_gender(char *gender_pointer)
{
    printf("請輸入性別，男生為M，女生為F\n");
    scanf("%c", &*gender_pointer);

} //end bmi_input_gender function

void bmi_judge_gender(char *gender_pointer) //avoid the wrong input
{
    while (*gender_pointer != 'm' && *gender_pointer != 'M' && *gender_pointer != 'f' && *gender_pointer != 'F')
    {
        puts("連性別都能輸入錯");
        puts("請輸入性別，男生為M，女生為F");
        getchar();
        scanf("%c", &*gender_pointer);
    }

} //end bmi_judge_gender function

void bmi_recommend_weight(float *recommend_weight_pointer, float height, char gender)
{
    if (gender == 'm' || gender == 'M') //judge which gender
        *recommend_weight_pointer = ((height * 100) - 80) * 0.7;
    else
        *recommend_weight_pointer = ((height * 100) - 70) * 0.6;

} //end bmi_recommend_weight function

void bmi_calculator(float weight, float height, float recommend_weight)
{
    float bmi = weight / (height * height);
    printf("您的BMI為\t%.2f  \n", bmi);
    if (18.50 <= bmi && bmi < 24.00)
    {
        printf("健康體位\n");
        printf("您的標準體重介於\t%.1f ~ %.1f", recommend_weight - recommend_weight * 0.1, recommend_weight + recommend_weight * 0.1);
    }

    else if (bmi < 18.50)
    {
        printf("體重過輕！\n");
        printf("您的標準體重介於\t%.1f ~ %.1f", recommend_weight - recommend_weight * 0.1, recommend_weight + recommend_weight * 0.1);
    }

    else if (24 <= bmi && bmi < 27)
    {
        printf("體重過重！\n");
        printf("您的標準體重介於\t%.1f ~ %.1f", recommend_weight - recommend_weight * 0.1, recommend_weight + recommend_weight * 0.1);
    }

    else if (27 <= bmi && bmi < 30)
    {
        printf("有點胖！\n");
        printf("您的標準體重介於\t%.1f ~ %.1f", recommend_weight - recommend_weight * 0.1, recommend_weight + recommend_weight * 0.1);
    }

    else if (30 < bmi && bmi <= 35)
    {
        printf("好胖！\n");
        printf("您的標準體重介於\t%.1f ~ %.1f", recommend_weight - recommend_weight * 0.1, recommend_weight + recommend_weight * 0.1);
    }

    else if (35 <= bmi)
    {
        printf("超胖！別再吃了\n");
        printf("您的標準體重介於\t%.1f ~ %.1f", recommend_weight - recommend_weight * 0.1, recommend_weight + recommend_weight * 0.1);
    }

    puts("");

} //end bmi_calculator function

void divider(void)
{
    puts("=======================================");

} //end divider function

void fortune_teller(char *studentID, int *begin_year_pointer, int *end_year_pointer)
{
    char year[3];
    year[0] = studentID[1];
    year[1] = studentID[2];

    *begin_year_pointer = atoi(year);
    *end_year_pointer = atoi(year) + 4;

} //end fortune_teller function

void input_studentID(char *studentID_pointer)
{
    puts("輸入您的學號(D1234567)");
    scanf("%8s", studentID_pointer);

} //end fortune_teller_input_studentID function

void fortune_teller_input_week(int *week_pointer)
{
    puts("輸入第幾週");
    scanf("%d", &*week_pointer);

} //end fortune_teller_input_week function

void fortune_teller_convert_AD(int *begin_year_pointer, int *end_year_pointer)
{
    if (*begin_year_pointer < 20)
    {
        *begin_year_pointer += 100;
        *end_year_pointer += 100;
    }

    //convert to A.D.
    *begin_year_pointer += 1911;
    *end_year_pointer += 1911;

} //end fortune_teller_convert_AD function

void fortune_teller_method(char *studentID)
{
    printf("入學管道：");

    if ('0' <= studentID[3] && studentID[3] <= '4')
        printf("特殊選材/繁星推薦/海外申請");

    else if ('5' <= studentID[3] && studentID[3] <= '8')
        printf("申請入學/四技二專徵選");

    else if ('9' == studentID[3])
        printf("考試入學");

    puts("");

} //end fortune_teller_method function

void fortune_teller_go_to_school(char *studentID, int week)
{
    if ((int)(studentID[7]) % 2 == 1)
    {
        if (week % 2 == 1)
            printf("這週要實體上課\n");

        else
            printf("這週線上上課\n");
    }

    else
    {
        if (week % 2 == 0)
            printf("這週實體上課\n");

        else
            printf("這週線上上課\n");
    }

} //end fortune_teller_go_to_school function

void studentID_checksystem(char *studentID)
{
    int sum = 0;
    int checknumber;

    for (int i = 0; i < 6; i++)
    {
        //D1051520
        //01234567
        int temp = (int)studentID[i+1] - '0'; //convert to number

        if (i % 3 == 0)
            temp *= 8;
        else if (i % 3 == 1)
            temp *= 7;
        else
            temp *= 6;

        while (temp > 0)
        {
            sum = sum + temp % 10;
            temp /= 10;
        }
    }

    checknumber = (10 - sum % 10) % 10;

    printf("Your student ID ");
    if(studentID[7] == (char)checknumber+'0')
        printf("is real");

    else
        printf("is fake");
    
    puts("");

} //end studentID_checksystem function

int studentID_checksystem_odd(int temp_ID)
{
    int sum = 0;
    int checknumber = temp_ID % 10;
    temp_ID /= 10;

    //the inspection process
    for (int i = 0; i < 5; i++)
    {
        int temp = temp_ID % 10;
        temp_ID /= 10;

        if (i % 3 == 0)
            temp *= 6;
        else if (i % 3 == 1)
            temp *= 7;

        else
            temp *= 8;

        while (temp > 0)
        {
            sum = sum + temp % 10;
            temp /= 10;
        }
    }

    if( (10 - sum % 10) % 10 == checknumber )
    {
        if(checknumber % 2 == 1)
            return 1;

        else
            return 2;
    }
    else
        return 0;
    
} //end studentID_checksystem_odd function

int studentID_checksystem_even(int temp_ID)
{
    int sum = 0;
    int checknumber = temp_ID % 10;
    temp_ID /= 10;

    //the inspection process
    for (int i = 0; i < 5; i++)
    {
        int temp = temp_ID % 10;
        temp_ID /= 10;

        if (i % 3 == 0)
            temp *= 6;
        else if (i % 3 == 1)
            temp *= 7;

        else
            temp *= 8;

        while (temp > 0)
        {
            sum = sum + temp % 10;
            temp /= 10;
        }
    }

    if( (10 - sum % 10) % 10 == checknumber )
    {
        if(checknumber % 2 == 1)
            return 1;

        else
            return 2;
    }
    else
        return 0;
} //end studentID_checksystem_even function
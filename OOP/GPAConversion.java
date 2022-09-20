import java.util.Scanner;

class GPAConversion{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Input Percentage: ");
        float p = sc.nextFloat();
        System.out.printf("GPA is %4.2f", p / 100 * 4);
        sc.close();
    }
}

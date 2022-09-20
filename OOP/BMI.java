import java.util.Scanner;

class BMI{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Input height(ex. 1.87): ");
        float h = sc.nextFloat();
        System.out.print("Input weight(ex. 59.2): ");
        float w = sc.nextFloat();

        System.out.printf("Your BMI: %4.1f", w/Math.pow(h, 2));
        sc.close();
    }
}


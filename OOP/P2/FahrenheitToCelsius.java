import java.util.Scanner;

class FahreheitToCelsius{
    public static void main(String[] args){
        System.out.print("Input a F degree: ");
        Scanner sc = new Scanner(System.in);

        float degree = sc.nextFloat();
        System.out.printf("Convert to Celsius degree is: %6.2f", 5.0/9 * (degree - 32));
        sc.close();
    }
}

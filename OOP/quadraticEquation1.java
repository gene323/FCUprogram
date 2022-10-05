import java.util.Scanner;

public class quadraticEquation1{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter coefficient a: ");
        double a = sc.nextDouble();
        System.out.print("Enter coefficient b: ");
        double b = sc.nextDouble();
        System.out.print("Enter coefficient c: ");
        double c = sc.nextDouble();
        System.out.print("Enter the first root r1: ");
        double r1 = sc.nextDouble();
        System.out.print("Enter the second root r2: ");
        double r2 = sc.nextDouble();

        if(r1 > r2){
            double tmp = r1;
            r1 = r2;
            r2 = tmp;
        }
        double D = Math.pow(Math.pow(b, 2) - 4 * a * c, 0.5);
        double realr1 = (-b - D)/(2 * a);
        double realr2 = (-b + D)/(2 * a);;

        if(realr1 == r1 && realr2 == r2){
            System.out.printf("%.4f and %.4f are the roots of equation "
                    + "%.4f x**2 + %.4f x + %.4f = 0.", r1, r2, a, b, c);
        }
        else{
            System.out.printf("%.4f and %.4f are not the roots of equation "
                    + "%.4f x**2 + %.4f x + %.4f = 0.", r1, r2, a, b, c);
        }
        sc.close();
    }
}

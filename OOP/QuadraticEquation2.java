import java.util.Scanner;

public class QuadraticEquation2{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter coefficient a: ");
        double a = sc.nextDouble();
        System.out.print("Enter coefficient b: ");
        double b = sc.nextDouble();
        System.out.print("Enter coefficient c: ");
        double c = sc.nextDouble();

        double D = Math.pow(Math.pow(b, 2) - 4 * a * c, 0.5);
        double r1 = (-b - D)/(2 * a);
        double r2 = (-b + D)/(2 * a);;
        if(D > 0){
            System.out.printf("The roots of equation %.4f x**2 + %.4f x + %.4f"
                    + "are %.4f and %.4f", a, b, c, r1, r2);
        }
        else if(D == 0){
            System.out.printf("The multiple real root of equation "
                    + "%.4f x**2 + %.4f x + %.4f is %.4f .", a, b, c, r1);
        }
        else{
            D = Math.pow(4 * a * c - Math.pow(b, 2), 0.5);
            double r = -b / (2 * a);
            double i = D / (2 * a);
            System.out.printf("The complex roots of equation "
                    + "%.4f x**2 + %.4f x + %.4f are "
                    + "%.4f+%.4fi and %.4f-%.4fi", a, b, c, r, i, r, i);
        }
        sc.close();
    }
}

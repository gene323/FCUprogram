package ComplexNumber;
import java.util.Scanner;

public class HW2APP_D1051520{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Complex complex1;
        Complex complex2;
        Complex complex3;
        double a, b, c;

        System.out.print("Enter the first complex number a + bi ");
        a = sc.nextDouble();
        b = sc.nextDouble();
        complex1 = new Complex(a, b);

        System.out.print("Enter the second complex number a + bi ");
        a = sc.nextDouble();
        b = sc.nextDouble();
        complex2 = new Complex(a, b);

        System.out.printf("\nThe complex numbers are ");
        complex1.printComplex();
        System.out.print(" and ");
        complex2.printComplex();
        System.out.printf("\n\n");
        System.out.println("After complex number arithmetic operations:");
        System.out.println("===========================================");

        System.out.printf("Complex addition: %s\n"
                , Complex.add(complex1, complex2));
        System.out.printf("Complex subtraction: %s\n"
                , Complex.subtraction(complex1, complex2));
        System.out.printf("Complex multiplication: %s\n"
                , Complex.multiplication(complex1, complex2));
        System.out.printf("Complex division: %s\n"
                , Complex.division(complex1, complex2));
        System.out.printf("First complex absolute value %s\n", Complex.absolute(complex1));
        System.out.printf("Second complex absolute value %s\n", Complex.absolute(complex2));

        System.out.print("\n\n");

        System.out.print("Enter coefficient a: ");
        a = sc.nextDouble();
        System.out.print("Enter coefficient b: ");
        b = sc.nextDouble();
        System.out.print("Enter coefficient c: ");
        c = sc.nextDouble();

        Complex.calcRoots(a, b, c);

        System.out.print("Enter coefficient a: ");
        a = sc.nextDouble();
        System.out.print("Enter coefficient b: ");
        b = sc.nextDouble();
        System.out.print("Enter coefficient c: ");
        c = sc.nextDouble();

        Complex.calcRoots(a, b, c);
        sc.close();
    }
}

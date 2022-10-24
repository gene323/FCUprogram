import java.util.Scanner;

public class DrawFiguresTriangle{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the side of an isosceles triangle "
                        + "(between 3 and 29): ");
        int side = sc.nextInt();

        for(int i=0; i<side - 1; i++){
            printBlank(10);
            printBlank(side - i - 1);
            System.out.print("*");
            if(i > 0){
                printBlank(i * 2 - 1);
                System.out.print("*");
            }
            System.out.println();
        }
        printBlank(10);
        for(int i=0; i<side * 2 - 1; i++){
            System.out.print("*");
        }

        sc.close();
    }
    public static void printBlank(int k){
        for(int i=0; i<k; i++)
            System.out.print(" ");
    }
}

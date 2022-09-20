import java.util.Scanner;

public class BitwiseOperation{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number A: ");
        int a = sc.nextInt();
        System.out.print("Enter a number B: ");
        int b = sc.nextInt();

        System.out.printf("%25s", "Bitwise A: ");
        printBinary(a);

        System.out.printf("%25s", "Bitwise B: ");
        printBinary(b);

        System.out.printf("%25s", "Bitwise A & B: ");
        printBinary(a & b);

        System.out.printf("%25s", "Bitwise A | B: ");
        printBinary(a | b);

        System.out.printf("%25s", "Bitwise A ^ B: ");
        printBinary(a ^ b);

        System.out.printf("%25s", "right shift 3 bits of A: ");
        printBinary(a >> 3);

        System.out.printf("%25s", "right shift 3 bits of B: ");
        printBinary(b >> 3);

        sc.close();
    }
    private static void printBinary(int a){
        for(int i=0; i<32; i++){
            System.out.print((a >> (31 - i)) & 1);
            if(i > 0 & (i + 1) % 4 == 0){
                System.out.print(" ");
            }
        }
        System.out.println();
    }
}

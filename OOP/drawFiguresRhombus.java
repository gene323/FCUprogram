import java.util.Scanner;

public class drawFiguresRhombus{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the side of a rhombus (between 3 and 29): ");
        int side = sc.nextInt();

        print(' ', 10 + side - 1);
        System.out.println("*");
        for(int i=1; i<side; i++){
            print(' ', 10 + side - i - 1);
            print('*', 1);
            print('@', i * 2 - 1);
            print('*', 1);
            System.out.println("");
        }
        for(int i=side - 2; i>0; i--){
            print(' ', 10 + side - i - 1);
            print('*', 1);
            print('@', i * 2 - 1);
            print('*', 1);
            System.out.println("");
        }
        print(' ', 10 + side - 1);
        System.out.println("*");

        sc.close();
    }
    public static void print(char ch, int k){
        for(int i=0; i<k; i++)
            System.out.print(ch);
    }
}

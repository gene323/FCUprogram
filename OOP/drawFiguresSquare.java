import java.util.Scanner;

public class drawFiguresSquare{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the side of a square (between 2 and 30): ");
        int side = sc.nextInt();

        print(' ', 10);
        print('*', side);
        System.out.println("");
        for(int i=0; i<side - 2; i++){
            print(' ', 10);
            print('*', 1);
            print(' ', side - 2);
            print('*', 1);
            System.out.println("");
        }
        print(' ', 10);
        print('*', side);
        System.out.println("");

        sc.close();
    }
    public static void print(char ch, int k){
        for(int i=0; i<k; i++)
            System.out.print(ch);
    }
}

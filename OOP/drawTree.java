import java.util.Scanner;

public class drawTree{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of tiers (2 to 5): ");
        int tiers = sc.nextInt();
        System.out.print("Enter the side of top triangle (3 to 6): ");
        int side = sc.nextInt();
        System.out.print("Enter the growth of two adjacent triangles (1 to 5): ");
        int growth = sc.nextInt();
        System.out.print("Enter the width of the trunk (odd number, 3 to 9): ");
        int width = sc.nextInt();
        System.out.print("Enter the height of the trunk (4 to 10): ");
        int height = sc.nextInt();

        int blank = side + growth * (tiers - 1) - 1;
        printChar(' ', blank);
        System.out.println('#');
        for(int i=0; i<tiers; i++){
            for(int j=1; j<side + growth * i; j++){
                printChar(' ', blank - j);
                printChar('#', 1);
                if(j + 1 == side + growth * i){
                    printChar('#', j * 2 - 1);
                }
                else{
                    printChar('@', j * 2 - 1);
                }
                printChar('#', 1);
                System.out.println("");
            }
        }

        for(int i=0; i<height; i++){
            printChar(' ', blank - width / 2);
            printChar('|', width);
            System.out.println();
        }
        sc.close();
    }
    public static void printChar(char ch, int k){
        for(int i=0; i<k; i++){
            System.out.print(ch);
        }
    }
}

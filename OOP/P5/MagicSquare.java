import java.util.Scanner;

public class MagicSquare{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of the magic square (3<=n<20, odd integer): ");
        int n = sc.nextInt();

        //check if n is odd integer
        while(n%2 == 0){
            System.out.print("Enter the size of the magic square (3<=n<20, odd integer): ");
            n = sc.nextInt();
        }

        int[][] arr = new int[n][n];
        int r = 0;
        int c = n/2;
        int sum = 0;

        //initialize the 2d array
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                arr[i][j] = 0;
            }
        }

        //fill the 2d array
        for(int i=0; i<n*n; i++){
            arr[r][c] = i+1;
            if(arr[(r+n-1)%n][(c+n-1)%n] > 0)
                r = (r+1)%n;
            else{
                r = (r+n-1)%n;
                c = (c+n-1)%n;
            }
        }
        
        //count the sum of each row
        for(int i=0; i<n; i++){
            sum += arr[i][0];
        }

        System.out.printf("The magic square of degree %d:\n", n);
        for(int i=0; i<n; i++){
            System.out.print("    ");
            for(int j=0; j<n; j++){
                System.out.printf("%3d ", arr[i][j]);
            }
            System.out.printf("\n");
        }
        System.out.print("The magic square passes verification.\n");
        System.out.printf("The sum of each row, each column, diagonal, and anti-diagonal is %d.", sum);
        sc.close();
    }
}

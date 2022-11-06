import java.util.Random; // Package for random number generator.
import java.util.Scanner; // Package for input stream.
import java.util.Arrays;

public class Mexam_skeleton_2 {

    public static void main(String[] args) {
        int[][] A; // Matrix A.
        int[][] B; // Matrix B.
        int[][] C; // Matrix C.
        int n; // Row size and Column size of square matrices A, b, and C.
        int ra, sa; // Lower bandwidth and upper bandwidth of matrix A.
        int rb, sb; // Lower bandwidth and upper bandwidth of matrix B.
        // Lower bandwidth and upper bandwidth of matrix C are ra+rb and sa+sb,
        // respectively.
        Scanner in = new Scanner(System.in); // Initial an input stream.

        //TODO: Add some code here for input data
        do {
            System.out.print("Enter integers n for square matrix size: ");
            n = in.nextInt(); // Row and column size of square matrices.
            System.out.print("Enter lower bandwidth and upper bandwidth of matrix A: ");
            ra = in.nextInt(); // Lower bandwidth matrix A.
            sa = in.nextInt(); // Upper bandwidth matrix A.
            System.out.print("Enter lower bandwidth and upper bandwidth of matrix B: ");
            rb = in.nextInt(); // Lower bandwidth matrix B.
            sb = in.nextInt(); // Upper bandwidth matrix B.
        } while (n <= 0 | ra < 0 | sa < 0 & rb < 0 | sb < 0 | ra >= n | sa >= n | rb >= n | sb >= n);

        //TODO: Add some code here & Complete the program.
        A = generateMatrix(n, sa, ra);
        B = generateMatrix(n, sb, rb);
        C = matrix_product_banded(A, B, n);


        System.out.println("Matrix A:");
        printMatrix(A, n, sa, ra);
        System.out.println("Matrix B:");
        printMatrix(B, n, sb, rb);
        System.out.println("Matrix C:");
        printMatrix(C, n, sa+sb, ra+rb);
        in.close();
    }

    // A: pointer to nxn banded matrix, 
    // B: pointer to nxn banded matrix, 
    // C: pointer to nxn banded matrix, 
    // ra: the lower bandwidth of matrix A, 
    // rb: the upper bandwidth of matrix A, 
    // sa: the lower bandwidth of matrix B, 
    // sb: the upper bandwidth of matrix B, 
    // ra+rb: the lower bandwidth of matrix C, 
    // sa+sb: the upper bandwidth of matrix C. 
    // Compute C=AxB using banded matrix multiplication algorithm.
    private static int[][] matrix_product_banded(int[][] A, int[][] B, int n) {
        int[][] C = new int[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int sum = 0;
                for(int k=0; k<n; k++){
                    sum += (A[i][k] * B[k][j]);
                }
                C[i][j] = sum;
            }
        }
        return C;
    }
    private static int[][] generateMatrix(int n, int upper, int lower){
        int[][] res = new int[n][n];
        Random rnd = new Random();
        for(int i=0; i<n; i++){
            int k = rnd.nextInt(101) - 50;
            res[i][i] = k;
        }
        for(int i=1; i<=upper; i++){
            for(int j=0; j<n-i; j++){
                int k = rnd.nextInt(101) - 50;
                res[j][i+j] = k;
            }
        }
        for(int i=1; i<=lower; i++){
            for(int j=0; j<n-i; j++){
                int k = rnd.nextInt(101) - 50;
                res[i+j][j] = k;
            }
        }
        return res;
    }
    private static void printMatrix(int[][] matrix, int n, int upper, int lower){
        for(int i=0; i<n; i++){
            int begin = (i - lower >= 0)? (i-lower): 0;
            int end = (i + upper + 1 < n)? (i+upper+1): n;
            for(int j=0; j<begin; j++){
                System.out.printf("%10c", ' ');
            }
            for(int j=begin; j<end; j++){
                System.out.printf("%10d", matrix[i][j]);
            }
            for(int j=end; j<n; j++){
                System.out.printf("%10c", ' ');
            }
            System.out.println();
        }
        System.out.println();
    }
}

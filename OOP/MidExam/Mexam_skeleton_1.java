import java.util.Scanner;
import java.util.Arrays;
import java.math.*;

public class Mexam_skeleton_1 {
    public static boolean isOK(int[][] square, int r, int c){
        if(square[r][c] != 0)
            return false;
        return true;
    }
    public static void main(String[] args) {
        int[][] square; // Two dimensional square matrix.
        Scanner in = new Scanner(System.in); // Initial an input stream.
        int n = 3; // Scale of the magic square, an odd number such that 3<=n<20.
        int start = 0; // Starting cell, at the center of 0: top row, 1: right-most column, 2: bottom row, 3: left-most column.		
        int move = 0; // Move step, 0: upper-left, 1: upper-right, 2: lower-right, 3: lower-left.
        int value = 1; // The first value to be filled to the magic square is 1.
        int row = 0, col = 0; // Row and column indexes. Initial to be the cell on the top-left corner.
        int total; // Total value, (1+n^2)n/2, of each row, each column, the diagonal, and the anti-diagonal.
        int sum; // To compute sum of rows, columns, the diagonal, and the anti-diagonal.
        int[][] dir = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
          
        //TODO: Add some code here for input data
        do {
            System.out.print("Enter the size of the magic square (3<=n<20, odd integer): ");
            n = in.nextInt();
        } while (n<3 | n >20 | n%2==0); // 3<=n<20 and n is odd; otherwise, repeat the input.
          
        // Set the starting cell, at the center of 0: top row, 1: right-most column, 2: bottom row, 3: left-most column.
        do {
            System.out.println("Enter position of the starting cell at the center of");
            System.out.print("  0: top row, 1: right-most column, 2: bottom row, 3: left-most column: ");
            start = in.nextInt();
        } while (start<0 | start>3); // If start is invalid, repeat the input.
          
        // Set the move step, 0: upper-left, 1: upper-right, 2: lower-right, 3: lower-left.
        do {
            System.out.print("Set move step (0: upper-left, 1: upper-right, 2: lower-right, 3: lower-left): ");
            move = in.nextInt();
        } while (move<0 | move >3); // If move is invalid, repeat the input.
        
        //TODO: Add some code here & complete the program.
        square = new int[n][n];
        total = (int)((1+Math.pow(n, 2))*n)/2;
        for(int[] it: square){
            Arrays.fill(it, 0);
        }
        //set row, col at start position
        if(start == 0){
            row = 0; col = n/2;
        }
        else if(start == 1){
            row = n/2; col = n-1;
        }
        else if(start == 2){
            row = n-1; col = n/2;
        }
        else if(start == 3){
            row = n/2; col = 0;
        }
        while(value <= n*n){
            square[row][col] = value++;
            if(isOK(square, ((row + dir[move][0] + n) % n), ((col + dir[move][1] + n) % n))){
                row = (row + dir[move][0] + n) % n;
                col = (col + dir[move][1] + n) % n;
            }
            else{
                if(move == 0 || move == 1)
                    row = (row + 1 + n) % n;
                else
                    row = (row - 1 + n) % n;
            }
        }
        
        // ToDo: Print the magic square.
        System.out.printf("The magic square of degree %d:\n", n); // Heading message.
        for (int i=0; i<n; i++) { // Output n rows.
            System.out.print("      "); // Leave 6 blanks on the left-hand-side.
            for (int j=0; j<n; j++) { // output n columns.
                System.out.printf("%4d", square[i][j]); // Print the value of a cell, 4-digit format.			
            }
            System.out.print("\n");
        }
        
        // ToDo: Start to verify magic square.
        // Verify all rows.
        // Verify all columns.	
        // Verify diagonals. 
        // Verify anti-diagonals.	
        // If all verification pass.
        boolean valid = true;
        //check row
        for(int i=0; i<n; i++){
            sum = 0;
            for(int j=0; j<n; j++){
                sum += square[i][j];
            }
            if(sum != total){
                valid = false;
                break;
            }
        }
        //check col
        for(int i=0; i<n; i++){
            sum = 0;
            for(int j=0; j<n; j++){
                sum += square[j][i];
            }
            if(sum != total){
                valid = false;
                break;
            }
        }
        //check diaginal
        sum = 0;
        for(int i=0; i<n; i++){
            sum += square[i][i];
        }
        if(sum != total)
            valid = false;
        //check anti-diaginal
        sum = 0;
        for(int i=n-1; i>=0; i--){
            sum += square[i][i];
        }
        if(sum != total)
            valid = false;

        if (valid) System.out.println("\nThe magic square passes verification.");
        if (valid) System.out.printf("The sum of each row and each column is %d.\n", total);
        if (valid) System.out.printf("The sum of at least one diaginal is %d.\n", total);
        if (valid) System.out.printf("The sum of at least one anti-diaginal is %d.\n", total);
        
        in.close();
    }
}

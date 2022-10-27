package Matrix;
import Matrix.util.Matrix;

public class MatrixApp{
    public static void main(String[] args){
        Matrix a = new Matrix(5, 4);
        Matrix b = new Matrix(5, 4);
        Matrix c = new Matrix(5, 4);
        Matrix d = new Matrix(4, 6);
        Matrix e = new Matrix(5, 6);

        System.out.printf("Matrix A:\n");
        a.printArr();

        System.out.printf("Matrix B:\n");
        b.printArr();

        System.out.printf("Matrix C:\n");
        c.printArr();

        System.out.printf("Matrix D:\n");
        d.printArr();

        System.out.printf("Matrix E:\n");
        e.printArr();

        System.out.printf("Resulting Matrix of A+B-C:\n");
        Matrix.subtract(Matrix.add(a, b), c).printArr();

        System.out.printf("Resulting Matrix of B*D+E:\n");
        Matrix.add(Matrix.multiply(b, d), e).printArr();

        System.out.printf("Resulting Matrix of E-A*D:\n");
        Matrix.subtract(e, Matrix.multiply(a, d)).printArr();
    }
}

package Matrix.util;

public class Matrix{
    private int[][] arr;
    private int n;
    private int m;
    public Matrix(int n, int m){
        this.arr = new int[n][m];
        this.n = n;
        this.m = m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                this.arr[i][j] = (int)(Math.random() * 101) - 50;
            }
        }
    }
    public static Matrix add(Matrix a, Matrix b){
        Matrix c = new Matrix(a.getN(), a.getM());
        for(int i=0; i<c.getN(); i++){
            for(int j=0; j<c.getM(); j++){
                c.setArr(a.getArr(i, j) + b.getArr(i, j), i, j);
            }
        }
        return c;
    }
    public static Matrix subtract(Matrix a, Matrix b){
        Matrix c = new Matrix(a.getN(), a.getM());
        for(int i=0; i<c.getN(); i++){
            for(int j=0; j<c.getM(); j++){
                c.setArr(a.getArr(i, j) - b.getArr(i, j), i, j);
            }
        }
        return c;
    }
    public static Matrix multiply(Matrix a, Matrix b){
        Matrix c = new Matrix(a.getN(), b.getM());
        for(int i=0; i<c.getN(); i++){
            for(int j=0; j<c.getN(); j++){
                int tmp = 0;
                for(int k=0; k<a.getM(); k++){
                    tmp += a.getArr(i, k) * b.getArr(k, j);
                }
                c.setArr(tmp, i, j);
            }
        }
        return c;
    }
    public int getN(){
        return this.n;
    }
    public int getM(){
        return this.m;
    }
    public void setArr(int k, int i, int j){
        this.arr[i][j] = k;
    }
    public int getArr(int i, int j){
        return this.arr[i][j];
    }
    public void printArr(){
        for(int i=0; i<this.n; i++){
            for(int j=0; j<this.m; j++){
                System.out.printf("%6d", this.arr[i][j]);
            }
            System.out.printf("\n");
        }
        System.out.printf("\n-------------------------------------------\n");
    }
}

package util;

public class Matrices implements Matrix<Matrices, MatrixException>{
    private double[][] matrix;
    private int row;
    private int col;
    private String name;

    public Matrices(String name, int r, int c){
        matrix = new double[r][c];
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                matrix[i][j] = Math.round(Math.random()*10000)/10000.0;
            }
        }
        this.name = name;
        this.row = r;
        this.col = c;
    }
    public Matrices(int r, int c){
        matrix = new double[r][c];
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                matrix[i][j] = Math.round(Math.random()*10000)/10000.0;
            }
        }
    }
    public Matrices addition(Matrices a){
        Matrices res = new Matrices(String.format("%s+%s", this, a), row, col);
        try{
            compare(a);
            for(int i=0; i<row; i++){
                for(int j=0; j<col; j++){
                    res.matrix[i][j] = this.matrix[i][j] + a.matrix[i][j];
                }
            }
        } catch(MatrixException ex){
            System.out.println(ex);
        }
        return res;

    }
    public Matrices subtraction(Matrices a){
        Matrices res = new Matrices(String.format("%s-%s", this, a), row, col);
        try{
            compare(a);
            for(int i=0; i<row; i++){
                for(int j=0; j<col; j++){
                    res.matrix[i][j] = matrix[i][j] - a.matrix[i][j];
                }
            }
        } catch(MatrixException ex){
            System.out.println(ex);
        }
        return res;
    }
    
    public Matrices multiplication(Matrices a){
        Matrices res = new Matrices(String.format("%s*%s", this, a), this.row, a.getCol());
        try{
            compareMultiply(col, a.getRow());
            for(int i=0; i<res.matrix.length; i++){
                double tmp = 0;
                for(int j=0; j<a.matrix[0].length; j++){
                    for(int k=0; k<a.matrix.length; k++){
                        tmp += (matrix[i][k]*a.matrix[k][j]);
                    }
                    res.matrix[i][j] = tmp;
                }
            }
            return res;
        } catch(MatrixException ex){
            System.out.println(ex);
        }
        return res;
    }
    public Matrices transposition(){
        Matrices res = new Matrices(String.format("(%s)^T", this), col, row);
        for(int i=0; i<res.getRow(); i++){
            for(int j=0; j<res.getCol(); j++){
                res.matrix[i][j] = matrix[j][i];
            }
        }
        return res;
    }
    public void compare(Matrices a) throws MatrixException{
        if(row != a.getRow() || col != a.getCol()){
            throw new MatrixException("mismatch matrix size");
        }
    }
    public void compareMultiply(int ra, int cb) throws MatrixException{
        if(ra != cb){
            throw new MatrixException("mismatch matrix size");
        }
    }
    public void printMatrix(){
        System.out.printf("Matrix %s:\n", name);
        for(double[] i: matrix){
            for(double j: i){
                System.out.printf("%.4f ", j);
            }
            System.out.println();
        }
        System.out.println("======================");
    }
    public String toString(){
        return this.name;
    }
    public int getRow(){
        return this.row;
    }
    public int getCol(){
        return this.col;
    }
}

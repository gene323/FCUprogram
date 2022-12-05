import util.Matrices;

public class MatrixApp{
    public static void main(String[] args){
        Matrices a = new Matrices("A", 6, 4);
        Matrices b = new Matrices("B", 6, 4);
        Matrices c = new Matrices("C", 4, 6);
        a.printMatrix();
        b.printMatrix();
        c.printMatrix();
        a.addition(b).printMatrix();
        a.subtraction(b).printMatrix();
        a.multiplication(c).printMatrix();
        c.multiplication(b).printMatrix();
        b.subtraction(a).transposition().printMatrix();
    } 
}

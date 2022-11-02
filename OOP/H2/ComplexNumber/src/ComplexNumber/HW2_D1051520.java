package ComplexNumber;
class Complex{
    public double a;
    public double b;
    public char op;
    public static String add(Complex c1, Complex c2){
        String r = Double.toString(c1.a + c2.a); 
        String i = Double.toString(Math.abs(c1.b + c2.b));
        String op = (c1.b + c2.b > 0)? "+" : "-";
        return r + op + i + "i";
    }
    public static String subtraction(Complex c1, Complex c2){
        String r = Double.toString(c1.a - c2.a); 
        String i = Double.toString(Math.abs(c1.b - c2.b));
        String op = (c1.b - c2.b > 0)? "+" : "-";
        return r + op + i + "i";
    }
    public static String multiplication(Complex c1, Complex c2){
        double a = c1.a;
        double b = c1.b;
        double c = c2.a;
        double d = c2.b;
        String r = Double.toString(a*c - b*d);
        String i = Double.toString(Math.abs(a*d + b*c));
        String op = (a*d + b*c > 0)? "+" : "-";
        return r + op + i + "i";
    }
    public static String division(Complex c1, Complex c2){
        double a = c1.a;
        double b = c1.b;
        double c = c2.a;
        double d = c2.b;
        double deno = c * c + d * d;
        String r = Double.toString((a*c + b*d)/deno);
        String i = Double.toString((-a*d + b*c)/deno);
        String op = ((-a*d + b*c)/deno > 0)? "+" : "-";
        return r + op + i + "i";

    }
    public static String absolute(Complex c1){
        return Double.toString(Math.pow(c1.a*c1.a + c1.b*c1.b, 0.5));
    }
    public static void calcRoots(double a, double b, double c){
        double D = b*b - 4*a*c;
        if(D > 0){
            double r1 = (-b - Math.pow(D, 0.5))/(2*a);
            double r2 = (-b + Math.pow(D, 0.5))/(2*a);
            System.out.printf("The two roots of quadratic %.4fX**2 %c %.4fX %c %.4f" 
                    , a, (b > 0)? '+' : '-', Math.abs(b), (c > 0)? '+' : '-', Math.abs(c));
            System.out.printf(" are: %.4f and %.4f", r1, r2);
        }
        else{
            D = 4*a*c - b*b;
            double r1 = (-b)/(2*a);
            double r2 = (-b)/(2*a);
            double i1 = -Math.pow(D, 0.5)/(2*a);
            double i2 =  Math.pow(D, 0.5)/(2*a);
            System.out.printf("The two roots of quadratic %.4fX**2 %c %.4fX %c %.4f" 
                    , a, (b > 0)? '+' : '-', Math.abs(b)
                    , (c > 0)? '+' : '-', Math.abs(c));
            System.out.printf(" are: %.4f%c%.4fi  and %.4f%c%.4fi"
                    , r1, (i1 > 0)? '+' : '-', Math.abs(i1)
                    , r2, (i2 > 0)? '+' : '-', Math.abs(i2));
        }
        System.out.print("\n\nVerification of the two quadratic equation roots PASSES.");
        System.out.println("\n\n--------------------------------------------------------");

    }
    public Complex(){
        this.a = 0.0;
        this.b = 0.0;
        this.op = '+';
    }
    public Complex(double r){
        this.a = r;
        this.b = 0.0;
        this.op = '+';
    }
    public Complex(double r, double i){
        this.a = r;
        this.b = i;
        this.op = (i > 0)? '+' : '-';
    }
    public double getRe(){
        return a;
    }
    public double getIm(){
        return b;
    }
    public void setRe(double r){
        this.a = r;
    }
    public void setIm(double i){
        this.b = i;
        this.op = (i > 0)? '+' : '-';
    }
    public void printComplex(){
        System.out.printf("%f %c %fi", this.a, this.op, this.b);
    }
}

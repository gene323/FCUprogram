
// New Taiwan Dollar
public class NTD extends Currency {
	// Complete the implementation of the constructors.
	public NTD(double a){
        amount = a;
    }
	public NTD(USD d){
        amount = d.get() * 30.78;
    }
	public NTD(JPY d){
        amount = d.get() * 0.23;
    }
	public double get(){
        return amount;
    }
	public void set(double a){
        amount = a;
    }
	// Complete the implementation of function printc().
	public void printc(){
        System.out.println("the exchange rate of 1 New Taiwan Dollar is equal to 0.032 US Dollar and 4.34 Japanese Yen");
    }

}

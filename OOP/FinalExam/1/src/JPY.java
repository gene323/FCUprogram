
public class JPY extends Currency {
	// Complete the implementation of the constructors.
	public JPY(double a){
        amount = a;
    }
	public JPY(USD d){
        amount = d.get() * 133.52;
    }
	public JPY(NTD d){
        amount = d.get() * 4.34;
    }
	public double get(){
        return amount;
    }
	public void set(double a){
        amount = a;
    }
	// Complete the implementation of function printc().
	public void printc(){
        System.out.println("the exchange rate of 1 Japanese Yen is equal to 0.0075 US Dollar and 0.23 New Taiwan Dollar.");
    }

}

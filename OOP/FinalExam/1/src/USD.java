
public class USD extends Currency {
	// Complete the implementation of the constructors.
	public USD(double a){
        this.amount = a;
    }
	public USD(NTD d){
        amount = d.get() * 0.032;
    }
	public USD(JPY d){
        amount = d.get() * 0.0075;
    }
	public double get(){
        return amount;
    }
	public void set(double a){
        amount = a;
    }
	// Complete the implementation of function printc().
	public void printc(){
        System.out.println("the exchange rate of 1 US Dollar is equal to 30.78 New Taiwan Dollar and 133.52 Japanese Yen");
    }

}

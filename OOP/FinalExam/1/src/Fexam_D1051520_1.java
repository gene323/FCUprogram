public class Fexam_D1051520_1 {

	public static void main(String[] args) {
		JPY j = new JPY(300000); // Concrete object of JPY. 
		NTD n = new NTD(j); // Concrete object of NTD.
		USD u1 = new USD(n); //exchange from NTD
        USD u2 = new USD(j); //exchange directly from JPY
  
        /*
    	The foreign exchange policy in Taiwan requires that any foreign currency 
	    exchange buying or selling must be via New Taiwan Dollar. 
        Suppose a person is going to buy US Dollar using 300,000 Japanese Yen. 
        Write a main function to compute his/her exchange gain/loss, 
        if he/she could directly buy US Dollar using Japanese Yen.
        */

        System.out.printf("If you directly buy US Dollar using Japanese Yen, you will get USD: %f\n", u2.get());
        System.out.printf("If you exchange from Japanese Yen to New Taiwan Dollar, then buy US Dollar using New Taiwan Dollar"
                + ", you will get USD: %f\n", u1.get());
        System.out.printf("\nyou loss %f\n", u2.get()-u1.get());
	}
}

import util.VendingMachine;

public class Main{
    public static void main(String[] args){
        VendingMachine vendingMachine = new VendingMachine();
        vendingMachine.select(VendingMachine.EVIAN_MINERAL_WATER);
        vendingMachine.show();
        System.out.print(VendingMachine.COCA_COLA.getPrice());
    }
}

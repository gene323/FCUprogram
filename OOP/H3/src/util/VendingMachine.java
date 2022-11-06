package VendingMachine.util;
import java.util.ArrayList;

public class VendingMachine{
    protected ArrayList<Product> shoppingCart;
    public final static Product COCA_COLA = new Product("Coca Cola", 1.65);
    public final static Product ORANGE_JUICE = new Product("Minute Maid Orange Juice", 3.50);
    public final static Product EVIAN_MINERAL_WATER = new Product("Evian Mineral Water", 2.80);

    public VendingMachine(){
        shoppingCart = new ArrayList<Product>();
    }

    public void select(Product product){
        shoppingCart.add(product);
    }
    public void show(){
        for(Product it: shoppingCart){
            System.out.println(it.getProdcutName());
        }
    }

    public static class Product{
        protected String productName;
        protected double price;
        public Product(String name, double price){
            this.productName = name;
            this.price = price;
        }

        public String getProdcutName(){
            return productName;
        }
        public double getPrice(){
            return price;
        }
    }
}

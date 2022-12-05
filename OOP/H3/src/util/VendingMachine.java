package util;
import java.util.ArrayList;

public class VendingMachine{
    protected ArrayList<Product> shoppingCart;
    private double money;
    public final static Product COCA_COLA = new Product("Coca Cola", 1.65);
    public final static Product ORANGE_JUICE = new Product("Minute Maid Orange Juice", 3.50);
    public final static Product EVIAN_MINERAL_WATER = new Product("Evian Mineral Water", 2.80);
    public final static Product MM_CHOCOLATE = new Product("M&M's Chocolate", 1.5); 
    public final static Product HERSHEY_CHOCOLATE_BAR = new Product("Hershey's Chocolate Bar", 1.85);
    public final static Product OREO_COOKIE = new Product("Oreo Cookies", 1.0);
    public final static Product DORITOS_TORTILLA_CHIP = new Product("Doritos Tortilla Chips", 3.25);
    public final static Product PRINGLES_POTATO_CHIP = new Product("Pringles Potato Chips", 3.4);
    public VendingMachine(){
        this.shoppingCart = new ArrayList<Product>();
        this.money = 0;
    }

    public void select(Product product){
        shoppingCart.add(product);
    }
    public void show(){
        for(Product it: shoppingCart){
            System.out.println(it.getName());
        }
    }
    public void depositMoney(double money){
        this.money += money;

    }
    public double getMoney(){
        return this.money;
    }

    public static class Product{
        protected String name;
        protected double price;
        public Product(String name, double price){
            this.name = name;
            this.price = price;
        }

        public String getName(){
            return name;
        }
        public double getPrice(){
            return price;
        }
    }
}

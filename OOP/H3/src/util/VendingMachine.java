package util;
import java.util.ArrayList;

public class VendingMachine{
    protected ArrayList<Product> shoppingCart;
    private double money;
    private double payment;

    public VendingMachine(){
        this.shoppingCart = new ArrayList<Product>();
        this.money = 0;
        this.shoppingCart.add(new Product("Coca Cola", 1.65));
        this.shoppingCart.add(new Product("Minute Maid Orange Juice", 3.50));
        this.shoppingCart.add(new Product("Evian Mineral Water", 2.80));
        this.shoppingCart.add(new Product("M&M's Chocolate", 1.5));
        this.shoppingCart.add(new Product("Hershey's Chocolate Bar", 1.85));
        this.shoppingCart.add(new Product("Oreo Cookies", 1.0));
        this.shoppingCart.add(new Product("Doritos Tortilla Chips", 3.25));
        this.shoppingCart.add(new Product("Pringles Potato Chips", 3.4));
    }

    public void select(Product product){
        product.setQuantity(product.getQuantity()+1);
        this.shoppingCart.set(this.shoppingCart.indexOf(product), product);
        this.payment += product.getPrice();
    }

    public void cancel(Product product){
        if(product.getQuantity() == 0)
            return ;

        product.setQuantity(product.getQuantity()-1);
        this.shoppingCart.set(this.shoppingCart.indexOf(product), product);
        this.payment -= product.getPrice();
    }

    public void purchase(){
        this.money -= this.payment;
        this.payment = 0;
        for(Product p: this.shoppingCart){
            if(p.getQuantity() != 0)
                System.out.printf("You get %d %s\n", p.getQuantity(), p);
            p.setQuantity(0);
        }
        System.out.printf("\nYour money: %.3f\n\n", this.money);
    }

    public String showShoppingCart(){
        String res = "";
        int i = 0;
        for(Product p: this.shoppingCart){
            res = String.format("%s%c: %-25s\tquantity: %d\n"
                    , res, i+'A', p, p.getQuantity());
            i++;
        }
        return res;
    }
    public ArrayList<Product> getShoppingCart(){
        return this.shoppingCart;
    }
    public void depositMoney(double money){
        this.money += money;

    }
    public double getMoney(){
        return this.money;
    }
    public double getPayment(){
        return this.payment;
    }
    public void setMoney(double money){
        this.money = money;
    }
    public String toString(){
        String res = "";
        int i = 0;
        for(Product p: this.shoppingCart){
            res = String.format("%s%c: %-25s\tprice: %.3f\n"
                    , res, i+'A', p, p.getPrice());
            i++;
        }
        return res;
    }

    public class Product{
        protected String name;
        protected double price;
        protected int quantity;
        public Product(String name, double price){
            this.name = name;
            this.price = price;
            this.quantity = 0;
        }
        public Product(String name, double price, int quantity){
            this.name = name;
            this.price = price;
            this.quantity = quantity;
        }

        public void setQuantity(int quantity){
            this.quantity = quantity;
        }

        public int getQuantity(){
            return this.quantity;
        }

        public double getPrice(){
            return this.price;
        }
        public String toString(){
            return this.name;
        }
    }
}

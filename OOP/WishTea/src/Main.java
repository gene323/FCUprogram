package WishTea;
import java.util.*;

public class Main{
    public static void main(String[] args){
        ArrayList<Tea> orders = new ArrayList<Tea>();
        Scanner sc = new Scanner(System.in);
        while(true){
            System.out.print("Please input your order,0 for fruit tea 1 for bubbletea:");
            int drink = sc.nextInt();
            System.out.print("Please input your order size,0 for small 1 for medium 2 for large:");
            int size = sc.nextInt();
            System.out.print("Please input your order ice,0 for none 1 for a little 2 for regular:");
            int ice = sc.nextInt();
            System.out.print("Please input your order topping,0 for none 1 for yes :");
            int topping = sc.nextInt();
            Tea t = new Tea(drink, size, ice, topping);
            orders.add(t);
            break;
        }
        orders.forEach((order) -> {
            System.out.printf("your cost is :%f", Tea.calcCost(order.getTeaName(), order.getSize(), order.getIce(), order.getTop()));
        });
        sc.close();
    }
}

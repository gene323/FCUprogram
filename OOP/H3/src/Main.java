import util.VendingMachine;
import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        VendingMachine vendingMachine = new VendingMachine();

        char op;
        do{
            System.out.print("a. Deposit bill(s) or coin(s),\n"
                            + "b. Select product(s),\n"
                            + "c. Cancel a product,\n"
                            + "d. Purchase product(s),\n"
                            + "e. Abort transaction.\n"
                            + "> "
            );
            op = sc.next().charAt(0);

            if(op == 'a'){
                char moneyType;
                do{
                    System.out.print("enter B for bill, C for coin, other letter to quti\n> ");
                    moneyType = sc.next().charAt(0);

                    if(moneyType == 'B'){
                        while(true){
                            System.out.print("enter 1, 5, 10, 20 dollars, 0 to quit\n> ");
                            double money = sc.nextDouble();
                            if(money == 1 || money == 5 || money == 10 || money == 20){
                                vendingMachine.depositMoney(money);
                            }
                            else if(money == 0)
                                break;
                            else{
                                System.out.println("wrong value");
                            }
                        }
                    }
                    else if(moneyType == 'C'){
                        while(true){
                            System.out.print("enter 5, 10, 25 cents, 0 to quit\n> ");
                            double money = sc.nextDouble();
                            if(money == 5 || money == 10 || money == 25){
                                vendingMachine.depositMoney(money);
                            }
                            else if(money == 0)
                                break;
                            else{
                                System.out.println("wrong value");
                            }
                        }
                    }
                } while(moneyType == 'B' || moneyType == 'C');
            }
            else if(op == 'b'){
                char productType;
                System.out.println(vendingMachine);
                do{
                    System.out.print("enter product code, Q to quit\n> ");
                    productType = sc.next().charAt(0);
                    int i = 0;
                    for(VendingMachine.Product p: vendingMachine.getShoppingCart()){
                        if(productType == (char)i + 'A'){
                            vendingMachine.select(p);
                            break;
                        }
                        i++;
                    }
                }while(productType != 'Q');
            }
            else if(op == 'c'){
                char productType;
                System.out.println(vendingMachine.showShoppingCart());
                do{
                    System.out.print("enter product code, Q to quit\n> ");
                    productType = sc.next().charAt(0);
                    int i = 0;
                    for(VendingMachine.Product p: vendingMachine.getShoppingCart()){
                        if(productType == (char)i + 'A'){
                            vendingMachine.cancel(p);
                            break;
                        }
                        i++;
                    }
                }while(productType != 'Q');
            }
            else if(op == 'd'){
                if(vendingMachine.getMoney() < vendingMachine.getPayment()){
                    System.out.printf("\nInsufficient Deposit\n"
                            + "Your money: %.3f, Payment: %.3f\n\n"
                            , vendingMachine.getMoney(), vendingMachine.getPayment());
                }
                else{
                    vendingMachine.purchase();
                }
            }

        }while(op != 'e');

        sc.close();
    }
}

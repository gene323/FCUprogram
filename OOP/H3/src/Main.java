import util.VendingMachine;
import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        VendingMachine vendingMachine = new VendingMachine();

        char op = '1';
        while(op != 'e'){
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
        }

        sc.close();
    }
}

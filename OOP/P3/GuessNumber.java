import java.util.Random;
import java.util.Scanner;

public class GuessNumber{
    public static void main(String[] args){
        Random random = new Random();
        Scanner sc = new Scanner(System.in);
        int answer = random.nextInt(1000) + 1;
        int guess = 0;
        int times = 0;

        while(guess != answer){
            System.out.print("Enter an interger between 1 and 1000: ");
            guess = sc.nextInt();

            if(guess < answer)
                System.out.printf("Your guess %d is too small. Try again.\n\n", guess);
            else
                System.out.printf("Your guess %d is too large. Try again.\n\n", guess);
            times++;
        }

        System.out.printf("Congratulations! Your guess %d is correct.\n", guess);
        System.out.printf("You guess %d times.\n", times);
        sc.close();
    }
}

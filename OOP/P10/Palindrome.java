import java.io.*;
import java.util.Scanner;

public class Palindrome{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print(">>>> Enter a String: ");
        String str = sc.nextLine();

        while(!str.equals("000")){
            boolean flag = true;
            int i = 0;
            int j = str.length() - 1;
            while(i < j){
                if(!Character.isLetter(str.charAt(i))){
                    i++;
                    continue;
                }
                if(!Character.isLetter(str.charAt(j))){
                    j--;
                    continue;
                }
                if(Character.toUpperCase(str.charAt(i)) !=  Character.toUpperCase(str.charAt(j))){
                    flag = false;
                    break;
                }
                i++;
                j--;
            }
            if(flag)
                System.out.print("**** Yes, it is a palindrome.\n");
            else
                System.out.print("**** Not, it is not a palindrome.\n");

            System.out.print(">>>> Enter a String: ");
            str = sc.nextLine();
        }


        try{
            final int SIGNLENGTH = 30;
            System.out.print(">>>> Enter file name: ");
            String fileName = sc.nextLine();
            File file = new File(fileName);
            BufferedInputStream bis = new BufferedInputStream(new FileInputStream(fileName));
            BufferedOutputStream bos = new BufferedOutputStream(new FileOutputStream("result.txt"));
            bis.mark(0);

            int englishChar = 0;
            int ch;
            String article = "";
            //count how many letters are in the file
            while((ch = bis.read()) != -1){
                if(Character.isLetter((char)ch)){
                    char uppercase = Character.toUpperCase((char)ch);
                    bos.write((int)uppercase);
                    article += uppercase;
                    englishChar++;
                }
            }

            System.out.printf("\n>>>> Text length: %d\n", file.length());
            System.out.printf("%s\n", "=".repeat(SIGNLENGTH));
            System.out.printf(">>>> File %s has been read.\n", file.getName());
            System.out.printf(">>>> The number of English characters in %s: %d\n", file.getName(), englishChar);
            System.out.printf(">>>> The first 500 English characters:\n");

            bis.reset();
            int stop = 0;
            //print the first 500 char in the file
            while((ch = bis.read()) != -1 && ++stop < 500){
                if(Character.isLetter((char)ch)){
                    char uppercase = Character.toUpperCase((char)ch);
                    System.out.print(uppercase);
                    //print new line in every 80 char
                    if(stop % 80 == 0){
                        System.out.print("\n");
                    }
                }
            }
            
            System.out.print("\n");
            System.out.printf("%s\n", "=".repeat(SIGNLENGTH));
            System.out.printf(">>>> File result.txt has been written.\n");
            System.out.printf("%s\n", "=".repeat(SIGNLENGTH));

            int i = 0;
            int j = article.length() - 1;
            boolean flag = true;
            while(i < j){
                if(article.charAt(i) != article.charAt(j)){
                    flag = false;
                    break;
                }
                i++; j--;
            }

            if(flag)
                System.out.printf("**** Yes, it is a palindrome. Final indices: i=%d, j=%d\n", i, j);
            else
                System.out.printf("**** No, it is not a palindrome.\n");

            bis.close();
            bos.close();
        } catch(Exception e){
            System.out.println(e);
        }
            
        sc.close();
    }
}

import java.io.*;
import java.util.Scanner;

public class hello{
    public static void main(String[] args){
        try{
            File obj = new File("./0913.txt");
            Scanner reader = new Scanner(obj);
            while(reader.hasNextLine()){
                String str = reader.nextLine();
                System.out.println(str);
            }
            reader.close();
        } catch(FileNotFoundException e){
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }
}

package BigHexInteger;
import java.util.*;
import java.math.*;
import BigHexInteger.*;

public class BigHexIntegerAPP{
    public static void main(String[] args){
        BigInteger[] bigIntArr = new BigInteger[6];
        bigIntArr[0] = new BigInteger("121");
        bigIntArr[1] = new BigHexInteger("-12");
        bigIntArr[2] = new BigInteger("-23");
        bigIntArr[3] = new BigHexInteger("FF");
        bigIntArr[4] = new BigInteger("45");
        bigIntArr[5] = new BigHexInteger("3A");

        BigInteger sumOfDec = new BigInteger("0"); 
        for(BigInteger it: bigIntArr){
            sumOfDec = sumOfDec.add(it);
        }

        BigHexInteger sumOfHex = new BigHexInteger(sumOfDec.toString(16));

        for(int i=0; i<bigIntArr.length; i++){
            System.out.printf("bi[%d] = %s (%s)\n", i, bigIntArr[i].toString(), bigIntArr[i].getClass().getSimpleName());
        }
        System.out.print("\n\n");
        System.out.println("Sum of BigInteger = " + sumOfDec);
        System.out.println("Sum of BigHexInteger = " + sumOfHex);
    }
}

package BigHexInteger;
import java.math.BigInteger;

public class BigHexInteger extends BigInteger{
    public BigHexInteger(String val){
        super(val, 16);
    }
    
    public BigHexInteger add(BigHexInteger val){
        BigHexInteger res = new BigHexInteger(super.add(val).toString());
        return res;
    }

    @Override
    public String toString(){
        return super.toString(16).toUpperCase();
    }
}

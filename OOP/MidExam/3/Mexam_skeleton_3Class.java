import java.math.BigInteger;

public class Mexam_skeleton_3Class extends BigInteger{

    public Mexam_skeleton_3Class(String val) {
        super(val, 16);
    }

    public Mexam_skeleton_3Class add(Mexam_skeleton_3Class val){
        Mexam_skeleton_3Class res = new Mexam_skeleton_3Class(super.add(val).toString());
        return res;
    }

    public String toString(){
        return super.toString(16).toUpperCase();
    }
}

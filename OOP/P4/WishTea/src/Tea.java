package WishTea;
class Tea{
    private int teaname;
    private int size;
    private int ice;
    private int topping;
    public int getTeaName(){
        return this.teaname;
    }
    public int getSize(){
        return this.size;
    }
    public int getIce(){
        return this.ice;
    }
    public int getTop(){
        return this.topping;
    }
    public void setTeaName(int teaname){
        this.teaname = teaname;
    }
    public void setSize(int size){
        this.size = size;
    }
    public void setIce(int ice){
        this.ice = ice;
    }
    public void setTop(int topping){
        this.topping = topping;
    }
    public static double calcCost(int name, int size, int ice, int topping){
        double cost=0;
        switch(name){
            case 0:
            switch(size){
                case 0:
                cost+=60;
                break;
                case 1:
                cost+=80;
                break;
                case 2:
                cost+=90;
                if(topping==1){
                    cost+=5;
                }
            }
            case 1:
            switch(size){
                case 0:
                cost+=40;
                break;
                case 1:
                cost+=50;
                break;
                case 2:
                cost+=60;
                if(topping==1){
                    cost+=10;
                }
            }
        }
        return cost;
    }
    public Tea(int teaname, int size, int ice, int topping){
        this.teaname = teaname;
        this.size = size;
        this.ice = ice;
        this.topping = topping;
    }
}

package util;

interface Matrix<T, Ex extends Throwable>{
    public T addition(T a);
    public T subtraction(T a);
    public T multiplication(T a);
    public T transposition();
    public void compare(T a) throws Ex;
    public void compareMultiply(int ra, int cb) throws Ex;
}
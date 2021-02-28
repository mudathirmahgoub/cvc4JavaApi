package cvc4;

public class Solver
{
    public native void setLogic(String logic);

    public native Sort getRealSort();

    public native Sort getIntegerSort();

    public native Term mkConst(Sort sort, String symbol);

    public native Term mkInteger(int val);

    public native Term mkReal(int num, int den);
}

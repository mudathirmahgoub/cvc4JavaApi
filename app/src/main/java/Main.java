import cvc4.Solver;
import cvc4.Sort;
import cvc4.Term;

public class Main
{
    public static void main(String args[])
    {
        System.out.println("Hello world");
        Solver slv = new Solver();
        slv.setLogic("QF_LIRA"); // set the logic

        // Prove that if given x (Integer) and y (Real) then
        // the maximum value of y - x is 2/3

        Sort real = slv.getRealSort();
        Sort integer = slv.getIntegerSort();

        // Variables
        Term x = slv.mkConst(integer, "x");
        Term y = slv.mkConst(real, "y");

        // Constants
        Term three = slv.mkInteger(3);
        Term neg2 = slv.mkInteger(-2);
        Term two_thirds = slv.mkReal(2, 3);
    }

    static
    {
        System.loadLibrary("cvc4JavaApi");
    }
}

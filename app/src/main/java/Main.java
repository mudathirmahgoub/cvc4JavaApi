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
    System.out.println(real);
    Sort integer = slv.getIntegerSort();
    System.out.println(integer);
    // Variables
    Term x = slv.mkConst(integer, "x");
    System.out.println(x);
    Term y = slv.mkConst(real, "y");
    System.out.println(y);

    //slv.checkSat();
  }

  static
  {
    System.loadLibrary("cvc4JavaApi");
  }
}

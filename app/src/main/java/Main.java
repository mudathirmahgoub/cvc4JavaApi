import cvc4.Result;
import cvc4.Solver;
import cvc4.Sort;
import cvc4.Term;

public class Main
{
  public static void main(String args[])
  {
    Solver slv = new Solver();
    slv.setLogic("QF_LIRA"); // set the logic

    // Prove that if given x (Integer) and y (Real) then
    // the maximum value of y - x is 2/3

    // Sorts
    Sort real = slv.getRealSort();
    Sort integer = slv.getIntegerSort();

    // Variables
    Term x = slv.mkConst(integer, "x");
    Term y = slv.mkConst(real, "y");

    // Constants
    Term three = slv.mkInteger(3);
    Term neg2 = slv.mkInteger(-2);
    Term two_thirds = slv.mkReal(2, 3);

    // Terms
//    Term three_y = slv.mkTerm(MULT, three, y);
//    Term diff = slv.mkTerm(MINUS, y, x);
//
//    // Formulas
//    Term x_geq_3y = slv.mkTerm(GEQ, x, three_y);
//    Term x_leq_y = slv.mkTerm(LEQ, x, y);
//    Term neg2_lt_x = slv.mkTerm(LT, neg2, x);

    Result result = slv.checkSat();
    System.out.println(result.toString());
  }

  static
  {
    System.loadLibrary("cvc4JavaApi");
  }
}

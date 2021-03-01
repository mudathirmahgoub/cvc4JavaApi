import static cvc4.Kind.*;

import cvc4.*;

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
    Term three_y = slv.mkTerm(MULT, three, y);
    Term diff = slv.mkTerm(MINUS, y, x);

    // Formulas
    Term x_geq_3y = slv.mkTerm(GEQ, x, three_y);
    Term x_leq_y = slv.mkTerm(LEQ, x, y);
    Term neg2_lt_x = slv.mkTerm(LT, neg2, x);

    Term assertions = slv.mkTerm(AND, x_geq_3y, x_leq_y, neg2_lt_x);

    System.out.println("Given the assertions " + assertions);
    slv.assertFormula(assertions);

    slv.push();

    Term diff_leq_two_thirds = slv.mkTerm(LEQ, diff, two_thirds);
    System.out.println("Prove that " + diff_leq_two_thirds + " with CVC4.");
    System.out.println("CVC4 should report ENTAILED.");
    System.out.println("Result from CVC4 is: " + slv.checkEntailed(diff_leq_two_thirds));

    slv.pop();

    System.out.println();

    slv.push();
    Term diff_is_two_thirds = slv.mkTerm(EQUAL, diff, two_thirds);
    slv.assertFormula(diff_is_two_thirds);
    System.out.println("Show that the assertions are consistent with ");
    System.out.println(diff_is_two_thirds + " with CVC4.");
    System.out.println("CVC4 should report SAT.");
    System.out.println("Result from CVC4 is: " + slv.checkSat());
    slv.pop();

    System.out.println("Thus the maximum value of (y - x) is 2/3.");
  }

  static
  {
    System.loadLibrary("cvc4JavaApi");
  }
}

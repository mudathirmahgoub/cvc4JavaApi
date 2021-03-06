package cvc;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class SolverTest
{
  private Solver d_solver;

  @BeforeEach void setUp()
  {
    d_solver = new Solver();
  }

  @AfterEach void tearDown()
  {
    d_solver.deleteSolver();
  }

  @Test void deleteSolver() {}

  @Test void recoverableException() throws CVCApiException
  {
    d_solver.setOption("produce-models", "true");
    Term x = d_solver.mkConst(d_solver.getBooleanSort(), "x");
    d_solver.assertFormula(x.eqTerm(x).notTerm());
    assertThrows(CVCApiRecoverableException.class, () -> d_solver.getValue(x));
  }

  @Test void setLogic() throws CVCApiException
  {
    assertDoesNotThrow(() -> d_solver.setLogic("AUFLIRA"));
    assertThrows(CVCApiException.class, () -> d_solver.setLogic("AF_BV"));
    d_solver.assertFormula(d_solver.mkTrue());
    assertThrows(CVCApiException.class, () -> d_solver.setLogic("AUFLIRA"));
  }

  @Test void getRealSort() {}

  @Test void getIntegerSort() {}

  @Test void testGetIntegerSort() {}

  @Test void mkConst() {}

  @Test void mkInteger() {}

  @Test void mkReal() {}

  @Test void checkSat() {}

  @Test void mkTerm() {}

  @Test void testMkTerm() {}

  @Test void assertFormula() {}

  @Test void push() {}

  @Test void testPush() {}

  @Test void checkEntailed() {}

  @Test void pop() {}

  @Test void testPop() {}
}
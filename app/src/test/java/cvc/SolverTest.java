package cvc;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class SolverTest
{
  private Solver solver;

  @BeforeEach void setUp()
  {
    solver = new Solver();
  }

  @AfterEach void tearDown()
  {
    solver.deleteSolver();
  }

  @Test void deleteSolver() {}

  @Test void setLogic() throws CVCApiException
  {
    assertDoesNotThrow(() -> solver.setLogic("AUFLIRA"));
    assertThrows(CVCApiException.class, () -> solver.setLogic("AF_BV"));
    solver.assertFormula(solver.mkTrue());
    assertThrows(CVCApiException.class, () -> solver.setLogic("AUFLIRA"));
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
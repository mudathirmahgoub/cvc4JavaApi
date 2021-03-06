package cvc;

import static cvc.RoundingMode.*;
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

  @Test void supportsFloatingPoint() throws CVCApiException
  {
    if (d_solver.supportsFloatingPoint())
    {
      assertDoesNotThrow(() -> d_solver.mkRoundingMode(ROUND_NEAREST_TIES_TO_EVEN));
    }
    else
    {
      assertThrows(
          CVCApiException.class, () -> d_solver.mkRoundingMode(ROUND_NEAREST_TIES_TO_EVEN));
    }
  }

  @Test void getBooleanSort()
  {
    assertDoesNotThrow(() -> d_solver.getBooleanSort());
  }

  @Test void getIntegerSort()
  {
    assertDoesNotThrow(() -> d_solver.getIntegerSort());
  }

  @Test void getNullSort()
  {
    assertDoesNotThrow(() -> d_solver.getNullSort());
  }

  @Test void getRealSort()
  {
    assertDoesNotThrow(() -> d_solver.getRealSort());
  }

  @Test void getRegExpSort()
  {
    assertDoesNotThrow(() -> d_solver.getRegExpSort());
  }

  @Test void getStringSort()
  {
    assertDoesNotThrow(() -> d_solver.getStringSort());
  }

  @Test void getRoundingModeSort()
  {
    if (d_solver.supportsFloatingPoint())
    {
      assertDoesNotThrow(() -> d_solver.getRoundingModeSort());
    }
    else
    {
      assertThrows(CVCApiException.class, () -> d_solver.getRoundingModeSort());
    }
  }

  @Test void mkArraySort() throws CVCApiException
  {
    Sort boolSort = d_solver.getBooleanSort();
    Sort intSort = d_solver.getIntegerSort();
    Sort realSort = d_solver.getRealSort();
    Sort bvSort = d_solver.mkBitVectorSort(32);
    assertDoesNotThrow(() -> d_solver.mkArraySort(boolSort, boolSort));
    assertDoesNotThrow(() -> d_solver.mkArraySort(intSort, intSort));
    assertDoesNotThrow(() -> d_solver.mkArraySort(realSort, realSort));
    assertDoesNotThrow(() -> d_solver.mkArraySort(bvSort, bvSort));
    assertDoesNotThrow(() -> d_solver.mkArraySort(boolSort, intSort));
    assertDoesNotThrow(() -> d_solver.mkArraySort(realSort, bvSort));

    if (d_solver.supportsFloatingPoint())
    {
      Sort fpSort = d_solver.mkFloatingPointSort(3, 5);
      assertDoesNotThrow(() -> d_solver.mkArraySort(fpSort, fpSort));
      assertDoesNotThrow(() -> d_solver.mkArraySort(bvSort, fpSort));
    }

    Solver slv = new Solver();
    assertThrows(CVCApiException.class, () -> slv.mkArraySort(boolSort, boolSort));
  }

  @Test void mkBitVectorSort() throws CVCApiException
  {
    assertDoesNotThrow(() -> d_solver.mkBitVectorSort(32));
    assertThrows(CVCApiException.class, () -> d_solver.mkBitVectorSort(0));
    assertThrows(CVCApiException.class, () -> d_solver.mkBitVectorSort(-5));
  }

  @Test void setLogic() throws CVCApiException
  {
    assertDoesNotThrow(() -> d_solver.setLogic("AUFLIRA"));
    assertThrows(CVCApiException.class, () -> d_solver.setLogic("AF_BV"));
    d_solver.assertFormula(d_solver.mkTrue());
    assertThrows(CVCApiException.class, () -> d_solver.setLogic("AUFLIRA"));
  }

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
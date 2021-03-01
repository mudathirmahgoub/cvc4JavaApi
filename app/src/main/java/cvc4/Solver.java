package cvc4;

import java.util.ArrayList;
import java.util.List;

public class Solver implements AutoCloseable
{
  private long solverPointer;

  static
  {
    String path = Solver.class.getClassLoader().getResource("libcvc4.so").toExternalForm();
    System.setProperty("java.library.path", "../../src/main/resources");
    System.loadLibrary("cvc4JavaApi");
  }

  public Solver()
  {
    solverPointer = newSolver();
  }

  private native long newSolver();

  public void deleteSolver()
  {
    deleteSolver(solverPointer);
  }

  private native void deleteSolver(long solverPointer);

  @Override public void close() throws Exception
  {
    deleteSolver();
  }

  public void setLogic(String logic)
  {
    setLogic(solverPointer, logic);
  }

  private native void setLogic(long solverPointer, String logic);

  public Sort getRealSort()
  {
    long sortPointer = getRealSort(solverPointer);
    return new Sort(this, sortPointer);
  }

  private native long getRealSort(long solverPointer);

  public Sort getIntegerSort()
  {
    long sortPointer = getIntegerSort(solverPointer);
    return new Sort(this, sortPointer);
  }

  public native long getIntegerSort(long solverPointer);

  public Term mkConst(Sort sort, String symbol)
  {
    long termPointer = mkConst(solverPointer, sort.getPointer(), symbol);
    return new Term(this, termPointer);
  }

  private native long mkConst(long solverPointer, long sortPointer, String symbol);

  public Term mkInteger(int val)
  {
    long termPointer = mkInteger(solverPointer, val);
    return new Term(this, termPointer);
  }

  private native long mkInteger(long solverPointer, int val);

  public Term mkReal(int num, int den)
  {
    long termPointer = mkReal(solverPointer, num, den);
    return new Term(this, termPointer);
  }

  private native long mkReal(long solverPointer, int num, int den);

  public Result checkSat()
  {
    long resultPointer = checkSat(solverPointer);
    return new Result(this, resultPointer);
  }

  public Term mkTerm(Kind kind, Term child1, Term child2)
  {
    long termPointer =
        mkTerm(solverPointer, kind.getValue(), child1.getPointer(), child2.getPointer());
    return new Term(this, termPointer);
  }

  private native long mkTerm(long solverPointer, int kind, long child1Pointer, long child2Pointer);

  public Term mkTerm(Kind kind, Term child1, Term child2, Term child3)
  {
    long termPointer = mkTerm(solverPointer,
        kind.getValue(),
        child1.getPointer(),
        child2.getPointer(),
        child3.getPointer());
    return new Term(this, termPointer);
  }

  private native long mkTerm(
      long solverPointer, int kind, long child1Pointer, long child2Pointer, long child3Pointer);

  private native long checkSat(long solverPointer);

  public void assertFormula(Term term)
  {
    assertFormula(solverPointer, term.getPointer());
  }

  private native void assertFormula(long solverPointer, long termPointer);

  public void push()
  {
    push(solverPointer, 1);
  }

  public void push(int nscopes)
  {
    push(solverPointer, nscopes);
  }

  private native void push(long solverPointer, int nscopes);

  public Result checkEntailed(Term term)
  {
    long resultPointer = checkEntailed(solverPointer, term.getPointer());
    return new Result(this, resultPointer);
  }

  private native long checkEntailed(long solverPointer, long termPointer);

  public void pop()
  {
    pop(solverPointer, 1);
  }

  public void pop(int nscopes)
  {
    pop(solverPointer, nscopes);
  }

  private native void pop(long solverPointer, int nscopes);
}

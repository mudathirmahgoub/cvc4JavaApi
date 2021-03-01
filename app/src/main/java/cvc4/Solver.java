package cvc4;

public class Solver
{
  private long solverPointer;

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

  public void setLogic(String logic)
  {
    setLogic(solverPointer, logic);
  }

  private native void setLogic(long solverPointer, String logic);

  public Sort getRealSort()
  {
    long sortPointer = getRealSort(solverPointer);
    return new Sort(sortPointer);
  }

  private native long getRealSort(long solverPointer);

  public Sort getIntegerSort()
  {
    long sortPointer = getIntegerSort(solverPointer);
    return new Sort(sortPointer);
  }

  public native long getIntegerSort(long solverPointer);

  public Term mkConst(Sort sort, String symbol)
  {
    long termPointer = mkConst(solverPointer, sort.getPointer(), symbol);
    return new Term(solverPointer, termPointer);
  }

  private native long mkConst(long solverPointer, long sortPointer, String symbol);

  public Term mkInteger(int val)
  {
    long termPointer = mkInteger(solverPointer, val);
    return new Term(solverPointer, termPointer);
  }

  private native long mkInteger(long solverPointer, int val);

  public Term mkReal(int num, int den)
  {
    long termPointer = mkReal(solverPointer, num, den);
    return new Term(solverPointer, termPointer);
  }

  private native long mkReal(long solverPointer, int num, int den);

  public Result checkSat()
  {
    long resultPointer = checkSat(solverPointer);
    return new Result(solverPointer, resultPointer);
  }

  private native long checkSat(long solverPointer);
}

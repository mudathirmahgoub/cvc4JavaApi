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
    return new Term(termPointer);
  }
  private native long mkConst(long solverPointer, long sortPointer, String symbol);

  public native Term mkInteger(int val);

  public native Term mkReal(int num, int den);
}

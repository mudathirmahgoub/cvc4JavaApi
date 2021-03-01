package cvc4;

public class Result
{
  private Solver solver;
  private long resultPointer;

  Result(Solver solver, long resultPointer)
  {
    this.solver = solver;
    this.resultPointer = resultPointer;
    solver.addResult(this);
  }

  public void deleteResult()
  {
    deleteResult(resultPointer);
  }

  private native void deleteResult(long resultPointer);

  public long getPointer()
  {
    return resultPointer;
  }

  @Override public String toString()
  {
    return toString(resultPointer);
  }

  private native String toString(long resultPointer);
}

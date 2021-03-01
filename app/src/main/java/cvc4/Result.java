package cvc4;

public class Result
{
  private Solver solver;
  private long resultPointer;

  Result(Solver solverPointer, long resultPointer)
  {
    this.solver = solver;
    this.resultPointer = resultPointer;
  }

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

package cvc4;

public class Result
{
  private long solverPointer;
  private long resultPointer;

  Result(long solverPointer, long resultPointer)
  {
    this.solverPointer = solverPointer;
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

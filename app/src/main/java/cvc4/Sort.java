package cvc4;

public class Sort
{
  private long solverPointer;
  private long sortPointer;

  Sort(long solverPointer, long sortPointer)
  {
    this.sortPointer = solverPointer;
    this.sortPointer = sortPointer;
  }

  public long getPointer()
  {
    return sortPointer;
  }

  @Override public String toString()
  {
    return toString(sortPointer);
  }

  private native String toString(long sortPointer);
}

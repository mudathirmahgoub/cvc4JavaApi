package cvc4;

public class Sort
{
  private Solver solver;
  private long sortPointer;

  Sort(Solver solver, long sortPointer)
  {
    this.solver = solver;
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

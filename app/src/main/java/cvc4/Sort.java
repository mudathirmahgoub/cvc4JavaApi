package cvc4;

public class Sort
{
  private Solver solver;
  private long sortPointer;

  Sort(Solver solver, long sortPointer)
  {
    this.solver = solver;
    this.sortPointer = sortPointer;
    solver.addSort(this);
  }

  public void deleteSort()
  {
    deleteSort(sortPointer);
  }

  private native void deleteSort(long sortPointer);

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

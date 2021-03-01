package cvc4;

public class Sort implements AutoCloseable
{
  private Solver solver;
  private long sortPointer;

  Sort(Solver solver, long sortPointer)
  {
    this.solver = solver;
    this.sortPointer = sortPointer;
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

  @Override public void close() throws Exception
  {
    deleteSort();
  }
}

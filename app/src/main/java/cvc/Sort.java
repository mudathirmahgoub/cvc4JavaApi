package cvc;

public class Sort implements IPointer
{
  private Solver solver;
  private long pointer;

  Sort(Solver solver, long pointer)
  {
    this.solver = solver;
    this.pointer = pointer;
    solver.addSort(this);
  }

  public void deletePointer()
  {
    deletePointer(pointer);
  }

  private native void deletePointer(long pointer);

  @Override
  public void finalize()
  {
    System.out.println("Finalizing sort: " + toString());
  }

  public long getPointer()
  {
    return pointer;
  }

  @Override public String toString()
  {
    return toString(pointer);
  }

  private native String toString(long sortPointer);
}

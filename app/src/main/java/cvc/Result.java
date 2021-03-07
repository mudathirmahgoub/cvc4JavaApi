package cvc;

public class Result implements IPointer
{
  private Solver solver;
  private long pointer;

  Result(Solver solver, long pointer)
  {
    this.solver = solver;
    this.pointer = pointer;
    solver.addResult(this);
  }

  public void deletePointer()
  {
    deletePointer(pointer);
  }

  private native void deletePointer(long pointer);

  public long getPointer()
  {
    return pointer;
  }

  @Override
  public void finalize()
  {
    System.out.println("Finalizing result: " + toString());
  }

  @Override public String toString()
  {
    return toString(pointer);
  }

  private native String toString(long resultPointer);
}

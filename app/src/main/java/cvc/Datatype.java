package cvc;

public class Datatype implements IPointer
{
  private Solver solver;
  private long pointer;

  Datatype(Solver solver, long pointer)
  {
    this.solver = solver;
    this.pointer = pointer;
  }

  public void deletePointer()
  {
    deletePointer(pointer);
  }

  private native void deletePointer(long pointer);

  @Override public void finalize()
  {
    System.out.println("Finalizing datatype: " + toString());
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

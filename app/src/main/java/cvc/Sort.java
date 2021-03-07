package cvc;

public class Sort extends AbstractPointer
{
  Sort(Solver solver, long pointer)
  {
    super(solver, pointer);
  }

  protected native void deletePointer(long pointer);

  protected native String toString(long pointer);

  /**
   * @return the underlying datatype of a datatype sort
   */
  public Datatype getDatatype()
  {
    long datatypePointer = getDatatype(pointer);
    return new Datatype(solver, datatypePointer);
  }

  private native long getDatatype(long pointer);
}

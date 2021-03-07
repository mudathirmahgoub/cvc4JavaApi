package cvc;

abstract public class AbstractPointer implements IPointer
{
  protected Solver solver;
  protected long pointer;

  public void deletePointer()
  {
    deletePointer(pointer);
  }

  abstract protected void deletePointer(long pointer);

  @Override public void finalize()
  {
    deletePointer();
  }

  public long getPointer()
  {
    return pointer;
  }

  @Override public String toString()
  {
    return toString(pointer);
  }

  abstract protected String toString(long pointer);

  AbstractPointer(Solver solver, long pointer)
  {
    this.solver = solver;
    this.pointer = pointer;
  }
}

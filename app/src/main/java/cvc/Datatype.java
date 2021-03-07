package cvc;

public class Datatype extends AbstractPointer
{
  Datatype(Solver solver, long pointer)
  {
    super(solver, pointer);
  }

  protected native void deletePointer(long pointer);

  protected native String toString(long pointer);
}

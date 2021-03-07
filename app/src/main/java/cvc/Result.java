package cvc;

public class Result extends AbstractPointer
{
  Result(Solver solver, long pointer)
  {
    super(solver, pointer);
  }

  protected native void deletePointer(long pointer);

  protected native String toString(long pointer);
}

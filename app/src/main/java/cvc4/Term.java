package cvc4;

public class Term implements AutoCloseable
{
  private Solver solver;
  private long termPointer;

  Term(Solver solver, long termPointer)
  {
    this.solver = solver;
    this.termPointer = termPointer;
  }

  public void deleteTerm()
  {
    deleteTerm(termPointer);
  }

  private native void deleteTerm(long termPointer);

  public long getPointer()
  {
    return termPointer;
  }

  @Override public String toString()
  {
    return toString(termPointer);
  }

  private native String toString(long termPointer);

  @Override public void close() throws Exception
  {
      deleteTerm();
  }
}

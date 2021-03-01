package cvc4;

public class Term
{
  private Solver solver;
  private long termPointer;

  Term(Solver solver, long termPointer)
  {
    this.solver = solver;
    this.termPointer = termPointer;
  }

  public long getPointer()
  {
    return termPointer;
  }

  @Override public String toString()
  {
    return toString(termPointer);
  }

  private native String toString(long termPointer);
}

package cvc;

public class Term
{
  private Solver solver;
  private long termPointer;

  Term(Solver solver, long termPointer)
  {
    this.solver = solver;
    this.termPointer = termPointer;
    solver.addTerm(this);
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
}

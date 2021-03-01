package cvc4;

public class Term
{
  private long solverPointer;
  private long termPointer;

  Term(long solverPointer, long termPointer)
  {
    this.solverPointer = solverPointer;
    this.termPointer = termPointer;
  }

  public long getPointer()
  {
    return termPointer;
  }

  @Override public String toString()
  {
    return "Term{"
        + "termPointer=" + termPointer + '}';
  }
}

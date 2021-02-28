package cvc4;

public class Term
{
  private long termPointer;

  Term(long sortPointer)
  {
    this.termPointer = sortPointer;
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

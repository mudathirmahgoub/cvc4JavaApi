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

  /**
   * Equality.
   * @param t a Boolean term
   * @return the Boolean equivalence of this term and the given term
   */
  public Term eqTerm(Term t) throws CVCApiException
  {
    long pointer = eqTerm(this.termPointer, t.termPointer);
    return new Term(solver, pointer);
  }

  private native long eqTerm(long termPointer, long tPointer) throws CVCApiException;

  /**
   * Boolean negation.
   * @return the Boolean negation of this term
   */
  public Term notTerm() throws CVCApiException
  {
    long pointer = notTerm(this.termPointer);
    return new Term(solver, pointer);
  }

  private native long notTerm(long termPointer) throws CVCApiException;
}

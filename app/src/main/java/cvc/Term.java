package cvc;

public class Term extends AbstractPointer
{
  Term(Solver solver, long pointer)
  {
    super(solver, pointer);
  }

  protected native void deletePointer(long pointer);

  protected native String toString(long pointer);

  /**
   * Equality.
   * @param t a Boolean term
   * @return the Boolean equivalence of this term and the given term
   */
  public Term eqTerm(Term t) throws CVCApiException
  {
    long pointer = eqTerm(this.pointer, t.pointer);
    return new Term(solver, pointer);
  }

  private native long eqTerm(long termPointer, long tPointer) throws CVCApiException;

  /**
   * Boolean negation.
   * @return the Boolean negation of this term
   */
  public Term notTerm() throws CVCApiException
  {
    long pointer = notTerm(this.pointer);
    return new Term(solver, pointer);
  }

  private native long notTerm(long termPointer) throws CVCApiException;
}

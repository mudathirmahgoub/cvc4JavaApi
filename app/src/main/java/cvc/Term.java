package cvc;

public class Term implements IPointer
{
  private Solver solver;
  private long pointer;

  Term(Solver solver, long pointer)
  {
    this.solver = solver;
    this.pointer = pointer;
    solver.addTerm(this);
  }

  public void deletePointer()
  {
    deletePointer(pointer);
  }

  private native void deletePointer(long pointer);

  public long getPointer()
  {
    return pointer;
  }

  @Override public String toString()
  {
    return toString(pointer);
  }

  private native String toString(long termPointer);

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

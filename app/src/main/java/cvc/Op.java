package cvc;

public class Op extends AbstractPointer
{
  Op(Solver solver, long pointer)
  {
    super(solver, pointer);
  }

  protected native void deletePointer(long pointer);

  protected native String toString(long pointer);

  /**
   * Syntactic equality operator.
   * Return true if both operators are syntactically identical.
   * Both operators must belong to the same solver object.
   *
   * @param op the operator to compare to for equality
   * @return true if the operators are equal
   */
  @Override public boolean equals(Object op)
  {
    if (this == op)
      return true;
    if (op == null || getClass() != op.getClass())
      return false;
    return equals(pointer, ((Op) op).pointer);
  }

  private native boolean equals(long pointer1, long pointer2);

  /**
   * @return the kind of this operator
   */
  public Kind getKind() throws CVCApiException
  {
    int kind = getKind(pointer);
    return Kind.fromInt(kind);
  }

  private native int getKind(long pointer);

  /**
   * @return true if this operator is a null term
   */
  boolean isNull()
  {
    return isNull(pointer);
  }

  private native boolean isNull(long pointer);

  /**
   * @return true iff this operator is indexed
   */
  boolean isIndexed()
  {
    return isIndexed(pointer);
  }

  private native boolean isIndexed(long pointer);

  /**
   * Get the indices used to create this Op.
   * Check the Op Kind with getKind() to determine which argument to use.
   *
   * @return the index used to create this Op
   */
  public int getIntegerIndex()
  {
    return getIntegerIndex(pointer);
  }

  private native int getIntegerIndex(long pointer);

  /**
   * Get the indices used to create this Op.
   * Check the Op Kind with getKind() to determine which argument to use.
   *
   * @return the indices used to create this Op
   */
  public String getStringIndices()
  {
    return getStringIndices(pointer);
  }

  private native String getStringIndices(long pointer);

  /**
   * Get the indices used to create this Op.
   * Check the Op Kind with getKind() to determine which argument to use.
   *
   * @return the indices used to create this Op
   */
  public Pair<Integer, Integer> getIntegerPairIndices()
  {
    int[] pair = getIntegerPairIndices(pointer);
    // invariant getIntegerPairIndices returns two integers
    return new Pair<>(pair[0], pair[1]);
  }

  private native int[] getIntegerPairIndices(long pointer);
}

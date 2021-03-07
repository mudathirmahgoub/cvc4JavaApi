package cvc;

public class DatatypeConstructorDecl implements IPointer
{
  private Solver solver;
  private long pointer;

  DatatypeConstructorDecl(Solver solver, long pointer)
  {
    this.solver = solver;
    this.pointer = pointer;
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

  private native String toString(long datatypeDeclPointer);

  /**
   * Add datatype selector declaration.
   * @param name the name of the datatype selector declaration to add
   * @param sort the range sort of the datatype selector declaration to add
   */
  public void addSelector(String name, Sort sort)
  {
    addSelector(pointer, name, sort.getPointer());
  }

  private native void addSelector(long pointer, String name, long sortPointer);
}

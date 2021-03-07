package cvc;

public class DatatypeConstructorDecl extends AbstractPointer
{
  DatatypeConstructorDecl(Solver solver, long pointer)
  {
    super(solver, pointer);
  }

  protected native void deletePointer(long pointer);

  protected native String toString(long pointer);

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

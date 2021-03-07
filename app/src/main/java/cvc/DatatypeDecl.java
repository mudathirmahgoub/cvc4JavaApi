package cvc;

public class DatatypeDecl extends AbstractPointer
{
  DatatypeDecl(Solver solver, long pointer)
  {
    super(solver, pointer);
  }

  protected native void deletePointer(long pointer);

  protected native String toString(long pointer);

  /**
   * Add datatype constructor declaration.
   * @param ctor the datatype constructor declaration to add
   */
  public void addConstructor(DatatypeConstructorDecl ctor)
  {
    addConstructor(pointer, ctor.getPointer());
  }

  private native void addConstructor(long pointer, long datatypeConstructorDeclPointer);
}

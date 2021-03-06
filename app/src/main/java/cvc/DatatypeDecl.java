package cvc;

public class DatatypeDecl
{
  private Solver solver;
  private long pointer;

  DatatypeDecl(Solver solver, long pointer)
  {
    this.solver = solver;
    this.pointer = pointer;
    solver.addDatatypeDecl(this);
  }

  public void deletePointer()
  {
    deletePointer(pointer);
  }

  private native void deletePointer(long datatypeDeclPointer);

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
   * Add datatype constructor declaration.
   * @param ctor the datatype constructor declaration to add
   */
  public void addConstructor(DatatypeConstructorDecl ctor)
  {
    addConstructor(pointer, ctor.getPointer());
  }

  private native void addConstructor(long pointer, long datatypeConstructorDeclPointer);
}

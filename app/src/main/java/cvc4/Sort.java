package cvc4;

public class Sort
{
  private long sortPointer;
  Sort(long sortPointer)
  {
    this.sortPointer = sortPointer;
  }

  @Override public String toString()
  {
    return "Sort{"
        + "sortPointer=" + sortPointer + '}';
  }
}

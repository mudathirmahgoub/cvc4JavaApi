package cvc;

import java.util.List;

public class Utils
{
  public static long[] getPointers(IPointer[] objects)
  {
    long[] pointers = new long[objects.length];
    for (int i = 0; i < pointers.length; i++)
    {
      pointers[i] = objects[i].getPointer();
    }
    return pointers;
  }

  public static Sort[] getSorts(Solver solver, long[] pointers)
  {
    Sort[] sorts = new Sort[pointers.length];
    for (int i = 0; i < pointers.length; i++)
    {
      sorts[i] = new Sort(solver, pointers[i]);
    }
    return sorts;
  }

  public static <K> Pair<K, Long>[] getPairs(Pair<K, Sort>[] ipointers)
  {
    Pair<K, Long>[] pointers = new Pair[ipointers.length];
    for (int i = 0; i < pointers.length; i++)
    {
      pointers[i] = new Pair<K, Long>(ipointers[i].first, ipointers[i].second.getPointer());
    }
    return pointers;
  }
}

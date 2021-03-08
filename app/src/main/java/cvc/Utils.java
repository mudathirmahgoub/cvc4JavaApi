package cvc;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardCopyOption;
import org.apache.commons.lang3.SystemUtils;

class Utils
{
  /**
   * @return the absolute path of cvcJavaApi dynamic library
   */
  static String getCvcApiLibFile() throws IOException
  {
    String cvcApiLibName = null;
    if (SystemUtils.IS_OS_LINUX)
    {
      cvcApiLibName = "libcvcJavaApi.so";
    }
    if (SystemUtils.IS_OS_MAC)
    {
      cvcApiLibName = "libcvcJavaApi.dylib";
    }
    if (SystemUtils.IS_OS_WINDOWS)
    {
      cvcApiLibName = "cvcJavaApi.dll";
    }
    String cvcApiLibFile =
        System.getProperty("java.io.tmpdir") + File.separatorChar + cvcApiLibName;
    InputStream input = Solver.class.getResourceAsStream("/" + cvcApiLibName);
    Files.copy(input, Paths.get(cvcApiLibFile), StandardCopyOption.REPLACE_EXISTING);
    return cvcApiLibFile;
  }

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

  public static <K> Pair<K, Long>[] getPairs(Pair<K, ? extends AbstractPointer>[] abstractPointers)
  {
    Pair<K, Long>[] pointers = new Pair[abstractPointers.length];
    for (int i = 0; i < pointers.length; i++)
    {
      pointers[i] = new Pair<>(abstractPointers[i].first, abstractPointers[i].second.getPointer());
    }
    return pointers;
  }
}

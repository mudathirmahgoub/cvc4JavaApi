package cvc;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardCopyOption;
import java.util.ArrayList;
import java.util.List;
import org.apache.commons.lang3.SystemUtils;

public class Solver
{
  private long solverPointer;

  private List<Sort> sorts = new ArrayList<>();

  private List<Term> terms = new ArrayList<>();

  private List<Result> results = new ArrayList<>();

  void addSort(Sort sort)
  {
    this.sorts.add(sort);
  }

  void addTerm(Term term)
  {
    this.terms.add(term);
  }

  void addResult(Result result)
  {
    this.results.add(result);
  }

  static
  {
    try
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
      System.out.println(cvcApiLibFile);
      InputStream input = Solver.class.getResourceAsStream("/" + cvcApiLibName);
      System.out.println("Input: " + input);
      Files.copy(input, Paths.get(cvcApiLibFile), StandardCopyOption.REPLACE_EXISTING);
      System.load(cvcApiLibFile);
    }
    catch (IOException e)
    {
      e.printStackTrace();
    }
  }

  public Solver()
  {
    solverPointer = newSolver();
  }

  private native long newSolver();

  public void deleteSolver()
  {
    for (Result result : results)
    {
      result.deleteResult();
    }

    for (Term term : terms)
    {
      term.deleteTerm();
    }

    for (Sort sort : sorts)
    {
      // TODO: fix errors with this line
      // sort.deleteSort();
    }

    deleteSolver(solverPointer);
  }

  private native void deleteSolver(long solverPointer);

  /**
   * Set logic.
   * SMT-LIB: ( set-logic <symbol> )
   * @param logic
   * @throws CVCApiException
   */
  public void setLogic(String logic) throws CVCApiException
  {
    setLogic(solverPointer, logic);
  }

  private native void setLogic(long solverPointer, String logic) throws CVCApiException;

  public Sort getRealSort()
  {
    long sortPointer = getRealSort(solverPointer);
    return new Sort(this, sortPointer);
  }

  private native long getRealSort(long solverPointer);

  public Sort getIntegerSort()
  {
    long sortPointer = getIntegerSort(solverPointer);
    return new Sort(this, sortPointer);
  }

  public native long getIntegerSort(long solverPointer);

  public Term mkConst(Sort sort, String symbol)
  {
    long termPointer = mkConst(solverPointer, sort.getPointer(), symbol);
    return new Term(this, termPointer);
  }

  private native long mkConst(long solverPointer, long sortPointer, String symbol);

  public Term mkInteger(int val)
  {
    long termPointer = mkInteger(solverPointer, val);
    return new Term(this, termPointer);
  }

  private native long mkInteger(long solverPointer, int val);

  public Term mkReal(int num, int den)
  {
    long termPointer = mkReal(solverPointer, num, den);
    return new Term(this, termPointer);
  }

  private native long mkReal(long solverPointer, int num, int den);

  public Result checkSat()
  {
    long resultPointer = checkSat(solverPointer);
    return new Result(this, resultPointer);
  }

  public Term mkTerm(Kind kind, Term child1, Term child2)
  {
    long termPointer =
        mkTerm(solverPointer, kind.getValue(), child1.getPointer(), child2.getPointer());
    return new Term(this, termPointer);
  }

  private native long mkTerm(long solverPointer, int kind, long child1Pointer, long child2Pointer);

  public Term mkTerm(Kind kind, Term child1, Term child2, Term child3)
  {
    long termPointer = mkTerm(solverPointer,
        kind.getValue(),
        child1.getPointer(),
        child2.getPointer(),
        child3.getPointer());
    return new Term(this, termPointer);
  }

  private native long mkTerm(
      long solverPointer, int kind, long child1Pointer, long child2Pointer, long child3Pointer);

  private native long checkSat(long solverPointer);

  public void assertFormula(Term term)
  {
    assertFormula(solverPointer, term.getPointer());
  }

  private native void assertFormula(long solverPointer, long termPointer);

  public void push()
  {
    push(solverPointer, 1);
  }

  public void push(int nscopes)
  {
    push(solverPointer, nscopes);
  }

  private native void push(long solverPointer, int nscopes);

  public Result checkEntailed(Term term)
  {
    long resultPointer = checkEntailed(solverPointer, term.getPointer());
    return new Result(this, resultPointer);
  }

  private native long checkEntailed(long solverPointer, long termPointer);

  public void pop()
  {
    pop(solverPointer, 1);
  }

  public void pop(int nscopes)
  {
    pop(solverPointer, nscopes);
  }

  private native void pop(long solverPointer, int nscopes);

  public Term mkTrue()
  {
    long termPointer = mkTrue(solverPointer);
    return new Term(this, termPointer);
  }

  private native long mkTrue(long solverPointer);
}

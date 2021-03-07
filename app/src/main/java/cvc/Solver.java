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

public class Solver implements IPointer
{
  private long pointer;

  public long getPointer()
  {
    return pointer;
  }

  private List<Sort> sorts = new ArrayList<>();

  private List<Term> terms = new ArrayList<>();

  private List<Result> results = new ArrayList<>();

  private List<DatatypeDecl> datatypeDecls = new ArrayList<>();

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

  public void addDatatypeDecl(DatatypeDecl datatypeDecl)
  {
    this.datatypeDecls.add(datatypeDecl);
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
      InputStream input = Solver.class.getResourceAsStream("/" + cvcApiLibName);
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
    pointer = newSolver();
  }

  private native long newSolver();

  public void deletePointer()
  {
    for (Result result : results)
    {
      result.deletePointer();
    }

    for (Term term : terms)
    {
      term.deletePointer();
    }

    for (Sort sort : sorts)
    {
      // TODO: fix errors with this line
      // sort.deletePointer();
    }

    deletePointer(pointer);
  }

  private native void deletePointer(long solverPointer);

  /**
   * Set logic.
   * SMT-LIB: ( set-logic <symbol> )
   *
   * @param logic
   * @throws CVCApiException
   */
  public void setLogic(String logic) throws CVCApiException
  {
    setLogic(pointer, logic);
  }

  private native void setLogic(long solverPointer, String logic) throws CVCApiException;

  /**
   * @return sort null
   */
  public Sort getNullSort()
  {
    long sortPointer = getNullSort(pointer);
    return new Sort(this, sortPointer);
  }

  private native long getNullSort(long solverPointer);

  /**
   * @return sort Boolean
   */
  public Sort getBooleanSort()
  {
    long sortPointer = getBooleanSort(pointer);
    return new Sort(this, sortPointer);
  }

  private native long getBooleanSort(long solverPointer);

  /* Sorts Handling                                                             */
  /* -------------------------------------------------------------------------- */
  // region Sorts Handling

  /**
   * @return sort Integer (in CVC4, Integer is a subtype of Real)
   */
  public Sort getIntegerSort()
  {
    long sortPointer = getIntegerSort(pointer);
    return new Sort(this, sortPointer);
  }

  /**
   * @return sort Real
   */
  public native long getIntegerSort(long solverPointer);

  public Sort getRealSort()
  {
    long sortPointer = getRealSort(pointer);
    return new Sort(this, sortPointer);
  }

  private native long getRealSort(long solverPointer);

  /**
   * @return sort RegExp
   */
  public Sort getRegExpSort()
  {
    long sortPointer = getRegExpSort(pointer);
    return new Sort(this, sortPointer);
  }

  private native long getRegExpSort(long solverPointer);

  /**
   * @return sort RoundingMode
   * @throws CVCApiException
   */
  public Sort getRoundingModeSort() throws CVCApiException
  {
    long sortPointer = getRoundingModeSort(pointer);
    return new Sort(this, sortPointer);
  }

  private native long getRoundingModeSort(long solverPointer) throws CVCApiException;

  /**
   * @return sort String
   */
  public Sort getStringSort()
  {
    long sortPointer = getStringSort(pointer);
    return new Sort(this, sortPointer);
  }

  private native long getStringSort(long solverPointer);

  // endregion

  public Term mkConst(Sort sort, String symbol)
  {
    long termPointer = mkConst(pointer, sort.getPointer(), symbol);
    return new Term(this, termPointer);
  }

  /* Create sorts ------------------------------------------------------- */
  // region Create sorts

  /**
   * Create an array sort.
   *
   * @param indexSort   the array index sort
   * @param elementSort the array element sort
   * @return the array sort
   */
  public Sort mkArraySort(Sort indexSort, Sort elementSort)
  {
    long sortPointer = mkArraySort(pointer, indexSort.getPointer(), elementSort.getPointer());
    return new Sort(this, sortPointer);
  }

  private native long mkArraySort(
      long solverPointer, long indexSortPointer, long elementSortPointer);

  /**
   * Create a bit-vector sort.
   *
   * @param size the bit-width of the bit-vector sort
   * @return the bit-vector sort
   */
  public Sort mkBitVectorSort(int size) throws CVCApiException
  {
    if (size < 0)
    {
      throw new CVCApiException("Expected size '" + size + "' to be non negative.");
    }
    long sortPointer = mkBitVectorSort(pointer, size);
    return new Sort(this, sortPointer);
  }

  private native long mkBitVectorSort(long solverPointer, int size);

  /**
   * Create a floating-point sort.
   *
   * @param exp the bit-width of the exponent of the floating-point sort.
   * @param sig the bit-width of the significand of the floating-point sort.
   */
  public Sort mkFloatingPointSort(int exp, int sig) throws CVCApiException
  {
    if (exp < 0)
    {
      throw new CVCApiException("Expected expr '" + exp + "' to be non negative.");
    }
    if (sig < 0)
    {
      throw new CVCApiException("Expected sig '" + sig + "' to be non negative.");
    }
    long sortPointer = mkFloatingPointSort(pointer, exp, sig);
    return new Sort(this, sortPointer);
  }

  private native long mkFloatingPointSort(long solverPointer, int exp, int sig)
      throws CVCApiException;

  /**
   * Create a datatype sort.
   * @param datatypeDecl the datatype declaration from which the sort is created
   * @return the datatype sort
   */
  public Sort mkDatatypeSort(DatatypeDecl datatypeDecl) throws CVCApiException
  {
    long pointer = mkDatatypeSort(this.pointer, datatypeDecl.getPointer());
    return new Sort(this, pointer);
  }

  private native long mkDatatypeSort(long solverPointer, long datatypeDeclPointer)
      throws CVCApiException;

  /**
   * Create a vector of datatype sorts. The names of the datatype declarations
   * must be distinct.
   *
   * @param datatypeDecls the datatype declarations from which the sort is created
   * @return the datatype sorts
   */
  public Sort[] mkDatatypeSorts(DatatypeDecl[] datatypeDecls) throws CVCApiException
  {
    long[] declPointers = new long[datatypeDecls.length];
    for (int i = 0; i < datatypeDecls.length; i++)
    {
      declPointers[i] = datatypeDecls[i].getPointer();
    }

    long[] sortPointers = mkDatatypeSorts(pointer, declPointers);

    Sort[] sorts = new Sort[sortPointers.length];
    for (int i = 0; i < sortPointers.length; i++)
    {
      sorts[i] = new Sort(this, sortPointers[i]);
    }

    return sorts;
  }

  private native long[] mkDatatypeSorts(long solverPointer, long[] declPointers)
      throws CVCApiException;

  /**
   * Create a vector of datatype sorts using unresolved sorts. The names of
   * the datatype declarations in dtypedecls must be distinct.
   *
   * This method is called when the DatatypeDecl objects dtypedecls have been
   * built using "unresolved" sorts.
   *
   * We associate each sort in unresolvedSorts with exactly one datatype from
   * dtypedecls. In particular, it must have the same name as exactly one
   * datatype declaration in dtypedecls.
   *
   * When constructing datatypes, unresolved sorts are replaced by the datatype
   * sort constructed for the datatype declaration it is associated with.
   *
   * @param dtypedecls the datatype declarations from which the sort is created
   * @param unresolvedSorts the list of unresolved sorts
   * @return the datatype sorts
   */
  public Sort[] mkDatatypeSorts(DatatypeDecl[] dtypedecls, Sort[] unresolvedSorts)
      throws CVCApiException
  {
    long[] declPointers = Utils.getPointers(dtypedecls);
    long[] unresolvedPointers = Utils.getPointers(unresolvedSorts);
    long[] sortPointers = mkDatatypeSorts(pointer, declPointers, unresolvedPointers);
    Sort[] sorts = Utils.getSorts(this, sortPointers);
    return sorts;
  }

  private native long[] mkDatatypeSorts(
      long pointer, long[] declPointers, long[] unresolvedPointers) throws CVCApiException;

  /**
   * Create an uninterpreted sort.
   * @param symbol the name of the sort
   * @return the uninterpreted sort
   */
  public Sort mkUninterpretedSort(String symbol)
  {
    long sortPointer = mkUninterpretedSort(pointer, symbol);
    return new Sort(this, sortPointer);
  }

  private native long mkUninterpretedSort(long solverPointer, String symbol);

  /**
   * Create function sort.
   * @param domain the sort of the fuction argument
   * @param codomain the sort of the function return value
   * @return the function sort
   */
  public Sort mkFunctionSort(Sort domain, Sort codomain)
  {
    long sortPointer = mkFunctionSort(pointer, domain.getPointer(), codomain.getPointer());
    return new Sort(this, sortPointer);
  }

  private native long mkFunctionSort(long pointer, long domainPointer, long codomainPointer);


  /**
   * Create function sort.
   * @param sorts the sort of the function arguments
   * @param codomain the sort of the function return value
   * @return the function sort
   */
  public Sort mkFunctionSort(Sort[] sorts, Sort codomain)
  {
    long sortPointer = mkFunctionSort(pointer, Utils.getPointers(sorts), codomain.getPointer());
    return new Sort(this, sortPointer);
  }

  private native long mkFunctionSort(long pointer, long[] sortPointers, long codomainPointer);

  /**
   * Create a sort parameter.
   * @param symbol the name of the sort
   * @return the sort parameter
   */
  public Sort mkParamSort(String symbol)
  {
    long sortPointer = mkParamSort(pointer, symbol);
    return new Sort(this, sortPointer);
  }

  private native long mkParamSort(long pointer, String symbol);

  // endregion

  private native long mkConst(long solverPointer, long sortPointer, String symbol);

  public Term mkInteger(int val)
  {
    long termPointer = mkInteger(pointer, val);
    return new Term(this, termPointer);
  }

  private native long mkInteger(long solverPointer, int val);

  public Term mkReal(int num, int den)
  {
    long termPointer = mkReal(pointer, num, den);
    return new Term(this, termPointer);
  }

  private native long mkReal(long solverPointer, int num, int den);

  public Result checkSat()
  {
    long resultPointer = checkSat(pointer);
    return new Result(this, resultPointer);
  }

  public Term mkTerm(Kind kind, Term child1, Term child2)
  {
    long termPointer = mkTerm(pointer, kind.getValue(), child1.getPointer(), child2.getPointer());
    return new Term(this, termPointer);
  }

  private native long mkTerm(long solverPointer, int kind, long child1Pointer, long child2Pointer);

  public Term mkTerm(Kind kind, Term child1, Term child2, Term child3)
  {
    long termPointer = mkTerm(
        pointer, kind.getValue(), child1.getPointer(), child2.getPointer(), child3.getPointer());
    return new Term(this, termPointer);
  }

  private native long mkTerm(
      long solverPointer, int kind, long child1Pointer, long child2Pointer, long child3Pointer);

  private native long checkSat(long solverPointer);

  public void assertFormula(Term term)
  {
    assertFormula(pointer, term.getPointer());
  }

  private native void assertFormula(long solverPointer, long termPointer);

  public void push()
  {
    push(pointer, 1);
  }

  public void push(int nscopes)
  {
    push(pointer, nscopes);
  }

  private native void push(long solverPointer, int nscopes);

  public Result checkEntailed(Term term)
  {
    long resultPointer = checkEntailed(pointer, term.getPointer());
    return new Result(this, resultPointer);
  }

  private native long checkEntailed(long solverPointer, long termPointer);

  public void pop()
  {
    pop(pointer, 1);
  }

  public void pop(int nscopes)
  {
    pop(pointer, nscopes);
  }

  private native void pop(long solverPointer, int nscopes);

  public Term mkTrue()
  {
    long termPointer = mkTrue(pointer);
    return new Term(this, termPointer);
  }

  private native long mkTrue(long solverPointer);

  /**
   * Set option.
   * SMT-LIB: ( set-option <option> )
   *
   * @param option option the option name
   * @param value  the option value
   * @throws CVCApiException
   */
  public void setOption(String option, String value) throws CVCApiException
  {
    setOption(pointer, option, value);
  }

  private native void setOption(long solverPointer, String option, String value)
      throws CVCApiException;

  /**
   * Get the value of the given term.
   * SMT-LIB: ( get-value ( <term> ) )
   *
   * @param term term the term for which the value is queried
   * @return the value of the given term
   */
  public Term getValue(Term term) throws CVCApiRecoverableException
  {
    long termPointer = getValue(pointer, term.getPointer());
    return new Term(this, termPointer);
  }

  private native long getValue(long solverPointer, long termPointer)
      throws CVCApiRecoverableException;

  public boolean supportsFloatingPoint()
  {
    return supportsFloatingPoint(pointer);
  }

  private native boolean supportsFloatingPoint(long solverPointer);

  /**
   * Create a roundingmode constant.
   *
   * @param rm the floating point rounding mode this constant represents
   */
  public Term mkRoundingMode(RoundingMode rm) throws CVCApiException
  {
    long termPointer = mkRoundingMode(pointer, rm.getValue());
    return new Term(this, termPointer);
  }

  private native long mkRoundingMode(long solverPointer, int value) throws CVCApiException;
  /* Create datatype declarations                                               */
  /* -------------------------------------------------------------------------- */
  // region Create datatype declarations

  /**
   * Create a datatype declaration.
   *
   * @param name the name of the datatype
   * @return the DatatypeDecl
   */
  public DatatypeDecl mkDatatypeDecl(String name)
  {
    return mkDatatypeDecl(name, false);
  }

  /**
   * Create a datatype declaration.
   *
   * @param name         the name of the datatype
   * @param isCoDatatype true if a codatatype is to be constructed
   * @return the DatatypeDecl
   */
  public DatatypeDecl mkDatatypeDecl(String name, boolean isCoDatatype)
  {
    long pointer = mkDatatypeDecl(this.pointer, name, isCoDatatype);
    return new DatatypeDecl(this, pointer);
  }

  private native long mkDatatypeDecl(long solverPointer, String name, boolean isCoDatatype);

  public DatatypeConstructorDecl mkDatatypeConstructorDecl(String name)
  {
    long pointer = mkDatatypeConstructorDecl(this.pointer, name);
    return new DatatypeConstructorDecl(this, pointer);
  }

  private native long mkDatatypeConstructorDecl(long solverPointer, String name);



  // endregion
}

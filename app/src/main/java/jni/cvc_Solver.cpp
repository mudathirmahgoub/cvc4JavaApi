#include "cvc_Solver.h"

#include "cvc4/api/cvc4cpp.h"

using namespace CVC4::api;

/*
 * Class:     cvc_Solver
 * Method:    newSolver
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_newSolver(JNIEnv*, jobject)
{
  Solver* solver = new Solver();
  return ((jlong)solver);
}

/*
 * Class:     cvc_Solver
 * Method:    deletePointer
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_cvc_Solver_deletePointer(JNIEnv*,
                                                     jobject,
                                                     jlong pointer)
{
  delete ((Solver*)pointer);
}

/*
 * Class:     cvc_Solver
 * Method:    setLogic
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_cvc_Solver_setLogic(JNIEnv* env,
                                                jobject,
                                                jlong solverPointer,
                                                jstring jLogic)
{
  Solver* solver = (Solver*)solverPointer;
  const char* cLogic = env->GetStringUTFChars(jLogic, nullptr);
  if (cLogic == nullptr)
  {
    return; /* out of memory error already thrown */
  }

  try
  {
    solver->setLogic(std::string(cLogic));
  }
  catch (const CVC4ApiException& e)
  {
    jclass exceptionClass = env->FindClass("cvc/CVCApiException");
    env->ThrowNew(exceptionClass, e.what());
  }
}

/*
 * Class:     cvc_Solver
 * Method:    getNullSort
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_getNullSort(JNIEnv*,
                                                    jobject,
                                                    jlong solverPointer)
{
  Solver* solver = (Solver*)solverPointer;
  Sort* sortPointer = new Sort(solver->getNullSort());
  return ((jlong)sortPointer);
}

/*
 * Class:     cvc_Solver
 * Method:    getBooleanSort
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_getBooleanSort(JNIEnv*,
                                                       jobject,
                                                       jlong solverPointer)
{
  Solver* solver = (Solver*)solverPointer;
  Sort* sortPointer = new Sort(solver->getBooleanSort());
  return ((jlong)sortPointer);
}

/*
 * Class:     cvc_Solver
 * Method:    getIntegerSort
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_getIntegerSort(JNIEnv*,
                                                       jobject,
                                                       jlong solverPointer)
{
  Solver* solver = (Solver*)solverPointer;
  Sort* sortPointer = new Sort(solver->getIntegerSort());
  return ((jlong)sortPointer);
}

/*
 * Class:     cvc_Solver
 * Method:    getRealSort
 * Signature: ()Lcvc4/Sort;
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_getRealSort(JNIEnv*,
                                                    jobject,
                                                    jlong solverPointer)
{
  Solver* solver = (Solver*)solverPointer;
  Sort* sortPointer = new Sort(solver->getRealSort());
  return ((jlong)sortPointer);
}

/*
 * Class:     cvc_Solver
 * Method:    getRegExpSort
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_getRegExpSort(JNIEnv*,
                                                      jobject,
                                                      jlong solverPointer)
{
  Solver* solver = (Solver*)solverPointer;
  Sort* sortPointer = new Sort(solver->getRegExpSort());
  return ((jlong)sortPointer);
}

/*
 * Class:     cvc_Solver
 * Method:    getRoundingModeSort
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_getRoundingModeSort(JNIEnv* env,
                                                            jobject,
                                                            jlong solverPointer)
{
  try
  {
    Solver* solver = (Solver*)solverPointer;
    Sort* sortPointer = new Sort(solver->getRoundingModeSort());
    return ((jlong)sortPointer);
  }
  catch (const CVC4ApiException& e)
  {
    jclass exceptionClass = env->FindClass("cvc/CVCApiException");
    env->ThrowNew(exceptionClass, e.what());
  }
  return 0;
}

/*
 * Class:     cvc_Solver
 * Method:    getStringSort
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_getStringSort(JNIEnv*,
                                                      jobject,
                                                      jlong solverPointer)
{
  Solver* solver = (Solver*)solverPointer;
  Sort* sortPointer = new Sort(solver->getStringSort());
  return ((jlong)sortPointer);
}

/* Create sorts ------------------------------------------------------- */
// region Create sorts

/*
 * Class:     cvc_Solver
 * Method:    mkArraySort
 * Signature: (JJJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkArraySort(JNIEnv* env,
                                                    jobject,
                                                    jlong solverPointer,
                                                    jlong indexSortPointer,
                                                    jlong elementSortPointer)
{
  try
  {
    Solver* solver = (Solver*)solverPointer;
    Sort* indexSort = (Sort*)indexSortPointer;
    Sort* elementSort = (Sort*)elementSortPointer;
    Sort* sortPointer = new Sort(solver->mkArraySort(*indexSort, *elementSort));
    return ((jlong)sortPointer);
  }
  catch (const CVC4ApiException& e)
  {
    jclass exceptionClass = env->FindClass("cvc/CVCApiException");
    env->ThrowNew(exceptionClass, e.what());
  }
  return 0;
}

/*
 * Class:     cvc_Solver
 * Method:    mkBitVectorSort
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkBitVectorSort(JNIEnv* env,
                                                        jobject,
                                                        jlong solverPointer,
                                                        jint size)
{
  try
  {
    Solver* solver = (Solver*)solverPointer;
    Sort* sortPointer = new Sort(solver->mkBitVectorSort((uint32_t)size));
    return ((jlong)sortPointer);
  }
  catch (const CVC4ApiException& e)
  {
    jclass exceptionClass = env->FindClass("cvc/CVCApiException");
    env->ThrowNew(exceptionClass, e.what());
  }
  return 0;
}

/*
 * Class:     cvc_Solver
 * Method:    mkFloatingPointSort
 * Signature: (JII)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkFloatingPointSort(
    JNIEnv* env, jobject, jlong solverPointer, jint exp, jint sig)
{
  try
  {
    Solver* solver = (Solver*)solverPointer;
    Sort* sortPointer =
        new Sort(solver->mkFloatingPointSort((uint32_t)exp, (uint32_t)sig));
    return ((jlong)sortPointer);
  }
  catch (const CVC4ApiException& e)
  {
    jclass exceptionClass = env->FindClass("cvc/CVCApiException");
    env->ThrowNew(exceptionClass, e.what());
  }
  return 0;
}

/*
 * Class:     cvc_Solver
 * Method:    mkDatatypeSort
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkDatatypeSort(
    JNIEnv* env, jobject, jlong solverPointer, jlong datatypeDeclPointer)
{
  try
  {
    Solver* solver = (Solver*)solverPointer;
    DatatypeDecl* datatypeDecl = (DatatypeDecl*)datatypeDeclPointer;
    Sort* sort = new Sort(solver->mkDatatypeSort(*datatypeDecl));
    return ((jlong)sort);
  }
  catch (const CVC4ApiException& e)
  {
    jclass exceptionClass = env->FindClass("cvc/CVCApiException");
    env->ThrowNew(exceptionClass, e.what());
  }
  return 0;
}

/*
 * Class:     cvc_Solver
 * Method:    mkDatatypeSorts
 * Signature: (J[J)[J
 */
JNIEXPORT jlongArray JNICALL Java_cvc_Solver_mkDatatypeSorts__J_3J(
    JNIEnv* env, jobject, jlong pointer, jlongArray declPointers)
{
  try
  {
    Solver* solver = (Solver*)pointer;
    jsize size = env->GetArrayLength(declPointers);
    jlong* elements = env->GetLongArrayElements(declPointers, nullptr);
    if (elements == 0)
    {
      throw CVC4ApiException("Null pointer elements in mkDatatypeSorts");
    }
    std::vector<DatatypeDecl> decls;
    for (size_t i = 0; i < size; i++)
    {
      DatatypeDecl* decl = (DatatypeDecl*)elements[i];
      decls.push_back(*decl);
    }
    env->ReleaseLongArrayElements(declPointers, elements, 0);

    std::vector<Sort> sorts = solver->mkDatatypeSorts(decls);
    long* sortPointers = new long[sorts.size()];
    for (size_t i = 0; i < sorts.size(); i++)
    {
      sortPointers[i] = (long)new Sort(sorts[i]);
    }

    jlongArray ret = env->NewLongArray(sorts.size());
    env->SetLongArrayRegion(ret, 0, sorts.size(), sortPointers);

    return ret;
  }
  catch (const CVC4ApiException& e)
  {
    jclass exceptionClass = env->FindClass("cvc/CVCApiException");
    env->ThrowNew(exceptionClass, e.what());
  }
  return nullptr;
}

/*
 * Class:     cvc_Solver
 * Method:    mkDatatypeSorts
 * Signature: (J[J[J)[J
 */
JNIEXPORT jlongArray JNICALL
Java_cvc_Solver_mkDatatypeSorts__J_3J_3J(JNIEnv* env,
                                         jobject,
                                         jlong pointer,
                                         jlongArray declPointers,
                                         jlongArray unresolvedPointers)
{
  try
  {
    Solver* solver = (Solver*)pointer;
    jsize declsSize = env->GetArrayLength(declPointers);
    jsize unresolvedSize = env->GetArrayLength(unresolvedPointers);
    jlong* declElements = env->GetLongArrayElements(declPointers, nullptr);
    if (declElements == 0)
    {
      throw CVC4ApiException("Null pointer declElements in mkDatatypeSorts");
    }
    jlong* unresolvedElements =
        env->GetLongArrayElements(unresolvedPointers, nullptr);
    if (unresolvedElements == 0)
    {
      throw CVC4ApiException(
          "Null pointer unresolvedElements in mkDatatypeSorts");
    }

    std::vector<DatatypeDecl> decls;
    for (size_t i = 0; i < declsSize; i++)
    {
      DatatypeDecl* decl = (DatatypeDecl*)declElements[i];
      decls.push_back(*decl);
    }
    env->ReleaseLongArrayElements(declPointers, declElements, 0);

    std::set<Sort> unresolved;
    for (size_t i = 0; i < unresolvedSize; i++)
    {
      Sort* sort = (Sort*)unresolvedElements[i];
      unresolved.insert(*sort);
    }

    env->ReleaseLongArrayElements(unresolvedPointers, unresolvedElements, 0);
    std::vector<Sort> sorts = solver->mkDatatypeSorts(decls, unresolved);
    long* sortPointers = new long[sorts.size()];
    for (size_t i = 0; i < sorts.size(); i++)
    {
      sortPointers[i] = (long)new Sort(sorts[i]);
    }

    jlongArray ret = env->NewLongArray(sorts.size());
    env->SetLongArrayRegion(ret, 0, sorts.size(), sortPointers);

    return ret;
  }
  catch (const CVC4ApiException& e)
  {
    jclass exceptionClass = env->FindClass("cvc/CVCApiException");
    env->ThrowNew(exceptionClass, e.what());
  }
  return nullptr;
}

/*
 * Class:     cvc_Solver
 * Method:    mkUninterpretedSort
 * Signature: (JLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkUninterpretedSort(JNIEnv* env,
                                                            jobject,
                                                            jlong pointer,
                                                            jstring jSymbol)
{
  try
  {
    Solver* solver = (Solver*)pointer;
    const char* cSymbol = env->GetStringUTFChars(jSymbol, nullptr);
    Sort* sort = new Sort(solver->mkUninterpretedSort(std::string(cSymbol)));
    return (jlong)sort;
  }
  catch (const CVC4ApiException& e)
  {
    jclass exceptionClass = env->FindClass("cvc/CVCApiException");
    env->ThrowNew(exceptionClass, e.what());
  }
  return 0;
}

// endregion

/*
 * Class:     cvc_Solver
 * Method:    mkConst
 * Signature: (JJLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkConst(JNIEnv* env,
                                                jobject,
                                                jlong solverPointer,
                                                jlong sortPointer,
                                                jstring jSymbol)
{
  Solver* solver = (Solver*)solverPointer;
  Sort* sort = (Sort*)sortPointer;
  const char* cSymbol = env->GetStringUTFChars(jSymbol, nullptr);
  Term* term = new Term(solver->mkConst((*sort), std::string(cSymbol)));
  return ((jlong)term);
}

/*
 * Class:     cvc_Solver
 * Method:    mkInteger
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkInteger(JNIEnv* env,
                                                  jobject,
                                                  jlong solverPointer,
                                                  jint val)
{
  Solver* solver = (Solver*)solverPointer;
  Term* term = new Term(solver->mkInteger(val));
  return ((jlong)term);
}

/*
 * Class:     cvc_Solver
 * Method:    mkReal
 * Signature: (JII)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkReal(
    JNIEnv*, jobject, jlong solverPointer, jint num, jint den)
{
  Solver* solver = (Solver*)solverPointer;
  Term* term = new Term(solver->mkReal(num, den));
  return ((jlong)term);
}

/*
 * Class:     cvc_Solver
 * Method:    mkTerm
 * Signature: (JIJJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkTerm__JIJJ(JNIEnv*,
                                                     jobject,
                                                     jlong solverPointer,
                                                     jint kind,
                                                     jlong child1Pointer,
                                                     jlong child2Pointer)
{
  Solver* solver = (Solver*)solverPointer;
  Term* child1 = (Term*)child1Pointer;
  Term* child2 = (Term*)child2Pointer;
  Term* term = new Term(solver->mkTerm((Kind)kind, *child1, *child2));
  return ((jlong)term);
}

/*
 * Class:     cvc_Solver
 * Method:    mkTerm
 * Signature: (JIJJJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkTerm__JIJJJ(JNIEnv*,
                                                      jobject,
                                                      jlong solverPointer,
                                                      jint kind,
                                                      jlong child1Pointer,
                                                      jlong child2Pointer,
                                                      jlong child3Pointer)
{
  Solver* solver = (Solver*)solverPointer;
  Term* child1 = (Term*)child1Pointer;
  Term* child2 = (Term*)child2Pointer;
  Term* child3 = (Term*)child3Pointer;
  Term* term = new Term(solver->mkTerm((Kind)kind, *child1, *child2, *child3));
  return ((jlong)term);
}

/*
 * Class:     cvc_Solver
 * Method:    checkSat
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_checkSat(JNIEnv*,
                                                 jobject,
                                                 jlong solverPointer)
{
  Solver* solver = (Solver*)solverPointer;
  Result* resultPointer = new Result(solver->checkSat());
  return ((jlong)resultPointer);
}

/*
 * Class:     cvc_Solver
 * Method:    assertFormula
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_cvc_Solver_assertFormula(JNIEnv*,
                                                     jobject,
                                                     jlong solverPointer,
                                                     jlong termPointer)
{
  Solver* solver = (Solver*)solverPointer;
  Term* term = (Term*)termPointer;
  solver->assertFormula(*term);
}

/*
 * Class:     cvc_Solver
 * Method:    push
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_cvc_Solver_push(JNIEnv*,
                                            jobject,
                                            jlong solverPointer,
                                            jint nscopes)
{
  Solver* solver = (Solver*)solverPointer;
  solver->push(nscopes);
}

/*
 * Class:     cvc_Solver
 * Method:    checkEntailed
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_checkEntailed(JNIEnv*,
                                                      jobject,
                                                      jlong solverPointer,
                                                      jlong termPointer)
{
  Solver* solver = (Solver*)solverPointer;
  Term* term = (Term*)termPointer;
  Result* resultPointer = new Result(solver->checkEntailed(*term));
  return (jlong)resultPointer;
}

/*
 * Class:     cvc_Solver
 * Method:    pop
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_cvc_Solver_pop(JNIEnv*,
                                           jobject,
                                           jlong solverPointer,
                                           jint nscopes)
{
  Solver* solver = (Solver*)solverPointer;
  solver->pop(nscopes);
}

/*
 * Class:     cvc_Solver
 * Method:    mkTrue
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkTrue(JNIEnv*,
                                               jobject,
                                               jlong solverPointer)
{
  Solver* solver = (Solver*)solverPointer;
  Term* term = new Term(solver->mkTrue());
  return ((jlong)term);
}

/*
 * Class:     cvc_Solver
 * Method:    setOption
 * Signature: (JLjava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_cvc_Solver_setOption(
    JNIEnv* env, jobject, jlong solverPointer, jstring jOption, jstring jValue)
{
  try
  {
    Solver* solver = (Solver*)solverPointer;
    const char* cOption = env->GetStringUTFChars(jOption, nullptr);
    const char* cValue = env->GetStringUTFChars(jValue, nullptr);
    solver->setOption(std::string(cOption), std::string(cValue));
  }
  catch (const CVC4ApiException& e)
  {
    jclass exceptionClass = env->FindClass("cvc/CVCApiException");
    env->ThrowNew(exceptionClass, e.what());
  }
}

/*
 * Class:     cvc_Solver
 * Method:    getValue
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_getValue(JNIEnv* env,
                                                 jobject,
                                                 jlong solverPointer,
                                                 jlong termPointer)
{
  try
  {
    Solver* solver = (Solver*)solverPointer;
    Term* term = (Term*)termPointer;
    Term* ret = new Term(solver->getValue(*term));
    return (jlong)ret;
  }
  catch (const CVC4ApiRecoverableException& e)
  {
    jclass exceptionClass = env->FindClass("cvc/CVCApiRecoverableException");
    env->ThrowNew(exceptionClass, e.what());
  }
  catch (const CVC4ApiException& e)
  {
    jclass exceptionClass = env->FindClass("cvc/CVCApiException");
    env->ThrowNew(exceptionClass, e.what());
  }
  // code should never reach here
  return 0;
}

/*
 * Class:     cvc_Solver
 * Method:    supportsFloatingPoint
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL
Java_cvc_Solver_supportsFloatingPoint(JNIEnv*, jobject, jlong solverPointer)
{
  Solver* solver = (Solver*)solverPointer;
  return (jboolean)solver->supportsFloatingPoint();
}

/*
 * Class:     cvc_Solver
 * Method:    mkRoundingMode
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkRoundingMode(JNIEnv* env,
                                                       jobject,
                                                       jlong solverPointer,
                                                       jint rm)
{
  try
  {
    Solver* solver = (Solver*)solverPointer;
    Term* ret = new Term(solver->mkRoundingMode((RoundingMode)rm));
    return (jlong)ret;
  }
  catch (const CVC4ApiException& e)
  {
    jclass exceptionClass = env->FindClass("cvc/CVCApiException");
    env->ThrowNew(exceptionClass, e.what());
  }
  // code should never reach here
  return 0;
}

/*
 * Class:     cvc_Solver
 * Method:    mkDatatypeDecl
 * Signature: (JLjava/lang/String;Z)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkDatatypeDecl(JNIEnv* env,
                                                       jobject,
                                                       jlong solverPointer,
                                                       jstring jName,
                                                       jboolean jIsCoDatatype)
{
  try
  {
    Solver* solver = (Solver*)solverPointer;
    const char* cName = env->GetStringUTFChars(jName, nullptr);
    bool cIsCoDatatype = (bool)jIsCoDatatype;
    DatatypeDecl* decl = new DatatypeDecl(
        solver->mkDatatypeDecl(std::string(cName), cIsCoDatatype));
    return (jlong)decl;
  }
  catch (const CVC4ApiException& e)
  {
    jclass exceptionClass = env->FindClass("cvc/CVCApiException");
    env->ThrowNew(exceptionClass, e.what());
  }
  // code should never reach here
  return 0;
}

/*
 * Class:     cvc_Solver
 * Method:    mkDatatypeConstructorDecl
 * Signature: (JLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkDatatypeConstructorDecl(
    JNIEnv* env, jobject, jlong solverPointer, jstring jName)
{
  try
  {
    Solver* solver = (Solver*)solverPointer;
    const char* cName = env->GetStringUTFChars(jName, nullptr);
    DatatypeConstructorDecl* decl = new DatatypeConstructorDecl(
        solver->mkDatatypeConstructorDecl(std::string(cName)));
    return (jlong)decl;
  }
  catch (const CVC4ApiException& e)
  {
    jclass exceptionClass = env->FindClass("cvc/CVCApiException");
    env->ThrowNew(exceptionClass, e.what());
  }
  // code should never reach here
  return 0;
}
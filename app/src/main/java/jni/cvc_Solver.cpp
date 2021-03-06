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
 * Method:    deleteSolver
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_cvc_Solver_deleteSolver(JNIEnv*,
                                                    jobject,
                                                    jlong solverPointer)
{
  delete ((Solver*)solverPointer);
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
    if (exceptionClass == nullptr)
    {
      /* Unable to find the exception class, give up. */
      return;
    }
    env->ThrowNew(exceptionClass, e.what());
  }
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
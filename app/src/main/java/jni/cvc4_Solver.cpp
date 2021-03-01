#include "cvc4_Solver.h"

#include "cvc4/api/cvc4cpp.h"

using namespace CVC4::api;

/*
 * Class:     cvc4_Solver
 * Method:    newSolver
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_cvc4_Solver_newSolver(JNIEnv*, jobject)
{
  Solver* solver = new Solver();
  return ((jlong)solver);
}

/*
 * Class:     cvc4_Solver
 * Method:    deleteSolver
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_cvc4_Solver_deleteSolver(JNIEnv*,
                                                     jobject,
                                                     jlong solverPointer)
{
  delete ((Solver*)solverPointer);
}

/*
 * Class:     cvc4_Solver
 * Method:    setLogic
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_cvc4_Solver_setLogic(JNIEnv* env,
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
  solver->setLogic(std::string(cLogic));
}

/*
 * Class:     cvc4_Solver
 * Method:    getRealSort
 * Signature: ()Lcvc4/Sort;
 */
JNIEXPORT jlong JNICALL Java_cvc4_Solver_getRealSort(JNIEnv*,
                                                     jobject,
                                                     jlong solverPointer)
{
  Solver* solver = (Solver*)solverPointer;
  Sort* sortPointer = new Sort(solver->getRealSort());
  return ((jlong)sortPointer);
}

/*
 * Class:     cvc4_Solver
 * Method:    getIntegerSort
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc4_Solver_getIntegerSort(JNIEnv*,
                                                        jobject,
                                                        jlong solverPointer)
{
  Solver* solver = (Solver*)solverPointer;
  Sort* sortPointer = new Sort(solver->getIntegerSort());
  return ((jlong)sortPointer);
}

/*
 * Class:     cvc4_Solver
 * Method:    mkConst
 * Signature: (JJLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_cvc4_Solver_mkConst(JNIEnv* env,
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
 * Class:     cvc4_Solver
 * Method:    mkInteger
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc4_Solver_mkInteger(JNIEnv* env,
                                                   jobject,
                                                   jlong solverPointer,
                                                   jint val)
{
  Solver* solver = (Solver*)solverPointer;
  Term* term = new Term(solver->mkInteger(val));
  return ((jlong)term);
}

/*
 * Class:     cvc4_Solver
 * Method:    mkReal
 * Signature: (JII)J
 */
JNIEXPORT jlong JNICALL Java_cvc4_Solver_mkReal(
    JNIEnv*, jobject, jlong solverPointer, jint num, jint den)
{
  Solver* solver = (Solver*)solverPointer;
  Term* term = new Term(solver->mkReal(num, den));
  return ((jlong)term);
}

/*
 * Class:     cvc4_Solver
 * Method:    mkTerm
 * Signature: (JIJJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc4_Solver_mkTerm__JIJJ(JNIEnv*,
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
 * Class:     cvc4_Solver
 * Method:    mkTerm
 * Signature: (JIJJJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc4_Solver_mkTerm__JIJJJ(JNIEnv*,
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
 * Class:     cvc4_Solver
 * Method:    checkSat
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc4_Solver_checkSat(JNIEnv*,
                                                  jobject,
                                                  jlong solverPointer)
{
  Solver* solver = (Solver*)solverPointer;
  Result* resultPointer = new Result(solver->checkSat());
  return ((jlong)resultPointer);
}

/*
 * Class:     cvc4_Solver
 * Method:    assertFormula
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_cvc4_Solver_assertFormula(JNIEnv*,
                                                      jobject,
                                                      jlong solverPointer,
                                                      jlong termPointer)
{
  Solver* solver = (Solver*)solverPointer;
  Term* term = (Term*)termPointer;
  solver->assertFormula(*term);
}

/*
 * Class:     cvc4_Solver
 * Method:    push
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_cvc4_Solver_push(JNIEnv*,
                                             jobject,
                                             jlong solverPointer,
                                             jint nscopes)
{
  Solver* solver = (Solver*)solverPointer;
  solver->push(nscopes);
}

/*
 * Class:     cvc4_Solver
 * Method:    checkEntailed
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc4_Solver_checkEntailed(JNIEnv*,
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
 * Class:     cvc4_Solver
 * Method:    pop
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_cvc4_Solver_pop(JNIEnv*,
                                            jobject,
                                            jlong solverPointer,
                                            jint nscopes)
{
  Solver* solver = (Solver*)solverPointer;
  solver->pop(nscopes);
}

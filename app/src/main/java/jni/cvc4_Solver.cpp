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
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_cvc4_Solver_setLogic(JNIEnv*,
                                                 jobject,
                                                 jlong,
                                                 jstring);

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
  Term term = solver->mkConst((*sort), std::string(cSymbol));
  Term* termPointer = new Term(term);
  return ((jlong)termPointer);
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
  Term term = solver->mkInteger(val);
  Term* termPointer = new Term(term);
  return ((jlong)termPointer);
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
  Term term = solver->mkReal(num, den);
  Term* termPointer = new Term(term);
  return ((jlong)termPointer);
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
  Result result = solver->checkSat();
  Result* resultPointer = new Result(result);
  return ((jlong)resultPointer);
}
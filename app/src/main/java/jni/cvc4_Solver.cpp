#include "cvc4_Solver.h"

#include <iostream>

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
  std::cout << "I am here without problems in c++ \n" << std::endl;
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
 * Signature: (Lcvc4/Sort;Ljava/lang/String;)Lcvc4/Term;
 */
JNIEXPORT jobject JNICALL Java_cvc4_Solver_mkConst(JNIEnv*,
                                                   jobject,
                                                   jobject,
                                                   jstring)
{
}

/*
 * Class:     cvc4_Solver
 * Method:    mkInteger
 * Signature: (I)Lcvc4/Term;
 */
JNIEXPORT jobject JNICALL Java_cvc4_Solver_mkInteger(JNIEnv*, jobject, jint) {}

/*
 * Class:     cvc4_Solver
 * Method:    mkReal
 * Signature: (II)Lcvc4/Term;
 */
JNIEXPORT jobject JNICALL Java_cvc4_Solver_mkReal(JNIEnv*, jobject, jint, jint)
{
}
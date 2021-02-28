#include "cvc4_Solver.h"

#include <iostream>

#include "cvc4/api/cvc4cpp.h"

using namespace CVC4::api;

/*
 * Class:     cvc4_Solver
 * Method:    setLogic
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_cvc4_Solver_setLogic(JNIEnv* env,
                                                 jobject obj,
                                                 jstring jLogic)
{
  const char* cLogic = env->GetStringUTFChars(jLogic, nullptr);
  if (cLogic == nullptr)
  {
    return; /* out of memory error already thrown */
  }
  Solver solver;
  solver.setLogic(std::string(cLogic));
  std::cout<<"I am here without problems \n" << std::endl;
}

/*
 * Class:     cvc4_Solver
 * Method:    getRealSort
 * Signature: ()Lcvc4/Sort;
 */
JNIEXPORT jobject JNICALL Java_cvc4_Solver_getRealSort(JNIEnv*, jobject) {}

/*
 * Class:     cvc4_Solver
 * Method:    getIntegerSort
 * Signature: ()Lcvc4/Sort;
 */
JNIEXPORT jobject JNICALL Java_cvc4_Solver_getIntegerSort(JNIEnv*, jobject) {}

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

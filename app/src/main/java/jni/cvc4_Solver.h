/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class cvc4_Solver */

#ifndef _Included_cvc4_Solver
#define _Included_cvc4_Solver
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     cvc4_Solver
 * Method:    newSolver
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_cvc4_Solver_newSolver
  (JNIEnv *, jobject);

/*
 * Class:     cvc4_Solver
 * Method:    deleteSolver
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_cvc4_Solver_deleteSolver
  (JNIEnv *, jobject, jlong);

/*
 * Class:     cvc4_Solver
 * Method:    setLogic
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_cvc4_Solver_setLogic
  (JNIEnv *, jobject, jlong, jstring);

/*
 * Class:     cvc4_Solver
 * Method:    getRealSort
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc4_Solver_getRealSort
  (JNIEnv *, jobject, jlong);

/*
 * Class:     cvc4_Solver
 * Method:    getIntegerSort
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc4_Solver_getIntegerSort
  (JNIEnv *, jobject, jlong);

/*
 * Class:     cvc4_Solver
 * Method:    mkConst
 * Signature: (JJLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_cvc4_Solver_mkConst
  (JNIEnv *, jobject, jlong, jlong, jstring);

/*
 * Class:     cvc4_Solver
 * Method:    mkInteger
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_cvc4_Solver_mkInteger
  (JNIEnv *, jobject, jlong, jint);

/*
 * Class:     cvc4_Solver
 * Method:    mkReal
 * Signature: (JII)J
 */
JNIEXPORT jlong JNICALL Java_cvc4_Solver_mkReal
  (JNIEnv *, jobject, jlong, jint, jint);

/*
 * Class:     cvc4_Solver
 * Method:    checkSat
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc4_Solver_checkSat
  (JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif

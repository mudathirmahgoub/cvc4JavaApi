/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class cvc_Solver */

#ifndef _Included_cvc_Solver
#define _Included_cvc_Solver
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     cvc_Solver
 * Method:    newSolver
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_newSolver
  (JNIEnv *, jobject);

/*
 * Class:     cvc_Solver
 * Method:    deletePointer
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_cvc_Solver_deletePointer
  (JNIEnv *, jobject, jlong);

/*
 * Class:     cvc_Solver
 * Method:    setLogic
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_cvc_Solver_setLogic
  (JNIEnv *, jobject, jlong, jstring);

/*
 * Class:     cvc_Solver
 * Method:    getNullSort
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_getNullSort
  (JNIEnv *, jobject, jlong);

/*
 * Class:     cvc_Solver
 * Method:    getBooleanSort
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_getBooleanSort
  (JNIEnv *, jobject, jlong);

/*
 * Class:     cvc_Solver
 * Method:    getIntegerSort
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_getIntegerSort
  (JNIEnv *, jobject, jlong);

/*
 * Class:     cvc_Solver
 * Method:    getRealSort
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_getRealSort
  (JNIEnv *, jobject, jlong);

/*
 * Class:     cvc_Solver
 * Method:    getRegExpSort
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_getRegExpSort
  (JNIEnv *, jobject, jlong);

/*
 * Class:     cvc_Solver
 * Method:    getRoundingModeSort
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_getRoundingModeSort
  (JNIEnv *, jobject, jlong);

/*
 * Class:     cvc_Solver
 * Method:    getStringSort
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_getStringSort
  (JNIEnv *, jobject, jlong);

/*
 * Class:     cvc_Solver
 * Method:    mkArraySort
 * Signature: (JJJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkArraySort
  (JNIEnv *, jobject, jlong, jlong, jlong);

/*
 * Class:     cvc_Solver
 * Method:    mkBitVectorSort
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkBitVectorSort
  (JNIEnv *, jobject, jlong, jint);

/*
 * Class:     cvc_Solver
 * Method:    mkFloatingPointSort
 * Signature: (JII)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkFloatingPointSort
  (JNIEnv *, jobject, jlong, jint, jint);

/*
 * Class:     cvc_Solver
 * Method:    mkDatatypeSort
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkDatatypeSort
  (JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     cvc_Solver
 * Method:    mkDatatypeSorts
 * Signature: (J[J)[J
 */
JNIEXPORT jlongArray JNICALL Java_cvc_Solver_mkDatatypeSorts__J_3J
  (JNIEnv *, jobject, jlong, jlongArray);

/*
 * Class:     cvc_Solver
 * Method:    mkDatatypeSorts
 * Signature: (J[J[J)[J
 */
JNIEXPORT jlongArray JNICALL Java_cvc_Solver_mkDatatypeSorts__J_3J_3J
  (JNIEnv *, jobject, jlong, jlongArray, jlongArray);

/*
 * Class:     cvc_Solver
 * Method:    mkUninterpretedSort
 * Signature: (JLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkUninterpretedSort
  (JNIEnv *, jobject, jlong, jstring);

/*
 * Class:     cvc_Solver
 * Method:    mkFunctionSort
 * Signature: (JJJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkFunctionSort__JJJ
  (JNIEnv *, jobject, jlong, jlong, jlong);

/*
 * Class:     cvc_Solver
 * Method:    mkFunctionSort
 * Signature: (J[JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkFunctionSort__J_3JJ
  (JNIEnv *, jobject, jlong, jlongArray, jlong);

/*
 * Class:     cvc_Solver
 * Method:    mkParamSort
 * Signature: (JLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkParamSort
  (JNIEnv *, jobject, jlong, jstring);

/*
 * Class:     cvc_Solver
 * Method:    mkPredicateSort
 * Signature: (J[J)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkPredicateSort
  (JNIEnv *, jobject, jlong, jlongArray);

/*
 * Class:     cvc_Solver
 * Method:    mkRecordSort
 * Signature: (J[Lcvc/Pair;)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkRecordSort
  (JNIEnv *, jobject, jlong, jobjectArray);

/*
 * Class:     cvc_Solver
 * Method:    mkConst
 * Signature: (JJLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkConst
  (JNIEnv *, jobject, jlong, jlong, jstring);

/*
 * Class:     cvc_Solver
 * Method:    mkInteger
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkInteger
  (JNIEnv *, jobject, jlong, jint);

/*
 * Class:     cvc_Solver
 * Method:    mkReal
 * Signature: (JII)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkReal
  (JNIEnv *, jobject, jlong, jint, jint);

/*
 * Class:     cvc_Solver
 * Method:    mkTerm
 * Signature: (JIJJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkTerm__JIJJ
  (JNIEnv *, jobject, jlong, jint, jlong, jlong);

/*
 * Class:     cvc_Solver
 * Method:    mkTerm
 * Signature: (JIJJJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkTerm__JIJJJ
  (JNIEnv *, jobject, jlong, jint, jlong, jlong, jlong);

/*
 * Class:     cvc_Solver
 * Method:    checkSat
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_checkSat
  (JNIEnv *, jobject, jlong);

/*
 * Class:     cvc_Solver
 * Method:    assertFormula
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_cvc_Solver_assertFormula
  (JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     cvc_Solver
 * Method:    push
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_cvc_Solver_push
  (JNIEnv *, jobject, jlong, jint);

/*
 * Class:     cvc_Solver
 * Method:    checkEntailed
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_checkEntailed
  (JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     cvc_Solver
 * Method:    pop
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_cvc_Solver_pop
  (JNIEnv *, jobject, jlong, jint);

/*
 * Class:     cvc_Solver
 * Method:    mkTrue
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkTrue
  (JNIEnv *, jobject, jlong);

/*
 * Class:     cvc_Solver
 * Method:    setOption
 * Signature: (JLjava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_cvc_Solver_setOption
  (JNIEnv *, jobject, jlong, jstring, jstring);

/*
 * Class:     cvc_Solver
 * Method:    getValue
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_getValue
  (JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     cvc_Solver
 * Method:    supportsFloatingPoint
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_cvc_Solver_supportsFloatingPoint
  (JNIEnv *, jobject, jlong);

/*
 * Class:     cvc_Solver
 * Method:    mkRoundingMode
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkRoundingMode
  (JNIEnv *, jobject, jlong, jint);

/*
 * Class:     cvc_Solver
 * Method:    mkDatatypeDecl
 * Signature: (JLjava/lang/String;Z)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkDatatypeDecl
  (JNIEnv *, jobject, jlong, jstring, jboolean);

/*
 * Class:     cvc_Solver
 * Method:    mkDatatypeConstructorDecl
 * Signature: (JLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Solver_mkDatatypeConstructorDecl
  (JNIEnv *, jobject, jlong, jstring);

#ifdef __cplusplus
}
#endif
#endif

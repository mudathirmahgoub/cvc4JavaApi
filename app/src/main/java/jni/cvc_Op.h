/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class cvc_Op */

#ifndef _Included_cvc_Op
#define _Included_cvc_Op
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     cvc_Op
 * Method:    deletePointer
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_cvc_Op_deletePointer
  (JNIEnv *, jclass, jlong);

/*
 * Class:     cvc_Op
 * Method:    toString
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_cvc_Op_toString
  (JNIEnv *, jobject, jlong);

/*
 * Class:     cvc_Op
 * Method:    equals
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_cvc_Op_equals
  (JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     cvc_Op
 * Method:    getKind
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_cvc_Op_getKind
  (JNIEnv *, jobject, jlong);

/*
 * Class:     cvc_Op
 * Method:    isNull
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_cvc_Op_isNull
  (JNIEnv *, jobject, jlong);

/*
 * Class:     cvc_Op
 * Method:    isIndexed
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_cvc_Op_isIndexed
  (JNIEnv *, jobject, jlong);

/*
 * Class:     cvc_Op
 * Method:    getIntegerIndex
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_cvc_Op_getIntegerIndex
  (JNIEnv *, jobject, jlong);

/*
 * Class:     cvc_Op
 * Method:    getStringIndices
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_cvc_Op_getStringIndices
  (JNIEnv *, jobject, jlong);

/*
 * Class:     cvc_Op
 * Method:    getIntegerPairIndices
 * Signature: (J)[I
 */
JNIEXPORT jintArray JNICALL Java_cvc_Op_getIntegerPairIndices
  (JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif

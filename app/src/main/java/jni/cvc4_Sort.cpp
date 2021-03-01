#include "cvc4_Sort.h"

#include "cvc4/api/cvc4cpp.h"

using namespace CVC4::api;

/*
 * Class:     cvc4_Sort
 * Method:    deleteSort
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_cvc4_Sort_deleteSort(JNIEnv*,
                                                 jobject,
                                                 jlong sortPointer);
{
  delete ((Sort*)sortPointer);
}

/*
 * Class:     cvc4_Sort
 * Method:    toString
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_cvc4_Sort_toString(JNIEnv* env,
                                                  jobject,
                                                  jlong sortPointer)
{
  Sort* sort = (Sort*)sortPointer;
  return env->NewStringUTF(sort->toString().c_str());
}
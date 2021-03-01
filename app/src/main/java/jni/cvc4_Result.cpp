#include <iostream>

#include "cvc4/api/cvc4cpp.h"
#include "cvc4_Result.h"

using namespace CVC4::api;

/*
 * Class:     cvc4_Result
 * Method:    toString
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_cvc4_Result_toString(JNIEnv* env,
                                                    jobject,
                                                    jlong resultPointer)
{
  Result* result = (Result*)resultPointer;
  return env->NewStringUTF(result->toString().c_str());
}
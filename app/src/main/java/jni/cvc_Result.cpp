#include "cvc_Result.h"

#include "cvc4/api/cvc4cpp.h"

using namespace CVC4::api;

/*
 * Class:     cvc_Result
 * Method:    deleteResult
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_cvc_Result_deleteResult(JNIEnv*,
                                                     jobject,
                                                     jlong resultPointer)
{
  delete ((Result*)resultPointer);
}

/*
 * Class:     cvc_Result
 * Method:    toString
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_cvc_Result_toString(JNIEnv* env,
                                                    jobject,
                                                    jlong resultPointer)
{
  Result* result = (Result*)resultPointer;
  return env->NewStringUTF(result->toString().c_str());
}